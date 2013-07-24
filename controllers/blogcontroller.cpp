#include "blogcontroller.h"
#include "blog.h"
#include "admin.h"
#include "user.h"

BlogController::BlogController(const BlogController &)
    : ApplicationController()
{ }

void BlogController::index()
{
    QList<Blog> blogList = Blog::getAll();
    texport(blogList);
    render("index", "primary");
}

void BlogController::show(const QString &pk)
{
    Blog blog = Blog::get(pk.toInt());
    texport(blog);
    render("show", "primary");
}

void BlogController::entry()
{
    renderEntry();
}

void BlogController::create()
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    QVariantMap form = httpRequest().formItems("blog");
    Blog blog = Blog::create(form);
    if (!blog.isNull()) {
        QString notice = "Created successfully.";
        tflash(notice);
        redirect(urla("show", blog.id()));
    } else {
        QString error = "Failed to create.";
        texport(error);
        renderEntry(form);
    }
}

void BlogController::renderEntry(const QVariantMap &blog)
{
    QList<User> users = User::getAll();
    texport(blog);
    texport(users);
    render("entry", "primary");
}

void BlogController::edit(const QString &pk)
{
    Blog blog = Blog::get(pk.toInt());
    if (!blog.isNull()) {
        session().insert("blog_lockRevision", blog.lockRevision());
        renderEdit(blog.toVariantMap());
    } else {
        redirect(urla("entry"));
    }
}

void BlogController::save(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    QString error;
    int rev = session().value("blog_lockRevision").toInt();
    Blog blog = Blog::get(pk.toInt(), rev);
    if (blog.isNull()) {
        error = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(error);
        redirect(urla("edit", pk));
        return;
    }

    QVariantMap form = httpRequest().formItems("blog");
    blog.setProperties(form);
    if (blog.save()) {
        QString notice = "Updated successfully.";
        tflash(notice);
        redirect(urla("show", pk));
    } else {
        error = "Failed to update.";
        texport(error);
        renderEdit(form);
    }
}

void BlogController::renderEdit(const QVariantMap &blog)
{
    QList<User> users = User::getAll();
    texport(blog);
    texport(users);
    render("edit", "primary");
}

void BlogController::remove(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    Blog blog = Blog::get(pk.toInt());
    blog.remove();
    redirect(urla("index"));
}

void BlogController::setAccessRules()
{
    setDenyDefault(true);
    QStringList allowed;
    allowed << "index" << "show" << "entry" << "create";
    setAllowUser("admin", allowed);
}

bool BlogController::preFilter()
{
    ApplicationController::preFilter();

    Admin loggedInAdmin = Admin::get(identityKeyOfLoginUser());

    if(!validateAccess(&loggedInAdmin)) {
        redirect(url("session", "form"));
        return false;
    }
    return true;
}

// Don't remove below this line
T_REGISTER_CONTROLLER(blogcontroller)

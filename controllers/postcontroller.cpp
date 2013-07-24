#include "postcontroller.h"
#include "post.h"
#include "blog.h"
#include "admin.h"

PostController::PostController(const PostController &)
    : ApplicationController()
{ }

void PostController::index()
{
    QList<Post> postList = Post::getAll();
    texport(postList);
    render("index", "primary");
}

void PostController::show(const QString &pk)
{
    Post post = Post::get(pk.toInt());
    texport(post);
    render("show", "primary");
}

void PostController::entry()
{
    renderEntry();
}

void PostController::create()
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    QVariantMap form = httpRequest().formItems("post");
    Post post = Post::create(form);
    if (!post.isNull()) {
        QString notice = "Created successfully.";
        tflash(notice);
        redirect(urla("show", post.id()));
    } else {
        QString error = "Failed to create.";
        texport(error);
        renderEntry(form);
    }
}

void PostController::renderEntry(const QVariantMap &post)
{
    QList<Blog> blogs = Blog::getAll();
    texport(post);
    texport(blogs);
    render("entry", "primary");
}

void PostController::edit(const QString &pk)
{
    Post post = Post::get(pk.toInt());
    if (!post.isNull()) {
        session().insert("post_lockRevision", post.lockRevision());
        renderEdit(post.toVariantMap());
    } else {
        redirect(urla("entry"));
    }
}

void PostController::save(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    QString error;
    int rev = session().value("post_lockRevision").toInt();
    Post post = Post::get(pk.toInt(), rev);
    if (post.isNull()) {
        error = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(error);
        redirect(urla("edit", pk));
        return;
    }

    QVariantMap form = httpRequest().formItems("post");
    post.setProperties(form);
    if (post.save()) {
        QString notice = "Updated successfully.";
        tflash(notice);
        redirect(urla("show", pk));
    } else {
        error = "Failed to update.";
        texport(error);
        renderEdit(form);
    }
}

void PostController::renderEdit(const QVariantMap &post)
{
    QList<Blog> blogs = Blog::getAll();
    texport(post);
    texport(blogs);
    render("edit", "primary");
}

void PostController::remove(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    Post post = Post::get(pk.toInt());
    post.remove();
    redirect(urla("index"));
}

void PostController::setAccessRules()
{
    setDenyDefault(true);
    QStringList allowed;
    allowed << "index" << "show" << "entry" << "create";
    setAllowUser("admin", allowed);
}

bool PostController::preFilter()
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
T_REGISTER_CONTROLLER(postcontroller)

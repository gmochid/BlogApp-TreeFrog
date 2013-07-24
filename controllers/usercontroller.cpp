#include "usercontroller.h"
#include "user.h"
#include "admin.h"

UserController::UserController(const UserController &)
    : ApplicationController()
{ }

void UserController::index()
{
    QList<User> userList = User::getAll();
    texport(userList);
    render("index", "primary");
}

void UserController::show(const QString &pk)
{
    User user = User::get(pk);
    texport(user);
    render("show", "primary");
}

void UserController::entry()
{
    renderEntry();
}

void UserController::create()
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    QVariantMap form = httpRequest().formItems("user");
    User user = User::create(form);
    if (!user.isNull()) {
        QString notice = "Created successfully.";
        tflash(notice);
        redirect(urla("show", user.username()));
    } else {
        QString error = "Failed to create.";
        texport(error);
        renderEntry(form);
    }
}

void UserController::renderEntry(const QVariantMap &user)
{
    texport(user);
    render("entry", "primary");
}

void UserController::edit(const QString &pk)
{
    User user = User::get(pk);
    if (!user.isNull()) {
        session().insert("user_lockRevision", user.lockRevision());
        renderEdit(user.toVariantMap());
    } else {
        redirect(urla("entry"));
    }
}

void UserController::save(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    QString error;
    int rev = session().value("user_lockRevision").toInt();
    User user = User::get(pk, rev);
    if (user.isNull()) {
        error = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(error);
        redirect(urla("edit", pk));
        return;
    }

    QVariantMap form = httpRequest().formItems("user");
    user.setProperties(form);
    if (user.save()) {
        QString notice = "Updated successfully.";
        tflash(notice);
        redirect(urla("show", pk));
    } else {
        error = "Failed to update.";
        texport(error);
        renderEdit(form);
    }
}

void UserController::renderEdit(const QVariantMap &user)
{
    texport(user);
    render("edit", "primary");
}

void UserController::remove(const QString &pk)
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    User user = User::get(pk);
    user.remove();
    redirect(urla("index"));
}

void UserController::setAccessRules()
{
    setDenyDefault(true);
    QStringList allowed;
    allowed << "index" << "show" << "entry" << "create";
    setAllowUser("admin", allowed);
}

bool UserController::preFilter()
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
T_REGISTER_CONTROLLER(usercontroller)

#include "sessioncontroller.h"
#include "admin.h"

SessionController::SessionController(const SessionController &)
    : ApplicationController()
{ }

void SessionController::form()
{
    render("form", "notlogin");
}

void SessionController::login()
{
    if (httpRequest().method() != Tf::Post) {
        return;
    }

    QString username = httpRequest().formItemValue("username");
    QString password = httpRequest().formItemValue("password");

    Admin admin = Admin::authenticate(username, password);

    if(!admin.isNull()) {
        userLogin(&admin);
        redirect(QUrl("/admin/dashboard"));
    } else {
        QString message = "Login failed";
        texport(message);
        redirect(url("session", "form"));
    }
}

void SessionController::logout()
{
    userLogout();
    redirect(url("session", "form"));
}

// Don't remove below this line
T_REGISTER_CONTROLLER(sessioncontroller)

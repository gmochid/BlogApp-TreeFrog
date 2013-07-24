#ifndef SESSIONCONTROLLER_H
#define SESSIONCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT SessionController : public ApplicationController
{
    Q_OBJECT
public:
    SessionController() { }
    SessionController(const SessionController &other);

public slots:
    void form();
    void login();
    void logout();
};

T_DECLARE_CONTROLLER(SessionController, sessioncontroller)

#endif // SESSIONCONTROLLER_H

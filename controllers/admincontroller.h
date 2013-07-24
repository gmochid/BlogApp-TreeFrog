#ifndef ADMINCONTROLLER_H
#define ADMINCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT AdminController : public ApplicationController
{
    Q_OBJECT
public:
    AdminController() { }
    AdminController(const AdminController &other);

public slots:
    void dashboard();
};

T_DECLARE_CONTROLLER(AdminController, admincontroller)

#endif // ADMINCONTROLLER_H

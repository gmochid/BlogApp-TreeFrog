#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT UserController : public ApplicationController
{
    Q_OBJECT
public:
    UserController() { }
    UserController(const UserController &other);
    void setAccessRules();
    bool preFilter();

public slots:
    void index();
    void show(const QString &pk);
    void entry();
    void create();
    void edit(const QString &pk);
    void save(const QString &pk);
    void remove(const QString &pk);

private:
    void renderEntry(const QVariantMap &user = QVariantMap());
    void renderEdit(const QVariantMap &user = QVariantMap());
};

T_DECLARE_CONTROLLER(UserController, usercontroller)

#endif // USERCONTROLLER_H

#ifndef POSTCONTROLLER_H
#define POSTCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT PostController : public ApplicationController
{
    Q_OBJECT
public:
    PostController() { }
    PostController(const PostController &other);
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
    void renderEntry(const QVariantMap &post = QVariantMap());
    void renderEdit(const QVariantMap &post = QVariantMap());
};

T_DECLARE_CONTROLLER(PostController, postcontroller)

#endif // POSTCONTROLLER_H

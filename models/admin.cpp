#include <TreeFrogModel>
#include "admin.h"
#include "adminobject.h"

Admin::Admin()
    : TAbstractUser(), TAbstractModel(), d(new AdminObject)
{ }

Admin::Admin(const Admin &other)
    : TAbstractUser(), TAbstractModel(), d(new AdminObject(*other.d))
{ }

Admin::Admin(const AdminObject &object)
    : TAbstractUser(), TAbstractModel(), d(new AdminObject(object))
{ }


Admin::~Admin()
{
    // If the reference count becomes 0,
    // the shared data object 'AdminObject' is deleted.
}

QString Admin::username() const
{
    return d->username;
}

void Admin::setUsername(const QString &username)
{
    d->username = username;
}

QString Admin::password() const
{
    return d->password;
}

void Admin::setPassword(const QString &password)
{
    d->password = password;
}

QDateTime Admin::createdAt() const
{
    return d->created_at;
}

QDateTime Admin::updatedAt() const
{
    return d->updated_at;
}

int Admin::lockRevision() const
{
    return d->lock_revision;
}

Admin &Admin::operator=(const Admin &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Admin Admin::authenticate(const QString &username, const QString &password)
{
    if (username.isEmpty() || password.isEmpty())
        return Admin();

    TSqlORMapper<AdminObject> mapper;
    AdminObject obj = mapper.findFirst(TCriteria(AdminObject::Username, username));
    if (obj.isNull() || obj.password != password) {
        obj.clear();
    }
    return Admin(obj);
}

Admin Admin::create(const QString &username, const QString &password)
{
    AdminObject obj;
    obj.username = username;
    obj.password = password;
    if (!obj.create()) {
        return Admin();
    }
    return Admin(obj);
}

Admin Admin::create(const QVariantMap &values)
{
    Admin model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Admin Admin::get(const QString &username)
{
    TSqlORMapper<AdminObject> mapper;
    return Admin(mapper.findByPrimaryKey(username));
}

Admin Admin::get(const QString &username, int lockRevision)
{
    TSqlORMapper<AdminObject> mapper;
    TCriteria cri;
    cri.add(AdminObject::Username, username);
    cri.add(AdminObject::LockRevision, lockRevision);
    return Admin(mapper.findFirst(cri));
}

QList<Admin> Admin::getAll()
{
    return tfGetModelListByCriteria<Admin, AdminObject>();
}

TModelObject *Admin::modelData()
{
    return d.data();
}

const TModelObject *Admin::modelData() const
{
    return d.data();
}

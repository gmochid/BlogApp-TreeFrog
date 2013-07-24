#include <TreeFrogModel>
#include "user.h"
#include "userobject.h"

User::User()
    : TAbstractModel(), d(new UserObject)
{ }

User::User(const User &other)
    : TAbstractModel(), d(new UserObject(*other.d))
{ }

User::User(const UserObject &object)
    : TAbstractModel(), d(new UserObject(object))
{ }

User::~User()
{
    // If the reference count becomes 0,
    // the shared data object 'UserObject' is deleted.
}

QString User::username() const
{
    return d->username;
}

void User::setUsername(const QString &username)
{
    d->username = username;
}

QString User::email() const
{
    return d->email;
}

void User::setEmail(const QString &email)
{
    d->email = email;
}

QString User::fullname() const
{
    return d->fullname;
}

void User::setFullname(const QString &fullname)
{
    d->fullname = fullname;
}

QString User::password() const
{
    return d->password;
}

void User::setPassword(const QString &password)
{
    d->password = password;
}

QDateTime User::createdAt() const
{
    return d->created_at;
}

QDateTime User::updatedAt() const
{
    return d->updated_at;
}

int User::lockRevision() const
{
    return d->lock_revision;
}

User &User::operator=(const User &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

User User::create(const QString &username, const QString &email, const QString &fullname, const QString &password)
{
    UserObject obj;
    obj.username = username;
    obj.email = email;
    obj.fullname = fullname;
    obj.password = password;
    if (!obj.create()) {
        return User();
    }
    return User(obj);
}

User User::create(const QVariantMap &values)
{
    User model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

User User::get(const QString &username)
{
    TSqlORMapper<UserObject> mapper;
    return User(mapper.findByPrimaryKey(username));
}

User User::get(const QString &username, int lockRevision)
{
    TSqlORMapper<UserObject> mapper;
    TCriteria cri;
    cri.add(UserObject::Username, username);
    cri.add(UserObject::LockRevision, lockRevision);
    return User(mapper.findFirst(cri));
}

QList<User> User::getAll()
{
    return tfGetModelListByCriteria<User, UserObject>(TCriteria());
}

TModelObject *User::modelData()
{
    return d.data();
}

const TModelObject *User::modelData() const
{
    return d.data();
}

#ifndef USER_H
#define USER_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TSqlObject;
class UserObject;


class T_MODEL_EXPORT User : public TAbstractModel
{
public:
    User();
    User(const User &other);
    User(const UserObject &object);
    ~User();

    QString username() const;
    void setUsername(const QString &username);
    QString email() const;
    void setEmail(const QString &email);
    QString fullname() const;
    void setFullname(const QString &fullname);
    QString password() const;
    void setPassword(const QString &password);
    QDateTime createdAt() const;
    QDateTime updatedAt() const;
    int lockRevision() const;
    User &operator=(const User &other);

    static User create(const QString &username, const QString &email, const QString &fullname, const QString &password);
    static User create(const QVariantMap &values);
    static User get(const QString &username);
    static User get(const QString &username, int lockRevision);
    static QList<User> getAll();

private:
    QSharedDataPointer<UserObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
};

Q_DECLARE_METATYPE(User)
Q_DECLARE_METATYPE(QList<User>)

#endif // USER_H

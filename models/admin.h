#ifndef ADMIN_H
#define ADMIN_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractUser>
#include <TAbstractModel>

class TSqlObject;
class AdminObject;


class T_MODEL_EXPORT Admin : public TAbstractUser, public TAbstractModel
{
public:
    Admin();
    Admin(const Admin &other);
    Admin(const AdminObject &object);
    ~Admin();

    QString username() const;
    void setUsername(const QString &username);
    QString password() const;
    void setPassword(const QString &password);
    QDateTime createdAt() const;
    QDateTime updatedAt() const;
    int lockRevision() const;
    QString identityKey() const { return username(); }
    Admin &operator=(const Admin &other);

    static Admin authenticate(const QString &username, const QString &password);
    static Admin create(const QString &username, const QString &password);
    static Admin create(const QVariantMap &values);
    static Admin get(const QString &username);
    static Admin get(const QString &username, int lockRevision);
    static QList<Admin> getAll();

private:
    QSharedDataPointer<AdminObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
};

Q_DECLARE_METATYPE(Admin)
Q_DECLARE_METATYPE(QList<Admin>)

#endif // ADMIN_H

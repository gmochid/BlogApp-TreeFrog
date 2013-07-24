#ifndef USEROBJECT_H
#define USEROBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT UserObject : public TSqlObject, public QSharedData
{
public:
    QString username;
    QString email;
    QString fullname;
    QString password;
    QDateTime created_at;
    QDateTime updated_at;
    int lock_revision;

    enum PropertyIndex {
        Username = 0,
        Email,
        Fullname,
        Password,
        CreatedAt,
        UpdatedAt,
        LockRevision,
    };

    int primaryKeyIndex() const { return Username; }
    int autoValueIndex() const { return -1; }
    QString tableName() const { return QLatin1String("user"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(QString username READ getusername WRITE setusername)
    T_DEFINE_PROPERTY(QString, username)
    Q_PROPERTY(QString email READ getemail WRITE setemail)
    T_DEFINE_PROPERTY(QString, email)
    Q_PROPERTY(QString fullname READ getfullname WRITE setfullname)
    T_DEFINE_PROPERTY(QString, fullname)
    Q_PROPERTY(QString password READ getpassword WRITE setpassword)
    T_DEFINE_PROPERTY(QString, password)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(int lock_revision READ getlock_revision WRITE setlock_revision)
    T_DEFINE_PROPERTY(int, lock_revision)
};

#endif // USEROBJECT_H

#ifndef POSTOBJECT_H
#define POSTOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT PostObject : public TSqlObject, public QSharedData
{
public:
    int id;
    int blog_id;
    QString title;
    QString content;
    QDateTime created_at;
    QDateTime updated_at;
    int lock_revision;

    enum PropertyIndex {
        Id = 0,
        BlogId,
        Title,
        Content,
        CreatedAt,
        UpdatedAt,
        LockRevision,
    };

    int primaryKeyIndex() const { return Id; }
    int autoValueIndex() const { return Id; }
    QString tableName() const { return QLatin1String("post"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(int blog_id READ getblog_id WRITE setblog_id)
    T_DEFINE_PROPERTY(int, blog_id)
    Q_PROPERTY(QString title READ gettitle WRITE settitle)
    T_DEFINE_PROPERTY(QString, title)
    Q_PROPERTY(QString content READ getcontent WRITE setcontent)
    T_DEFINE_PROPERTY(QString, content)
    Q_PROPERTY(QDateTime created_at READ getcreated_at WRITE setcreated_at)
    T_DEFINE_PROPERTY(QDateTime, created_at)
    Q_PROPERTY(QDateTime updated_at READ getupdated_at WRITE setupdated_at)
    T_DEFINE_PROPERTY(QDateTime, updated_at)
    Q_PROPERTY(int lock_revision READ getlock_revision WRITE setlock_revision)
    T_DEFINE_PROPERTY(int, lock_revision)
};

#endif // POSTOBJECT_H

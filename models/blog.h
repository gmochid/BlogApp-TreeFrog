#ifndef BLOG_H
#define BLOG_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TSqlObject;
class BlogObject;


class T_MODEL_EXPORT Blog : public TAbstractModel
{
public:
    Blog();
    Blog(const Blog &other);
    Blog(const BlogObject &object);
    ~Blog();

    int id() const;
    QString username() const;
    void setUsername(const QString &username);
    QString title() const;
    void setTitle(const QString &title);
    QString description() const;
    void setDescription(const QString &description);
    QDateTime createdAt() const;
    QDateTime updatedAt() const;
    int lockRevision() const;
    Blog &operator=(const Blog &other);

    static Blog create(const QString &username, const QString &title, const QString &description);
    static Blog create(const QVariantMap &values);
    static Blog get(int id);
    static Blog get(int id, int lockRevision);
    static QList<Blog> getAll();

private:
    QSharedDataPointer<BlogObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
};

Q_DECLARE_METATYPE(Blog)
Q_DECLARE_METATYPE(QList<Blog>)

#endif // BLOG_H

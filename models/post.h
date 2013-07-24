#ifndef POST_H
#define POST_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TSqlObject;
class PostObject;


class T_MODEL_EXPORT Post : public TAbstractModel
{
public:
    Post();
    Post(const Post &other);
    Post(const PostObject &object);
    ~Post();

    int id() const;
    int blogId() const;
    void setBlogId(int blogId);
    QString title() const;
    void setTitle(const QString &title);
    QString content() const;
    void setContent(const QString &content);
    QDateTime createdAt() const;
    QDateTime updatedAt() const;
    int lockRevision() const;
    Post &operator=(const Post &other);

    static Post create(int blogId, const QString &title, const QString &content);
    static Post create(const QVariantMap &values);
    static Post get(int id);
    static Post get(int id, int lockRevision);
    static QList<Post> getAll();

private:
    QSharedDataPointer<PostObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
};

Q_DECLARE_METATYPE(Post)
Q_DECLARE_METATYPE(QList<Post>)

#endif // POST_H

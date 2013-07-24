#include <TreeFrogModel>
#include "post.h"
#include "postobject.h"

Post::Post()
    : TAbstractModel(), d(new PostObject)
{
    d->blog_id = 0;
}

Post::Post(const Post &other)
    : TAbstractModel(), d(new PostObject(*other.d))
{ }

Post::Post(const PostObject &object)
    : TAbstractModel(), d(new PostObject(object))
{ }

Post::~Post()
{
    // If the reference count becomes 0,
    // the shared data object 'PostObject' is deleted.
}

int Post::id() const
{
    return d->id;
}

int Post::blogId() const
{
    return d->blog_id;
}

void Post::setBlogId(int blogId)
{
    d->blog_id = blogId;
}

QString Post::title() const
{
    return d->title;
}

void Post::setTitle(const QString &title)
{
    d->title = title;
}

QString Post::content() const
{
    return d->content;
}

void Post::setContent(const QString &content)
{
    d->content = content;
}

QDateTime Post::createdAt() const
{
    return d->created_at;
}

QDateTime Post::updatedAt() const
{
    return d->updated_at;
}

int Post::lockRevision() const
{
    return d->lock_revision;
}

Post &Post::operator=(const Post &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Post Post::create(int blogId, const QString &title, const QString &content)
{
    PostObject obj;
    obj.blog_id = blogId;
    obj.title = title;
    obj.content = content;
    if (!obj.create()) {
        return Post();
    }
    return Post(obj);
}

Post Post::create(const QVariantMap &values)
{
    Post model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Post Post::get(int id)
{
    TSqlORMapper<PostObject> mapper;
    return Post(mapper.findByPrimaryKey(id));
}

Post Post::get(int id, int lockRevision)
{
    TSqlORMapper<PostObject> mapper;
    TCriteria cri;
    cri.add(PostObject::Id, id);
    cri.add(PostObject::LockRevision, lockRevision);
    return Post(mapper.findFirst(cri));
}

QList<Post> Post::getAll()
{
    return tfGetModelListByCriteria<Post, PostObject>(TCriteria());
}

TModelObject *Post::modelData()
{
    return d.data();
}

const TModelObject *Post::modelData() const
{
    return d.data();
}

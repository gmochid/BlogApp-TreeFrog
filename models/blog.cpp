#include <TreeFrogModel>
#include "blog.h"
#include "blogobject.h"

Blog::Blog()
    : TAbstractModel(), d(new BlogObject)
{ }

Blog::Blog(const Blog &other)
    : TAbstractModel(), d(new BlogObject(*other.d))
{ }

Blog::Blog(const BlogObject &object)
    : TAbstractModel(), d(new BlogObject(object))
{ }

Blog::~Blog()
{
    // If the reference count becomes 0,
    // the shared data object 'BlogObject' is deleted.
}

int Blog::id() const
{
    return d->id;
}

QString Blog::username() const
{
    return d->username;
}

void Blog::setUsername(const QString &username)
{
    d->username = username;
}

QString Blog::title() const
{
    return d->title;
}

void Blog::setTitle(const QString &title)
{
    d->title = title;
}

QString Blog::description() const
{
    return d->description;
}

void Blog::setDescription(const QString &description)
{
    d->description = description;
}

QDateTime Blog::createdAt() const
{
    return d->created_at;
}

QDateTime Blog::updatedAt() const
{
    return d->updated_at;
}

int Blog::lockRevision() const
{
    return d->lock_revision;
}

Blog &Blog::operator=(const Blog &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Blog Blog::create(const QString &username, const QString &title, const QString &description)
{
    BlogObject obj;
    obj.username = username;
    obj.title = title;
    obj.description = description;
    if (!obj.create()) {
        return Blog();
    }
    return Blog(obj);
}

Blog Blog::create(const QVariantMap &values)
{
    Blog model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Blog Blog::get(int id)
{
    TSqlORMapper<BlogObject> mapper;
    return Blog(mapper.findByPrimaryKey(id));
}

Blog Blog::get(int id, int lockRevision)
{
    TSqlORMapper<BlogObject> mapper;
    TCriteria cri;
    cri.add(BlogObject::Id, id);
    cri.add(BlogObject::LockRevision, lockRevision);
    return Blog(mapper.findFirst(cri));
}

QList<Blog> Blog::getAll()
{
    return tfGetModelListByCriteria<Blog, BlogObject>(TCriteria());
}

TModelObject *Blog::modelData()
{
    return d.data();
}

const TModelObject *Blog::modelData() const
{
    return d.data();
}

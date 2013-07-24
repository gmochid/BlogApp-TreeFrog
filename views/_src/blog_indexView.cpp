#include <QtCore>
#include <TreeFrogView>
#include "blog.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT blog_indexView : public TActionView
{
  Q_OBJECT
public:
  blog_indexView() : TActionView() { }
  blog_indexView(const blog_indexView &) : TActionView() { }
  QString toString();
};

QString blog_indexView::toString()
{
  responsebody.reserve(1495);
    responsebody += tr("\n<h1>Listing Blog</h1>\n\n");
  responsebody += QVariant(linkTo("Dashboard", QUrl("/Admin/dashboard"))).toString();
  responsebody += tr("<br />\n\n");
  responsebody += QVariant(linkTo("New entry", urla("entry"))).toString();
  responsebody += tr("<br />\n<br />\n<table border=\"1\" cellpadding=\"5\" style=\"border: 1px #d0d0d0 solid; border-collapse: collapse;\">\n  <tr>\n    <th>ID</th>\n    <th>Username</th>\n    <th>Title</th>\n    <th>Description</th>\n  </tr>\n");
  tfetch(QList<Blog>, blogList);
  for (QListIterator<Blog> it(blogList); it.hasNext(); ) {
     const Blog &i = it.next();
  responsebody += tr("  <tr>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += tr("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.username());
  responsebody += tr("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.title());
  responsebody += tr("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.description());
  responsebody += tr("</td>\n    <td>\n      ");
  responsebody += QVariant(linkTo("Show", urla("show", i.id()))).toString();
  responsebody += tr("\n      ");
  responsebody += QVariant(linkTo("Edit", urla("edit", i.id()))).toString();
  responsebody += tr("\n      ");
  responsebody += QVariant(linkTo("Remove", urla("remove", i.id()), Tf::Post, "confirm('Are you sure?')")).toString();
  responsebody += tr("\n    </td>\n  </tr>\n");
  };
  responsebody += tr("</table>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(blog_indexView)
T_REGISTER_VIEW(blog_indexView)

#include "blog_indexView.moc"

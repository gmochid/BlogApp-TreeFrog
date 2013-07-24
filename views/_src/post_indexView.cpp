#include <QtCore>
#include <TreeFrogView>
#include "post.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT post_indexView : public TActionView
{
  Q_OBJECT
public:
  post_indexView() : TActionView() { }
  post_indexView(const post_indexView &) : TActionView() { }
  QString toString();
};

QString post_indexView::toString()
{
  responsebody.reserve(1514);
  responsebody += tr("\n");
    responsebody += tr("\n<h1>Listing Post</h1>\n\n");
  responsebody += QVariant(linkTo("Dashboard", QUrl("/Admin/dashboard"))).toString();
  responsebody += tr("<br />\n\n");
  responsebody += QVariant(linkTo("New entry", urla("entry"))).toString();
  responsebody += tr("<br />\n<br />\n<table border=\"1\" cellpadding=\"5\" style=\"border: 1px #d0d0d0 solid; border-collapse: collapse;\">\n  <tr>\n    <th>ID</th>\n    <th>Blog ID</th>\n    <th>Title</th>\n    <th>Content</th>\n  </tr>\n");
  tfetch(QList<Post>, postList);
  for (QListIterator<Post> it(postList); it.hasNext(); ) {
     const Post &i = it.next();
  responsebody += tr("  <tr>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += tr("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.blogId());
  responsebody += tr("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.title());
  responsebody += tr("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.content());
  responsebody += tr("</td>\n    <td>\n      ");
  responsebody += QVariant(linkTo("Show", urla("show", i.id()))).toString();
  responsebody += tr("\n      ");
  responsebody += QVariant(linkTo("Edit", urla("edit", i.id()))).toString();
  responsebody += tr("\n      ");
  responsebody += QVariant(linkTo("Remove", urla("remove", i.id()), Tf::Post, "confirm('Are you sure?')")).toString();
  responsebody += tr("\n    </td>\n  </tr>\n");
  };
  responsebody += tr("</table>\n\n");

  return responsebody;
}

Q_DECLARE_METATYPE(post_indexView)
T_REGISTER_VIEW(post_indexView)

#include "post_indexView.moc"

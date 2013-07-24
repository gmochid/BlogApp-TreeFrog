#include <QtCore>
#include <TreeFrogView>
#include "blog.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT blog_showView : public TActionView
{
  Q_OBJECT
public:
  blog_showView() : TActionView() { }
  blog_showView(const blog_showView &) : TActionView() { }
  QString toString();
};

QString blog_showView::toString()
{
  responsebody.reserve(1314);
  responsebody += tr("\n");
    tfetch(Blog, blog);
  responsebody += tr("\n<p style=\"color: red\">");
  tehex(error);
  responsebody += tr("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += tr("</p>\n\n<h1>Showing Blog</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(blog.id());
  responsebody += tr("</dd><br />\n<dt>Username</dt><dd>");
  responsebody += THttpUtility::htmlEscape(blog.username());
  responsebody += tr("</dd><br />\n<dt>Title</dt><dd>");
  responsebody += THttpUtility::htmlEscape(blog.title());
  responsebody += tr("</dd><br />\n<dt>Description</dt><dd>");
  responsebody += THttpUtility::htmlEscape(blog.description());
  responsebody += tr("</dd><br />\n<dt>Created at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(blog.createdAt());
  responsebody += tr("</dd><br />\n<dt>Updated at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(blog.updatedAt());
  responsebody += tr("</dd><br />\n<dt>Lock Revision</dt><dd>");
  responsebody += THttpUtility::htmlEscape(blog.lockRevision());
  responsebody += tr("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("edit", blog.id()))).toString();
  responsebody += tr(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += tr("\n\n");

  return responsebody;
}

Q_DECLARE_METATYPE(blog_showView)
T_REGISTER_VIEW(blog_showView)

#include "blog_showView.moc"

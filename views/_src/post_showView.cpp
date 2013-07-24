#include <QtCore>
#include <TreeFrogView>
#include "post.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT post_showView : public TActionView
{
  Q_OBJECT
public:
  post_showView() : TActionView() { }
  post_showView(const post_showView &) : TActionView() { }
  QString toString();
};

QString post_showView::toString()
{
  responsebody.reserve(1303);
  responsebody += tr("\n");
    tfetch(Post, post);
  responsebody += tr("\n<p style=\"color: red\">");
  tehex(error);
  responsebody += tr("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += tr("</p>\n\n<h1>Showing Post</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(post.id());
  responsebody += tr("</dd><br />\n<dt>Blog ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(post.blogId());
  responsebody += tr("</dd><br />\n<dt>Title</dt><dd>");
  responsebody += THttpUtility::htmlEscape(post.title());
  responsebody += tr("</dd><br />\n<dt>Content</dt><dd>");
  responsebody += THttpUtility::htmlEscape(post.content());
  responsebody += tr("</dd><br />\n<dt>Created at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(post.createdAt());
  responsebody += tr("</dd><br />\n<dt>Updated at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(post.updatedAt());
  responsebody += tr("</dd><br />\n<dt>Lock Revision</dt><dd>");
  responsebody += THttpUtility::htmlEscape(post.lockRevision());
  responsebody += tr("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("edit", post.id()))).toString();
  responsebody += tr(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += tr("\n\n");

  return responsebody;
}

Q_DECLARE_METATYPE(post_showView)
T_REGISTER_VIEW(post_showView)

#include "post_showView.moc"

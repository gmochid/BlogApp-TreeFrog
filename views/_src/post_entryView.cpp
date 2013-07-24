#include <QtCore>
#include <TreeFrogView>
#include "post.h" 
#include "blog.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT post_entryView : public TActionView
{
  Q_OBJECT
public:
  post_entryView() : TActionView() { }
  post_entryView(const post_entryView &) : TActionView() { }
  QString toString();
};

QString post_entryView::toString()
{
  responsebody.reserve(1419);
  responsebody += tr("\n");
      tfetch(QVariantMap, post);
  tfetch(QList<Blog>, blogs);
  responsebody += tr("\n<p style=\"color: red\">");
  tehex(error);
  responsebody += tr("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += tr("</p>\n\n<h1>New Post</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += tr("\n  <p>\n    <label>Blog Title<br/>\n    <select name=\"post[blogId]\" selected=\"");
  responsebody += THttpUtility::htmlEscape(post["blogId"]);
  responsebody += tr("\">\n        ");
  foreach (Blog blog, blogs) {;
  responsebody += tr("        <option value=\"");
  responsebody += THttpUtility::htmlEscape(blog.id());
  responsebody += tr("\">");
  responsebody += THttpUtility::htmlEscape(blog.title());
  responsebody += tr("</option>\n        ");
  };
  responsebody += tr("    </select>\n  </p>\n  <p>\n    <label>Title<br /><input name=\"post[title]\" value=\"");
  responsebody += THttpUtility::htmlEscape(post["title"]);
  responsebody += tr("\" /></label>\n  </p>\n  <p>\n    <label>Content<br /><input name=\"post[content]\" value=\"");
  responsebody += THttpUtility::htmlEscape(post["content"]);
  responsebody += tr("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += tr("\n\n");

  return responsebody;
}

Q_DECLARE_METATYPE(post_entryView)
T_REGISTER_VIEW(post_entryView)

#include "post_entryView.moc"

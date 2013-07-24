#include <QtCore>
#include <TreeFrogView>
#include "post.h" 
#include "blog.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT post_editView : public TActionView
{
  Q_OBJECT
public:
  post_editView() : TActionView() { }
  post_editView(const post_editView &) : TActionView() { }
  QString toString();
};

QString post_editView::toString()
{
  responsebody.reserve(1700);
  responsebody += tr("\n");
      tfetch(QVariantMap, post);
  tfetch(QList<Blog>, blogs);
  responsebody += tr("\n<p style=\"color: red\">");
  tehex(error);
  responsebody += tr("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += tr("</p>\n\n<h1>Editing Post</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", post["id"]), Tf::Post)).toString();
  responsebody += tr("\n  <p>\n    <label>ID<br/>\n    <b>");
  responsebody += THttpUtility::htmlEscape(post["id"]);
  responsebody += tr("</b>\n  </p>\n  <p>\n    <label>Blog Title<br/>\n    <select name=\"post[blogId]\" selected=\"");
  responsebody += THttpUtility::htmlEscape(post["blogId"]);
  responsebody += tr("\">\n        ");
  foreach (Blog blog, blogs) {;
  responsebody += tr("        <option value=\"");
  responsebody += THttpUtility::htmlEscape(blog.id());
  responsebody += tr("\">");
  responsebody += THttpUtility::htmlEscape(blog.title());
  responsebody += tr("</option>\n        ");
  };
  responsebody += tr("    </select>\n  </p>\n  <p>\n    <label>Title<br /><input type=\"text\" name=\"post[title]\" value=\"");
  responsebody += THttpUtility::htmlEscape(post["title"]);
  responsebody += tr("\" /></label>\n  </p>\n  <p>\n    <label>Content<br /><input type=\"text\" name=\"post[content]\" value=\"");
  responsebody += THttpUtility::htmlEscape(post["content"]);
  responsebody += tr("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Update\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", post["id"]))).toString();
  responsebody += tr(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += tr("\n");

  return responsebody;
}

Q_DECLARE_METATYPE(post_editView)
T_REGISTER_VIEW(post_editView)

#include "post_editView.moc"

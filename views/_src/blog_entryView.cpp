#include <QtCore>
#include <TreeFrogView>
#include "blog.h" 
#include "user.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT blog_entryView : public TActionView
{
  Q_OBJECT
public:
  blog_entryView() : TActionView() { }
  blog_entryView(const blog_entryView &) : TActionView() { }
  QString toString();
};

QString blog_entryView::toString()
{
  responsebody.reserve(1442);
  responsebody += tr("\n");
      tfetch(QVariantMap, blog);
  tfetch(QList<User>, users);
  responsebody += tr("\n<p style=\"color: red\">");
  tehex(error);
  responsebody += tr("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += tr("</p>\n\n<h1>New Blog</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += tr("\n  <p>\n    <label>Username<br />\n    <select name=\"post[username]\" selected=\"");
  responsebody += THttpUtility::htmlEscape(blog["username"]);
  responsebody += tr("\">\n        ");
  foreach (User user, users) {;
  responsebody += tr("        <option value=\"");
  responsebody += THttpUtility::htmlEscape(user.username());
  responsebody += tr("\" >");
  responsebody += THttpUtility::htmlEscape(user.fullname());
  responsebody += tr("</option>\n        ");
  };
  responsebody += tr("    </select>\n  </p>\n  <p>\n    <label>Title<br /><input name=\"blog[title]\" value=\"");
  responsebody += THttpUtility::htmlEscape(blog["title"]);
  responsebody += tr("\" /></label>\n  </p>\n  <p>\n    <label>Description<br /><input name=\"blog[description]\" value=\"");
  responsebody += THttpUtility::htmlEscape(blog["description"]);
  responsebody += tr("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += tr("\n");

  return responsebody;
}

Q_DECLARE_METATYPE(blog_entryView)
T_REGISTER_VIEW(blog_entryView)

#include "blog_entryView.moc"

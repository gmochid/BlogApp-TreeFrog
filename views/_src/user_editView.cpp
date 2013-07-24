#include <QtCore>
#include <TreeFrogView>
#include "user.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT user_editView : public TActionView
{
  Q_OBJECT
public:
  user_editView() : TActionView() { }
  user_editView(const user_editView &) : TActionView() { }
  QString toString();
};

QString user_editView::toString()
{
  responsebody.reserve(1467);
  responsebody += tr("\n");
    tfetch(QVariantMap, user);
  responsebody += tr("\n<p style=\"color: red\">");
  tehex(error);
  responsebody += tr("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += tr("</p>\n\n<h1>Editing User</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", user["username"]), Tf::Post)).toString();
  responsebody += tr("\n  <p>\n    <label>Username<br /><input type=\"text\" name=\"user[username]\" value=\"");
  responsebody += THttpUtility::htmlEscape(user["username"]);
  responsebody += tr("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>Email<br /><input type=\"text\" name=\"user[email]\" value=\"");
  responsebody += THttpUtility::htmlEscape(user["email"]);
  responsebody += tr("\" /></label>\n  </p>\n  <p>\n    <label>Fullname<br /><input type=\"text\" name=\"user[fullname]\" value=\"");
  responsebody += THttpUtility::htmlEscape(user["fullname"]);
  responsebody += tr("\" /></label>\n  </p>\n  <p>\n    <label>Password<br /><input type=\"text\" name=\"user[password]\" value=\"");
  responsebody += THttpUtility::htmlEscape(user["password"]);
  responsebody += tr("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Update\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", user["username"]))).toString();
  responsebody += tr(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += tr("\n\n");

  return responsebody;
}

Q_DECLARE_METATYPE(user_editView)
T_REGISTER_VIEW(user_editView)

#include "user_editView.moc"

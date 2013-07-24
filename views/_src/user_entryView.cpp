#include <QtCore>
#include <TreeFrogView>
#include "user.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT user_entryView : public TActionView
{
  Q_OBJECT
public:
  user_entryView() : TActionView() { }
  user_entryView(const user_entryView &) : TActionView() { }
  QString toString();
};

QString user_entryView::toString()
{
  responsebody.reserve(1252);
  responsebody += tr("\n");
    tfetch(QVariantMap, user);
  responsebody += tr("\n<p style=\"color: red\">");
  tehex(error);
  responsebody += tr("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += tr("</p>\n\n<h1>New User</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += tr("\n  <p>\n    <label>Username<br /><input name=\"user[username]\" value=\"");
  responsebody += THttpUtility::htmlEscape(user["username"]);
  responsebody += tr("\" /></label>\n  </p>\n  <p>\n    <label>Email<br /><input name=\"user[email]\" value=\"");
  responsebody += THttpUtility::htmlEscape(user["email"]);
  responsebody += tr("\" /></label>\n  </p>\n  <p>\n    <label>Fullname<br /><input name=\"user[fullname]\" value=\"");
  responsebody += THttpUtility::htmlEscape(user["fullname"]);
  responsebody += tr("\" /></label>\n  </p>\n  <p>\n    <label>Password<br /><input name=\"user[password]\" value=\"");
  responsebody += THttpUtility::htmlEscape(user["password"]);
  responsebody += tr("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += tr("\n\n");

  return responsebody;
}

Q_DECLARE_METATYPE(user_entryView)
T_REGISTER_VIEW(user_entryView)

#include "user_entryView.moc"

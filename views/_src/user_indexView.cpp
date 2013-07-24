#include <QtCore>
#include <TreeFrogView>
#include "user.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT user_indexView : public TActionView
{
  Q_OBJECT
public:
  user_indexView() : TActionView() { }
  user_indexView(const user_indexView &) : TActionView() { }
  QString toString();
};

QString user_indexView::toString()
{
  responsebody.reserve(1547);
  responsebody += tr("\n");
    responsebody += tr("\n<h1>Listing User</h1>\n\n");
  responsebody += QVariant(linkTo("Dashboard", QUrl("/Admin/dashboard"))).toString();
  responsebody += tr("<br />\n\n");
  responsebody += QVariant(linkTo("New entry", urla("entry"))).toString();
  responsebody += tr("<br />\n<br />\n<table border=\"1\" cellpadding=\"5\" style=\"border: 1px #d0d0d0 solid; border-collapse: collapse;\">\n  <tr>\n    <th>Username</th>\n    <th>Email</th>\n    <th>Fullname</th>\n    <th>Password</th>\n  </tr>\n");
  tfetch(QList<User>, userList);
  for (QListIterator<User> it(userList); it.hasNext(); ) {
     const User &i = it.next();
  responsebody += tr("  <tr>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.username());
  responsebody += tr("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.email());
  responsebody += tr("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.fullname());
  responsebody += tr("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.password());
  responsebody += tr("</td>\n    <td>\n      ");
  responsebody += QVariant(linkTo("Show", urla("show", i.username()))).toString();
  responsebody += tr("\n      ");
  responsebody += QVariant(linkTo("Edit", urla("edit", i.username()))).toString();
  responsebody += tr("\n      ");
  responsebody += QVariant(linkTo("Remove", urla("remove", i.username()), Tf::Post, "confirm('Are you sure?')")).toString();
  responsebody += tr("\n    </td>\n  </tr>\n");
  };
  responsebody += tr("</table>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(user_indexView)
T_REGISTER_VIEW(user_indexView)

#include "user_indexView.moc"

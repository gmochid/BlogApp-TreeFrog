#include <QtCore>
#include <TreeFrogView>
#include "user.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT user_showView : public TActionView
{
  Q_OBJECT
public:
  user_showView() : TActionView() { }
  user_showView(const user_showView &) : TActionView() { }
  QString toString();
};

QString user_showView::toString()
{
  responsebody.reserve(1324);
  responsebody += tr("\n");
    tfetch(User, user);
  responsebody += tr("\n<p style=\"color: red\">");
  tehex(error);
  responsebody += tr("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += tr("</p>\n\n<h1>Showing User</h1>\n<dt>Username</dt><dd>");
  responsebody += THttpUtility::htmlEscape(user.username());
  responsebody += tr("</dd><br />\n<dt>Email</dt><dd>");
  responsebody += THttpUtility::htmlEscape(user.email());
  responsebody += tr("</dd><br />\n<dt>Fullname</dt><dd>");
  responsebody += THttpUtility::htmlEscape(user.fullname());
  responsebody += tr("</dd><br />\n<dt>Password</dt><dd>");
  responsebody += THttpUtility::htmlEscape(user.password());
  responsebody += tr("</dd><br />\n<dt>Created at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(user.createdAt());
  responsebody += tr("</dd><br />\n<dt>Updated at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(user.updatedAt());
  responsebody += tr("</dd><br />\n<dt>Lock Revision</dt><dd>");
  responsebody += THttpUtility::htmlEscape(user.lockRevision());
  responsebody += tr("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("edit", user.username()))).toString();
  responsebody += tr(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += tr("\n");

  return responsebody;
}

Q_DECLARE_METATYPE(user_showView)
T_REGISTER_VIEW(user_showView)

#include "user_showView.moc"

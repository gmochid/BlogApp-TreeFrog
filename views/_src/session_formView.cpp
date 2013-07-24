#include <QtCore>
#include <TreeFrogView>
#include "admin.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT session_formView : public TActionView
{
  Q_OBJECT
public:
  session_formView() : TActionView() { }
  session_formView(const session_formView &) : TActionView() { }
  QString toString();
};

QString session_formView::toString()
{
  responsebody.reserve(513);
  responsebody += tr("\n");
    responsebody += tr("\n<h1>Login</h1>\n<div style=\"color: red;\">");
  techoex(message);
  responsebody += tr("</div>\n");
  responsebody += QVariant(formTag(urla("login"), Tf::Post)).toString();
  responsebody += tr("\n    <p>\n        <label>Username<br /><input type=\"text\" name=\"username\"/></label>\n    </p>\n    <p>\n      <label>Password<br /><input type=\"password\" name=\"password\"/></label>\n    </p>\n        <input type=\"submit\" text=\"Login\">\n</form>\n\n");

  return responsebody;
}

Q_DECLARE_METATYPE(session_formView)
T_REGISTER_VIEW(session_formView)

#include "session_formView.moc"

#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT admin_dashboardView : public TActionView
{
  Q_OBJECT
public:
  admin_dashboardView() : TActionView() { }
  admin_dashboardView(const admin_dashboardView &) : TActionView() { }
  QString toString();
};

QString admin_dashboardView::toString()
{
  responsebody.reserve(312);
  responsebody += QVariant(linkTo("User", QUrl("/User/index"))).toString();
  responsebody += tr("\n");
  responsebody += QVariant(linkTo("Blog", QUrl("/Blog/index"))).toString();
  responsebody += tr("\n");
  responsebody += QVariant(linkTo("Post", QUrl("/Post/index"))).toString();
  responsebody += tr("\n");

  return responsebody;
}

Q_DECLARE_METATYPE(admin_dashboardView)
T_REGISTER_VIEW(admin_dashboardView)

#include "admin_dashboardView.moc"

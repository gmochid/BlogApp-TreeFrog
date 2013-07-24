#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT layouts_notloginView : public TActionView
{
  Q_OBJECT
public:
  layouts_notloginView() : TActionView() { }
  layouts_notloginView(const layouts_notloginView &) : TActionView() { }
  QString toString();
};

QString layouts_notloginView::toString()
{
  responsebody.reserve(518);
  responsebody += tr("<!DOCTYPE HTML>\n<html>\n<head>\n  <meta http-equiv=\"content-type\" content=\"text/html;charset=UTF-8\" />\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += tr("</title>\n    <link rel=\"stylesheet\" href=\"../css/bootstrap.min.css\">\n    <script src=\"../js/bootstrap.min.js\"></script>\n</head>\n<body>\n    ");
  responsebody += QVariant(yield()).toString();
  responsebody += tr("\n</body>\n</html>\n");

  return responsebody;
}

Q_DECLARE_METATYPE(layouts_notloginView)
T_REGISTER_VIEW(layouts_notloginView)

#include "layouts_notloginView.moc"

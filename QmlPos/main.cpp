#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include "libPos.h"
#include "qormfiltermodel.h"
#include "loginhandler.h"
#include "rciprint.h"
#include "qmlposimageprovide.h"

#include "qormusuario.h"

template <class TChild, class TParent>
class QOrmRelation1N : public QOrmTableModel<TChild>
{
public:
    QOrmRelation1N() :
        QOrmTableModel<TChild>(
            QOrmBasicLoader::QOrmRelation1N<TParent, TChild>())
    {
    }
};

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    app.setOrganizationName("KISystem");
    app.setOrganizationDomain("kisystem.com.ar");
    app.setApplicationName("QmlPos");

    qRegisterMetaType<QAbstractItemModel*>();

    QOrmPos::init();

    qmlRegisterType<QOrmRelation1N<QOrmProductos, QOrmCategoria> >("libPos.models", 0, 1, "OrmProductosXCategRelation");
    qmlRegisterType<FilterModel>("libPos.models", 0, 0, "FilterModel");


    QQmlApplicationEngine engine;
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    engine.addImportPath(QDir::currentPath()+"/ui/");
    engine.addImageProvider("productos", new QmlPosImageProvider());
    QDir::addSearchPath("img",   QDir::currentPath() + "/img/");
    QDir::addSearchPath("icons", QDir::currentPath() + "/img/");

    LoginHandler *handler = new LoginHandler(&engine, &db);
    engine.rootContext()->setContextProperty("LoginHandler", handler);
    engine.rootContext()->setContextProperty("Printer", new RCIPrint());

    engine.load("ui/main.qml");

    return app.exec();
}

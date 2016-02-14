#include "qmlposimageprovide.h"

#include <QOrmLoader>
#include <QtSql>

#include "QOrm/qormproductos.h"

QPixmap QmlPosImageProvider::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
{
    /*QSqlQuery q;
    q.prepare("SELECT foto FROM Productos WHERE idProducto = ?");
    q.addBindValue(id);
    if(!q.exec()) { qDebug()<<q.lastError().text(); return QPixmap(); }
    if(!q.next()) return QPixmap(); //*/

    QOrmLoader<QOrmProductos> ld;
    QOrmProductos *p = ld.loadOne(id);
    if (!p)
        return QPixmap();

    QPixmap pixmap = p->foto();
    //pixmap.loadFromData(q.value(0).toByteArray());

    if (requestedSize.isValid())
        pixmap = pixmap.scaled(requestedSize.width(), requestedSize.height());

    return pixmap;
}

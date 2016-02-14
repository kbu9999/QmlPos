
/*
*/
#include "qormproductos.h"

#include <QOrm>

#include "qormmarcas.h" 
#include "qormcategoria.h" 
#include "qormunidadmedida.h" 

#include <QtSql>

QOrmTableInfo *QOrmProductos::staticMetaTable = QOrm::registerTable<QOrmProductos>("Productos",
{
   /*
        * QOrmAttributeInfo("propertyName", "attributeName", &QOrmProductos::load, &QOrmProductos::store),
        * OR Only
        * QOrmAttributeInfo("propertyName"),
       */
   new QOrmAttributeInfo("idProducto", "idProducto"),
   new QOrmAttributeInfo("marcas", "idMarca"),
   new QOrmAttributeInfo("categoria", "idCategoria"),
   new QOrmAttributeInfo("unidadMedida", "idUnidad"),
   new QOrmAttributeInfo("nombre", "nombre"),
   new QOrmAttributeInfo("unidades", "unidades"),
   new QOrmAttributeInfo("costo", "costo"),
   new QOrmAttributeInfo("precio", "precio"),
   new QOrmAttributeInfo("stock", "stock")
},{
   new QOrmChildrens("CompraItems", &QOrmProductos::m_compraitems, &QOrmProductos::appendCompraItems, &QOrmProductos::removeCompraItems),
   new QOrmChildrens("VentaItems", &QOrmProductos::m_ventaitems, &QOrmProductos::appendVentaItems, &QOrmProductos::removeVentaItems)
}/*,
"SELECT * FROM Productos ",
"INSERT INTO Productos SET ... ",
"DELETE FROM Productos WHERE idProductos = :id"
"UPDATE Productos SET ... "
"DB_Name" */
);

QOrmProductos::QOrmProductos() :
    QOrmObject(staticMetaTable)
{
    m_idProducto = 0;
    m_marcas = 0;
    m_categoria = 0;
    m_unidadMedida = 0;
    m_unidades = 0;
    m_costo = 0;
    m_precio = 0;
    m_stock = 0;
}

QOrmProductos::~QOrmProductos()
{
}


int QOrmProductos::idProducto() const
{
    return m_idProducto;
}

QOrmMarcas* QOrmProductos::marcas() const
{
    return m_marcas;
}

QOrmCategoria* QOrmProductos::categoria() const
{
    return m_categoria;
}

QOrmUnidadMedida* QOrmProductos::unidadMedida() const
{
    return m_unidadMedida;
}

QString QOrmProductos::nombre() const
{
    return m_nombre;
}

double QOrmProductos::unidades() const
{
    return m_unidades;
}

double QOrmProductos::costo() const
{
    return m_costo;
}

double QOrmProductos::precio() const
{
    return m_precio;
}

int QOrmProductos::stock() const
{
    return m_stock;
}

QPixmap QOrmProductos::foto()
{
    if (m_foto.isNull() && isSaved()) {
        QSqlQuery q;
        q.prepare("SELECT foto FROM Productos WHERE idProducto = ?");
        q.addBindValue(m_idProducto);

        if(!q.exec()) { qDebug()<<q.lastError().text(); return QPixmap(); }
        if(!q.next()) return QPixmap();

        QPixmap pix;
        pix.loadFromData(q.value(0).toByteArray());
        m_foto = pix;
    }
    return m_foto;
}


void QOrmProductos::setIdProducto(int value)
{
    if(m_idProducto == value) return;

    m_idProducto = value;
    emit idProductoChanged(value);
}

void QOrmProductos::setMarcas(QOrmMarcas* value)
{
    if(m_marcas == value) return;

    m_marcas = value;
    emit marcasChanged(value);
}

void QOrmProductos::setCategoria(QOrmCategoria* value)
{
    if(m_categoria == value) return;

    m_categoria = value;
    emit categoriaChanged(value);
}

void QOrmProductos::setUnidadMedida(QOrmUnidadMedida* value)
{
    if(m_unidadMedida == value) return;

    m_unidadMedida = value;
    emit unidadMedidaChanged(value);
}

void QOrmProductos::setNombre(QString value)
{
    if(m_nombre == value) return;

    m_nombre = value;
    emit nombreChanged(value);
}

void QOrmProductos::setUnidades(double value)
{
    if(m_unidades == value) return;

    m_unidades = value;
    emit unidadesChanged(value);
}

void QOrmProductos::setCosto(double value)
{
    if(m_costo == value) return;

    m_costo = value;
    emit costoChanged(value);
}

void QOrmProductos::setPrecio(double value)
{
    if(m_precio == value) return;

    m_precio = value;
    emit precioChanged(value);
}

void QOrmProductos::setStock(int value)
{
    if(m_stock == value) return;

    m_stock = value;
    emit stockChanged(value);
}

void QOrmProductos::setFoto(QPixmap value)
{
    m_foto = value;

    emit fotoChanged();
}

void QOrmProductos::loadFotoFromFile(QString file)
{
    static int max = 200;
    m_foto.load(file.replace("file://", ""));

    if ((m_foto.height() > max) || (m_foto.width() > max) ) {
        QPixmap newPix;
        if (m_foto.height() == m_foto.width()) {
            newPix = m_foto.scaled(QSize(max, max));
        }
        else if (m_foto.height() > m_foto.width() ) {
            newPix = m_foto.scaledToHeight(max);
        }
        else  {
            newPix = m_foto.scaledToWidth(max);
        }
        m_foto = newPix;
    }

    emit fotoChanged();
}

QList<QOrmCompraItems *> QOrmProductos::listCompraItems() const
{
    return m_compraitems;
}
void QOrmProductos::appendCompraItems(QOrmCompraItems *child)
{
    m_compraitems.append(child);

    appendChildren(child);
    emit compraitemsChanged();
}
void QOrmProductos::removeCompraItems(QOrmCompraItems *child)
{
    m_compraitems.removeOne(child);

    removeChildren(child);
    emit compraitemsChanged();
}

QQmlListProperty<QOrmCompraItems> QOrmProductos::compraitems()
{
    return QQmlListProperty<QOrmCompraItems>(this, m_compraitems);
}

QList<QOrmVentaItems *> QOrmProductos::listVentaItems() const
{
    return m_ventaitems;
}

#include <QSqlQuery>
#include <QSqlError>

void QOrmProductos::save()
{
    QOrmObject::save();
    if (!isSaved()) return;

    QByteArray bytes;
    QBuffer buffer(&bytes);
    buffer.open(QIODevice::WriteOnly);

    if (!m_foto.hasAlpha())
        m_foto.save(&buffer, "JPG");
    else
        m_foto.save(&buffer, "PNG");

    QSqlQuery q;
    q.prepare("UPDATE Productos SET foto = :val WHERE idProducto = :id");
    q.bindValue(":id", m_idProducto);
    q.bindValue(":val", bytes);
    q.exec();

    //qDebug()<<"foto: "<<q.lastError().text();
}
void QOrmProductos::appendVentaItems(QOrmVentaItems *child)
{
    m_ventaitems.append(child);

    appendChildren(child);
    emit ventaitemsChanged();
}
void QOrmProductos::removeVentaItems(QOrmVentaItems *child)
{
    m_ventaitems.removeOne(child);

    removeChildren(child);
    emit ventaitemsChanged();
}

QQmlListProperty<QOrmVentaItems> QOrmProductos::ventaitems()
{
    return QQmlListProperty<QOrmVentaItems>(this, m_ventaitems);
}

#include "moc_qormproductos.cpp"

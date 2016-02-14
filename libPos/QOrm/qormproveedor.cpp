
/*
*/
#include "qormproveedor.h"

#include <QOrm>

#include "qormhaciento.h" 

QOrmTableInfo *QOrmProveedor::staticMetaTable = QOrm::registerTable<QOrmProveedor>("Proveedor",
{
    /*
     * QOrmAttributeInfo("propertyName", "attributeName", &QOrmProveedor::load, &QOrmProveedor::store),
     * OR Only
     * QOrmAttributeInfo("propertyName"),
    */
    new QOrmAttributeInfo("idProveedor", "idProveedor"),
     new QOrmAttributeInfo("haciento", "idHaciento"),
     new QOrmAttributeInfo("proveedor", "Proveedor")
},{
    new QOrmChildrens("Compra", &QOrmProveedor::m_compra, &QOrmProveedor::appendCompra, &QOrmProveedor::removeCompra)
}/*,
"SELECT * FROM Proveedor ",
"INSERT INTO Proveedor SET ... ",
"DELETE FROM Proveedor WHERE idProveedor = :id"
"UPDATE Proveedor SET ... "
"DB_Name" */
);

QOrmProveedor::QOrmProveedor() :
    QOrmObject(staticMetaTable)
{
     m_idProveedor = 0;
    m_haciento = 0;
}

QOrmProveedor::~QOrmProveedor()
{
}


int QOrmProveedor::idProveedor() const
{
    return m_idProveedor;
}

QOrmHaciento* QOrmProveedor::haciento() const
{
    return m_haciento;
}

QString QOrmProveedor::proveedor() const
{
    return m_proveedor;
}



void QOrmProveedor::setIdProveedor(int value)
{
    if(m_idProveedor == value) return;

    m_idProveedor = value;
    emit idProveedorChanged(value);
}

void QOrmProveedor::setHaciento(QOrmHaciento* value)
{
    if(m_haciento == value) return;

    m_haciento = value;
    emit hacientoChanged(value);
}

void QOrmProveedor::setProveedor(QString value)
{
    if(m_proveedor == value) return;

    m_proveedor = value;
    emit proveedorChanged(value);
}



QList<QOrmCompra *> QOrmProveedor::listCompra() const
{
    return m_compra;
}
void QOrmProveedor::appendCompra(QOrmCompra *child)
{
    m_compra.append(child);

    appendChildren(child);
    emit compraChanged();
}
void QOrmProveedor::removeCompra(QOrmCompra *child)
{
    m_compra.removeOne(child);

    removeChildren(child);
    emit compraChanged();
}

QQmlListProperty<QOrmCompra> QOrmProveedor::compra()
{
    return QQmlListProperty<QOrmCompra>(this, m_compra);
}


#include "moc_qormproveedor.cpp"

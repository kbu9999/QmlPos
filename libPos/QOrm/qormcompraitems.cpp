
/*
*/
#include "qormcompraitems.h"

#include <QOrm>

#include "qormproductos.h" 
#include "qormcompra.h" 

QOrmTableInfo *QOrmCompraItems::staticMetaTable = QOrm::registerTable<QOrmCompraItems>("CompraItems",
{
    /*
     * QOrmAttributeInfo("propertyName", "attributeName", &QOrmCompraItems::load, &QOrmCompraItems::store),
     * OR Only
     * QOrmAttributeInfo("propertyName"),
    */
    new QOrmAttributeInfo("idCompraItems", "idCompraItems"),
     new QOrmAttributeInfo("productos", "idProducto"),
     new QOrmAttributeInfo("compra", "idCompra"),
     new QOrmAttributeInfo("cantidad", "cantidad"),
     new QOrmAttributeInfo("costo", "precio")
},{
    
}/*,
"SELECT * FROM CompraItems ",
"INSERT INTO CompraItems SET ... ",
"DELETE FROM CompraItems WHERE idCompraItems = :id"
"UPDATE CompraItems SET ... "
"DB_Name" */
);

QOrmCompraItems::QOrmCompraItems() :
    QOrmObject(staticMetaTable)
{
     m_idCompraItems = 0;
    m_productos = 0;
    m_compra = 0;
    m_cantidad = 0;
    m_precio = 0;
}

QOrmCompraItems::~QOrmCompraItems()
{
}


int QOrmCompraItems::idCompraItems() const
{
    return m_idCompraItems;
}

QOrmProductos* QOrmCompraItems::productos() const
{
    return m_productos;
}

QOrmCompra* QOrmCompraItems::compra() const
{
    return m_compra;
}

int QOrmCompraItems::cantidad() const
{
    return m_cantidad;
}

double QOrmCompraItems::costo() const
{
    return m_precio;
}



void QOrmCompraItems::setIdCompraItems(int value)
{
    if(m_idCompraItems == value) return;

    m_idCompraItems = value;
    emit idCompraItemsChanged(value);
}

void QOrmCompraItems::setProductos(QOrmProductos* value)
{
    if(m_productos == value) return;

    m_productos = value;
    emit productosChanged(value);
}

void QOrmCompraItems::setCompra(QOrmCompra* value)
{
    if(m_compra == value) return;

    m_compra = value;
    emit compraChanged(value);
}

void QOrmCompraItems::setCantidad(int value)
{
    if(m_cantidad == value) return;

    m_cantidad = value;
    emit cantidadChanged(value);
}

void QOrmCompraItems::setCosto(double value)
{
    if(m_precio == value) return;

    m_precio = value;
    emit costoChanged(value);
}




#include "moc_qormcompraitems.cpp"


/*
*/
#include "qormventaitems.h"

#include <QOrm>

#include "qormventas.h" 
#include "qormproductos.h" 

QOrmTableInfo *QOrmVentaItems::staticMetaTable = QOrm::registerTable<QOrmVentaItems>("VentaItems",
{
    /*
     * QOrmAttributeInfo("propertyName", "attributeName", &QOrmVentaItems::load, &QOrmVentaItems::store),
     * OR Only
     * QOrmAttributeInfo("propertyName"),
    */
    new QOrmAttributeInfo("idVentaItem", "idVentaItem"),
     new QOrmAttributeInfo("ventas", "idVenta"),
     new QOrmAttributeInfo("productos", "idProducto"),
     new QOrmAttributeInfo("cantidad", "cantidad"),
     new QOrmAttributeInfo("precio", "precio")
},{
    
}/*,
"SELECT * FROM VentaItems ",
"INSERT INTO VentaItems SET ... ",
"DELETE FROM VentaItems WHERE idVentaItems = :id"
"UPDATE VentaItems SET ... "
"DB_Name" */
);

QOrmVentaItems::QOrmVentaItems() :
    QOrmObject(staticMetaTable)
{
     m_idVentaItem = 0;
    m_ventas = 0;
    m_productos = 0;
    m_cantidad = 0;
    m_precio = 0;
}

QOrmVentaItems::~QOrmVentaItems()
{
}


int QOrmVentaItems::idVentaItem() const
{
    return m_idVentaItem;
}

QOrmVentas* QOrmVentaItems::ventas() const
{
    return m_ventas;
}

QOrmProductos* QOrmVentaItems::productos() const
{
    return m_productos;
}

double QOrmVentaItems::cantidad() const
{
    return m_cantidad;
}

double QOrmVentaItems::precio() const
{
    return m_precio;
}



void QOrmVentaItems::setIdVentaItem(int value)
{
    if(m_idVentaItem == value) return;

    m_idVentaItem = value;
    emit idVentaItemChanged(value);
}

void QOrmVentaItems::setVentas(QOrmVentas* value)
{
    if(m_ventas == value) return;

    m_ventas = value;
    emit ventasChanged(value);
}

void QOrmVentaItems::setProductos(QOrmProductos* value)
{
    if(m_productos == value) return;

    m_productos = value;
    emit productosChanged(value);
}

void QOrmVentaItems::setCantidad(double value)
{
    if(m_cantidad == value) return;

    m_cantidad = value;
    emit cantidadChanged(value);
}

void QOrmVentaItems::setPrecio(double value)
{
    if(m_precio == value) return;

    m_precio = value;
    emit precioChanged(value);
}




#include "moc_qormventaitems.cpp"


/*
*/
#include "qormcompra.h"

#include <QOrm>

#include "qormproveedor.h" 
#include "qormproductos.h"

QOrmTableInfo *QOrmCompra::staticMetaTable = QOrm::registerTable<QOrmCompra>("Compra",
{
    /*
     * QOrmAttributeInfo("propertyName", "attributeName", &QOrmCompra::load, &QOrmCompra::store),
     * OR Only
     * QOrmAttributeInfo("propertyName"),
    */
    new QOrmAttributeInfo("idCompra", "idCompra"),
     new QOrmAttributeInfo("fecha", "fecha"),
     new QOrmAttributeInfo("proveedor", "idProveedor")
},{
    new QOrmChildrens("CompraItems", &QOrmCompra::m_compraitems, &QOrmCompra::appendCompraItems, &QOrmCompra::removeCompraItems)
}/*,
"SELECT * FROM Compra ",
"INSERT INTO Compra SET ... ",
"DELETE FROM Compra WHERE idCompra = :id"
"UPDATE Compra SET ... "
"DB_Name" */
);

QOrmCompra::QOrmCompra() :
    QOrmObject(staticMetaTable)
{
     m_idCompra = 0;
    m_proveedor = 0;
}

QOrmCompra::~QOrmCompra()
{
}


int QOrmCompra::idCompra() const
{
    return m_idCompra;
}

QDateTime QOrmCompra::fecha() const
{
    return m_fecha;
}

QOrmProveedor* QOrmCompra::proveedor() const
{
    return m_proveedor;
}

double QOrmCompra::suma() const
{
    return m_suma;
}



void QOrmCompra::setIdCompra(int value)
{
    if(m_idCompra == value) return;

    m_idCompra = value;
    emit idCompraChanged(value);
}

void QOrmCompra::setFecha(QDateTime value)
{
    if(m_fecha == value) return;

    m_fecha = value;
    emit fechaChanged(value);
}

void QOrmCompra::setProveedor(QOrmProveedor* value)
{
    if(m_proveedor == value) return;

    m_proveedor = value;
    emit proveedorChanged(value);
}



QList<QOrmCompraItems *> QOrmCompra::listCompraItems() const
{
    return m_compraitems;
}
void QOrmCompra::appendCompraItems(QOrmCompraItems *child)
{
    m_compraitems.append(child);

    appendChildren(child);
    emit compraitemsChanged();

    m_suma += child->costo() * child->cantidad();
    emit sumaChanged(m_suma);
}
void QOrmCompra::removeCompraItems(QOrmCompraItems *child)
{
    m_compraitems.removeOne(child);

    removeChildren(child);
    emit compraitemsChanged();

    m_suma -= child->costo() * child->cantidad();
    emit sumaChanged(m_suma);
}

void QOrmCompra::addItem(QOrmProductos *prod, int cant)
{
    QOrmCompraItems *nvi = 0;
    for(QOrmCompraItems *vi : m_compraitems) {
        if (vi->productos() == prod) {
            nvi = vi;
            break;
        }
    }

    if(!nvi) {
        nvi = new QOrmCompraItems();
        nvi->setCompra(this);
        nvi->setProductos(prod);
        nvi->setCosto(prod->costo());

        m_compraitems.append(nvi);
    }

    nvi->setCantidad(nvi->cantidad() + cant);
    emit compraitemsChanged();

    m_suma += nvi->costo() * cant;
    emit sumaChanged(m_suma);
}

void QOrmCompra::remItem(int row)
{
    QOrmCompraItems *ci = m_compraitems.at(row);
    m_compraitems.removeAt(row);

    emit compraitemsChanged();

    m_suma -= ci->costo() * ci->cantidad();
    emit sumaChanged(m_suma);
}

QQmlListProperty<QOrmCompraItems> QOrmCompra::compraitems()
{
    return QQmlListProperty<QOrmCompraItems>(this, m_compraitems);
}


#include "moc_qormcompra.cpp"

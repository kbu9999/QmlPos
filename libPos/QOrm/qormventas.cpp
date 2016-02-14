
/*
*/
#include "qormventas.h"

#include <QOrm>

#include "qormusuario.h"

#include "qormclientes.h" 
#include "qormproductos.h"

QOrmTableInfo *QOrmVentas::staticMetaTable = QOrm::registerTable<QOrmVentas>("Ventas",
{
    /*
     * QOrmAttributeInfo("propertyName", "attributeName", &QOrmVentas::load, &QOrmVentas::store),
     * OR Only
     * QOrmAttributeInfo("propertyName"),
    */
    new QOrmAttributeInfo("idVenta", "idVenta"),
     new QOrmAttributeInfo("fecha", "fecha"),
     new QOrmAttributeInfo("usuario", "idUsuario"),
     new QOrmAttributeInfo("clientes", "idCliente")
},{
    new QOrmChildrens("Pago", &QOrmVentas::m_pago, &QOrmVentas::appendPago, &QOrmVentas::removePago),
    new QOrmChildrens("VentaItems", &QOrmVentas::m_ventaitems, &QOrmVentas::appendVentaItems, &QOrmVentas::removeVentaItems)
}/*,
"SELECT * FROM Ventas ",
"INSERT INTO Ventas SET ... ",
"DELETE FROM Ventas WHERE idVentas = :id"
"UPDATE Ventas SET ... "
"DB_Name" */
);

QOrmVentas::QOrmVentas() :
    QOrmObject(staticMetaTable)
{
     m_idVenta = 0;
    m_usuario = 0;
    m_clientes = 0;

    m_suma = 0;
}

QOrmVentas::~QOrmVentas()
{
}


int QOrmVentas::idVenta() const
{
    return m_idVenta;
}

QDateTime QOrmVentas::fecha() const
{
    return m_fecha;
}

QOrmUsuario* QOrmVentas::usuario() const
{
    return m_usuario;
}

QOrmClientes* QOrmVentas::clientes() const
{
    return m_clientes;
}



void QOrmVentas::setIdVenta(int value)
{
    if(m_idVenta == value) return;

    m_idVenta = value;
    emit idVentaChanged(value);
}

void QOrmVentas::setFecha(QDateTime value)
{
    if(m_fecha == value) return;

    m_fecha = value;
    emit fechaChanged(value);
}

void QOrmVentas::setusuario(QOrmUsuario* value)
{
    if(m_usuario == value) return;

    m_usuario = value;
    emit usuarioChanged(value);
}

void QOrmVentas::setClientes(QOrmClientes* value)
{
    if(m_clientes == value) return;

    m_clientes = value;
    emit clientesChanged(value);
}



QList<QOrmPago *> QOrmVentas::listPago() const
{
    return m_pago;
}
void QOrmVentas::appendPago(QOrmPago *child)
{
    m_pago.append(child);

    appendChildren(child);
    emit pagoChanged();
}
void QOrmVentas::removePago(QOrmPago *child)
{
    m_pago.removeOne(child);

    removeChildren(child);
    emit pagoChanged();
}

QQmlListProperty<QOrmPago> QOrmVentas::pago()
{
    return QQmlListProperty<QOrmPago>(this, m_pago);
}

QList<QOrmVentaItems *> QOrmVentas::listVentaItems() const
{
    return m_ventaitems;
}

double QOrmVentas::suma() const
{
    return m_suma;
}

void QOrmVentas::afterLoad()
{
    loadChildren<QOrmVentaItems>();

    for(QOrmVentaItems *vi : m_ventaitems) {
        m_suma += vi->precio() * vi->cantidad();
    }

    emit sumaChanged(m_suma);
}
void QOrmVentas::appendVentaItems(QOrmVentaItems *child)
{
    m_ventaitems.append(child);

    appendChildren(child);
    emit ventaitemsChanged();

    m_suma += child->precio() * child->cantidad();
    emit sumaChanged(m_suma);
}
void QOrmVentas::removeVentaItems(QOrmVentaItems *child)
{
    m_ventaitems.removeOne(child);

    removeChildren(child);
    emit ventaitemsChanged();

    m_suma -= child->precio() * child->cantidad();
    emit sumaChanged(m_suma);
}

void QOrmVentas::addVentaItems(QOrmProductos *prod, double cant)
{
    QOrmVentaItems *nvi = 0;
    for(QOrmVentaItems *vi : m_ventaitems) {
        if (vi->productos() == prod) {
            nvi = vi;
            break;
        }
    }

    if(!nvi) {
        nvi = new QOrmVentaItems();
        nvi->setVentas(this);
        nvi->setProductos(prod);
        nvi->setPrecio(prod->precio());

        m_ventaitems.append(nvi);
    }

    nvi->setCantidad(nvi->cantidad() + cant);
    emit ventaitemsChanged();

    m_suma += nvi->precio() * cant;
    emit sumaChanged(m_suma);
}

QQmlListProperty<QOrmVentaItems> QOrmVentas::ventaitems()
{
    return QQmlListProperty<QOrmVentaItems>(this, m_ventaitems);
}


#include "moc_qormventas.cpp"

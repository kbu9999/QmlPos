
/*
*/
#include "qormhaciento.h"

#include <QOrm>


QOrmTableInfo *QOrmHaciento::staticMetaTable = QOrm::registerTable<QOrmHaciento>("Haciento",
{
    /*
     * QOrmAttributeInfo("propertyName", "attributeName", &QOrmHaciento::load, &QOrmHaciento::store),
     * OR Only
     * QOrmAttributeInfo("propertyName"),
    */
    new QOrmAttributeInfo("idHaciento", "idHaciento"),
     new QOrmAttributeInfo("haciento", "haciento")
},{
    new QOrmChildrens("Caja", &QOrmHaciento::m_caja, &QOrmHaciento::appendCaja, &QOrmHaciento::removeCaja),
    new QOrmChildrens("Clientes", &QOrmHaciento::m_clientes, &QOrmHaciento::appendClientes, &QOrmHaciento::removeClientes),
    new QOrmChildrens("Proveedor", &QOrmHaciento::m_proveedor, &QOrmHaciento::appendProveedor, &QOrmHaciento::removeProveedor)
}/*,
"SELECT * FROM Haciento ",
"INSERT INTO Haciento SET ... ",
"DELETE FROM Haciento WHERE idHaciento = :id"
"UPDATE Haciento SET ... "
"DB_Name" */
);

QOrmHaciento::QOrmHaciento() :
    QOrmObject(staticMetaTable)
{
     m_idHaciento = 0;
}

QOrmHaciento::~QOrmHaciento()
{
}


int QOrmHaciento::idHaciento() const
{
    return m_idHaciento;
}

QString QOrmHaciento::haciento() const
{
    return m_haciento;
}



void QOrmHaciento::setIdHaciento(int value)
{
    if(m_idHaciento == value) return;

    m_idHaciento = value;
    emit idHacientoChanged(value);
}

void QOrmHaciento::setHaciento(QString value)
{
    if(m_haciento == value) return;

    m_haciento = value;
    emit hacientoChanged(value);
}



QList<QOrmCaja *> QOrmHaciento::listCaja() const
{
    return m_caja;
}
void QOrmHaciento::appendCaja(QOrmCaja *child)
{
    m_caja.append(child);

    appendChildren(child);
    emit cajaChanged();
}
void QOrmHaciento::removeCaja(QOrmCaja *child)
{
    m_caja.removeOne(child);

    removeChildren(child);
    emit cajaChanged();
}

QQmlListProperty<QOrmCaja> QOrmHaciento::caja()
{
    return QQmlListProperty<QOrmCaja>(this, m_caja);
}

QList<QOrmClientes *> QOrmHaciento::listClientes() const
{
    return m_clientes;
}
void QOrmHaciento::appendClientes(QOrmClientes *child)
{
    m_clientes.append(child);

    appendChildren(child);
    emit clientesChanged();
}
void QOrmHaciento::removeClientes(QOrmClientes *child)
{
    m_clientes.removeOne(child);

    removeChildren(child);
    emit clientesChanged();
}

QQmlListProperty<QOrmClientes> QOrmHaciento::clientes()
{
    return QQmlListProperty<QOrmClientes>(this, m_clientes);
}

QList<QOrmProveedor *> QOrmHaciento::listProveedor() const
{
    return m_proveedor;
}
void QOrmHaciento::appendProveedor(QOrmProveedor *child)
{
    m_proveedor.append(child);

    appendChildren(child);
    emit proveedorChanged();
}
void QOrmHaciento::removeProveedor(QOrmProveedor *child)
{
    m_proveedor.removeOne(child);

    removeChildren(child);
    emit proveedorChanged();
}

QQmlListProperty<QOrmProveedor> QOrmHaciento::proveedor()
{
    return QQmlListProperty<QOrmProveedor>(this, m_proveedor);
}


#include "moc_qormhaciento.cpp"

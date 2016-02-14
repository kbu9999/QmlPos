
/*
*/
#include "qormclientes.h"

#include <QOrm>

#include "qormhaciento.h" 

QOrmTableInfo *QOrmClientes::staticMetaTable = QOrm::registerTable<QOrmClientes>("Clientes",
{
    /*
     * QOrmAttributeInfo("propertyName", "attributeName", &QOrmClientes::load, &QOrmClientes::store),
     * OR Only
     * QOrmAttributeInfo("propertyName"),
    */
    new QOrmAttributeInfo("idCliente", "idCliente"),
     new QOrmAttributeInfo("haciento", "idHaciento"),
     new QOrmAttributeInfo("nombre", "nombre"),
     new QOrmAttributeInfo("apellido", "apellido"),
     new QOrmAttributeInfo("direccion", "direccion"),
     new QOrmAttributeInfo("telefono", "telefono")
},{
    new QOrmChildrens("Ventas", &QOrmClientes::m_ventas, &QOrmClientes::appendVentas, &QOrmClientes::removeVentas)
}/*,
"SELECT * FROM Clientes ",
"INSERT INTO Clientes SET ... ",
"DELETE FROM Clientes WHERE idClientes = :id"
"UPDATE Clientes SET ... "
"DB_Name" */
);

QOrmClientes::QOrmClientes() :
    QOrmObject(staticMetaTable)
{
     m_idCliente = 0;
    m_haciento = 0;
}

QOrmClientes::~QOrmClientes()
{
}


int QOrmClientes::idCliente() const
{
    return m_idCliente;
}

QOrmHaciento* QOrmClientes::haciento() const
{
    return m_haciento;
}

QString QOrmClientes::nombre() const
{
    return m_nombre;
}

QString QOrmClientes::apellido() const
{
    return m_apellido;
}

QString QOrmClientes::direccion() const
{
    return m_direccion;
}

QString QOrmClientes::telefono() const
{
    return m_telefono;
}



void QOrmClientes::setIdCliente(int value)
{
    if(m_idCliente == value) return;

    m_idCliente = value;
    emit idClienteChanged(value);
}

void QOrmClientes::setHaciento(QOrmHaciento* value)
{
    if(m_haciento == value) return;

    m_haciento = value;
    emit hacientoChanged(value);
}

void QOrmClientes::setNombre(QString value)
{
    if(m_nombre == value) return;

    m_nombre = value;
    emit nombreChanged(value);
}

void QOrmClientes::setApellido(QString value)
{
    if(m_apellido == value) return;

    m_apellido = value;
    emit apellidoChanged(value);
}

void QOrmClientes::setDireccion(QString value)
{
    if(m_direccion == value) return;

    m_direccion = value;
    emit direccionChanged(value);
}

void QOrmClientes::setTelefono(QString value)
{
    if(m_telefono == value) return;

    m_telefono = value;
    emit telefonoChanged(value);
}



QList<QOrmVentas *> QOrmClientes::listVentas() const
{
    return m_ventas;
}
void QOrmClientes::appendVentas(QOrmVentas *child)
{
    m_ventas.append(child);

    appendChildren(child);
    emit ventasChanged();
}
void QOrmClientes::removeVentas(QOrmVentas *child)
{
    m_ventas.removeOne(child);

    removeChildren(child);
    emit ventasChanged();
}

QQmlListProperty<QOrmVentas> QOrmClientes::ventas()
{
    return QQmlListProperty<QOrmVentas>(this, m_ventas);
}


#include "moc_qormclientes.cpp"

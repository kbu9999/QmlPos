
/*
*/
#include "qormunidadmedida.h"

#include <QOrm>


QOrmTableInfo *QOrmUnidadMedida::staticMetaTable = QOrm::registerTable<QOrmUnidadMedida>("UnidadMedida",
{
    /*
     * QOrmAttributeInfo("propertyName", "attributeName", &QOrmUnidadMedida::load, &QOrmUnidadMedida::store),
     * OR Only
     * QOrmAttributeInfo("propertyName"),
    */
    new QOrmAttributeInfo("idUnidadMedida", "idUnidadMedida"),
     new QOrmAttributeInfo("nombre", "nombre"),
     new QOrmAttributeInfo("esDecimal", "esDecimal")
},{
    new QOrmChildrens("Productos", &QOrmUnidadMedida::m_productos, &QOrmUnidadMedida::appendProductos, &QOrmUnidadMedida::removeProductos)
}/*,
"SELECT * FROM UnidadMedida ",
"INSERT INTO UnidadMedida SET ... ",
"DELETE FROM UnidadMedida WHERE idUnidadMedida = :id"
"UPDATE UnidadMedida SET ... "
"DB_Name" */
);

QOrmUnidadMedida::QOrmUnidadMedida() :
    QOrmObject(staticMetaTable)
{
     m_idUnidadMedida = 0;
}

QOrmUnidadMedida::~QOrmUnidadMedida()
{
}


int QOrmUnidadMedida::idUnidadMedida() const
{
    return m_idUnidadMedida;
}

QString QOrmUnidadMedida::nombre() const
{
    return m_nombre;
}

bool QOrmUnidadMedida::esDecimal() const
{
    return m_esDecimal;
}



void QOrmUnidadMedida::setIdUnidadMedida(int value)
{
    if(m_idUnidadMedida == value) return;

    m_idUnidadMedida = value;
    emit idUnidadMedidaChanged(value);
}

void QOrmUnidadMedida::setNombre(QString value)
{
    if(m_nombre == value) return;

    m_nombre = value;
    emit nombreChanged(value);
}

void QOrmUnidadMedida::setEsDecimal(bool value)
{
    if(m_esDecimal == value) return;

    m_esDecimal = value;
    emit esDecimalChanged(value);
}



QList<QOrmProductos *> QOrmUnidadMedida::listProductos() const
{
    return m_productos;
}
void QOrmUnidadMedida::appendProductos(QOrmProductos *child)
{
    m_productos.append(child);

    appendChildren(child);
    emit productosChanged();
}
void QOrmUnidadMedida::removeProductos(QOrmProductos *child)
{
    m_productos.removeOne(child);

    removeChildren(child);
    emit productosChanged();
}

QQmlListProperty<QOrmProductos> QOrmUnidadMedida::productos()
{
    return QQmlListProperty<QOrmProductos>(this, m_productos);
}


#include "moc_qormunidadmedida.cpp"

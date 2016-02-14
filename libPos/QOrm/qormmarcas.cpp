
/*
*/
#include "qormmarcas.h"

#include <QOrm>


QOrmTableInfo *QOrmMarcas::staticMetaTable = QOrm::registerTable<QOrmMarcas>("Marcas",
{
    /*
     * QOrmAttributeInfo("propertyName", "attributeName", &QOrmMarcas::load, &QOrmMarcas::store),
     * OR Only
     * QOrmAttributeInfo("propertyName"),
    */
    new QOrmAttributeInfo("idMarca", "idMarca"),
     new QOrmAttributeInfo("nombre", "nombre")
},{
    new QOrmChildrens("Productos", &QOrmMarcas::m_productos, &QOrmMarcas::appendProductos, &QOrmMarcas::removeProductos)
}/*,
"SELECT * FROM Marcas ",
"INSERT INTO Marcas SET ... ",
"DELETE FROM Marcas WHERE idMarcas = :id"
"UPDATE Marcas SET ... "
"DB_Name" */
);

QOrmMarcas::QOrmMarcas() :
    QOrmObject(staticMetaTable)
{
     m_idMarca = 0;
}

QOrmMarcas::~QOrmMarcas()
{
}


int QOrmMarcas::idMarca() const
{
    return m_idMarca;
}

QString QOrmMarcas::nombre() const
{
    return m_nombre;
}



void QOrmMarcas::setIdMarca(int value)
{
    if(m_idMarca == value) return;

    m_idMarca = value;
    emit idMarcaChanged(value);
}

void QOrmMarcas::setNombre(QString value)
{
    if(m_nombre == value) return;

    m_nombre = value;
    emit nombreChanged(value);
}



QList<QOrmProductos *> QOrmMarcas::listProductos() const
{
    return m_productos;
}
void QOrmMarcas::appendProductos(QOrmProductos *child)
{
    m_productos.append(child);

    appendChildren(child);
    emit productosChanged();
}
void QOrmMarcas::removeProductos(QOrmProductos *child)
{
    m_productos.removeOne(child);

    removeChildren(child);
    emit productosChanged();
}

QQmlListProperty<QOrmProductos> QOrmMarcas::productos()
{
    return QQmlListProperty<QOrmProductos>(this, m_productos);
}


#include "moc_qormmarcas.cpp"

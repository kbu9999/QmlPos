
/*
*/
#include "qormcategoria.h"

#include <QOrm>


QOrmTableInfo *QOrmCategoria::staticMetaTable = QOrm::registerTable<QOrmCategoria>("Categoria",
{
    /*
     * QOrmAttributeInfo("propertyName", "attributeName", &QOrmCategoria::load, &QOrmCategoria::store),
     * OR Only
     * QOrmAttributeInfo("propertyName"),
    */
    new QOrmAttributeInfo("idCategoria", "idCategoria"),
     new QOrmAttributeInfo("nombre", "nombre")
},{
    new QOrmChildrens("Productos", &QOrmCategoria::m_productos, &QOrmCategoria::appendProductos, &QOrmCategoria::removeProductos)
}/*,
"SELECT * FROM Categoria ",
"INSERT INTO Categoria SET ... ",
"DELETE FROM Categoria WHERE idCategoria = :id"
"UPDATE Categoria SET ... "
"DB_Name" */
);

QOrmCategoria::QOrmCategoria() :
    QOrmObject(staticMetaTable)
{
     m_idCategoria = 0;
}

QOrmCategoria::~QOrmCategoria()
{
}


int QOrmCategoria::idCategoria() const
{
    return m_idCategoria;
}

QString QOrmCategoria::nombre() const
{
    return m_nombre;
}



void QOrmCategoria::setIdCategoria(int value)
{
    if(m_idCategoria == value) return;

    m_idCategoria = value;
    emit idCategoriaChanged(value);
}

void QOrmCategoria::setNombre(QString value)
{
    if(m_nombre == value) return;

    m_nombre = value;
    emit nombreChanged(value);
}



QList<QOrmProductos *> QOrmCategoria::listProductos() const
{
    return m_productos;
}
void QOrmCategoria::appendProductos(QOrmProductos *child)
{
    m_productos.append(child);

    appendChildren(child);
    emit productosChanged();
}
void QOrmCategoria::removeProductos(QOrmProductos *child)
{
    m_productos.removeOne(child);

    removeChildren(child);
    emit productosChanged();
}

QQmlListProperty<QOrmProductos> QOrmCategoria::productos()
{
    return QQmlListProperty<QOrmProductos>(this, m_productos);
}


#include "moc_qormcategoria.cpp"

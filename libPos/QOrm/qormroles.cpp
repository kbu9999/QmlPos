
/*
*/
#include "qormroles.h"

#include <QOrm>


QOrmTableInfo *QOrmRoles::staticMetaTable = QOrm::registerTable<QOrmRoles>("Roles",
{
    /*
     * QOrmAttributeInfo("propertyName", "attributeName", &QOrmRoles::load, &QOrmRoles::store),
     * OR Only
     * QOrmAttributeInfo("propertyName"),
    */
    new QOrmAttributeInfo("idRol", "idRol"),
     new QOrmAttributeInfo("nombre", "Nombre")
},{
    new QOrmChildrens("Privilegios", &QOrmRoles::m_privilegios, &QOrmRoles::appendPrivilegios, &QOrmRoles::removePrivilegios),
    new QOrmChildrens("Usuarios", &QOrmRoles::m_usuarios, &QOrmRoles::appendUsuarios, &QOrmRoles::removeUsuarios)
}/*,
"SELECT * FROM Roles ",
"INSERT INTO Roles SET ... ",
"DELETE FROM Roles WHERE idRoles = :id"
"UPDATE Roles SET ... "
"DB_Name" */
);

QOrmRoles::QOrmRoles() :
    QOrmObject(staticMetaTable)
{
     m_idRol = 0;
}

QOrmRoles::~QOrmRoles()
{
}


int QOrmRoles::idRol() const
{
    return m_idRol;
}

QString QOrmRoles::nombre() const
{
    return m_nombre;
}



void QOrmRoles::setIdRol(int value)
{
    if(m_idRol == value) return;

    m_idRol = value;
    emit idRolChanged(value);
}

void QOrmRoles::setNombre(QString value)
{
    if(m_nombre == value) return;

    m_nombre = value;
    emit nombreChanged(value);
}



QList<QOrmPrivilegios *> QOrmRoles::listPrivilegios() const
{
    return m_privilegios;
}
void QOrmRoles::appendPrivilegios(QOrmPrivilegios *child)
{
    m_privilegios.append(child);

    appendChildren(child);
    emit privilegiosChanged();
}
void QOrmRoles::removePrivilegios(QOrmPrivilegios *child)
{
    m_privilegios.removeOne(child);

    removeChildren(child);
    emit privilegiosChanged();
}

QQmlListProperty<QOrmPrivilegios> QOrmRoles::privilegios()
{
    return QQmlListProperty<QOrmPrivilegios>(this, m_privilegios);
}

QList<QOrmUsuarios *> QOrmRoles::listUsuarios() const
{
    return m_usuarios;
}
void QOrmRoles::appendUsuarios(QOrmUsuarios *child)
{
    m_usuarios.append(child);

    appendChildren(child);
    emit usuariosChanged();
}
void QOrmRoles::removeUsuarios(QOrmUsuarios *child)
{
    m_usuarios.removeOne(child);

    removeChildren(child);
    emit usuariosChanged();
}

QQmlListProperty<QOrmUsuarios> QOrmRoles::usuarios()
{
    return QQmlListProperty<QOrmUsuarios>(this, m_usuarios);
}


#include "moc_qormroles.cpp"


/*
*/
#include "qormprivilegios.h"

#include <QOrm>

#include "qormroles.h" 

QOrmTableInfo *QOrmPrivilegios::staticMetaTable = QOrm::registerTable<QOrmPrivilegios>("Privilegios",
{
    /*
     * QOrmAttributeInfo("propertyName", "attributeName", &QOrmPrivilegios::load, &QOrmPrivilegios::store),
     * OR Only
     * QOrmAttributeInfo("propertyName"),
    */
    new QOrmAttributeInfo("idPrivilegio", "idPrivilegio"),
     new QOrmAttributeInfo("roles", "Rol"),
     new QOrmAttributeInfo("nombre", "Nombre")
},{
    
}/*,
"SELECT * FROM Privilegios ",
"INSERT INTO Privilegios SET ... ",
"DELETE FROM Privilegios WHERE idPrivilegios = :id"
"UPDATE Privilegios SET ... "
"DB_Name" */
);

QOrmPrivilegios::QOrmPrivilegios() :
    QOrmObject(staticMetaTable)
{
     m_idPrivilegio = 0;
    m_roles = 0;
}

QOrmPrivilegios::~QOrmPrivilegios()
{
}


int QOrmPrivilegios::idPrivilegio() const
{
    return m_idPrivilegio;
}

QOrmRoles* QOrmPrivilegios::roles() const
{
    return m_roles;
}

QString QOrmPrivilegios::nombre() const
{
    return m_nombre;
}



void QOrmPrivilegios::setIdPrivilegio(int value)
{
    if(m_idPrivilegio == value) return;

    m_idPrivilegio = value;
    emit idPrivilegioChanged(value);
}

void QOrmPrivilegios::setRoles(QOrmRoles* value)
{
    if(m_roles == value) return;

    m_roles = value;
    emit rolesChanged(value);
}

void QOrmPrivilegios::setNombre(QString value)
{
    if(m_nombre == value) return;

    m_nombre = value;
    emit nombreChanged(value);
}




#include "moc_qormprivilegios.cpp"

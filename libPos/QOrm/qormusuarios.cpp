
/*
*/
#include "qormusuarios.h"

#include <QOrm>

#include "qormroles.h" 

QOrmTableInfo *QOrmUsuarios::staticMetaTable = QOrm::registerTable<QOrmUsuarios>("Usuarios",
{
    /*
     * QOrmAttributeInfo("propertyName", "attributeName", &QOrmUsuarios::load, &QOrmUsuarios::store),
     * OR Only
     * QOrmAttributeInfo("propertyName"),
    */
    new QOrmAttributeInfo("idUsuario", "idUsuario"),
     new QOrmAttributeInfo("roles", "idRol"),
     new QOrmAttributeInfo("user", "user"),
     new QOrmAttributeInfo("pass", "pass"),
     new QOrmAttributeInfo("nombre", "Nombre"),
     new QOrmAttributeInfo("apellido", "Apellido"),
     new QOrmAttributeInfo("telefono", "Telefono")
},{
    new QOrmChildrens("Logs", &QOrmUsuarios::m_logs, &QOrmUsuarios::appendLogs, &QOrmUsuarios::removeLogs),
    new QOrmChildrens("Ventas", &QOrmUsuarios::m_ventas, &QOrmUsuarios::appendVentas, &QOrmUsuarios::removeVentas)
}/*,
"SELECT * FROM Usuarios ",
"INSERT INTO Usuarios SET ... ",
"DELETE FROM Usuarios WHERE idUsuarios = :id"
"UPDATE Usuarios SET ... "
"DB_Name" */
);

QOrmUsuarios::QOrmUsuarios() :
    QOrmObject(staticMetaTable)
{
     m_idUsuario = 0;
    m_roles = 0;
}

QOrmUsuarios::~QOrmUsuarios()
{
}


int QOrmUsuarios::idUsuario() const
{
    return m_idUsuario;
}

QOrmRoles* QOrmUsuarios::roles() const
{
    return m_roles;
}

QString QOrmUsuarios::user() const
{
    return m_user;
}

QString QOrmUsuarios::pass() const
{
    return m_pass;
}

QString QOrmUsuarios::nombre() const
{
    return m_nombre;
}

QString QOrmUsuarios::apellido() const
{
    return m_apellido;
}

QString QOrmUsuarios::telefono() const
{
    return m_telefono;
}



void QOrmUsuarios::setIdUsuario(int value)
{
    if(m_idUsuario == value) return;

    m_idUsuario = value;
    emit idUsuarioChanged(value);
}

void QOrmUsuarios::setRoles(QOrmRoles* value)
{
    if(m_roles == value) return;

    m_roles = value;
    emit rolesChanged(value);
}

void QOrmUsuarios::setUser(QString value)
{
    if(m_user == value) return;

    m_user = value;
    emit userChanged(value);
}

void QOrmUsuarios::setPass(QString value)
{
    if(m_pass == value) return;

    m_pass = value;
    emit passChanged(value);
}

void QOrmUsuarios::setNombre(QString value)
{
    if(m_nombre == value) return;

    m_nombre = value;
    emit nombreChanged(value);
}

void QOrmUsuarios::setApellido(QString value)
{
    if(m_apellido == value) return;

    m_apellido = value;
    emit apellidoChanged(value);
}

void QOrmUsuarios::setTelefono(QString value)
{
    if(m_telefono == value) return;

    m_telefono = value;
    emit telefonoChanged(value);
}



QList<QOrmLogs *> QOrmUsuarios::listLogs() const
{
    return m_logs;
}
void QOrmUsuarios::appendLogs(QOrmLogs *child)
{
    m_logs.append(child);

    appendChildren(child);
    emit logsChanged();
}
void QOrmUsuarios::removeLogs(QOrmLogs *child)
{
    m_logs.removeOne(child);

    removeChildren(child);
    emit logsChanged();
}

QQmlListProperty<QOrmLogs> QOrmUsuarios::logs()
{
    return QQmlListProperty<QOrmLogs>(this, m_logs);
}

QList<QOrmVentas *> QOrmUsuarios::listVentas() const
{
    return m_ventas;
}
void QOrmUsuarios::appendVentas(QOrmVentas *child)
{
    m_ventas.append(child);

    appendChildren(child);
    emit ventasChanged();
}
void QOrmUsuarios::removeVentas(QOrmVentas *child)
{
    m_ventas.removeOne(child);

    removeChildren(child);
    emit ventasChanged();
}

QQmlListProperty<QOrmVentas> QOrmUsuarios::ventas()
{
    return QQmlListProperty<QOrmVentas>(this, m_ventas);
}


#include "moc_qormusuarios.cpp"

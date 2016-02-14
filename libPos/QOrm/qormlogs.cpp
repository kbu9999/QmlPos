
/*
*/
#include "qormlogs.h"

#include <QOrm>

#include "qormusuarios.h" 

QOrmTableInfo *QOrmLogs::staticMetaTable = QOrm::registerTable<QOrmLogs>("Logs",
{
    /*
     * QOrmAttributeInfo("propertyName", "attributeName", &QOrmLogs::load, &QOrmLogs::store),
     * OR Only
     * QOrmAttributeInfo("propertyName"),
    */
    new QOrmAttributeInfo("idLog", "idLog"),
     new QOrmAttributeInfo("usuarios", "idUsuario"),
     new QOrmAttributeInfo("accion", "accion")
},{
    
}/*,
"SELECT * FROM Logs ",
"INSERT INTO Logs SET ... ",
"DELETE FROM Logs WHERE idLogs = :id"
"UPDATE Logs SET ... "
"DB_Name" */
);

QOrmLogs::QOrmLogs() :
    QOrmObject(staticMetaTable)
{
     m_idLog = 0;
    m_usuarios = 0;
}

QOrmLogs::~QOrmLogs()
{
}


int QOrmLogs::idLog() const
{
    return m_idLog;
}

QOrmUsuarios* QOrmLogs::usuarios() const
{
    return m_usuarios;
}

QString QOrmLogs::accion() const
{
    return m_accion;
}



void QOrmLogs::setIdLog(int value)
{
    if(m_idLog == value) return;

    m_idLog = value;
    emit idLogChanged(value);
}

void QOrmLogs::setUsuarios(QOrmUsuarios* value)
{
    if(m_usuarios == value) return;

    m_usuarios = value;
    emit usuariosChanged(value);
}

void QOrmLogs::setAccion(QString value)
{
    if(m_accion == value) return;

    m_accion = value;
    emit accionChanged(value);
}




#include "moc_qormlogs.cpp"

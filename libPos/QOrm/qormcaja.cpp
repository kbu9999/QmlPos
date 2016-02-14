
/*
*/
#include "qormcaja.h"

#include <QOrm>

#include "qormhaciento.h" 

QOrmTableInfo *QOrmCaja::staticMetaTable = QOrm::registerTable<QOrmCaja>("Caja",
{
    /*
     * QOrmAttributeInfo("propertyName", "attributeName", &QOrmCaja::load, &QOrmCaja::store),
     * OR Only
     * QOrmAttributeInfo("propertyName"),
    */
    new QOrmAttributeInfo("idCaja", "idCaja"),
     new QOrmAttributeInfo("haciento", "idHaciento"),
     new QOrmAttributeInfo("flujo", "flujo")
},{
    
}/*,
"SELECT * FROM Caja ",
"INSERT INTO Caja SET ... ",
"DELETE FROM Caja WHERE idCaja = :id"
"UPDATE Caja SET ... "
"DB_Name" */
);

QOrmCaja::QOrmCaja() :
    QOrmObject(staticMetaTable)
{
     m_idCaja = 0;
    m_haciento = 0;
    m_flujo = 0;
}

QOrmCaja::~QOrmCaja()
{
}


int QOrmCaja::idCaja() const
{
    return m_idCaja;
}

QOrmHaciento* QOrmCaja::haciento() const
{
    return m_haciento;
}

double QOrmCaja::flujo() const
{
    return m_flujo;
}



void QOrmCaja::setIdCaja(int value)
{
    if(m_idCaja == value) return;

    m_idCaja = value;
    emit idCajaChanged(value);
}

void QOrmCaja::setHaciento(QOrmHaciento* value)
{
    if(m_haciento == value) return;

    m_haciento = value;
    emit hacientoChanged(value);
}

void QOrmCaja::setFlujo(double value)
{
    if(m_flujo == value) return;

    m_flujo = value;
    emit flujoChanged(value);
}




#include "moc_qormcaja.cpp"

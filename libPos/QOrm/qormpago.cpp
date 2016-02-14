
/*
*/
#include "qormpago.h"

#include <QOrm>

#include "qormventas.h" 
#include "qormformapago.h" 

QOrmTableInfo *QOrmPago::staticMetaTable = QOrm::registerTable<QOrmPago>("Pago",
{
    /*
     * QOrmAttributeInfo("propertyName", "attributeName", &QOrmPago::load, &QOrmPago::store),
     * OR Only
     * QOrmAttributeInfo("propertyName"),
    */
    new QOrmAttributeInfo("idPago", "idPago"),
     new QOrmAttributeInfo("ventas", "idVenta"),
     new QOrmAttributeInfo("formaPago", "idFormaPago"),
     new QOrmAttributeInfo("monto", "monto"),
     new QOrmAttributeInfo("recargo", "recargo"),
     new QOrmAttributeInfo("sobreTotal", "sobreTotal")
},{
    
}/*,
"SELECT * FROM Pago ",
"INSERT INTO Pago SET ... ",
"DELETE FROM Pago WHERE idPago = :id"
"UPDATE Pago SET ... "
"DB_Name" */
);

QOrmPago::QOrmPago() :
    QOrmObject(staticMetaTable)
{
     m_idPago = 0;
    m_ventas = 0;
    //m_formaPago = 0;
    m_monto = 0;
    m_recargo = 0;

    m_sobreTotal = false;
    m_formaPago = QOrmLoader<QOrmFormaPago>::loadOne(1);
}

QOrmPago::~QOrmPago()
{
}


int QOrmPago::idPago() const
{
    return m_idPago;
}

QOrmVentas* QOrmPago::ventas() const
{
    return m_ventas;
}

QOrmFormaPago* QOrmPago::formaPago() const
{
    return m_formaPago;
}

double QOrmPago::monto() const
{
    return m_monto;
}

double QOrmPago::recargo() const
{
    return m_recargo;
}

bool QOrmPago::sobreTotal() const
{
    return m_sobreTotal;
}



void QOrmPago::setIdPago(int value)
{
    if(m_idPago == value) return;

    m_idPago = value;
    emit idPagoChanged(value);
}

void QOrmPago::setVentas(QOrmVentas* value)
{
    if(m_ventas == value) return;

    m_ventas = value;
    emit ventasChanged(value);
}

void QOrmPago::setFormaPago(QOrmFormaPago* value)
{
    if(m_formaPago == value) return;

    m_formaPago = value;
    emit formaPagoChanged(value);
}

void QOrmPago::setMonto(double value)
{
    if(m_monto == value) return;

    m_monto = value;
    emit montoChanged(value);
}

void QOrmPago::setRecargo(double value)
{
    if(m_recargo == value) return;

    m_recargo = value;
    emit recargoChanged(value);
}

void QOrmPago::setSobreTotal(bool value)
{
    if(m_sobreTotal == value) return;

    m_sobreTotal = value;
    emit sobreTotalChanged(value);
}




#include "moc_qormpago.cpp"

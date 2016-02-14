
/*
*/
#include "qormformapago.h"

#include <QOrm>


QOrmTableInfo *QOrmFormaPago::staticMetaTable = QOrm::registerTable<QOrmFormaPago>("FormaPago",
{
    /*
     * QOrmAttributeInfo("propertyName", "attributeName", &QOrmFormaPago::load, &QOrmFormaPago::store),
     * OR Only
     * QOrmAttributeInfo("propertyName"),
    */
    new QOrmAttributeInfo("idFormaPago", "idFormaPago"),
     new QOrmAttributeInfo("formaPago", "FormaPago")
},{
    new QOrmChildrens("Pago", &QOrmFormaPago::m_pago, &QOrmFormaPago::appendPago, &QOrmFormaPago::removePago)
}/*,
"SELECT * FROM FormaPago ",
"INSERT INTO FormaPago SET ... ",
"DELETE FROM FormaPago WHERE idFormaPago = :id"
"UPDATE FormaPago SET ... "
"DB_Name" */
);

QOrmFormaPago::QOrmFormaPago() :
    QOrmObject(staticMetaTable)
{
     m_idFormaPago = 0;
}

QOrmFormaPago::~QOrmFormaPago()
{
}


int QOrmFormaPago::idFormaPago() const
{
    return m_idFormaPago;
}

QString QOrmFormaPago::formaPago() const
{
    return m_formaPago;
}



void QOrmFormaPago::setIdFormaPago(int value)
{
    if(m_idFormaPago == value) return;

    m_idFormaPago = value;
    emit idFormaPagoChanged(value);
}

void QOrmFormaPago::setFormaPago(QString value)
{
    if(m_formaPago == value) return;

    m_formaPago = value;
    emit formaPagoChanged(value);
}



QList<QOrmPago *> QOrmFormaPago::listPago() const
{
    return m_pago;
}
void QOrmFormaPago::appendPago(QOrmPago *child)
{
    m_pago.append(child);

    appendChildren(child);
    emit pagoChanged();
}
void QOrmFormaPago::removePago(QOrmPago *child)
{
    m_pago.removeOne(child);

    removeChildren(child);
    emit pagoChanged();
}

QQmlListProperty<QOrmPago> QOrmFormaPago::pago()
{
    return QQmlListProperty<QOrmPago>(this, m_pago);
}


#include "moc_qormformapago.cpp"

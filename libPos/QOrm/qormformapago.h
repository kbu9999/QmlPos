
/* */
#ifndef QORMFORMAPAGO_H
#define QORMFORMAPAGO_H

#include <QtCore>
#include <QOrmObject>
#include <QOrmTableInfo>
#include <QtQml/QQmlListProperty>

#include "qormpago.h" 


class QOrmFormaPago : public QOrmObject
{
    Q_OBJECT
    QORM_OBJECT 
    Q_PROPERTY(int idFormaPago READ idFormaPago WRITE setIdFormaPago NOTIFY idFormaPagoChanged) 
    Q_PROPERTY(QString formaPago READ formaPago WRITE setFormaPago NOTIFY formaPagoChanged)  
    Q_PROPERTY(QQmlListProperty<QOrmPago> pago READ pago NOTIFY pagoChanged) 
public:
    QOrmFormaPago();
    virtual ~QOrmFormaPago();
    
    int idFormaPago() const; 
    QString formaPago() const; 
    
    QList<QOrmPago*> listPago() const;

public slots: 
     void setIdFormaPago(int value);
     void setFormaPago(QString value); 
     Q_INVOKABLE void appendPago(QOrmPago *value);
     Q_INVOKABLE void removePago(QOrmPago *value);

signals: 
    void idFormaPagoChanged(int value);
    void formaPagoChanged(QString value); 
    void pagoChanged(); 

private: 
    QQmlListProperty<QOrmPago> pago(); 
    
    int m_idFormaPago;
    QString m_formaPago; 
    QList<QOrmPago*> m_pago; 
};

Q_DECLARE_METATYPE(QOrmFormaPago*)
Q_DECLARE_METATYPE(QQmlListProperty<QOrmFormaPago>)
#endif // QORMFORMAPAGO_H

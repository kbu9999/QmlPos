
/* */
#ifndef QORMPAGO_H
#define QORMPAGO_H

#include <QtCore>
#include <QOrmObject>
#include <QOrmTableInfo>
#include <QtQml/QQmlListProperty>


class QOrmVentas; 
class QOrmFormaPago; 

class QOrmPago : public QOrmObject
{
    Q_OBJECT
    QORM_OBJECT 
    Q_PROPERTY(int idPago READ idPago WRITE setIdPago NOTIFY idPagoChanged) 
    Q_PROPERTY(QOrmVentas* ventas READ ventas WRITE setVentas NOTIFY ventasChanged) 
    Q_PROPERTY(QOrmFormaPago* formaPago READ formaPago WRITE setFormaPago NOTIFY formaPagoChanged) 
    Q_PROPERTY(double monto READ monto WRITE setMonto NOTIFY montoChanged) 
    Q_PROPERTY(double recargo READ recargo WRITE setRecargo NOTIFY recargoChanged) 
    Q_PROPERTY(bool sobreTotal READ sobreTotal WRITE setSobreTotal NOTIFY sobreTotalChanged)  
public:
    QOrmPago();
    virtual ~QOrmPago();
    
    int idPago() const; 
    QOrmVentas* ventas() const; 
    QOrmFormaPago* formaPago() const; 
    double monto() const; 
    double recargo() const; 
    bool sobreTotal() const; 
    

public slots: 
     void setIdPago(int value);
     void setVentas(QOrmVentas* value);
     void setFormaPago(QOrmFormaPago* value);
     void setMonto(double value);
     void setRecargo(double value);
     void setSobreTotal(bool value); 

signals: 
    void idPagoChanged(int value);
    void ventasChanged(QOrmVentas* value);
    void formaPagoChanged(QOrmFormaPago* value);
    void montoChanged(double value);
    void recargoChanged(double value);
    void sobreTotalChanged(bool value); 

private: 
    
    int m_idPago;
    QOrmVentas* m_ventas;
    QOrmFormaPago* m_formaPago;
    double m_monto;
    double m_recargo;
    bool m_sobreTotal; 
};

Q_DECLARE_METATYPE(QOrmPago*)
Q_DECLARE_METATYPE(QQmlListProperty<QOrmPago>)
#endif // QORMPAGO_H

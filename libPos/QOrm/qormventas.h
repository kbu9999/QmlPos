
/* */
#ifndef QORMVENTAS_H
#define QORMVENTAS_H

#include <QtCore>
#include <QOrmObject>
#include <QOrmTableInfo>
#include <QtQml/QQmlListProperty>

#include "qormpago.h" 
#include "qormventaitems.h" 

class QOrmUsuario;
class QOrmClientes; 

class QOrmVentas : public QOrmObject
{
    Q_OBJECT
    QORM_OBJECT 
    Q_PROPERTY(int idVenta READ idVenta WRITE setIdVenta NOTIFY idVentaChanged) 
    Q_PROPERTY(QDateTime fecha READ fecha WRITE setFecha NOTIFY fechaChanged) 
    Q_PROPERTY(QOrmUsuario* usuario READ usuario WRITE setusuario NOTIFY usuarioChanged)
    Q_PROPERTY(QOrmClientes* clientes READ clientes WRITE setClientes NOTIFY clientesChanged)  
    Q_PROPERTY(QQmlListProperty<QOrmPago> pago READ pago NOTIFY pagoChanged) 
    Q_PROPERTY(QQmlListProperty<QOrmVentaItems> ventaitems READ ventaitems NOTIFY ventaitemsChanged) 
    Q_PROPERTY(double suma READ suma NOTIFY sumaChanged)
public:
    QOrmVentas();
    virtual ~QOrmVentas();
    
    int idVenta() const; 
    QDateTime fecha() const; 
    QOrmUsuario* usuario() const;
    QOrmClientes* clientes() const; 
    QList<QOrmPago*> listPago() const;
    QList<QOrmVentaItems*> listVentaItems() const;
    double suma() const;

    void afterLoad();

public slots: 
     void setIdVenta(int value);
     void setFecha(QDateTime value);
     void setusuario(QOrmUsuario* value);
     void setClientes(QOrmClientes* value); 
     Q_INVOKABLE void appendPago(QOrmPago *value);
     Q_INVOKABLE void removePago(QOrmPago *value);
     Q_INVOKABLE void appendVentaItems(QOrmVentaItems *value);
     Q_INVOKABLE void removeVentaItems(QOrmVentaItems *value);
     Q_INVOKABLE void addVentaItems(QOrmProductos *prod, double cant = 1);

signals: 
    void idVentaChanged(int value);
    void fechaChanged(QDateTime value);
    void usuarioChanged(QOrmUsuario* value);
    void clientesChanged(QOrmClientes* value); 
    void pagoChanged(); 
    void ventaitemsChanged();
    void sumaChanged(double value);

private: 
    QQmlListProperty<QOrmPago> pago(); 
    QQmlListProperty<QOrmVentaItems> ventaitems(); 
    
    int m_idVenta;
    QDateTime m_fecha;
    QOrmUsuario* m_usuario;
    QOrmClientes* m_clientes; 
    QList<QOrmPago*> m_pago; 
    QList<QOrmVentaItems*> m_ventaitems; 
    double m_suma;
};

Q_DECLARE_METATYPE(QOrmVentas*)
Q_DECLARE_METATYPE(QQmlListProperty<QOrmVentas>)
#endif // QORMVENTAS_H

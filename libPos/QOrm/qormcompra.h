
/* */
#ifndef QORMCOMPRA_H
#define QORMCOMPRA_H

#include <QtCore>
#include <QOrmObject>
#include <QOrmTableInfo>
#include <QtQml/QQmlListProperty>

#include "qormcompraitems.h" 

class QOrmProveedor; 

class QOrmCompra : public QOrmObject
{
    Q_OBJECT
    QORM_OBJECT 
    Q_PROPERTY(int idCompra READ idCompra WRITE setIdCompra NOTIFY idCompraChanged) 
    Q_PROPERTY(QDateTime fecha READ fecha WRITE setFecha NOTIFY fechaChanged) 
    Q_PROPERTY(QOrmProveedor* proveedor READ proveedor WRITE setProveedor NOTIFY proveedorChanged)  
    Q_PROPERTY(QQmlListProperty<QOrmCompraItems> compraitems READ compraitems NOTIFY compraitemsChanged) 
    Q_PROPERTY(double suma READ suma NOTIFY sumaChanged)
public:
    QOrmCompra();
    virtual ~QOrmCompra();
    
    int idCompra() const; 
    QDateTime fecha() const; 
    QOrmProveedor* proveedor() const; 
    double suma() const;
    
    QList<QOrmCompraItems*> listCompraItems() const;

public slots: 
     void setIdCompra(int value);
     void setFecha(QDateTime value);
     void setProveedor(QOrmProveedor* value); 
     Q_INVOKABLE void appendCompraItems(QOrmCompraItems *value);
     Q_INVOKABLE void removeCompraItems(QOrmCompraItems *value);

     Q_INVOKABLE void addItem(QOrmProductos *prod, int cant);
     Q_INVOKABLE void remItem(int row);

signals: 
    void idCompraChanged(int value);
    void fechaChanged(QDateTime value);
    void proveedorChanged(QOrmProveedor* value); 
    void compraitemsChanged(); 
    void sumaChanged(double value);

private: 
    QQmlListProperty<QOrmCompraItems> compraitems(); 
    
    int m_idCompra;
    QDateTime m_fecha;
    QOrmProveedor* m_proveedor; 
    QList<QOrmCompraItems*> m_compraitems; 
    double m_suma;
};

Q_DECLARE_METATYPE(QOrmCompra*)
Q_DECLARE_METATYPE(QQmlListProperty<QOrmCompra>)
#endif // QORMCOMPRA_H

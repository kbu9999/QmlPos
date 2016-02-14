
/* */
#ifndef QORMCOMPRAITEMS_H
#define QORMCOMPRAITEMS_H

#include <QtCore>
#include <QOrmObject>
#include <QOrmTableInfo>
#include <QtQml/QQmlListProperty>


class QOrmProductos; 
class QOrmCompra; 

class QOrmCompraItems : public QOrmObject
{
    Q_OBJECT
    QORM_OBJECT 
    Q_PROPERTY(int idCompraItems READ idCompraItems WRITE setIdCompraItems NOTIFY idCompraItemsChanged) 
    Q_PROPERTY(QOrmProductos* productos READ productos WRITE setProductos NOTIFY productosChanged) 
    Q_PROPERTY(QOrmCompra* compra READ compra WRITE setCompra NOTIFY compraChanged) 
    Q_PROPERTY(int cantidad READ cantidad WRITE setCantidad NOTIFY cantidadChanged) 
    Q_PROPERTY(double costo READ costo WRITE setCosto NOTIFY costoChanged)
public:
    QOrmCompraItems();
    virtual ~QOrmCompraItems();
    
    int idCompraItems() const; 
    QOrmProductos* productos() const; 
    QOrmCompra* compra() const; 
    int cantidad() const; 
    double costo() const;
    

public slots: 
     void setIdCompraItems(int value);
     void setProductos(QOrmProductos* value);
     void setCompra(QOrmCompra* value);
     void setCantidad(int value);
     void setCosto(double value);

signals: 
    void idCompraItemsChanged(int value);
    void productosChanged(QOrmProductos* value);
    void compraChanged(QOrmCompra* value);
    void cantidadChanged(int value);
    void costoChanged(double value);

private: 
    
    int m_idCompraItems;
    QOrmProductos* m_productos;
    QOrmCompra* m_compra;
    int m_cantidad;
    double m_precio; 
};

Q_DECLARE_METATYPE(QOrmCompraItems*)
Q_DECLARE_METATYPE(QQmlListProperty<QOrmCompraItems>)
#endif // QORMCOMPRAITEMS_H

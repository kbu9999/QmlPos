
/* */
#ifndef QORMVENTAITEMS_H
#define QORMVENTAITEMS_H

#include <QtCore>
#include <QOrmObject>
#include <QOrmTableInfo>
#include <QtQml/QQmlListProperty>


class QOrmVentas; 
class QOrmProductos; 

class QOrmVentaItems : public QOrmObject
{
    Q_OBJECT
    QORM_OBJECT 
    Q_PROPERTY(int idVentaItem READ idVentaItem WRITE setIdVentaItem NOTIFY idVentaItemChanged) 
    Q_PROPERTY(QOrmVentas* ventas READ ventas WRITE setVentas NOTIFY ventasChanged) 
    Q_PROPERTY(QOrmProductos* productos READ productos WRITE setProductos NOTIFY productosChanged) 
    Q_PROPERTY(double cantidad READ cantidad WRITE setCantidad NOTIFY cantidadChanged) 
    Q_PROPERTY(double precio READ precio WRITE setPrecio NOTIFY precioChanged)
public:
    QOrmVentaItems();
    virtual ~QOrmVentaItems();
    
    int idVentaItem() const; 
    QOrmVentas* ventas() const; 
    QOrmProductos* productos() const; 
    double cantidad() const; 
    double precio() const;
    

public slots: 
     void setIdVentaItem(int value);
     void setVentas(QOrmVentas* value);
     void setProductos(QOrmProductos* value);
     void setCantidad(double value);
     void setPrecio(double value);

signals: 
    void idVentaItemChanged(int value);
    void ventasChanged(QOrmVentas* value);
    void productosChanged(QOrmProductos* value);
    void cantidadChanged(double value);
    void precioChanged(double value);

private: 
    
    int m_idVentaItem;
    QOrmVentas* m_ventas;
    QOrmProductos* m_productos;
    double m_cantidad;
    double m_precio;
};

Q_DECLARE_METATYPE(QOrmVentaItems*)
Q_DECLARE_METATYPE(QQmlListProperty<QOrmVentaItems>)
#endif // QORMVENTAITEMS_H

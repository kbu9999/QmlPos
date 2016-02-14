
/* */
#ifndef QORMPRODUCTOS_H
#define QORMPRODUCTOS_H

#include <QtCore>
#include <QOrmObject>
#include <QOrmTableInfo>
#include <QPixmap>
#include <QtQml/QQmlListProperty>

#include "qormcompraitems.h" 
#include "qormventaitems.h" 

class QOrmMarcas; 
class QOrmCategoria; 
class QOrmUnidadMedida; 

class QOrmProductos : public QOrmObject
{
    Q_OBJECT
    QORM_OBJECT 
    Q_PROPERTY(int idProducto READ idProducto WRITE setIdProducto NOTIFY idProductoChanged) 
    Q_PROPERTY(QOrmMarcas* marcas READ marcas WRITE setMarcas NOTIFY marcasChanged) 
    Q_PROPERTY(QOrmCategoria* categoria READ categoria WRITE setCategoria NOTIFY categoriaChanged) 
    Q_PROPERTY(QOrmUnidadMedida* unidadMedida READ unidadMedida WRITE setUnidadMedida NOTIFY unidadMedidaChanged) 
    Q_PROPERTY(QString nombre READ nombre WRITE setNombre NOTIFY nombreChanged) 
    Q_PROPERTY(double unidades READ unidades WRITE setUnidades NOTIFY unidadesChanged) 
    Q_PROPERTY(double costo READ costo WRITE setCosto NOTIFY costoChanged) 
    Q_PROPERTY(double precio READ precio WRITE setPrecio NOTIFY precioChanged) 
    Q_PROPERTY(int stock READ stock WRITE setStock NOTIFY stockChanged)
    Q_PROPERTY(QPixmap foto READ foto WRITE setFoto NOTIFY fotoChanged)
    Q_PROPERTY(QQmlListProperty<QOrmCompraItems> compraitems READ compraitems NOTIFY compraitemsChanged) 
    Q_PROPERTY(QQmlListProperty<QOrmVentaItems> ventaitems READ ventaitems NOTIFY ventaitemsChanged) 
public:
    QOrmProductos();
    virtual ~QOrmProductos();
    
    int idProducto() const; 
    QOrmMarcas* marcas() const; 
    QOrmCategoria* categoria() const; 
    QOrmUnidadMedida* unidadMedida() const; 
    QString nombre() const; 
    double unidades() const; 
    double costo() const; 
    double precio() const; 
    int stock() const;
    QPixmap foto();
    
    QList<QOrmCompraItems*> listCompraItems() const;
    QList<QOrmVentaItems*> listVentaItems() const;

    Q_INVOKABLE void save();

public slots: 
     void setIdProducto(int value);
     void setMarcas(QOrmMarcas* value);
     void setCategoria(QOrmCategoria* value);
     void setUnidadMedida(QOrmUnidadMedida* value);
     void setNombre(QString value);
     void setUnidades(double value);
     void setCosto(double value);
     void setPrecio(double value);
     void setStock(int value);
     void setFoto(QPixmap value);
     Q_INVOKABLE void loadFotoFromFile(QString file);

     Q_INVOKABLE void appendCompraItems(QOrmCompraItems *value);
     Q_INVOKABLE void removeCompraItems(QOrmCompraItems *value);
     Q_INVOKABLE void appendVentaItems(QOrmVentaItems *value);
     Q_INVOKABLE void removeVentaItems(QOrmVentaItems *value);

signals: 
    void idProductoChanged(int value);
    void marcasChanged(QOrmMarcas* value);
    void categoriaChanged(QOrmCategoria* value);
    void unidadMedidaChanged(QOrmUnidadMedida* value);
    void nombreChanged(QString value);
    void unidadesChanged(double value);
    void costoChanged(double value);
    void precioChanged(double value);
    void stockChanged(int value);
    void fotoChanged();
    void compraitemsChanged(); 
    void ventaitemsChanged(); 

private: 
    QQmlListProperty<QOrmCompraItems> compraitems(); 
    QQmlListProperty<QOrmVentaItems> ventaitems(); 
    
    int m_idProducto;
    QOrmMarcas* m_marcas;
    QOrmCategoria* m_categoria;
    QOrmUnidadMedida* m_unidadMedida;
    QString m_nombre;
    double m_unidades;
    double m_costo;
    double m_precio;
    int m_stock;
    QPixmap m_foto;
    QList<QOrmCompraItems*> m_compraitems; 
    QList<QOrmVentaItems*> m_ventaitems; 
};

Q_DECLARE_METATYPE(QOrmProductos*)
Q_DECLARE_METATYPE(QQmlListProperty<QOrmProductos>)
#endif // QORMPRODUCTOS_H


/* */
#ifndef QORMCATEGORIA_H
#define QORMCATEGORIA_H

#include <QtCore>
#include <QOrmObject>
#include <QOrmTableInfo>
#include <QtQml/QQmlListProperty>

#include "qormproductos.h" 


class QOrmCategoria : public QOrmObject
{
    Q_OBJECT
    QORM_OBJECT 
    Q_PROPERTY(int idCategoria READ idCategoria WRITE setIdCategoria NOTIFY idCategoriaChanged) 
    Q_PROPERTY(QString nombre READ nombre WRITE setNombre NOTIFY nombreChanged)  
    Q_PROPERTY(QQmlListProperty<QOrmProductos> productos READ productos NOTIFY productosChanged) 
public:
    QOrmCategoria();
    virtual ~QOrmCategoria();
    
    int idCategoria() const; 
    QString nombre() const; 
    
    QList<QOrmProductos*> listProductos() const;

public slots: 
     void setIdCategoria(int value);
     void setNombre(QString value); 
     Q_INVOKABLE void appendProductos(QOrmProductos *value);
     Q_INVOKABLE void removeProductos(QOrmProductos *value);

signals: 
    void idCategoriaChanged(int value);
    void nombreChanged(QString value); 
    void productosChanged(); 

private: 
    QQmlListProperty<QOrmProductos> productos(); 
    
    int m_idCategoria;
    QString m_nombre; 
    QList<QOrmProductos*> m_productos; 
};

Q_DECLARE_METATYPE(QOrmCategoria*)
Q_DECLARE_METATYPE(QQmlListProperty<QOrmCategoria>)
#endif // QORMCATEGORIA_H

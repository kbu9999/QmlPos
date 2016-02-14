
/* */
#ifndef QORMMARCAS_H
#define QORMMARCAS_H

#include <QtCore>
#include <QOrmObject>
#include <QOrmTableInfo>
#include <QtQml/QQmlListProperty>

#include "qormproductos.h" 


class QOrmMarcas : public QOrmObject
{
    Q_OBJECT
    QORM_OBJECT 
    Q_PROPERTY(int idMarca READ idMarca WRITE setIdMarca NOTIFY idMarcaChanged) 
    Q_PROPERTY(QString nombre READ nombre WRITE setNombre NOTIFY nombreChanged)  
    Q_PROPERTY(QQmlListProperty<QOrmProductos> productos READ productos NOTIFY productosChanged) 
public:
    QOrmMarcas();
    virtual ~QOrmMarcas();
    
    int idMarca() const; 
    QString nombre() const; 
    
    QList<QOrmProductos*> listProductos() const;

public slots: 
     void setIdMarca(int value);
     void setNombre(QString value); 
     Q_INVOKABLE void appendProductos(QOrmProductos *value);
     Q_INVOKABLE void removeProductos(QOrmProductos *value);

signals: 
    void idMarcaChanged(int value);
    void nombreChanged(QString value); 
    void productosChanged(); 

private: 
    QQmlListProperty<QOrmProductos> productos(); 
    
    int m_idMarca;
    QString m_nombre; 
    QList<QOrmProductos*> m_productos; 
};

Q_DECLARE_METATYPE(QOrmMarcas*)
Q_DECLARE_METATYPE(QQmlListProperty<QOrmMarcas>)
#endif // QORMMARCAS_H

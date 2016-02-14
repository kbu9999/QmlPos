
/* */
#ifndef QORMPROVEEDOR_H
#define QORMPROVEEDOR_H

#include <QtCore>
#include <QOrmObject>
#include <QOrmTableInfo>
#include <QtQml/QQmlListProperty>

#include "qormcompra.h" 

class QOrmHaciento; 

class QOrmProveedor : public QOrmObject
{
    Q_OBJECT
    QORM_OBJECT 
    Q_PROPERTY(int idProveedor READ idProveedor WRITE setIdProveedor NOTIFY idProveedorChanged) 
    Q_PROPERTY(QOrmHaciento* haciento READ haciento WRITE setHaciento NOTIFY hacientoChanged) 
    Q_PROPERTY(QString proveedor READ proveedor WRITE setProveedor NOTIFY proveedorChanged)  
    Q_PROPERTY(QQmlListProperty<QOrmCompra> compra READ compra NOTIFY compraChanged) 
public:
    QOrmProveedor();
    virtual ~QOrmProveedor();
    
    int idProveedor() const; 
    QOrmHaciento* haciento() const; 
    QString proveedor() const; 
    
    QList<QOrmCompra*> listCompra() const;

public slots: 
     void setIdProveedor(int value);
     void setHaciento(QOrmHaciento* value);
     void setProveedor(QString value); 
     Q_INVOKABLE void appendCompra(QOrmCompra *value);
     Q_INVOKABLE void removeCompra(QOrmCompra *value);

signals: 
    void idProveedorChanged(int value);
    void hacientoChanged(QOrmHaciento* value);
    void proveedorChanged(QString value); 
    void compraChanged(); 

private: 
    QQmlListProperty<QOrmCompra> compra(); 
    
    int m_idProveedor;
    QOrmHaciento* m_haciento;
    QString m_proveedor; 
    QList<QOrmCompra*> m_compra; 
};

Q_DECLARE_METATYPE(QOrmProveedor*)
Q_DECLARE_METATYPE(QQmlListProperty<QOrmProveedor>)
#endif // QORMPROVEEDOR_H

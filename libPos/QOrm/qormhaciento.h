
/* */
#ifndef QORMHACIENTO_H
#define QORMHACIENTO_H

#include <QtCore>
#include <QOrmObject>
#include <QOrmTableInfo>
#include <QtQml/QQmlListProperty>

#include "qormcaja.h" 
#include "qormclientes.h" 
#include "qormproveedor.h" 


class QOrmHaciento : public QOrmObject
{
    Q_OBJECT
    QORM_OBJECT 
    Q_PROPERTY(int idHaciento READ idHaciento WRITE setIdHaciento NOTIFY idHacientoChanged) 
    Q_PROPERTY(QString haciento READ haciento WRITE setHaciento NOTIFY hacientoChanged)  
    Q_PROPERTY(QQmlListProperty<QOrmCaja> caja READ caja NOTIFY cajaChanged) 
    Q_PROPERTY(QQmlListProperty<QOrmClientes> clientes READ clientes NOTIFY clientesChanged) 
    Q_PROPERTY(QQmlListProperty<QOrmProveedor> proveedor READ proveedor NOTIFY proveedorChanged) 
public:
    QOrmHaciento();
    virtual ~QOrmHaciento();
    
    int idHaciento() const; 
    QString haciento() const; 
    
    QList<QOrmCaja*> listCaja() const;
    QList<QOrmClientes*> listClientes() const;
    QList<QOrmProveedor*> listProveedor() const;

public slots: 
     void setIdHaciento(int value);
     void setHaciento(QString value); 
     Q_INVOKABLE void appendCaja(QOrmCaja *value);
     Q_INVOKABLE void removeCaja(QOrmCaja *value);
     Q_INVOKABLE void appendClientes(QOrmClientes *value);
     Q_INVOKABLE void removeClientes(QOrmClientes *value);
     Q_INVOKABLE void appendProveedor(QOrmProveedor *value);
     Q_INVOKABLE void removeProveedor(QOrmProveedor *value);

signals: 
    void idHacientoChanged(int value);
    void hacientoChanged(QString value); 
    void cajaChanged(); 
    void clientesChanged(); 
    void proveedorChanged(); 

private: 
    QQmlListProperty<QOrmCaja> caja(); 
    QQmlListProperty<QOrmClientes> clientes(); 
    QQmlListProperty<QOrmProveedor> proveedor(); 
    
    int m_idHaciento;
    QString m_haciento; 
    QList<QOrmCaja*> m_caja; 
    QList<QOrmClientes*> m_clientes; 
    QList<QOrmProveedor*> m_proveedor; 
};

Q_DECLARE_METATYPE(QOrmHaciento*)
Q_DECLARE_METATYPE(QQmlListProperty<QOrmHaciento>)
#endif // QORMHACIENTO_H

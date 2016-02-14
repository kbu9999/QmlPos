
/* */
#ifndef QORMCLIENTES_H
#define QORMCLIENTES_H

#include <QtCore>
#include <QOrmObject>
#include <QOrmTableInfo>
#include <QtQml/QQmlListProperty>

#include "qormventas.h" 

class QOrmHaciento; 

class QOrmClientes : public QOrmObject
{
    Q_OBJECT
    QORM_OBJECT 
    Q_PROPERTY(int idCliente READ idCliente WRITE setIdCliente NOTIFY idClienteChanged) 
    Q_PROPERTY(QOrmHaciento* haciento READ haciento WRITE setHaciento NOTIFY hacientoChanged) 
    Q_PROPERTY(QString nombre READ nombre WRITE setNombre NOTIFY nombreChanged) 
    Q_PROPERTY(QString apellido READ apellido WRITE setApellido NOTIFY apellidoChanged) 
    Q_PROPERTY(QString direccion READ direccion WRITE setDireccion NOTIFY direccionChanged) 
    Q_PROPERTY(QString telefono READ telefono WRITE setTelefono NOTIFY telefonoChanged)  
    Q_PROPERTY(QQmlListProperty<QOrmVentas> ventas READ ventas NOTIFY ventasChanged) 
public:
    QOrmClientes();
    virtual ~QOrmClientes();
    
    int idCliente() const; 
    QOrmHaciento* haciento() const; 
    QString nombre() const; 
    QString apellido() const; 
    QString direccion() const; 
    QString telefono() const; 
    
    QList<QOrmVentas*> listVentas() const;

public slots: 
     void setIdCliente(int value);
     void setHaciento(QOrmHaciento* value);
     void setNombre(QString value);
     void setApellido(QString value);
     void setDireccion(QString value);
     void setTelefono(QString value); 
     Q_INVOKABLE void appendVentas(QOrmVentas *value);
     Q_INVOKABLE void removeVentas(QOrmVentas *value);

signals: 
    void idClienteChanged(int value);
    void hacientoChanged(QOrmHaciento* value);
    void nombreChanged(QString value);
    void apellidoChanged(QString value);
    void direccionChanged(QString value);
    void telefonoChanged(QString value); 
    void ventasChanged(); 

private: 
    QQmlListProperty<QOrmVentas> ventas(); 
    
    int m_idCliente;
    QOrmHaciento* m_haciento;
    QString m_nombre;
    QString m_apellido;
    QString m_direccion;
    QString m_telefono; 
    QList<QOrmVentas*> m_ventas; 
};

Q_DECLARE_METATYPE(QOrmClientes*)
Q_DECLARE_METATYPE(QQmlListProperty<QOrmClientes>)
#endif // QORMCLIENTES_H

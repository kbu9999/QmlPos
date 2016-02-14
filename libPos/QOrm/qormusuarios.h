
/* */
#ifndef QORMUSUARIOS_H
#define QORMUSUARIOS_H

#include <QtCore>
#include <QOrmObject>
#include <QOrmTableInfo>
#include <QtQml/QQmlListProperty>

#include "qormlogs.h" 
#include "qormventas.h" 

class QOrmRoles; 

class QOrmUsuarios : public QOrmObject
{
    Q_OBJECT
    QORM_OBJECT 
    Q_PROPERTY(int idUsuario READ idUsuario WRITE setIdUsuario NOTIFY idUsuarioChanged) 
    Q_PROPERTY(QOrmRoles* roles READ roles WRITE setRoles NOTIFY rolesChanged) 
    Q_PROPERTY(QString user READ user WRITE setUser NOTIFY userChanged) 
    Q_PROPERTY(QString pass READ pass WRITE setPass NOTIFY passChanged) 
    Q_PROPERTY(QString nombre READ nombre WRITE setNombre NOTIFY nombreChanged) 
    Q_PROPERTY(QString apellido READ apellido WRITE setApellido NOTIFY apellidoChanged) 
    Q_PROPERTY(QString telefono READ telefono WRITE setTelefono NOTIFY telefonoChanged)  
    Q_PROPERTY(QQmlListProperty<QOrmLogs> logs READ logs NOTIFY logsChanged) 
    Q_PROPERTY(QQmlListProperty<QOrmVentas> ventas READ ventas NOTIFY ventasChanged) 
public:
    QOrmUsuarios();
    virtual ~QOrmUsuarios();
    
    int idUsuario() const; 
    QOrmRoles* roles() const; 
    QString user() const; 
    QString pass() const; 
    QString nombre() const; 
    QString apellido() const; 
    QString telefono() const; 
    
    QList<QOrmLogs*> listLogs() const;
    QList<QOrmVentas*> listVentas() const;

public slots: 
     void setIdUsuario(int value);
     void setRoles(QOrmRoles* value);
     void setUser(QString value);
     void setPass(QString value);
     void setNombre(QString value);
     void setApellido(QString value);
     void setTelefono(QString value); 
     Q_INVOKABLE void appendLogs(QOrmLogs *value);
     Q_INVOKABLE void removeLogs(QOrmLogs *value);
     Q_INVOKABLE void appendVentas(QOrmVentas *value);
     Q_INVOKABLE void removeVentas(QOrmVentas *value);

signals: 
    void idUsuarioChanged(int value);
    void rolesChanged(QOrmRoles* value);
    void userChanged(QString value);
    void passChanged(QString value);
    void nombreChanged(QString value);
    void apellidoChanged(QString value);
    void telefonoChanged(QString value); 
    void logsChanged(); 
    void ventasChanged(); 

private: 
    QQmlListProperty<QOrmLogs> logs(); 
    QQmlListProperty<QOrmVentas> ventas(); 
    
    int m_idUsuario;
    QOrmRoles* m_roles;
    QString m_user;
    QString m_pass;
    QString m_nombre;
    QString m_apellido;
    QString m_telefono; 
    QList<QOrmLogs*> m_logs; 
    QList<QOrmVentas*> m_ventas; 
};

Q_DECLARE_METATYPE(QOrmUsuarios*)
Q_DECLARE_METATYPE(QQmlListProperty<QOrmUsuarios>)
#endif // QORMUSUARIOS_H

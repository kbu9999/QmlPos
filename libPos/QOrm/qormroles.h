
/* */
#ifndef QORMROLES_H
#define QORMROLES_H

#include <QtCore>
#include <QOrmObject>
#include <QOrmTableInfo>
#include <QtQml/QQmlListProperty>

#include "qormprivilegios.h" 
#include "qormusuarios.h" 


class QOrmRoles : public QOrmObject
{
    Q_OBJECT
    QORM_OBJECT 
    Q_PROPERTY(int idRol READ idRol WRITE setIdRol NOTIFY idRolChanged) 
    Q_PROPERTY(QString nombre READ nombre WRITE setNombre NOTIFY nombreChanged)  
    Q_PROPERTY(QQmlListProperty<QOrmPrivilegios> privilegios READ privilegios NOTIFY privilegiosChanged) 
    Q_PROPERTY(QQmlListProperty<QOrmUsuarios> usuarios READ usuarios NOTIFY usuariosChanged) 
public:
    QOrmRoles();
    virtual ~QOrmRoles();
    
    int idRol() const; 
    QString nombre() const; 
    
    QList<QOrmPrivilegios*> listPrivilegios() const;
    QList<QOrmUsuarios*> listUsuarios() const;

public slots: 
     void setIdRol(int value);
     void setNombre(QString value); 
     Q_INVOKABLE void appendPrivilegios(QOrmPrivilegios *value);
     Q_INVOKABLE void removePrivilegios(QOrmPrivilegios *value);
     Q_INVOKABLE void appendUsuarios(QOrmUsuarios *value);
     Q_INVOKABLE void removeUsuarios(QOrmUsuarios *value);

signals: 
    void idRolChanged(int value);
    void nombreChanged(QString value); 
    void privilegiosChanged(); 
    void usuariosChanged(); 

private: 
    QQmlListProperty<QOrmPrivilegios> privilegios(); 
    QQmlListProperty<QOrmUsuarios> usuarios(); 
    
    int m_idRol;
    QString m_nombre; 
    QList<QOrmPrivilegios*> m_privilegios; 
    QList<QOrmUsuarios*> m_usuarios; 
};

Q_DECLARE_METATYPE(QOrmRoles*)
Q_DECLARE_METATYPE(QQmlListProperty<QOrmRoles>)
#endif // QORMROLES_H

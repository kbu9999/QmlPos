
/* */
#ifndef QORMPRIVILEGIOS_H
#define QORMPRIVILEGIOS_H

#include <QtCore>
#include <QOrmObject>
#include <QOrmTableInfo>
#include <QtQml/QQmlListProperty>


class QOrmRoles; 

class QOrmPrivilegios : public QOrmObject
{
    Q_OBJECT
    QORM_OBJECT 
    Q_PROPERTY(int idPrivilegio READ idPrivilegio WRITE setIdPrivilegio NOTIFY idPrivilegioChanged) 
    Q_PROPERTY(QOrmRoles* roles READ roles WRITE setRoles NOTIFY rolesChanged) 
    Q_PROPERTY(QString nombre READ nombre WRITE setNombre NOTIFY nombreChanged)  
public:
    QOrmPrivilegios();
    virtual ~QOrmPrivilegios();
    
    int idPrivilegio() const; 
    QOrmRoles* roles() const; 
    QString nombre() const; 
    

public slots: 
     void setIdPrivilegio(int value);
     void setRoles(QOrmRoles* value);
     void setNombre(QString value); 

signals: 
    void idPrivilegioChanged(int value);
    void rolesChanged(QOrmRoles* value);
    void nombreChanged(QString value); 

private: 
    
    int m_idPrivilegio;
    QOrmRoles* m_roles;
    QString m_nombre; 
};

Q_DECLARE_METATYPE(QOrmPrivilegios*)
Q_DECLARE_METATYPE(QQmlListProperty<QOrmPrivilegios>)
#endif // QORMPRIVILEGIOS_H

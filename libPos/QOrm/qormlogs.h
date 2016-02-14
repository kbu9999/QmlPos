
/* */
#ifndef QORMLOGS_H
#define QORMLOGS_H

#include <QtCore>
#include <QOrmObject>
#include <QOrmTableInfo>
#include <QtQml/QQmlListProperty>


class QOrmUsuarios; 

class QOrmLogs : public QOrmObject
{
    Q_OBJECT
    QORM_OBJECT 
    Q_PROPERTY(int idLog READ idLog WRITE setIdLog NOTIFY idLogChanged) 
    Q_PROPERTY(QOrmUsuarios* usuarios READ usuarios WRITE setUsuarios NOTIFY usuariosChanged) 
    Q_PROPERTY(QString accion READ accion WRITE setAccion NOTIFY accionChanged)  
public:
    QOrmLogs();
    virtual ~QOrmLogs();
    
    int idLog() const; 
    QOrmUsuarios* usuarios() const; 
    QString accion() const; 
    

public slots: 
     void setIdLog(int value);
     void setUsuarios(QOrmUsuarios* value);
     void setAccion(QString value); 

signals: 
    void idLogChanged(int value);
    void usuariosChanged(QOrmUsuarios* value);
    void accionChanged(QString value); 

private: 
    
    int m_idLog;
    QOrmUsuarios* m_usuarios;
    QString m_accion; 
};

Q_DECLARE_METATYPE(QOrmLogs*)
Q_DECLARE_METATYPE(QQmlListProperty<QOrmLogs>)
#endif // QORMLOGS_H

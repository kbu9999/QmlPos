
/* */
#ifndef QORMCAJA_H
#define QORMCAJA_H

#include <QtCore>
#include <QOrmObject>
#include <QOrmTableInfo>
#include <QtQml/QQmlListProperty>


class QOrmHaciento; 

class QOrmCaja : public QOrmObject
{
    Q_OBJECT
    QORM_OBJECT 
    Q_PROPERTY(int idCaja READ idCaja WRITE setIdCaja NOTIFY idCajaChanged) 
    Q_PROPERTY(QOrmHaciento* haciento READ haciento WRITE setHaciento NOTIFY hacientoChanged) 
    Q_PROPERTY(double flujo READ flujo WRITE setFlujo NOTIFY flujoChanged)  
public:
    QOrmCaja();
    virtual ~QOrmCaja();
    
    int idCaja() const; 
    QOrmHaciento* haciento() const; 
    double flujo() const; 
    

public slots: 
     void setIdCaja(int value);
     void setHaciento(QOrmHaciento* value);
     void setFlujo(double value); 

signals: 
    void idCajaChanged(int value);
    void hacientoChanged(QOrmHaciento* value);
    void flujoChanged(double value); 

private: 
    
    int m_idCaja;
    QOrmHaciento* m_haciento;
    double m_flujo; 
};

Q_DECLARE_METATYPE(QOrmCaja*)
Q_DECLARE_METATYPE(QQmlListProperty<QOrmCaja>)
#endif // QORMCAJA_H

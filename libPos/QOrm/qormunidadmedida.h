
/* */
#ifndef QORMUNIDADMEDIDA_H
#define QORMUNIDADMEDIDA_H

#include <QtCore>
#include <QOrmObject>
#include <QOrmTableInfo>
#include <QtQml/QQmlListProperty>

#include "qormproductos.h" 


class QOrmUnidadMedida : public QOrmObject
{
    Q_OBJECT
    QORM_OBJECT 
    Q_PROPERTY(int idUnidadMedida READ idUnidadMedida WRITE setIdUnidadMedida NOTIFY idUnidadMedidaChanged) 
    Q_PROPERTY(QString nombre READ nombre WRITE setNombre NOTIFY nombreChanged) 
    Q_PROPERTY(bool esDecimal READ esDecimal WRITE setEsDecimal NOTIFY esDecimalChanged)  
    Q_PROPERTY(QQmlListProperty<QOrmProductos> productos READ productos NOTIFY productosChanged) 
public:
    QOrmUnidadMedida();
    virtual ~QOrmUnidadMedida();
    
    int idUnidadMedida() const; 
    QString nombre() const; 
    bool esDecimal() const; 
    
    QList<QOrmProductos*> listProductos() const;

public slots: 
     void setIdUnidadMedida(int value);
     void setNombre(QString value);
     void setEsDecimal(bool value); 
     Q_INVOKABLE void appendProductos(QOrmProductos *value);
     Q_INVOKABLE void removeProductos(QOrmProductos *value);

signals: 
    void idUnidadMedidaChanged(int value);
    void nombreChanged(QString value);
    void esDecimalChanged(bool value); 
    void productosChanged(); 

private: 
    QQmlListProperty<QOrmProductos> productos(); 
    
    int m_idUnidadMedida;
    QString m_nombre;
    bool m_esDecimal; 
    QList<QOrmProductos*> m_productos; 
};

Q_DECLARE_METATYPE(QOrmUnidadMedida*)
Q_DECLARE_METATYPE(QQmlListProperty<QOrmUnidadMedida>)
#endif // QORMUNIDADMEDIDA_H

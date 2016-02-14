
#ifndef QORMQMLPOS_GLOBAL_H
#define QORMQMLPOS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QORMQMLPOS_LIBRARY)
#  define QORMQMLPOSSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QORMQMLPOSSHARED_EXPORT Q_DECL_IMPORT
#endif

#include <QOrm>
#include <QOrm/QOrm>

#include <QtQml/qqml.h>


#include "QOrm/qormcaja.h" 
#include "QOrm/qormcategoria.h" 
#include "QOrm/qormclientes.h" 
#include "QOrm/qormcompra.h" 
#include "QOrm/qormcompraitems.h" 
#include "QOrm/qormformapago.h" 
#include "QOrm/qormhaciento.h" 
#include "QOrm/qormlogs.h" 
#include "QOrm/qormmarcas.h" 
#include "QOrm/qormpago.h"
#include "QOrm/qormproductos.h" 
#include "QOrm/qormproveedor.h"
#include "QOrm/qormunidadmedida.h"
#include "QOrm/qormventaitems.h" 
#include "QOrm/qormventas.h" 

class QORMQMLPOSSHARED_EXPORT QOrmPos
{
public:
    static void init() {
        const char *uri = "libPos";
        
        qRegisterMetaType<QOrmCaja*>(); 
        qRegisterMetaType<QOrmCategoria*>(); 
        qRegisterMetaType<QOrmClientes*>(); 
        qRegisterMetaType<QOrmCompra*>(); 
        qRegisterMetaType<QOrmCompraItems*>(); 
        qRegisterMetaType<QOrmFormaPago*>(); 
        qRegisterMetaType<QOrmHaciento*>(); 
        qRegisterMetaType<QOrmLogs*>(); 
        qRegisterMetaType<QOrmMarcas*>(); 
        qRegisterMetaType<QOrmPago*>();
        qRegisterMetaType<QOrmProductos*>(); 
        qRegisterMetaType<QOrmProveedor*>();
        qRegisterMetaType<QOrmUnidadMedida*>(); 
        qRegisterMetaType<QOrmVentaItems*>(); 
        qRegisterMetaType<QOrmVentas*>(); 
        
        qRegisterMetaType<QQmlListProperty<QOrmCaja> >(); 
        qRegisterMetaType<QQmlListProperty<QOrmCategoria> >(); 
        qRegisterMetaType<QQmlListProperty<QOrmClientes> >(); 
        qRegisterMetaType<QQmlListProperty<QOrmCompra> >(); 
        qRegisterMetaType<QQmlListProperty<QOrmCompraItems> >(); 
        qRegisterMetaType<QQmlListProperty<QOrmFormaPago> >(); 
        qRegisterMetaType<QQmlListProperty<QOrmHaciento> >(); 
        qRegisterMetaType<QQmlListProperty<QOrmLogs> >(); 
        qRegisterMetaType<QQmlListProperty<QOrmMarcas> >(); 
        qRegisterMetaType<QQmlListProperty<QOrmPago> >();
        qRegisterMetaType<QQmlListProperty<QOrmProductos> >(); 
        qRegisterMetaType<QQmlListProperty<QOrmProveedor> >();
        qRegisterMetaType<QQmlListProperty<QOrmUnidadMedida> >();
        qRegisterMetaType<QQmlListProperty<QOrmVentaItems> >(); 
        qRegisterMetaType<QQmlListProperty<QOrmVentas> >(); 
        
        qmlRegisterType<QOrmCaja>(uri, 0, 1, "OrmCaja"); 
        qmlRegisterType<QOrmCategoria>(uri, 0, 1, "OrmCategoria"); 
        qmlRegisterType<QOrmClientes>(uri, 0, 1, "OrmClientes"); 
        qmlRegisterType<QOrmCompra>(uri, 0, 1, "OrmCompra"); 
        qmlRegisterType<QOrmCompraItems>(uri, 0, 1, "OrmCompraItems"); 
        qmlRegisterType<QOrmFormaPago>(uri, 0, 1, "OrmFormaPago"); 
        qmlRegisterType<QOrmHaciento>(uri, 0, 1, "OrmHaciento"); 
        qmlRegisterType<QOrmLogs>(uri, 0, 1, "OrmLogs"); 
        qmlRegisterType<QOrmMarcas>(uri, 0, 1, "OrmMarcas"); 
        qmlRegisterType<QOrmPago>(uri, 0, 1, "OrmPago");
        qmlRegisterType<QOrmProductos>(uri, 0, 1, "OrmProductos"); 
        qmlRegisterType<QOrmProveedor>(uri, 0, 1, "OrmProveedor");
        qmlRegisterType<QOrmUnidadMedida>(uri, 0, 1, "OrmUnidadMedida");
        qmlRegisterType<QOrmVentaItems>(uri, 0, 1, "OrmVentaItems"); 
        qmlRegisterType<QOrmVentas>(uri, 0, 1, "OrmVentas"); 
        
        const char *uri2 = "libPos.models";
        qmlRegisterType<QOrmTableModel<QOrmCaja> >(uri2, 0, 1, "OrmCajaModel"); 
        qmlRegisterType<QOrmTableModel<QOrmCategoria> >(uri2, 0, 1, "OrmCategoriaModel"); 
        qmlRegisterType<QOrmTableModel<QOrmClientes> >(uri2, 0, 1, "OrmClientesModel"); 
        qmlRegisterType<QOrmTableModel<QOrmCompra> >(uri2, 0, 1, "OrmCompraModel"); 
        qmlRegisterType<QOrmTableModel<QOrmCompraItems> >(uri2, 0, 1, "OrmCompraItemsModel"); 
        qmlRegisterType<QOrmTableModel<QOrmFormaPago> >(uri2, 0, 1, "OrmFormaPagoModel"); 
        qmlRegisterType<QOrmTableModel<QOrmHaciento> >(uri2, 0, 1, "OrmHacientoModel"); 
        qmlRegisterType<QOrmTableModel<QOrmLogs> >(uri2, 0, 1, "OrmLogsModel"); 
        qmlRegisterType<QOrmTableModel<QOrmMarcas> >(uri2, 0, 1, "OrmMarcasModel"); 
        qmlRegisterType<QOrmTableModel<QOrmPago> >(uri2, 0, 1, "OrmPagoModel");
        qmlRegisterType<QOrmTableModel<QOrmProductos> >(uri2, 0, 1, "OrmProductosModel"); 
        qmlRegisterType<QOrmTableModel<QOrmProveedor> >(uri2, 0, 1, "OrmProveedorModel");
        qmlRegisterType<QOrmTableModel<QOrmUnidadMedida> >(uri2, 0, 1, "OrmUnidadMedidaModel");
        qmlRegisterType<QOrmTableModel<QOrmVentaItems> >(uri2, 0, 1, "OrmVentaItemsModel"); 
        qmlRegisterType<QOrmTableModel<QOrmVentas> >(uri2, 0, 1, "OrmVentasModel"); 
    }
};

#endif // QORMQMLPOS_GLOBAL_H

import QtQuick 2.2
import Basics 1.0
import QtQuick.Controls 1.3
import MyQuick.Columnas 1.0
import libPos.models 0.1

DefaultTableView {
    id: main

    filterColumn: 4
    model: OrmProductosModel {
    }

    TableViewColumn {
        title: "ID"
        role: "idProducto"
        width: 60
    }

    TableViewColumn {
        title: "Nombre"
        role: "nombre"
        width: 100
    }

    FKColumn {
        title: "Marca"
        role: "marca"
        fkrole: "nombre"
        width: 100
    }

    FKColumn {
        title: "Categoria"
        role: "categoria"
        fkrole: "nombre"
        width: 100
    }

    TableViewColumn {
        title: "Unidades"
        role: "unidades"
        width: 80
    }

    FKColumn {
        title: "Medida"
        role: "unidad"
        fkrole: "nombre"
        width: 100
    }

    TableViewColumn {
        title: "Costo"
        role: "costo"
        width: 80
    }

    TableViewColumn {
        title: "Precio"
        role: "precio"
        width: 80
    }

    TableViewColumn {
        title: "Stock"
        role: "stock"
        width: 80
    }

    Component.onCompleted: {
        model.load()
    }
}

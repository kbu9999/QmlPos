import QtQuick 2.2
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.3

import MyQuick 1.0
import Style 1.0 as S
import MyQuick.Columnas 1.0
import Basics 1.0
import libPos.models 0.1

DefaultTableView {
    id: main

    filterColumn: 4
    model: OrmProveedorModel {
    }

    TableViewColumn {
        title: "ID"
        role: "idProveedor"
        width: 60
    }

    TextFieldColumn {
        title: "Nombre"
        role: "Proveedor"
        width: 100

        onTextChanged: {
            var v = main.at(row)
            v.proveedor = text
        }
    }

    Component.onCompleted: {
        model.load()
        if (model.count() === 0)
            main.model.insertRows(0, 1)
    }
}

import QtQuick 2.2
import QtQuick.Controls 1.3
import Style 1.0 as S
import MyQuick.Columnas 1.0
import Basics 1.0
import libPos.models 0.1


DefaultTableView {
    id: main

    filterColumn: 2
    model: OrmUnidadMedidaModel {
        id: modelProd
    }

    TableViewColumn {
        title: "ID"
        role: "idUnidadMedida"
        width: 80
    }

    TextFieldColumn {
        title: "Nombre"
        role: "nombre"
        width: 100

        onTextChanged: {
           var v = main.at(row)
           v.nombre = text
        }
    }

    Component.onCompleted: {
        model.load()
    }
}

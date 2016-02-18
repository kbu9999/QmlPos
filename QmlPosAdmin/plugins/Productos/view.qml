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

    onDoubleClicked: {
        var o = main.at(row)
        if (!o) return;

        txtid.text = o.idProducto
        edit.producto = o;
        panel.visible = true
    }

    Item {
        id: panel
        visible: false
        anchors.fill: parent

        Rectangle {
            color: "grey"
            opacity: 0.5
            anchors.fill: parent
        }

        Rectangle {
            id: rect1
            color: "#ffffff"
            radius: 30
            width: 700
            height: 250
            anchors.centerIn: parent
            anchors.margins: 15

            Text {
                y: 10
                id: txtid
                text: edit.producto? "ID: "+edit.producto.idProducto : "ID: NULL"
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.leftMargin: 15
                height: 25
                font.bold: true
                font.pointSize: 12
            }

            Rectangle {
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.leftMargin: 15
                anchors.rightMargin: 15
                anchors.top: txtid.bottom
                anchors.topMargin: 5
                height: 1;
                color: "#2b2b2b"
            }

            ProductoEdit {
                id: edit
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: txtid.bottom
                anchors.topMargin: 15
                height: 160
                anchors.margins: 20
            }
        }
    }
}

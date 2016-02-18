import QtQuick 2.2
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.3

import MyQuick 1.0
import Style 1.0 as S
import MyQuick.Columnas 1.0
import MyQuick.FieldPanel 1.0 as FP
import Basics 1.0
import libPos.models 0.1

DefaultTableView {
    id: main

    filterColumn: 4
    model: OrmClientesModel {
        id: modelProd
    }

    TableViewColumn {
        title: "ID"
        role: "idCliente"
        width: 60
    }

    TableViewColumn {
        title: "Nombre"
        role: "nombre"
        width: 140
    }

    Component.onCompleted: {
        model.load()
    }

    onDoubleClicked: {
        var o = main.at(row)
        if (!o) return;

        editor.ormObject = o;
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
            x: 20; y: 10
            width: 600; height: 250
            anchors.centerIn: parent
            anchors.margins: 25

            Image {
                source: "img:add-user.png"
                width: 128; height: 128
            }

            Text {
                y: 10
                text: editor.ormObject? "ID: "+editor.ormObject.idCliente : "ID: NULL"
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.leftMargin: 138
                anchors.rightMargin: 20
                font.bold: true
                font.pointSize: 12
            }

            Rectangle {
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.leftMargin: 138
                anchors.rightMargin: 25
                height: 1;
                y: 35
                color: "#2b2b2b"
            }

            FP.Panel {
                id: editor
                anchors.fill: parent
                anchors.leftMargin: 138
                anchors.topMargin: 50
                anchors.margins: 20

                editIcon: "img:rename.png"
                closeIcon: "img:quit.png"

                FP.FieldTextEdit {
                    title: "Nombre"
                    role: "nombre"
                    //editable: false
                }
            }
        }
    }
}

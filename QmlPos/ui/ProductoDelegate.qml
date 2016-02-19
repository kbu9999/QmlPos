import QtQuick 2.2
import QtQuick.Controls 1.2

Rectangle {
    id: deleg
    width: 120; height: 120
    color: "white"

    border.color: "#d3d3d3"
    border.width: 1
    anchors.margins: 1

    clip: true

    Image {
        id: img
        //fillMode: Image.PreserveAspectFit
        anchors.fill: parent
        anchors.margins: 1
        source: "image://productos/"+idProducto
    }

    Rectangle {
        color: "#7a7da7"
        anchors.top: parent.top
        anchors.topMargin: 3
        anchors.rightMargin: 3
        anchors.right: parent.right
        width: 60; height: 20

        Text {
            anchors.fill: parent
            color: "white"
            font.bold: true

            text: "$ "+ precio.toFixed(2) + " " + unidades
            verticalAlignment: Text.AlignVCenter
        }
    }

    Rectangle {
        anchors.left: parent.left; anchors.bottom: parent.bottom
        anchors.leftMargin: 2; anchors.bottomMargin: 2
        width: ntxt.width + 10 ; height: ntxt.height
        color: "white"

        Text {
            x: 5
            id: ntxt
            text: nombre
            font.bold: true
        }
    }
}

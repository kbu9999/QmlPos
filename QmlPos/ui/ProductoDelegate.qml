import QtQuick 2.2
import QtQuick.Controls 1.2

Rectangle {
    id: deleg
    width: 120; height: 120
    color: "white"

    property alias source: img.source
    property string uni: "U"
    property real prec: 0
    property string name: "Producto"

    border.color: "#d3d3d3"
    border.width: 1

    clip: true

    Image {
        id: img
        fillMode: Image.PreserveAspectFit
        anchors.fill: parent
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

            text: "$ "+ deleg.prec.toFixed(2) + " " + deleg.uni
            verticalAlignment: Text.AlignVCenter
        }
    }

    Text {
        text: name
        anchors.left: parent.left
        anchors.leftMargin: 5
        anchors.bottomMargin: 5
        anchors.bottom: parent.bottom
    }
}

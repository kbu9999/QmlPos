import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Controls.Styles 1.1


import MyQuick 1.0
import libPos 0.1

Item {
    id: main
    width: 800
    height: 600

    focus: true

    property alias source: view.source

    //Action { shortcut: "down";  onTriggered: seleccion.moveCurrentIndexDown() }
    //Action { shortcut: "up";    onTriggered: seleccion.moveCurrentIndexUp() }
    //Action { shortcut: "left";  onTriggered: seleccion.moveCurrentIndexLeft() }
    //Action { shortcut: "right"; onTriggered: seleccion.moveCurrentIndexRight() }

    Action { shortcut: "F6"; onTriggered: terminar() }

    Rectangle {
        anchors.fill: parent

        color: "#e2e2e2"

        Loader {
            id: view
            anchors.fill: parent
        }
    }
}

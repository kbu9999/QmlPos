import QtQuick 2.2
import QtQuick.Window 2.1

import QtQuick.Controls 1.1

import libPos 0.1

ApplicationWindow {
    id: main
    visible: true
    width: 800
    height: 600
    objectName: "main"

    menuBar: MenuView {
        Menu {
            title: "Archivo"
        }
    }

    PosWindow {
        id: window
        anchors.fill: parent

        property alias showConfig: config.visible

        PanelConfig {
            id: config
            anchors.fill: parent
        }

        Connections {
            target: LoginHandler
            onConnectedChanged: {
                if (!LoginHandler.connected) return;

                window.terminar()
                window.focus = true
            }
        }
    }
}

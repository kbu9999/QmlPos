import QtQuick 2.2
import QtQuick.Window 2.1

import QtQuick.Controls 1.1
import QtQuick.Dialogs 1.2

import libPos 0.1

ApplicationWindow {
    id: main
    visible: true
    width: 800
    height: 600
    objectName: "main"

    FileDialog {
        id: fileDialog
        selectMultiple: false
    }

    CaptureDialog {
        id: captDialog
    }

    Item {
        anchors.fill: parent

        MenuView {
            id: menu
            width: parent.width

            onViewChanged: window.source = source
        }

        PosWindow {
            id: window
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.top: menu.bottom

            property alias showConfig: config.visible

            PanelConfig {
                id: config
                anchors.fill: parent
            }

            PanelEditor {
                id: editor
                anchors.fill: parent
            }

            Connections {
                target: LoginHandler
                onConnectedChanged: {
                    if (!LoginHandler.connected) return;

                    window.focus = true
                    window.source = "../plugins/Compra/view.qml"
                }
            }
        }
    }
}

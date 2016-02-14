import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2

import MyQuick 1.0

MenuBar {
    id: rectangle1

    style: MenuBarStyle {
        background: Rectangle {
            implicitHeight: 40
            color: "#393939"

            Row {
                id: row
                anchors.verticalCenterOffset: -2
                anchors.verticalCenter: parent.verticalCenter
                spacing: 5
                layoutDirection: Qt.RightToLeft
                anchors.right: parent.right
                anchors.rightMargin: 10

                IconButton {
                    width: 30; height: 30
                    color: "white"
                    hoveredColor: "#e0392e"
                    source: "icons:system-shutdown.png"

                    //onClicked: LoginHandler.closeSession();
                }

                IconButton {
                    width: 30; height: 30
                    color: LoginHandler.connected? "#37b44b" : "#e0392e"
                    hoverEnabled: false
                    source: "icons:network-wireless.png"
                }

                IconButton {
                    width: 24; height: 24
                    color: "#37b44b"
                    hoveredColor: "white"
                    source: "icons:configure.png"

                    onClicked:  { console.log("dashk"); window.showConfig = !window.showConfig; }
                }
            }


            Text {
                id: text2
                color: "#ffffff"
                text: qsTr("Administrador")
                font.bold: true
                font.italic: true
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 15
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.rightMargin: 120
                anchors.bottom: parent.bottom
            }
        }
    }
}

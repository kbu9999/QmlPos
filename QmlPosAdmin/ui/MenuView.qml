import QtQuick 2.2
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2
import Qt.labs.folderlistmodel 2.0

import MyQuick 1.0

Rectangle {
    id: bar
    implicitHeight: 40
    color: "#393939"

    signal viewChanged(string source)

    FolderListModel {
        id: pluginsModel
        folder: "../plugins/"
        showDirs: true
        showDirsFirst: true
    }

    ListView {
        id: toolbar
        anchors.rightMargin: 10
        anchors.leftMargin: 10
        anchors.right: text2.left
        anchors.left: parent.left
        //clip: true
        orientation: ListView.Horizontal
        spacing: 0

        model: pluginsModel

        delegate: Item {
            id: item1
            implicitHeight: bar.height
            implicitWidth: 70
            width: txt.width + 10

            Rectangle {
                color: "#89cdab"
                anchors.bottom: parent.bottom
                visible: toolbar.currentIndex == index
                height: 4
                width: parent.width
            }

            Text {
                id: txt
                text: fileName
                height: parent.height
                verticalAlignment: Text.AlignVCenter
                anchors.horizontalCenter: parent.horizontalCenter
                color: "white"
                font.pointSize: 9
                font.bold: true
                font.family: "BellGothic BT"
                horizontalAlignment: Text.AlignHCenter
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    bar.viewChanged(fileURL+"/view.qml")
                    toolbar.currentIndex = index
                }
            }
        }
    }

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

            onClicked: LoginHandler.closeSession();
        }

        IconButton {
            width: 30; height: 30
            color: LoginHandler.connected? "#37b44b" : "#e0392e"
            hoverEnabled: false
            source: "icons:network-wireless.png"
        }

        IconButton {
            width: 30; height: 30
            color: "#37b44b"
            hoveredColor: "white"
            source: "icons:configure.png"

            onClicked:  { window.showConfig = !window.showConfig; }
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


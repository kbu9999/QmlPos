import QtQuick 2.0

Image {
    id: editBtn
    width: 16; height: 16
    source: "img:rename.png"
    opacity: mai.containsMouse? 0.5 : 0.9
    anchors.verticalCenter: parent.verticalCenter
    anchors.verticalCenterOffset: 2
    visible: main.producto? true : false

    signal clicked()

    MouseArea {
        id: mai
        anchors.fill: parent
        hoverEnabled: true

        onClicked:  editBtn.clicked()
    }

    Rectangle {
        anchors.fill: parent
        border.color: "black"
        border.width: 1
        color: "transparent"
        radius: 3
        visible: mai.containsMouse
    }
}


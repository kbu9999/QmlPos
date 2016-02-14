import QtQuick 2.0

Item {

    property alias editor: ld.source
    visible: ld.item? true : false

    Rectangle {
        anchors.fill: parent
        color: "#393939"
        opacity: 0.3
    }

    Rectangle {
        width: ld.item? ld.item.witdh + 30 : 0
        height: ld.item? ld.item.height + 30 : 0

        radius: 40

        Loader {
            id: ld
        }
    }
}


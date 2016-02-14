import QtQuick 2.0
import QtQuick.Controls.Styles 1.1

TableViewStyle {
    frame: null
    decrementControl: null
    incrementControl: null

    handle: Rectangle {
        color: "#3daee9"
        implicitWidth: 14
        implicitHeight: 14

    }

    headerDelegate: Rectangle {
        color: "white"
        height: 40
        width: 40

        Rectangle {
            width: parent.width
            height: 1
            color: "#d9d9d9"
        }

        TextStyled {
            anchors.fill: parent
            anchors.leftMargin: 20

            text: styleData.value
            color: "black"
        }

        Rectangle {
            anchors.bottom: parent.bottom
            width: parent.width
            height: 1
            color: "#d9d9d9"
        }
    }

    rowDelegate: Rectangle {
        color: styleData.selected? "#3daee9" : "white"
        height: 30
        clip: true

        Rectangle {
            visible: styleData.row !== undefined
            anchors.bottom: parent.bottom
            width: parent.width
            height: 1
            color: "#d9d9d9"
        }
    }

    itemDelegate: TextStyled {
        text: styleData.value? styleData.value : ""

        anchors.fill: parent
        anchors.leftMargin: 10

        selected: styleData.selected
    }
}

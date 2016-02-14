import QtQuick 2.0
import QtQuick.Controls.Styles 1.1

TableViewStyle {
    frame: null
    decrementControl: null
    incrementControl: null

    handle: Rectangle {
        color: "#89cdab"
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
            color: "#e2e2e2"
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
            color: "#e2e2e2"
        }
    }

    rowDelegate: Rectangle {
        color: styleData.selected? "#89cdab" : "white"
        height: 30
        clip: true

        Rectangle {
            visible: styleData.row !== undefined
            anchors.bottom: parent.bottom
            width: parent.width
            height: 1
            color: "#e2e2e2"
        }
    }

    itemDelegate: TextStyled {
        text: styleData.value? styleData.value : ""

        anchors.fill: parent
        anchors.leftMargin: 10

        selected: styleData.selected
    }
}

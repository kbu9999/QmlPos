//pragma singleton
import QtQuick 2.2
import QtQuick.Controls.Styles 1.3

ButtonStyle {
    background: Rectangle {
        color: control.checked || control.hovered ? "#6ec89b" : "#e2e2e2"
        border.color: "#848484"
        border.width: 1
        radius: 1
        implicitWidth: 50
        implicitHeight: 30
    }

    label: Text {
        color: control.checked || control.hovered? "white" : "#393939"
        text: control.text
        font.pointSize: 9
        font.bold: control.checked
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        //anchors.fill: control
    }
}


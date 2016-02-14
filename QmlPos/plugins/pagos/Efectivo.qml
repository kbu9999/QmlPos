import QtQuick 2.0

import QtQuick.Controls 1.1
import QtQuick.Controls.Styles 1.1


import MyQuick 1.0
import libPos 0.1
import libPos.models 0.1
import Style 1.0

Item {
    implicitHeight: 300
    implicitWidth: 400

    Component {
        id: btstl
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
    }

    Connections {
        target: mainVenta
        onSumaChanged: tPg.value = mainVenta.suma
    }

    Button {
        id: button1
        x: 45
        y: 20
        text: qsTr("Cliente")
        anchors.verticalCenterOffset: 0
        anchors.rightMargin: -2
        anchors.verticalCenter: cbCli.verticalCenter
        anchors.right: cbCli.left
        checkable: true
        checked: cbCli.focus

        style: btstl
    }

    Button {
        id: button2
        x: 45
        y: 54
        text: qsTr("Paga")
        anchors.rightMargin: -2
        anchors.verticalCenter: tPg.verticalCenter
        anchors.right: tPg.left
        checkable: true
        checked: tPg.focus

        style: btstl
    }

    ComboBox {
        id: cbCli
        x: 125
        y: 8
        width: 180
        height: 30

        editable: true
        textRole: "nombre"

        model: OrmClientesModel { id: clModel }

        onCurrentIndexChanged:  tPg.focus = true
        onFocusChanged: if (focus) selectAll()
        KeyNavigation.tab: tPg

        style: ComboBoxStyle { textColor: "black" }
    }

    SpinBox {
        id: tPg
        x: 125
        y: 44
        width: 180
        height: 32
        maximumValue: 9999
        prefix: "$"
        decimals: 2
        value: 0

        KeyNavigation.tab: seleccion.search

        onValueChanged: window.mainPago.monto = value

        style: SpinBoxStyle { textColor: "black" }
    }


    Pad {
        id: pad
        x: 145
        y: 80
        width: 160
        height: 160
    }

    Component.onCompleted: clModel.load()
}


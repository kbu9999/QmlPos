import QtQuick 2.0

import MyQuick 1.0

Rectangle {
    id: detalle
    height: 320
    anchors.right: parent.right
    anchors.left: parent.left
    anchors.top: parent.top

    color: "white"
    radius: 5

    ListView {
        id: detView
        anchors.bottomMargin: 50
        anchors.topMargin: 15
        anchors.fill: parent
        model: mainVenta? mainVenta.ventaitems : []
        delegate: DetalleDelegate {
            width: parent.width
            state: ListView.isCurrentItem? "selected" : ""
            MouseArea {
                anchors.fill: parent
                onClicked: detView.currentIndex = index
            }
        }

        highlight: Rectangle {
            color: "#e7e8f0"
        }
    }

    Rectangle {
        height: 2
        color: "#89cdab"
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.right: parent.right
    }

    Item {
        id: item1
        width: 140
        anchors.rightMargin: 20
        anchors.top: detView.bottom
        anchors.bottom: parent.bottom
        anchors.right: parent.right

        Text {
            y: 3
            color: "#1b1b1b"
            text: "Total: $"+mainVenta.suma.toFixed(2)
            font.pointSize: 12
            anchors.horizontalCenter: parent.horizontalCenter
            font.italic: true
            font.bold: true
        }

        Rectangle {
            id: rectangle3
            height: 1
            color: "#1b1b1b"
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
        }

        Text {
            y: 27
            color: "#2d2d2d"
            text: "Vuelto: $"+(mainVenta.suma - mainPago.monto).toFixed(2)
            anchors.horizontalCenterOffset: 1
            anchors.horizontalCenter: parent.horizontalCenter
            font.italic: true
            font.bold: true
            font.pointSize: 11
        }

    }

    function down(){
        detView.currentIndex++
        if (detView.currentIndex >= detView.count)
            detView.currentIndex = 0
    }

    function up(){
        detView.currentIndex--
        if (detView.currentIndex < 0)
            detView.currentIndex = detView.count - 1
    }

    function plus() {
        var item = detView.model[detView.currentIndex]
        if (!item) return;

        item.cantidad++;
    }

    function minus() {
        var item = detView.model[detView.currentIndex]
        if (!item) return;

        item.cantidad--;
        if (item.cantidad <= 0)
            mainVenta.removeVentaItems(item)
    }
}


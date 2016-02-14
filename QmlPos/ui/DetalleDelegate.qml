import QtQuick 2.2
import QtQuick.Controls 1.2

Item {
    id: main
    width: 300
    height: 40

    Text {
        id: tname
        x: 15
        y: 5
        text: productos.nombre
        font.pointSize: 10
        font.bold: true
        color: "#1b1b1b"
    }

    Text {
        id: tprec
        x: 114
        text: "$ "+(precio * cantidad).toFixed(2)
        anchors.verticalCenter: tname.verticalCenter
        font.pointSize: 10
        anchors.rightMargin: 20
        anchors.right: parent.right
        font.bold: true
        font.italic: true
        color: "#1b1b1b"
    }

    Text {
        id: text2
        x: 15
        y: 34
        width: 280
        color: "#3b3b3b"
        text: cantidad + " Unidad(es) a $" + precio.toFixed(2)
        visible: false
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 3
        font.italic: true
        font.pixelSize: 12
    }

    states: [
        State {
            name: "selected"

            PropertyChanges {
                target: text2
                visible: true
            }

            PropertyChanges {
                target: main
                height: 60
            }
        }
    ]


}

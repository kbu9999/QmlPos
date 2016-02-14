import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Controls.Styles 1.1


import MyQuick 1.0
import libPos 0.1

Item {
    id: main
    width: 800
    height: 600

    property OrmVentas mainVenta
    property OrmPago mainPago

    focus: true

    Action { shortcut: "+";     onTriggered: detalle.plus() }
    Action { shortcut: "-";     onTriggered: detalle.minus() }
    Action { shortcut: "pgup";  onTriggered: detalle.up() }
    Action { shortcut: "pgdown"; onTriggered: detalle.down() }

    Action { shortcut: "down";  onTriggered: seleccion.moveCurrentIndexDown() }
    Action { shortcut: "up";    onTriggered: seleccion.moveCurrentIndexUp() }
    Action { shortcut: "left";  onTriggered: seleccion.moveCurrentIndexLeft() }
    Action { shortcut: "right"; onTriggered: seleccion.moveCurrentIndexRight() }

    Action { shortcut: "F6"; onTriggered: terminar() }

    ProductosView {
        id: seleccion

        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: venta.left
    }

    Rectangle {
        id: venta
        width: 480
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        //anchors.left: seleccion.right
        anchors.top: parent.top

        color: "#e2e2e2"

        DetalleView {
            id: detalle
            height: 320
            anchors.right: parent.right
            anchors.left: parent.left
            anchors.top: parent.top
        }

        Loader {
            id: pago
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            anchors.left: parent.left
            anchors.top: detalle.bottom

            source: "../plugins/pagos/Efectivo.qml"
        }
    }

    Component{
        id: compVenta
        OrmVentas {
            fecha: new Date()
            usuario: LoginHandler.user
        }
    }

    Component{
        id: compPago
        OrmPago {
            //fecha: new Date()
            ventas: window.mainVenta
            monto: 0
        }
    }

    function terminar() {
        if (mainVenta) mainVenta.save();
        if (mainPago) mainPago.save();

        mainVenta = compVenta.createObject(window);
        mainPago = compPago.createObject(window);
    }
}

import QtQuick 2.4
import QtQuick.Controls 1.1
import QtQuick.Controls.Styles 1.1
import QtQuick.Layouts 1.2
import Qt.labs.folderlistmodel 2.0

import MyQuick 1.0
import libPos 0.1
import Style 1.0 as S

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

        ColumnLayout {
            anchors.fill: parent
            spacing: 0

            DetalleView {
                id: detalle
                Layout.fillWidth: true
                Layout.minimumHeight: 360
            }

            RowLayout {
                Layout.fillWidth: true
                Layout.minimumHeight: 35
                spacing: 0

                ExclusiveGroup {
                    id: excl
                }

                Repeater {
                    model: FolderListModel {
                        id: pluginsModel
                        folder: "../plugins/pagos"
                    }
                    delegate: Button {
                        text: fileName.replace(".qml", "")
                        checkable: true
                        Layout.fillWidth: true
                        Layout.fillHeight: true

                        style: S.ButtonStyle { }

                        onClicked: pago.setSource(fileURL)

                        exclusiveGroup: excl
                    }
                }
            }

            Loader {
                id: pago
                Layout.fillWidth: true
                Layout.fillHeight: true
            }
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

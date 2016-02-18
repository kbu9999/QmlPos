import QtQuick 2.2
import QtQuick.Layouts 1.1

import MyQuick 1.0
import MyQuick.Columnas 1.0
import MyQuick.FieldPanel 1.0 as F
import QtQuick.Controls 1.2
import Style 1.0 as S

import libPos 0.1
import libPos.models 0.1


Item {
    width: 500
    height: 600

    Component {
        id: nCompra
        OrmCompra {
            fecha: new Date()
        }
    }

    QtObject {
        id: pr
        property OrmCompra cmp: OrmCompra {
            fecha: new Date()
            //proveedor:
        }

        property OrmProveedorModel provs: OrmProductosModel { }

        Component.onCompleted: provs.load()
    }

    Rectangle {
        id: rect1
        color: "#ffffff"
        radius: 30
        anchors.fill: parent
        anchors.margins: 10

        Item {
            anchors.fill: parent
            anchors.margins: 20

            F.Panel {
                id: cmpEdit
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.leftMargin: 40
                anchors.rightMargin: 40

                height: 50
                z: 15

                columns: 2
                ormObject: pr.cmp
                editIcon: "img:rename.png"
                closeIcon: "img:quit.png"

                F.FieldDate {
                    title: "Fecha de Compra"
                    role: "fecha"
                }

                F.FieldComboBox {
                    title: "Proveedor"
                    role: "proveedor"
                    fkrole: "proveedor"
                    model: pr.provs
                }
            }

            ProductoSearch {
                id: search
                anchors.top: cmpEdit.bottom
                anchors.left: parent.left
                anchors.right: parent.right

                anchors.topMargin: 20

                onAddProducto: pr.cmp.addItem(prod, cant)
                z: 10
            }

            TableView {
                id: tbView
                anchors.top: search.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.bottom: feet.bottom

                anchors.topMargin: 10

                model: pr.cmp.compraitems
                KeyNavigation.priority: KeyNavigation.BeforeItem

                style: S.TableViewStyle { }

                FKColumn {
                    title: "Producto"
                    role: "productos"
                    fkrole: "nombre"
                }

                TableViewColumn {
                    title: "Cantidad"
                    role: "cantidad"
                }

                SpinBoxColumn {
                    title: "Precio"
                    role: "costo"
                    decimals: 2
                    prefix: "$ "
                    onValueChanged: {
                        var i = filterProd.sourceIndex(row)
                        var v = tbView.model.at(i)
                        v.precio = value
                    }
                }

                TableViewColumn {
                    title: "Subtotal"

                    delegate: S.TextStyled {
                        property var item: tbView.model[styleData.row]
                        text: item? "$" + (item.costo * item.cantidad).toFixed(2) : ""
                    }
                }
            }

            RowLayout {
                id: feet
                height: 30
                anchors.left: parent.left; anchors.right: parent.right
                anchors.bottom: parent.bottom
                anchors.leftMargin: 10; anchors.rightMargin: 10

                Button {
                    text: "Terminar"
                    onClicked: {
                        var b = pr.cmp.save();
                        if (!b) return;

                        pr.cmp = nCompra.createObject(pr)
                    }
                }
                Item { Layout.fillWidth: true }
                S.TextStyled {
                    text: "Total: $"+pr.cmp.suma.toFixed(2)
                    font.bold: true
                }
            }
        }
    }

}


import QtQuick 2.2

import MyQuick 1.0
import Basics  1.0
import MyQuick.Columnas 1.0
import QtQuick.Controls 1.2

import libPos 0.1
import libPos.models 0.1

FocusScope {
    id: main
    width: 200
    height: 40

    FilterModel {
        id: filterProd
        sourceModel: modelProd
        filterKeyColumn: 4

        Component.onCompleted: {
            modelProd.load()
        }
    }

    OrmProductosModel {
        id: modelProd
    }

    property OrmProductos producto

    signal addProducto(var prod, var cant)

    Row {
        id: row
        anchors.left: parent.left
        anchors.right: parent.right
        width: 30

        spacing: 5

        Search {
            id: search
            width: 240
            height: 30

            color: "#e3e3e3"
            source: "img:find.png"

            validator: RegExpValidator { regExp: new RegExp("\\D[^\\+\\-]+|\\d+") }

            onFilterChanged: {
                var id = parseInt(filter);
                if (!id) {
                    filterProd.filterRegExp = new RegExp(filter, 'i')
                    main.state = "busq"
                    busqueda.currentIndex = -1
                    main.producto = null
                    return;
                }
            }

            onReturnPressed: {
                if (main.producto && main.producto.idProducto == filter) {
                    addToList()
                    return;
                }

                var id = parseInt(filter);
                if (!id) {
                    busqueda.currentIndex = 0
                    return
                }

                main.producto = filterProd.findByID(id)
                if (!main.producto) {
                    main.producto = nProd.createObject(main, { "idProducto": id} )
                    editar.forceActiveFocus()
                    main.state = "edit"
                }
            }

            Component {
                id: nProd
                OrmProductos { }
            }

            function addToList() {
                main.addProducto(main.producto, cant.value)
                search.setFilterText("")
                main.producto = null
                main.state = ""
                cant.value = 1
                search.forceActiveFocus()
            }
        }

        Text {
            text: main.producto? main.producto.nombre : "S/Producto"
            horizontalAlignment: Text.AlignHCenter
            anchors.verticalCenter: parent.verticalCenter
            anchors.verticalCenterOffset: 3
            width: 160
        }

        SimpleButton {
            id: editBtn
            source: "img:rename.png"
            visible: main.producto? true : false

            anchors.verticalCenter: parent.verticalCenter
            anchors.verticalCenterOffset: 2

            onClicked: {
                if (main.state == "edit") {
                    main.producto.save()
                    main.state = ""
                }
                else {
                    main.state = "edit"
                    //editar.forceActiveFocus()
                    editar.focus = true
                }
            }
        }

        SimpleButton {
            id: quitBtn
            source: "img:quit.png"

            anchors.verticalCenter: parent.verticalCenter
            anchors.verticalCenterOffset: 2

            visible: main.state == "edit"

            onClicked: main.state = ""
        }

        SimpleButton {
            id: addBtn
            source: "img:add.png"

            anchors.verticalCenter: parent.verticalCenter
            anchors.verticalCenterOffset: 2

            visible: main.producto? !main.producto.saved : true
        }

        SpinBox {
            id: cant
            maximumValue: 999999
            minimumValue: 1
            width: 80

            //onEditingFinished: {
            Keys.onReturnPressed: {
                if (main.producto && main.producto.idProducto == search.filter) {
                    search.addToList()
                }
            }
        }
    }

    GridView {
        id: busqueda
        visible: false
        anchors.top: row.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom

        anchors.topMargin: 10

        model: filterProd

        cellWidth: 90; cellHeight: 50
        delegate: Text {
            width: 90;
            height: 50

            text: nombre
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            color: GridView.isCurrentItem ? "white" : "#2b2b2b"

            MouseArea {
                anchors.fill: parent
                onClicked: busqueda.currentIndex = index
            }

            Keys.onReturnPressed: {
                var i = filterProd.sourceIndex(index)
                var p = modelProd.at(i)
                search.setFilterText(p.idProducto)
                main.producto = p
                main.state = ""
                search.forceActiveFocus()
            }

            KeyNavigation.tab: search
            Keys.onLeftPressed: busqueda.moveCurrentIndexLeft()
            Keys.onRightPressed: busqueda.moveCurrentIndexRight()
            Keys.onDownPressed: busqueda.moveCurrentIndexDown()
            Keys.onUpPressed: busqueda.moveCurrentIndexUp()
        }
        highlight: Rectangle {
            color: "#89cdab"
            radius: 20
        }

        onCurrentItemChanged: {
            if (!currentItem) return;
            currentItem.forceActiveFocus()
        }
    }

    ProductoEdit {
        id: editar
        visible: false
        anchors.top: row.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom

        anchors.margins: 20

        producto: main.producto
    }

    Rectangle {
        width: parent.width;
        height: 1;
        anchors.bottom: busqueda.top
        anchors.bottomMargin: -1
        color: "#2b2b2b"
    }

    function moveCurrentIndexDown() { busqueda.moveCurrentIndexDown() }
    function moveCurrentIndexUp() { busqueda.moveCurrentIndexUp() }
    function moveCurrentIndexLeft() { busqueda.moveCurrentIndexLeft() }
    function moveCurrentIndexRight() { busqueda.moveCurrentIndexRight() }

    Behavior on height { NumberAnimation { duration: 400 } }

    states: [
        State {
            name: "busq"
            PropertyChanges {
                target: busqueda
                visible: true
            }
            PropertyChanges {
                target: main
                height: 200
            }
        },
        State {
            name: "edit"
            PropertyChanges {
                target: editar
                visible: true
            }
            PropertyChanges {
                target: main
                height: 210
            }
            PropertyChanges {
                target: editBtn
                source: "img:save.png"
            }
            PropertyChanges {
                target: search
                enabled: false
            }
        }
    ]
}


import QtQuick 2.0

import MyQuick 1.0
import libPos 0.1
import libPos.models 0.1

Rectangle {
    id: main
    width: 480
    height: 480

    color: "#f0eeee"
    radius: 5

    property alias search: search1

    FilterModel {
        id: filterProd
        sourceModel: modelProd
        filterKeyColumn: 4
    }

    OrmProductosModel {
        id: modelProd
    }

    OrmCategoriaModel {
        id: modelCateg
    }

    Component.onCompleted: {
        modelProd.load()
        modelCateg.load()
    }

    Rectangle {
        id: lines
        width: 2
        color: "#393939"
        anchors.bottom: parent.bottom
        anchors.top: parent.top
        anchors.right: parent.right
        z:10
    }

    Rectangle {
        id: stackBar
        height: 40
        color: "#d3d3d3"
        clip: true
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.top: parent.top

        Image {
            id: image1
            x: 5
            sourceSize.height: 36
            sourceSize.width: 36
            opacity: mah.containsMouse ? 0.8 : 0.5
            anchors.verticalCenter: parent.verticalCenter
            fillMode: Image.PreserveAspectFit
            source: "../img/home.png"

            MouseArea {
                id: mah
                anchors.fill: parent
                hoverEnabled: true

                onClicked: categView.currentIndex = -1
            }
        }

        Search {
            id: search1
            width: 140
            anchors.rightMargin: 10
            anchors.bottomMargin: 5
            anchors.bottom: parent.bottom
            anchors.top: parent.top
            anchors.topMargin: 5
            anchors.right: parent.right

            source: "../img/find.png"
            focus: true

            //KeyNavigation.tab: cbCli
            validator: RegExpValidator { regExp: new RegExp("\\D[^\\+\\-]+|\\d+") }

            onFilterChanged: {
                var id = parseInt(filter);
                if (!id) {
                    filterProd.filterRegExp = new RegExp(filter, 'i')
                    prodView.currentIndex = -1
                    return;
                }

                console.log(id)
            }
        }

        Image {
            id: image2
            x: 35
            y: -10
            height: 60
            opacity: 0.4
            source: "../img/go-next.png"
        }
    }

    Rectangle {
        id: categoriesBar
        height: 40
        color: "#e2e2e2"
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.top: stackBar.bottom

        ListView {
            id: categView
            clip: true
            orientation: ListView.Horizontal
            anchors.fill: parent
            model: modelCateg

            property OrmCategoria current: currentIndex < 0? null : modelCateg.at(currentIndex)

            delegate: Rectangle {
                width: 100
                height: 40
                //border.color: "#393939"
                color: ma.containsMouse || categView.currentIndex == index? "#89cdab" : "#e2e2e2"
                Text {
                    text: nombre
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter
                    font.pointSize: 9
                    verticalAlignment: Text.AlignVCenter
                    color: "#393939"
                }

                Rectangle {
                    width: 1
                    color: "#cbcbcb"
                    anchors.bottom: parent.bottom
                    anchors.top: parent.top
                    anchors.right: parent.right
                    z:10
                }

                MouseArea {
                    id: ma
                    anchors.fill: parent
                    hoverEnabled: true

                    onClicked: categView.currentIndex = index
                }
            }
        }

        Rectangle {
            id: rectangle2
            y: 8
            height: 2
            color: "#89cdab"
            anchors.right: parent.right
            anchors.left: parent.left
            anchors.bottom: parent.bottom
        }
    }

    GridView {
        id: prodView
        anchors.top: categoriesBar.bottom
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.margins: 20

        model: categView.currentIndex < 0? filterProd : modelCateg.at(categView.currentIndex).productos

        cellWidth: 140
        cellHeight: 140
        clip: true
        delegate: ProductoDelegate {
            name: nombre
            uni: unidades
            prec: precio
            //source: "image://productos/"+idProducto
            //focus: prodView.currentIndex == index

            MouseArea {
                anchors.fill: parent
                onClicked: prodView.currentIndex = index
                onDoubleClicked: parent.add2Venta()
            }

            Rectangle {
                color: "#89cdab"
                opacity: 0.3
                anchors.fill: parent
                visible: parent.focus
            }

            function add2Venta() {
                var i = filterProd.sourceIndex(index)
                mainVenta.addVentaItems(modelProd.at(i))
            }

            KeyNavigation.tab: search1

            Keys.onReturnPressed: add2Venta()
        }

        onCurrentItemChanged: {
            if (!currentItem) return;
            currentItem.forceActiveFocus()
        }
    }

    function moveCurrentIndexDown() { prodView.moveCurrentIndexDown() }
    function moveCurrentIndexUp() { prodView.moveCurrentIndexUp() }
    function moveCurrentIndexLeft() { prodView.moveCurrentIndexLeft() }
    function moveCurrentIndexRight() { prodView.moveCurrentIndexRight() }
}

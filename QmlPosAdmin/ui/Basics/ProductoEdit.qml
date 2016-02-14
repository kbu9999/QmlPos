import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2

import libPos 0.1
import libPos.models 0.1
import MyQuick.FieldPanel 1.0

Item {
    property alias producto: panel.ormObject

    onFocusChanged: if (focus) panel.forceActiveFocus()

    Panel {
        id: panel
        //anchors.fill: parent
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: fotopart.left

        columns: 2
        //spacing: 15
        rowSpacing: 15

        editIcon: "img:rename.png"
        closeIcon: "img:quit.png"

        FieldTextEdit {
            title: "Nombre"
            role: "nombre"
            //editable: false
        }

        FieldComboBox {
            title: "Marca"
            role: "marcas"
            fkrole: "nombre"

            model: OrmMarcasModel { }

            Component.onCompleted: model.load()
        }

        FieldComboBox {
            title: "Categoria"
            role: "categoria"
            fkrole: "nombre"

            model: OrmCategoriaModel { }

            Component.onCompleted: model.load()
        }

        FieldComboBox {
            title: "Unidad de Medida"
            role: "unidadMedida"
            fkrole: "nombre"
            model: OrmUnidadMedidaModel { }

            Component.onCompleted: model.load()
        }

        FieldSpinBox {
            title: "Unidades"
            role: "unidades"
        }

        FieldSpinBox {
            title: "Precio"
            role: "precio"

            decimals: 2
            prefix: "$ "
        }

        FieldSpinBox {
            title: "Costo"
            role: "costo"

            decimals: 2
            prefix: "$ "
        }
    }

    Item {
        id: fotopart
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        width: 130

        Column {
            anchors.fill: parent

            Rectangle {
                width: fotopart.width; height: fotopart.width
                color: "transparent"
                border.color: "black"
                border.width: 1
                anchors.margins: 5

                OrmImage {
                    id: foto
                    anchors.fill: parent
                    pixmap: producto? producto.foto : null
                }
            }

            Row {
                spacing: 10

                SimpleButton {
                    source: "img:open.png"
                    width: 24; height: 24
                    onClicked: {
                        fcon.target = fileDialog
                        fileDialog.title = "Imagen del Producto"
                        fileDialog.open()
                    }

                    Connections {
                        id: fcon
                        ignoreUnknownSignals: true
                        onAccepted: {
                            target = null
                            producto.loadFotoFromFile(fileDialog.fileUrl)
                       }
                    }
                }

                SimpleButton {
                    source: "img:record.png"
                    width: 24; height: 24
                    onClicked: {
                        ccon.target = captDialog
                        captDialog.title = "Capturar"
                        captDialog.open()
                    }
                    Connections {
                        id: ccon
                        ignoreUnknownSignals: true
                        onCaptured: {
                            target = null
                            producto.foto = preview
                            console.log("captura---")
                            console.log(preview)
                       }
                    }
                }
            }
        }

    }

}


import QtQuick 2.2
import QtQuick.Window 2.0
import QtQuick.Controls 1.1
import QtGraphicalEffects 1.0

Window {
    width: 400
    height: 400
    visible: true

    property var obj: mdl_equipos.at(0)

    ListModel {
        id: instalacionModel
        ListElement {
            pos: 0
            index: 0
            type: "INTEGER"
            name: "idEquipo"
            fk: -1
            fk_table: ""
            fk_role: ""
            texto: "ID"
        }
        ListElement {
            pos: 1
            index: 1
            type: "QORM"
            name: "tipoEquipo"
            fk: 0
            fk_table: "TipoEquipo"
            fk_role: "tipoEquipo"
            texto: "Modelo"
        }
        ListElement {
            pos: 3
            index: -1
            type: "STRING"
            name: "mac"
            fk: -1
            fk_table: ""
            fk_role: ""
            texto: "MAC"
        }
        ListElement {
            pos: 3
            index: -1
            type: "STRING"
            name: "ip"
            fk: -1
            fk_table: ""
            fk_role: ""
            texto: "IP"
        }
        ListElement {
            pos: 4
            index: -1
            type: "BOOL"
            name: "propiedad"
            fk: -1
            fk_table: ""
            fk_role: ""
            texto: "Propio"
        }
        ListElement {
            pos: 5
            index: -1
            type: "BOOL"
            name: "isAp"
            fk: -1
            fk_table: ""
            fk_role: ""
            texto: "Access Point"
        }
        ListElement {
            pos: 6
            index: 2
            type: "QORM"
            name: "nt_Red"
            fk: 0
            fk_table: "nt_Red"
            fk_role: "red"
            texto: "Red"
        }
    }

    ListView {
        id: lview
        model: instalacionModel
        anchors.fill: parent
        property int max: 80

        delegate: Item {
            width: 300
            height: 40
            Row {
                anchors.fill: parent

                Text { text: texto; font.bold: true; width: lview.max }
                Loader {
                    id: ldzone
                    width: lview.max
                    property string propname: name
                    property string fkrole: fk_role
                    sourceComponent: fk < 0 ? fieldEdit : fieldShow
                }

                Image {
                    source: "img/rename.png"

                    MouseArea {
                        anchors.fill: parent;
                        onClicked:  ldzone.item.editMode()
                    }
                }
            }
        }
    }

    Component {
        id: fieldShow
        Item {
            id: main
            property var value: obj ? obj[propname][fkrole] : " -- "

            function editMode() {
                clId.visible = !clId.visible
                if (!clId.visible) {
                    clField.selectAll()
                    clField.focus = true
                    if (clField.text.length == 0) clField.showall();
                }
            }

            width: clId.visible ? clId.width : clField.width
            height: clId.visible ? clId.height : clField.height

            Text {
                id: clId;
                text: main.value
                //anchors.verticalCenter: parent.verticalCenter
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
            }

            TextField {
                id: clField
                text: main.value
                //anchors.verticalCenter: parent.verticalCenter
                visible: !clId.visible

                ListModel {
                    id: showModel
                }

                Keys.onEscapePressed: {
                    if (list.height == 0) clId.visible = true;
                    else list.height = 0
                }

                Keys.onReturnPressed: select(menu.currentIndex)

                Rectangle {
                    id: list
                    y: parent.height
                    color: "white"
                    width: parent.width
                    height: parent.visible ? 80 : 0
                    z: 1
                    border.color: "#3eafea"
                    border.width: 1
                    radius: 5

                    ListView {
                        id: menu
                        anchors.fill: parent
                        anchors.margins: 5
                        model: showModel

                        delegate: Item {
                            //anchors.fill: txt

                            Rectangle {
                                id: rect
                                color: parent.ListView.isCurrentItem ? "#3eafea" : "transparent"
                                //color: "transparent"
                                anchors.fill: txt
                            }

                            Text {
                                id: txt
                                width: menu.width
                                text: texto
                                font.italic: true
                            }

                            MouseArea {
                                anchors.fill: txt
                                hoverEnabled: true

                                onExited: rect.color = "transparent"
                                onEntered: rect.color = "#3eafea"
                                onClicked: clField.select(index)
                            }
                        }
                    }

                    Behavior on height { NumberAnimation { duration: 300 } }
                }

                function select(index) {
                    var i = showModel.get(index).pos
                    var o = main.model.at(i);
                    if (!o) return;

                    main.value = o[main.role];
                    //main.selected(o)
                    obj[propname] = o
                    clId.visible = true
                }

                function search(buscar) {
                    showModel.clear()
                    var regexp = new RegExp(buscar, "i")
                    for(var i = 0; i < model.count(); i++)
                    {
                        var o = model.at(i);
                        var dt = o[role];
                        if (dt.match(regexp))
                            showModel.append({texto: dt, pos: i})
                    }
                }

                function showall() {
                    showModel.clear()
                    for(var i = 0; i < model.count(); i++)
                    {
                        var o = model.at(i);
                        var dt = o[role];
                        showModel.append({texto: dt, pos: i})
                    }
                }

                onTextChanged: {
                    if (!visible) return;

                    if (list.height == 0) list.height = 80;

                    if (clField.text.length == 0) clField.showall();
                    else search(clField.text)
                }
            }
        }
    }

    Component {
        id: fieldEdit
        Item {
            id: zone

            property string value: obj ? obj[propname] : " -- "

            width: clId.visible ? clId.width : clField.width
            height: 30

            Text {
                id: clId;
                text: zone.value.length == 0 ? " " : zone.value
                anchors.verticalCenter: parent.verticalCenter
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
            }

            TextField {
                id: clField
                text: zone.value
                anchors.verticalCenter: parent.verticalCenter
                visible: !clId.visible

                Keys.onEscapePressed: showMode()
                Keys.onReturnPressed: showMode()
            }

            function editMode() {
                clId.visible = !clId.visible
                if (!clId.visible) clField.selectAll()
            }

            function showMode() {
                value = clField.text;
                clId.visible = true
            }
        }
    }
}

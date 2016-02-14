import QtQuick 2.2
import QtQuick.Controls 1.3
import QtQuick.Controls.Styles 1.3

import MyQuick 1.0
import Style 1.0 as S
import MyQuick.Columnas 1.0

import libPos.models 0.1

Item {
    id: main
    width: 300
    height: 200
    
    property alias model: filter.sourceModel
    property alias filterColumn: filter.filterKeyColumn
    default property alias data: tbView.data

    function at(row) {
        var i = filter.sourceIndex(row)
        return model.at(i)
    }

    FilterModel {
        id: filter
    }

    Item {
        anchors.fill: parent

        Rectangle {
            id: stackBar
            height: 40
            color: "#d3d3d3"
            clip: true
            anchors.right: parent.right
            anchors.left: parent.left
            anchors.top: parent.top

            Image {
                id: image2
                x: 5
                sourceSize.height: 36
                sourceSize.width: 36
                anchors.verticalCenter: parent.verticalCenter
                fillMode: Image.PreserveAspectFit
                source: "img:home.png"
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

                source: "img:find.png"
                focus: true

                //KeyNavigation.tab: cbCli
                //validator: RegExpValidator { regExp: new RegExp("\\D[^\\+\\-]+|\\d+") }

                onFilterChanged: {
                    var id = parseInt(filter);
                    if (!id) {
                        filter.filterRegExp = new RegExp(filter, 'i')
                        return;
                    }
                }
            }
        }

        TableView {
            id: tbView
            anchors.top: stackBar.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom

            model: filter

            style: S.TableViewStyle {
                id: stl
            }

            ButtomColumn {
                source: "img:/add.png"
                onClicked: {
                    var i = filter.sourceIndex(row)
                    model.insertRows(i, 1)
                }
            }

            ButtomColumn {
                source: "img:/quit.png"
                onClicked: {
                    var i = filter.sourceIndex(row)
                    model.removeRows(i, 1)
                }
            }

            ButtomColumn {
                source: "img:/save.png"
                onClicked: {
                    var s = main.at(row)
                    s.save()
                }
            }
            
            
        }
    }
}

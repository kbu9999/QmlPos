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
    //property var model
    property alias filterColumn: filter.filterKeyColumn
    default property alias data: tbView.data

    function at(row) {
        var i = filter.sourceIndex(row)
        return model.at(i)
    }

    FilterModel {
        id: filter
        sourceModel: main.model
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

            Row {
                anchors.fill: parent

                IconButton {
                    width: 32; height: 32
                    anchors.verticalCenter: parent.verticalCenter
                    source:  "img:/add.png"
                    color: "#393939"
                    hoveredColor: "#89cdab"
                    hoverEnabled: true
                    onClicked: {
                        var i = model.count() - 1
                        model.insertRows(i, 1)
                    }
                }

                IconButton {
                    width: 32; height: 32
                    anchors.verticalCenter: parent.verticalCenter
                    source:  "img:/quit.png"
                    color: "#393939"
                    hoveredColor: "#89cdab"
                    hoverEnabled: true
                    onClicked: {
                        tbView.selection.forEach( function(row) {
                             var i = filter.sourceIndex(row)
                             model.removeRows(i, 1)
                        });
                    }
                }

                IconButton {
                    width: 32; height: 32
                    anchors.verticalCenter: parent.verticalCenter
                    source:  "img:/save.png"
                    color: "#393939"
                    hoveredColor: "#89cdab"
                    hoverEnabled: true
                    onClicked:  model.submitAll()
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
            
        }
    }
}

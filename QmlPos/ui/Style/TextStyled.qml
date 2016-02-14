import QtQuick 2.0
import QtQuick.Controls 1.1

Text {
    property bool selected: false
    property color selectedColor: "white"

    verticalAlignment: Text.AlignVCenter

    font.pointSize: 10
    font.family: "BellGothic BT"

    color: selected? selectedColor : "#232323"
    style: selected? Text.Raised : Text.Normal
    styleColor: "white"
}

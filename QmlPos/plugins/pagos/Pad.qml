import QtQuick 2.0
import QtQuick.Controls 1.2
import Style 1.0 as S

Grid {
    columns: 4
    spacing: -1

    clip: true

    Component {
        id: btstl
        S.ButtonStyle { }
    }

    Button { style: btstl; text: "7"; width: 40; height: 40 }
    Button { style: btstl; text: "8"; width: 40; height: 40 }
    Button { style: btstl; text: "9"; width: 40; height: 40 }
    Button { id:bQty; style: btstl; text: "Cant"; width: 40; height: 40; checkable: true }
    Button { style: btstl; text: "4"; width: 40; height: 40 }
    Button { style: btstl; text: "5"; width: 40; height: 40 }
    Button { style: btstl; text: "6"; width: 40; height: 40 }
    Button { id:bPr; style: btstl; text: "Pr"; width: 40; height: 40; checkable: true  }
    Button { style: btstl; text: "1"; width: 40; height: 40 }
    Button { style: btstl; text: "2"; width: 40; height: 40 }
    Button { style: btstl; text: "3"; width: 40; height: 40 }
    Button { id: bDisq; style: btstl; text: "D"; width: 40; height: 40; checkable: true  }
    Button { style: btstl; text: "+/-"; width: 40; height: 40 }
    Button { style: btstl; text: "0"; width: 40; height: 40 }
    Button { style: btstl; text: "."; width: 40; height: 40 }
    Button { style: btstl; text: "Cl"; width: 40; height: 40 }

    ExclusiveGroup {
        id: excl
    }

    Component.onCompleted: {
        excl.bindCheckable(bQty)
        excl.bindCheckable(bPr)
        excl.bindCheckable(bDisq)
    }
}

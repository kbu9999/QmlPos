import QtQuick 2.2
import QtQuick.Controls 1.1

import "../models" as M

Item {
    id: item1
    width: 300
    height: 400

    Rectangle {
        color: "#393939"
        anchors.fill: parent
        opacity: 0.65
    }

    M.Config {
        id: conf

        Component.onCompleted: {
            if (conf.db_user.length == 0) return;
            if (conf.db_pass.length == 0) return;
            if (conf.db_database.length == 0) return;
            if (conf.db_host.length == 0) return;

            LoginHandler.connectDB(conf.db_user, conf.db_pass, conf.db_database, conf.db_host)
            if (LoginHandler.connected) window.showConfig = false
        }
    }

    Grid {
        width: 300
        height: 300
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        spacing: 20
        columns: 2

        verticalItemAlignment: Grid.AlignVCenter

        Text {
            id: luser
            x: 121
            y: 110
            text: "DB Usuario"
            font.bold: true
        }

        TextField {
            text: conf.db_user

            onEditingFinished: conf.db_user = text

            KeyNavigation.tab: fpass
        }

        Text {
            id: lpass
            x: 137
            y: 146
            text: "DB Contraseña"
            font.bold: true
        }

        TextField {
            id: fpass
            text: conf.db_pass
            echoMode: TextInput.Password

            onEditingFinished: conf.db_pass = text

            KeyNavigation.tab: fname
        }

        Text {
            id: lname
            x: 128
            y: 192
            text: "DB Nombre"
            font.bold: true
        }

        TextField {
            id: fname
            text: conf.db_database

            onEditingFinished: conf.db_database = text

            KeyNavigation.tab: fhost
        }

        Text {
            id: lhost
            x: 121
            y: 251
            text: "DB Host"
            font.bold: true
        }

        TextField{
            id: fhost
            text: conf.db_host

            onEditingFinished: conf.db_host = text

            KeyNavigation.tab: bcon
        }

        Button {
            id: bcon
            text: "Conectar"

            onClicked: {
                LoginHandler.connectDB(conf.db_user, conf.db_pass, conf.db_database, conf.db_host)
                if (LoginHandler.connected) window.showConfig = false
            }
        }

    }

}

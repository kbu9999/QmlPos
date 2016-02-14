TEMPLATE = app

QT += qml quick sql printsupport

SOURCES += main.cpp
#RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH = ui

# Default rules for deployment.
include(deployment.pri)

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../libRCISecure/release/ -lRCISecure
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../libRCISecure/debug/ -lRCISecure
else:unix: LIBS += -L$$OUT_PWD/../../libRCISecure/ -lRCISecure

INCLUDEPATH += $$PWD/../../libRCISecure
DEPENDPATH +=  $$PWD/../../libRCISecure

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../QOrm/release/ -lQOrm
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../QOrm/debug/ -lQOrm
else:unix: LIBS += -L$$OUT_PWD/../../QOrm/ -lQOrm

INCLUDEPATH += $$PWD/../../QOrm
DEPENDPATH += $$PWD/../../QOrm

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../libPos/release/ -llibPos
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../libPos/debug/ -llibPos
else:unix: LIBS += -L$$OUT_PWD/../libPos/ -llibPos

INCLUDEPATH += $$PWD/../libPos
DEPENDPATH += $$PWD/../libPos

DISTFILES += \
    models/Config.qml \
    ui/DetalleDelegate.qml \
    ui/PanelConfig.qml \
    ui/ProductoDelegate.qml \
    ui/Style/TextStyled.qml \
    ui/Style/TableViewStyle.qml \
    ui/MyQuick/Search.qml \
    ui/MyQuick/FieldButton.qml \
    ui/MyQuick/FieldCal.qml \
    ui/MyQuick/FieldCheck.qml \
    ui/MyQuick/FieldEdit.qml \
    ui/MyQuick/FieldSearch.qml \
    ui/MyQuick/IconButton.qml \
    ui/MyQuick/OpButton.qml \
    ui/PosWindow.qml \
    ui/main.qml \
    ui/ProductosView.qml \
    ui/DetalleView.qml \
    ui/Pad.qml \
    ui/MenuView.qml \
    plugins/pagos/Efectivo.qml

#-------------------------------------------------
#
# Project created by QORMMAKE
#
#-------------------------------------------------

QT       += sql printsupport
QT       -= gui

TARGET = libPos
TEMPLATE = lib
CONFIG += c++11

DEFINES += QORMQMLPOS_LIBRARY

SOURCES +=  \
    QOrm/qormcaja.cpp  \
    QOrm/qormcategoria.cpp  \
    QOrm/qormclientes.cpp  \
    QOrm/qormcompra.cpp  \
    QOrm/qormcompraitems.cpp  \
    QOrm/qormformapago.cpp  \
    QOrm/qormhaciento.cpp  \
    QOrm/qormlogs.cpp  \
    QOrm/qormmarcas.cpp  \
    QOrm/qormpago.cpp  \
    QOrm/qormproductos.cpp  \
    QOrm/qormproveedor.cpp  \
    QOrm/qormunidadmedida.cpp  \
    #QOrm/qormusuarios.cpp  \
    QOrm/qormventaitems.cpp  \
    QOrm/qormventas.cpp \ 
    qmlposimageprovide.cpp \
    qormfiltermodel.cpp \
    rciprint.cpp \
    qmlposimagesaver.cpp

HEADERS +=  \
    QOrm/qormcaja.h  \
    QOrm/qormcategoria.h  \
    QOrm/qormclientes.h  \
    QOrm/qormcompra.h  \
    QOrm/qormcompraitems.h  \
    QOrm/qormformapago.h  \
    QOrm/qormhaciento.h  \
    QOrm/qormlogs.h  \
    QOrm/qormmarcas.h  \
    QOrm/qormpago.h  \
    QOrm/qormproductos.h  \
    QOrm/qormproveedor.h  \
    QOrm/qormunidadmedida.h  \
    QOrm/qormventaitems.h  \
    QOrm/qormventas.h  \
    libPos.h \
    rciprint.h \
    qmlposimageprovide.h \
    qormfiltermodel.h \
    qmlposimagesaver.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../QOrm/release/ -lQOrm
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../QOrm/debug/ -lQOrm
else:unix: LIBS += -L$$OUT_PWD/../../QOrm/ -lQOrm

INCLUDEPATH += $$PWD/../../QOrm
DEPENDPATH += $$PWD/../../QOrm

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../libRCISecure/release/ -lRCISecure
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../libRCISecure/debug/ -lRCISecure
else:unix: LIBS += -L$$OUT_PWD/../../libRCISecure/ -lRCISecure

INCLUDEPATH += $$PWD/../../libRCISecure
DEPENDPATH += $$PWD/../../libRCISecure

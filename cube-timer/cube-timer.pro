QT += qml quick quickcontrols2 sql

CONFIG += c++11

CONFIG(debug, debug|release){
CONFIG += qml_debug
}

HEADERS += \
    cubetimer.h \
    viewcontroller.h \
    pages/mainpageview.h \
    defines.h \
    dbhandle.h \
    pages/timespageview.h \
    pages/viewbase.h \
    serv/requestmapper.h

SOURCES += main.cpp \
    cubetimer.cpp \
    viewcontroller.cpp \
    pages/mainpageview.cpp \
    dbhandle.cpp \
    pages/timespageview.cpp \
    pages/viewbase.cpp \
    serv/requestmapper.cpp

RESOURCES += qml.qrc

INCLUDEPATH += pages\

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


ios {
#    QMAKE_INFO_PLIST = ios/Info.plist
    ios_icon.files = $$files($$PWD/ios/Icon-*.png)
    QMAKE_BUNDLE_DATA += ios_icon
}

include(../libs/QtWebApp/httpserver/httpserver.pri)

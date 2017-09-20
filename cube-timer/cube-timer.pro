QT += qml quick quickcontrols2 sql

CONFIG += c++11

CONFIG(debug, debug|release){
CONFIG += qml_debug
}

HEADERS += \
    $$PWD/cubetimer.h \
    $$PWD/viewcontroller.h \
    $$PWD/pages/mainpageview.h \
    $$PWD/defines.h \
    $$PWD/dbhandle.h \
    $$PWD/pages/timespageview.h \
    $$PWD/pages/viewbase.h

SOURCES += $$PWD/main.cpp \
    $$PWD/cubetimer.cpp \
    $$PWD/viewcontroller.cpp \
    $$PWD/pages/mainpageview.cpp \
    $$PWD/dbhandle.cpp \
    $$PWD/pages/timespageview.cpp \
    $$PWD/pages/viewbase.cpp

RESOURCES += $$PWD/qml.qrc

INCLUDEPATH += $$PWD/pages\

#ios {
#    QMAKE_INFO_PLIST = ios/Info.plist
#    ios_icon.files = $$files($$PWD/ios/Icon-*.png)
#    QMAKE_BUNDLE_DATA += ios_icon
#}

mac {
    # Since things are buried in the app folder, we'll copy configs there.
    MediaFiles.files = \
        $$PWD/config/global.json \
        $$PWD/config/routes.json

    ios{
        MediaFiles.path = config
    }
    else{
        MediaFiles.path = Contents/MacOS/config
    }
    QMAKE_BUNDLE_DATA += MediaFiles
}

include($$PWD/config/config.pri)
include($$PWD/../libs/QttpServer/core.pri)

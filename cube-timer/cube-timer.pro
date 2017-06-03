QT += qml quick quickcontrols2

CONFIG += c++11

SOURCES += main.cpp \
    cubetimer.cpp \
    viewcontroller.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    cubetimer.h \
    viewcontroller.h

ios {
    QMAKE_INFO_PLIST = ios/Info.plist
    ios_icon.files = $$files($$PWD/ios/Icon-*.png)
    QMAKE_BUNDLE_DATA += ios_icon
}

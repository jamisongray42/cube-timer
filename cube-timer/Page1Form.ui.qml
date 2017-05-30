import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

import "qrc:///components/"

Item {
    height: 1136
    property alias timeCounter: timeCounter
    property alias actionButton: actionButton

    ColumnLayout {
        id: columnLayout
        anchors.rightMargin: 100
        anchors.leftMargin: 100
        anchors.fill: parent

        TimeCounter {
            id: timeCounter
            Layout.fillWidth: true
            opacity: 1
        }


        Button {
            id: actionButton
            text: qsTr("Start")
            Layout.fillWidth: true
        }


    }
    state: "start"
    states: [
        State {
            name: "stop"

            PropertyChanges {
                target: actionButton
                text: qsTr("Stop")
            }
        },
        State {
            name: "reset"
            PropertyChanges {
                target: actionButton
                text: qsTr("Reset")
            }
        },
        State {
            name: "start"
            PropertyChanges {
                target: actionButton
                text: qsTr("Start")
            }
        }
    ]
}

import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1

import "../components"

Item {
    id: item1
    property alias actionButton: actionButton
    property alias progressBar: progressBar
    property int pad: 24

    property alias timeCounter: timeCounter
    property alias multiArea: multiArea

    TimeCounter {
        id: timeCounter
        height: 100
        fontPointSize: 50
        anchors.topMargin: -3 * pad
        anchors.right: parent.right
        anchors.rightMargin: pad
        anchors.left: parent.left
        anchors.leftMargin: pad
        anchors.top: parent.verticalCenter
        opacity: 1
    }

    ProgressBar {
        id: progressBar
        anchors.top: timeCounter.bottom
        anchors.topMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: pad
        anchors.left: parent.left
        anchors.leftMargin: pad
        value: 0
        visible: value != 0
    }

    Button {
        id: actionButton
        x: 24
        y: 620
        height: 100
        text: qsTr("Start")
        anchors.right: parent.right
        anchors.rightMargin: 24
        anchors.left: parent.left
        anchors.leftMargin: 24
        anchors.top: progressBar.bottom
        anchors.topMargin: 24
        z: 10
        checked: false

        MultiPointTouchArea{
            id: multiArea
            anchors.fill: parent
        }
    }

    state: "base"
    states: [
        State {
            name: "base"
        },
        State {
            name: "started"

            PropertyChanges {
                target: actionButton
                text: qsTr("Stop")
            }
        },
        State {
            name: "stopped"

            PropertyChanges {
                target: actionButton
                text: qsTr("Reset")
            }
        }
    ]
}

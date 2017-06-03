import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1

import "../components"

Item {
    id: item1
    property int pad: 24

    Flow {
        id: flow1
        spacing: 24
        anchors.rightMargin: 24
        anchors.leftMargin: 24
        anchors.bottomMargin: 24
        anchors.topMargin: 24
        anchors.fill: parent

        Button {
            id: button
            text: qsTr("some time")
        }

        Button {
            id: button1
            text: qsTr("some time")
        }

        Button {
            id: button2
            text: qsTr("some time")
        }

        Button {
            id: button3
            text: qsTr("some time")
        }

        Button {
            id: button4
            text: qsTr("some time")
        }

        Button {
            id: button5
            text: qsTr("some time")
        }

        Button {
            id: button6
            text: qsTr("some time")
        }

        Button {
            id: button7
            text: qsTr("some time")
        }

        Button {
            id: button8
            text: qsTr("some time")
        }

        Button {
            id: button9
            text: qsTr("some time")
        }
    }
}

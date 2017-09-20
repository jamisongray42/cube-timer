import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1

import "../components"

Item {
    id: item1
    property int pad: 24

    BusyIndicator {
        id: busyIndicator
        anchors.fill: parent
    }

    Label {
        id: label
        text: qsTr("About")
        font.pointSize: 24
        horizontalAlignment: Text.AlignHCenter
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 24
    }
}

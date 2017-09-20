import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1

import "../components"

Item {
    id: item1
    property int pad: 24
    property alias runListModel: runListModel

    ListModel{
        id: runListModel
        ListElement{runId: 1; runTime: "runTime"; dateTime: "dateTime"}
        ListElement{runId: 2; runTime: "runTime"; dateTime: "dateTime"}
        ListElement{runId: 3; runTime: "runTime"; dateTime: "dateTime"}
    }

    Flickable {
        id: flickable
        flickableDirection: Flickable.VerticalFlick
        ScrollBar.vertical: ScrollBar{}
        anchors.fill: parent
        contentHeight: recordFlow.implicitHeight + 2 * pad

        Flow {
            id: recordFlow
            x: 24
            y: 24
            spacing: 24
            anchors.rightMargin: 24
            anchors.leftMargin: 24
            anchors.bottomMargin: 24
            anchors.topMargin: 24
            anchors.fill: parent

            Repeater{
                id: repeater
                model: runListModel
                delegate: Button{
                    width: (root.width - pad * 4) / 3 - 0.5
                    text: runTime + "\n" + dateTime
                    //                onClicked: console.log("runId", runId)
                }
            }

        }
    }

}

import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1

import "../components"

Item {
    id: item1
    property int pad: 24

    Column {
        id: column
        anchors.rightMargin: 24
        anchors.leftMargin: 24
        anchors.bottomMargin: 24
        anchors.topMargin: 24
        spacing: 24
        anchors.fill: parent

        Button {
            id: button
            text: qsTr("Button")
        }

        Slider {
            id: slider
            value: 0.5
        }

        SpinBox {
            id: spinBox
        }

        TextField {
            id: textField
            text: qsTr("Text Field")
        }

        RadioButton {
            id: radioButton
            text: qsTr("Radio Button")
        }

        CheckBox {
            id: checkBox
            text: qsTr("Check Box")
        }
    }
}

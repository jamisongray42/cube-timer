import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Controls.Material 2.1
import QtQuick.Layouts 1.0

import "pages"

ApplicationWindow {
    visible: true
    width: 640
    height: 1136
    title: qsTr("Cube Timer")

    Material.theme: Material.Dark

    header: ToolBar{
        ToolButton{
            text: "\u22EE"
            onClicked: mainMenu.open()
            font.pointSize: 20
            Menu{
                id: mainMenu
                MenuItem{
                    text: "Menu Item1"
                }
                MenuSeparator{ }
                MenuItem{
                    text: "Menu Item2"
                }
            }
        }
    }

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex
        interactive: false

        Page1 {
        }

        Page {
            Label {
                text: qsTr("Second page")
                anchors.centerIn: parent
            }
        }
    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex
        TabButton {
            text: qsTr("First")
        }
        TabButton {
            enabled: false
            text: qsTr("Second")
        }
    }
}

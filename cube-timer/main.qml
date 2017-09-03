import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Controls.Material 2.1
import QtQuick.Layouts 1.1

import "pages"

ApplicationWindow {
    id: root
    visible: true
    width: 640
    height: 1136
    title: qsTr("Cube Timer")

    signal switchedToPage(int index)

    Material.theme: Material.Dark
    Material.accent: Material.LightBlue

    header: ToolBar{
        id: toolBar
        Material.primary: Material.LightBlue

        RowLayout{
            ToolButton{
                text: "\u2193"
                visible: stackView.depth > 2
                font.pointSize: 24
                onClicked: {
                    while(stackView.depth > 1){
                        stackView.pop()
                    }
                    drawerListView.currentIndex = 0
                }
            }
            ToolButton{
                text: "\u2190"
                visible: stackView.depth > 1
                font.pointSize: 24
                onClicked: {
                    stackView.pop()
                    drawerListView.currentIndex = -1 // TODO maybe keep history of these
                }
            }
            ToolButton{
                text: "\u2630"
                font.pointSize: 24
                onClicked: drawer.open()
            }
        }
    }

    Label{
        z:10
        id: toolBarTitleLabel
        anchors.centerIn: toolBar
        font.pixelSize: 24
        text: stackView.currentItem.title
    }

    Drawer {
        id: drawer
        width: 0.66 * parent.width
        height: parent.height

        ListView{
            id: drawerListView
            anchors.fill: parent
            currentIndex: 0

            delegate: ItemDelegate{
                width: parent.width
                text: model.title
                highlighted: ListView.isCurrentItem
                onClicked: {
                    drawerListView.currentIndex = index

                    if(stackView.currentItem.title !== model.title){
                        if(model.title === "Timer")      stackView.push(mainPage)
                        else if(model.title === "View Times") stackView.push(viewTimesPage)
                        else if(model.title === "Settings") stackView.push(settingsPage)
                        else if(model.title === "About") stackView.push(aboutPage)
                    }

                    switchedToPage(index)
                    drawer.close()
                }
            }

            model: ListModel{
                ListElement{ title: "Timer" }
                ListElement{ title: "View Times" }
                ListElement{ title: "Settings" }
                ListElement{ title: "About"}
            }
            ScrollIndicator.vertical: ScrollIndicator{}
        }

    }

    StackView{
       id: stackView
       anchors.fill: parent
       initialItem: mainPage
       property int fadeDur: 200
       pushEnter: Transition {
           PropertyAnimation {
               property: "opacity"
               from: 0
               to:1
               duration: stackView.fadeDur
           }
       }
       pushExit: Transition {
           PropertyAnimation {
               property: "opacity"
               from: 1
               to:0
               duration: stackView.fadeDur
           }
       }
       popEnter: Transition {
           PropertyAnimation {
               property: "opacity"
               from: 0
               to:1
               duration:stackView.fadeDur
           }
       }
       popExit: Transition {
           PropertyAnimation {
               property: "opacity"
               from: 1
               to:0
               duration: stackView.fadeDur
           }
       }
    }

    MainPage{ id: mainPage;           visible: false}
    ViewTimesPage{ id: viewTimesPage; visible: false}
    SettingsPage{ id: settingsPage;   visible: false}
    AboutPage{ id: aboutPage;         visible: false}

}

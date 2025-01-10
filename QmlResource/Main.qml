import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Imagine 2.12


Window {
    width: 960
    height: 680
    visible: true
    title: qsTr("Hello World")

    Column {
        id: mainPage
        anchors.fill: parent

        TabBar {
            id: mainBar
            height: 60
            currentIndex:1
            contentHeight : 60
            WWTabButton {
                text: qsTr("Personal")
                onClicked: {
                    personaliaPage.visible = true
                    diaryPage.visible = false
                    itemsPage.visible = false
                    recipePage.visible = false
                }
            }
            WWTabButton {
                text: qsTr("Diary")
                onClicked: {
                    personaliaPage.visible = false
                    diaryPage.visible = true
                    itemsPage.visible = false
                    recipePage.visible = false
                }
            }
            WWTabButton {
                text: qsTr("Items")
                onClicked: {
                    personaliaPage.visible = false
                    diaryPage.visible = false
                    itemsPage.visible = true
                    recipePage.visible = false
                }
            }
            WWTabButton {
                text: qsTr("Recipes")
                onClicked: {
                    personaliaPage.visible = false
                    diaryPage.visible = false
                    itemsPage.visible = false
                    recipePage.visible = true
                }
            }
        } // header: TabBar

        PersonaliaPage {
            id: personaliaPage
            height: parent.height - mainBar.height
            width: parent.width
            visible: false
        }
        DiaryPage {
            id: diaryPage
            height: parent.height - mainBar.height
            width: parent.width
        }
        ItemsPage {
            id: itemsPage
            height: parent.height - mainBar.height
            width: parent.width
        }
        RecipePage {
            id: recipePage
            height: parent.height - mainBar.height
            width: parent.width
        }

    } // Column
} // Window

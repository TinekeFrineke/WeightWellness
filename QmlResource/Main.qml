import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Imagine 2.12


Window {
    width: 960
    height: 680
    visible: true
    title: qsTr("Control your weight")

    Loader {
        id: pageLoader
        anchors.fill: parent
        anchors.topMargin: mainBar.height
        sourceComponent: diaryPage
    }

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
                    pageLoader.sourceComponent = personaliaPage
                }
            }
            WWTabButton {
                text: qsTr("Diary")
                onClicked: {
                    pageLoader.sourceComponent = diaryPage
                }
            }
            WWTabButton {
                text: qsTr("Items")
                onClicked: {
                    pageLoader.sourceComponent = itemsPage
                }
            }
            WWTabButton {
                text: qsTr("Recipes")
                onClicked: {
                    pageLoader.sourceComponent = recipePage
                }
            }
        } // header: TabBar

        Component {
            id: personaliaPage
            PersonaliaPage {
                height: parent.height - mainBar.height
                width: parent.width
            }
        }
        Component {
            id: diaryPage
            DiaryPage {
                height: parent.height - mainBar.height
                width: parent.width
            }
        }
        Component {
            id: itemsPage
            ItemsPage {
                height: parent.height - mainBar.height
                width: parent.width
            }
        }
        Component {
            id: recipePage
            RecipePage {
                height: parent.height - mainBar.height
                width: parent.width
            }
        }
    } // Column
} // Window

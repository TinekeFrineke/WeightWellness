import QtQuick
import QtQuick.Layouts

Rectangle {
    id: itemsPage
    color: "#ffff99"

    ColumnLayout {
        anchors.fill: parent
        // This rectangle contains the actual page contents. It also pushes the
        // button bar to the bottom
        Rectangle {
            id: diaryMain
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.margins: 20

            ColumnLayout {
                height: parent.height
                spacing: 10

                Rectangle {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.preferredWidth: diaryMain.width - Layout.leftMargin - Layout.rightMargin
                    color: "#ffff99"

                    FoodDefinitionList {
                        id: foodListView
                        model: FoodDefinitionListModel
                        anchors.fill: parent
                    }
                }


            } // ColumnLayout
        } //Rectangle

        RowLayout {
            id: buttonBarId
            Layout.fillWidth: true
            Layout.preferredHeight : WWRowLayout.buttonBarHeight
            spacing: 0

            WWButton {
                id: addButton
                text: "&Add"
                Layout.fillWidth: true
                Layout.preferredHeight: buttonBarId.Layout.preferredHeight
            }

            WWButton {
                id: editButton
                text: "&Edit"
                Layout.fillWidth: true
                Layout.preferredHeight: buttonBarId.Layout.preferredHeight
            }

            WWButton {
                id: deleteButton
                text: "&Delete"
                Layout.fillWidth: true
                Layout.preferredHeight: buttonBarId.Layout.preferredHeight
            }
        } // RowLayout
    } // ColumnLayout
}

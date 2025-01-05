import QtQuick
import QtQuick.Layouts

import "controls" as WW


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
            color: "#ffff99"

            ColumnLayout {
                height: parent.height
                spacing: 10

                Rectangle {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.preferredWidth: diaryMain.width - Layout.leftMargin - Layout.rightMargin
                    color: "#ffff99"
                    FoodDefinitionModel {
                        id: foodModel
                    }

                    FoodDefinitionList {
                        id: foodListView
                        model: foodModel
                        anchors.fill: parent
                    }
                }


            } // ColumnLayout
        } //Rectangle

        RowLayout {
            id: buttonBarId
            Layout.fillWidth: true
            Layout.preferredHeight : 40
            spacing: 0

            WW.Button {
                id: addButton
                text: "&Add"
                Layout.fillWidth: true
                Layout.preferredHeight: buttonBarId.Layout.preferredHeight
            }

            WW.Button {
                id: editButton
                text: "&Edit"
                Layout.fillWidth: true
                Layout.preferredHeight: buttonBarId.Layout.preferredHeight
            }

            WW.Button {
                id: deleteButton
                text: "&Delete"
                Layout.fillWidth: true
                Layout.preferredHeight: buttonBarId.Layout.preferredHeight
            }
        } // RowLayout
    } // ColumnLayout
}

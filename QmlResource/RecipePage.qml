import QtQuick
import QtQuick.Layouts

// pragma ComponentBehavior: Bound

Rectangle {
    id: itemsPage
    color: "#ccccff"

    ColumnLayout {
        anchors.fill: parent
        // This rectangle contains the actual page contents. It also pushes the
        // button bar to the bottom
        Rectangle {
            id: diaryMain
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.margins: 20
            color: "#ccccff"

            ColumnLayout {
                height: parent.height
                spacing: 10
                ListModel {
                    id: foodModel

                    ListElement { name: "Spaghetti"; points: 52 }
                    ListElement { name: "Macaroni"; points: 89 }
                    ListElement { name: "Muesli"; points: 402 }
                }

                ListView {
                    id: recipeListView
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.preferredHeight: 400
                    Layout.preferredWidth: diaryMain.width - Layout.leftMargin - Layout.rightMargin
                    model: RecipeListModel
                    // Define the header
                    header: RowLayout {
                        height: WWListView.itemHeight // Set a fixed height for the header
                        anchors.left: parent.left
                        anchors.right: parent.right

                        WWLabel {
                            text: "Name"
                            font.bold: true
                            Layout.preferredWidth: 4 // Match proportions with rows
                            Layout.fillWidth: true
                            verticalAlignment: Text.AlignVCenter
                        }
                        WWLabel {
                            text: "Points/portion"
                            font.bold: true
                            Layout.preferredWidth: 1 // Match proportions with rows
                            Layout.fillWidth: true
                            horizontalAlignment: Text.AlignRight
                            verticalAlignment: Text.AlignVCenter
                        }
                    }
                    delegate: Item {
                        width: ListView.view.width // Match the width of the ListView
                        height: WWListView.itemHeight // Fixed row height

                        RowLayout {
                            anchors.fill: parent
                            spacing: 10

                            WWLabel {
                                text: model.name
                                Layout.preferredWidth: 4
                                Layout.fillWidth: true
                                elide: Text.ElideRight
                            }
                            WWLabel {
                                text: model.points
                                horizontalAlignment: Text.AlignRight
                                Layout.preferredWidth: 1
                                Layout.fillWidth: true
                            }
                        }
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

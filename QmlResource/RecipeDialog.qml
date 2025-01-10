import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Dialog {

    property string name

    id: recipeDialog
    title: "Title"
    width: 650
    height: 550
    modal: true

    header : WWLabel {
        text: "Recipe Item"
    }

    background: Rectangle {
        anchors.fill: parent
        color: "lightgreen"
    }

    ColumnLayout {
        Layout.fillHeight: true
        RowLayout {
            Layout.fillWidth: true

            WWLabel {
                Layout.preferredWidth: 100
                text: "Name"
            }
            WWTextField {
                id: nameId
                Layout.preferredWidth: 300
                Layout.preferredHeight: 40
            }
        } // RowLayout

        Component {
            id: delegateId
            Rectangle {
                id: rectangleId
                width: parent.width  // Remember to specify these sizes or you'll have problems
                height: WWListView.itemHeight
                color: "beige"
                border.color: "yellowgreen"
                radius: 1

                RowLayout {
                    Layout.fillWidth: true
                    Layout.preferredWidth: 400
                    WWLabel {
                        id: textId
                        Layout.preferredWidth: 140
                        text: model.name
                        font.pointSize: 16
                    }

                    WWLabel {
                        horizontalAlignment: Text.AlignRight
                        Layout.leftMargin: 140
                        Layout.alignment : Qt.AlignRight
                        id: pointsId
                        text: model.points
                        font.pointSize: 16
                    }
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        console.log("Clicked on: " + model.name);
                    }
                }
            }
        }

        ListModel {
            id: foodModel

            ListElement { name: "Spaghetti"; points: 52 }
            ListElement { name: "Couscous"; points: 89 }
            ListElement { name: "Pastei Tutup"; points: 402 }
        }

        ListView {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.margins: 10

            id: foodListView
            Layout.preferredHeight: 300
            Layout.preferredWidth: recipeDialog.width - Layout.leftMargin - Layout.rightMargin
            model: foodModel
            delegate: delegateId

            header: RowLayout {
                Layout.fillWidth: true
                Layout.preferredWidth: 400
                WWLabel {
                    id: headerNameId
                    Layout.preferredWidth: 140
                    text: "Name"
                    font.pointSize: 16
                }

                WWLabel {
                    id: headerPointsId
                    Layout.fillWidth: true
                    Layout.leftMargin: 140
                    horizontalAlignment: Text.AlignRight
                    text: "Points"
                    font.pointSize: 16
                }
            }
        } // RowLayout

        RowLayout {
            Layout.fillWidth: true

            WWLabel {
                Layout.preferredWidth: 100
                text: "Portions"
            }
            WWTextField {
                id: portionsId
                Layout.preferredWidth: 50
                Layout.preferredHeight: 40
            }
            WWLabel {
                Layout.preferredWidth: 100
                text: "Points"
            }
            WWTextField {
                id: pointsId
                Layout.preferredWidth: 70
                Layout.preferredHeight: 40
            }
        } // RowLayout
    } // ColumnLayout

    footer : Rectangle {
        id: footerId
        width: parent.width
        height: 40
        color: "green"

        ColumnLayout {
            anchors.fill: parent
            RowLayout {
                id: footerId2
                Layout.minimumHeight: 40
                Layout.fillWidth: true
                spacing: 0
                WWButton {
                    Layout.fillWidth: true
                    Layout.minimumHeight: footerId2.Layout.minimumHeight
                    text: "Ok"
                    onClicked: {
                       recipeDialog.accept()
                    }
                }
                WWButton {
                    Layout.fillWidth : true
                    Layout.minimumHeight: footerId2.Layout.minimumHeight
                    text: "Cancel"
                    onClicked: {
                       recipeDialog.reject()
                    }
                }
            }
        }
    }

    anchors.centerIn: parent

    function onAccepted() {
        console.log("Ok clicked")
    }

    function onRejected() {
        console.log("Cancel clicked")
    }
}

import QtQuick
import QtQuick.Layouts


Rectangle {
    signal dayMin()
    signal dayPlus()

    id: diaryPage
    color: "lightblue"

    ColumnLayout {
        anchors.fill: parent
        // This rectangle contains the actual page contents. It also pushes the
        // WWButton bar to the bottom
        Rectangle {
            id: diaryMain
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.margins: 20
            color: "lightblue"

            ColumnLayout {
                id: mainColumn
                height: parent.height
                spacing: 10

                RowLayout {
                    spacing: 10

                    WWLabel {
                        text: "Day"
                    }
                    RowLayout {
                        spacing: 0
                        WWButton {
                            Layout.minimumWidth: 30
                            Layout.minimumHeight: 30
                            text: "-"
                            onClicked: diaryPage.dayMin()
                        }
                        WWTextField {
                            id: dayId
                            Layout.preferredWidth: 100
                            Layout.preferredHeight: 40
                        }
                        WWButton {
                            Layout.minimumWidth: 30
                            Layout.minimumHeight: 30
                            text: "+"
                            onClicked: diaryPage.dayPlus()
                        }
                    }
                    WWLabel {
                        text: "Week start"
                    }
                    WWTextField {
                        id: weekStartId
                        Layout.preferredWidth: 100
                        Layout.preferredHeight: 40
                    }
                    WWLabel {
                        text: "Week end"
                    }
                    WWTextField {
                        id: weekEndId
                        Layout.preferredWidth: 100
                        Layout.preferredHeight: 40
                    }
                }
                RowLayout {
                    spacing: 10
                    Layout.preferredHeight: 40
                    Layout.fillWidth: true
                    WWLabel {
                        text: "Strategy"
                    }
                    WWTextField {
                        id: strategyId
                        Layout.preferredWidth: 100
                        Layout.preferredHeight: 40
                    }
                    WWLabel {
                        text: "Weight"
                    }
                    WWTextField {
                        id: weightId
                        validator: DoubleValidator {
                            bottom: 0
                            top: 9999
                            decimals: 2
                        }
                        Layout.preferredWidth: 80
                        Layout.preferredHeight: 40
                    }
                    WWLabel {
                        text: "Points"
                    }
                    WWTextField {
                        id: pointsId
                        validator: DoubleValidator {}
                        Layout.preferredWidth: 80
                        Layout.preferredHeight: 40
                    }
                    WWLabel {
                        text: "Free bonus"
                    }
                    WWTextField {
                        id: freeBonusId
                        validator: DoubleValidator {}
                        Layout.preferredWidth: 80
                        Layout.preferredHeight: 40
                    }
                } // RowLayout

                RowLayout {
                    spacing: 10
                    Layout.preferredHeight: 40
                    Layout.fillWidth: true
                    WWLabel {
                        text: "Movement bonus"
                    }
                    WWTextField {
                        id: movementBonusId
                        validator: DoubleValidator {}
                        Layout.preferredWidth: 80
                        Layout.preferredHeight: 40
                    }
                    WWLabel {
                        text: "Left"
                    }
                    WWTextField {
                        id: leftId
                        validator: DoubleValidator {}
                        Layout.preferredWidth: 80
                        Layout.preferredHeight: 40
                    }
                    WWLabel {
                        text: "Week points"
                    }
                    WWTextField {
                        id: weekPointsId
                        validator: DoubleValidator {}
                        Layout.preferredWidth: 80
                        Layout.preferredHeight: 40
                    }
                } // RowLayout

                ListModel {
                    id: foodModel

                    ListElement { name: "Apple"; points: 52 }
                    ListElement { name: "Banana"; points: 89 }
                    ListElement { name: "Cheese"; points: 402 }
                }

                Rectangle {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.preferredWidth: diaryMain.width - Layout.leftMargin - Layout.rightMargin
                    color: "#ffff99"
                    ListView {
                        anchors.fill: parent

                        id: foodListView
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
                                text: "Points"
                                font.pointSize: 16
                            }
                        }
                    }

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
                }

                RowLayout {
                    spacing: 10
                    Layout.preferredHeight: 40
                    Layout.fillWidth: true
                    WWLabel {
                        text: "Total"
                    }
                    WWTextField {
                        id: totalId
                        validator: DoubleValidator {}
                        Layout.preferredWidth: 100
                        Layout.preferredHeight: 40
                    }
                } // RowLayout
            } // mainColumn ColumnLayout
        } // diaryMain Rectangle


        RowLayout {
            id: buttonBarId
            Layout.fillWidth: true
            Layout.preferredHeight : WWRowLayout.buttonBarHeight
            spacing: 0

            WWButton {
                id: addFoodButton
                text: "Add &Food"
                Layout.fillWidth: true
                Layout.preferredHeight: buttonBarId.Layout.preferredHeight
                onClicked: {
                    foodDialog.visible = true
                }
            }

            WWButton {
                id: addManualButton
                text: "Add &Manual"
                Layout.fillWidth: true
                Layout.preferredHeight: buttonBarId.Layout.preferredHeight
                onClicked: {
                    manualDialog.visible = true
                }
            }

            WWButton {
                id: addRecipeButton
                text: "Add &Recipe"
                Layout.fillWidth: true
                Layout.preferredHeight: buttonBarId.Layout.preferredHeight
                onClicked: {
                    recipeDialog.visible = true
                }
            }

            WWButton {
                id: editWWButton
                text: "&Edit"
                Layout.fillWidth: true
                Layout.preferredHeight: buttonBarId.Layout.preferredHeight
            }

            WWButton {
                id: deleteWWButton
                text: "&Delete"
                Layout.fillWidth: true
                Layout.preferredHeight: buttonBarId.Layout.preferredHeight
            }
        } // RowLayout
    } // ColumnLayout

    FoodDialog {
        id: foodDialog
        visible: false
    }

    ManualDialog {
        id: manualDialog
        visible: false
    }

    RecipeDialog {
        id: recipeDialog
        visible: false
    }
}

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
                            onClicked: ViewModel.DayMinusOne()
                        }
                        WWTextField {
                            id: dayId
                            horizontalAlignment: Qt.AlignHCenter
                            placeholderText: "Enter date (yyyyMMdd)"
                            text: ViewModel.currentDate
                            validator: RegularExpressionValidator {
                                regularExpression: /^\d{8}$/
                            }
                            Layout.preferredWidth: 110
                            Layout.preferredHeight: 50
                        }
                        WWButton {
                            Layout.minimumWidth: 30
                            Layout.minimumHeight: 30
                            text: "+"
                            onClicked: ViewModel.DayPlusOne()
                        }
                    }
                    WWLabel {
                        text: "Week start"
                    }
                    WWTextField {
                        id: weekStartId
                        placeholderText: "Enter date (yyyyMMdd)"
                        text: ViewModel.startDate
                        horizontalAlignment: Qt.AlignHCenter
                        validator: RegularExpressionValidator {
                            regularExpression: /^\d{8}$/
                        }
                        Layout.preferredWidth: 110
                        Layout.preferredHeight: 40
                    }
                    WWLabel {
                        text: "Week end"
                    }
                    RowLayout {
                        spacing: 0
                        WWButton {
                            Layout.minimumWidth: 30
                            Layout.minimumHeight: 30
                            text: "-"
                            onClicked: ViewModel.endDateMinusOne()
                        }
                        WWTextField {
                            id: weekEndId
                            placeholderText: "Enter date (yyyyMMdd)"
                            text: ViewModel.endDate
                            onEditingFinished: {
                                ViewModel.endDate = text;
                            }
                            horizontalAlignment: Qt.AlignHCenter
                            validator: RegularExpressionValidator {
                                regularExpression: /^\d{8}$/
                            }
                            Layout.preferredWidth: 110
                            Layout.preferredHeight: 40
                        }
                        WWButton {
                            Layout.minimumWidth: 30
                            Layout.minimumHeight: 30
                            text: "+"
                            onClicked: ViewModel.endDatePlusOne()
                        }
                    } // RowLayout
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
                        text: Week.strategy
                        readOnly: true
                        horizontalAlignment: Qt.AlignLeft
                        Layout.preferredWidth: 180
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
                            decimals: 1
                        }
                        text: Day.weight.toFixed(1)
                        onEditingFinished: {
                            Day.weight = parseFloat(text);
                        }
                        horizontalAlignment: Qt.AlignRight
                        Layout.preferredWidth: 90
                        Layout.preferredHeight: 40
                    }
                    WWLabel {
                        text: "Points"
                    }
                    WWTextField {
                        id: pointsId
                        readOnly: true
                        horizontalAlignment: Qt.AlignRight
                        validator: DoubleValidator {}
                        text: Week.pointsAvailable.toFixed(2)
                        Layout.preferredWidth: 90
                        Layout.preferredHeight: 40
                    }
                    WWLabel {
                        text: "Free bonus"
                    }
                    WWTextField {
                        id: freeBonusId
                        horizontalAlignment: Qt.AlignRight
                        validator: DoubleValidator {}
                        text: Day.freeBonus.toFixed(0)
                        onEditingFinished: {
                            Day.freeBonus = parseFloat(text);
                        }
                        Layout.preferredWidth: 90
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
                        readOnly: true
                        text: "0.0"
                        horizontalAlignment: Qt.AlignRight
                        validator: DoubleValidator {}
                        Layout.preferredWidth: 90
                        Layout.preferredHeight: 40
                    }
                    WWLabel {
                        text: "Left"
                    }
                    WWTextField {
                        id: leftId
                        readOnly: true
                        validator: DoubleValidator {}
                        text: ViewModel.pointsLeft.toFixed(2)
                        horizontalAlignment: Qt.AlignRight
                        Layout.preferredWidth: 90
                        Layout.preferredHeight: 40
                    }
                    WWLabel {
                        text: "Week points"
                    }
                    WWTextField {
                        id: weekPointsId
                        readOnly: true
                        validator: DoubleValidator {}
                        text: ViewModel.weekPointsLeft.toFixed(2)
                        horizontalAlignment: Qt.AlignRight
                        Layout.preferredWidth: 90
                        Layout.preferredHeight: 40
                    }
                } // RowLayout

                Rectangle {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.preferredWidth: diaryMain.width - Layout.leftMargin - Layout.rightMargin
                    color: "#ffff99"
                    ListView {
                        id: foodListView
                        anchors.fill: parent

                        model: FoodListModel //foodModel

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
                            color: index === foodListView.currentIndex ? "lightblue" :"yellow"
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
                                    text: model.points.toFixed(2)
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
                        text: Day.totalPointsSpent.toFixed(2)
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

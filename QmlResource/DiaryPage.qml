import QtQuick
import QtQuick.Layouts

import "controls" as WW


Rectangle {
    signal dayMin()
    signal dayPlus()

    property string day : dayId.text
    property string weekStart : weekStartId.text
    property string weekEnd : weekEndId.text
    property string strategy : dayId.text
    property string weight : dayId.text
    property string points: pointsId.text
    property string freeBonus: freeBonusId.text
    property string movementBonus: movementBonusId.text
    property string pointsLeft: leftId.text
    property string weekPoints: weekPointsId.text
    property string totalPoints: totalId.text
    property var model: foodListView.model

    id: diaryPage
    color: "lightblue"

    ColumnLayout {
        anchors.fill: parent
        // This rectangle contains the actual page contents. It also pushes the
        // button bar to the bottom
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

                    WW.Label {
                        text: "Day"
                    }
                    RowLayout {
                        spacing: 0
                        WW.Button {
                            Layout.minimumWidth: 30
                            Layout.minimumHeight: 30
                            text: "-"
                            onClicked: diaryPage.dayMin()
                        }
                        WW.TextField {
                            id: dayId
                            Layout.preferredWidth: 100
                            Layout.preferredHeight: 40
                        }
                        WW.Button {
                            Layout.minimumWidth: 30
                            Layout.minimumHeight: 30
                            text: "+"
                            onClicked: diaryPage.dayPlus()
                        }
                    }
                    WW.Label {
                        text: "Week start"
                    }
                    WW.TextField {
                        id: weekStartId
                        Layout.preferredWidth: 100
                        Layout.preferredHeight: 40
                    }
                    WW.Label {
                        text: "Week end"
                    }
                    WW.TextField {
                        id: weekEndId
                        Layout.preferredWidth: 100
                        Layout.preferredHeight: 40
                    }
                }
                RowLayout {
                    spacing: 10
                    Layout.preferredHeight: 40
                    Layout.fillWidth: true
                    WW.Label {
                        text: "Strategy"
                    }
                    WW.TextField {
                        id: strategyId
                        Layout.preferredWidth: 100
                        Layout.preferredHeight: 40
                    }
                    WW.Label {
                        text: "Weight"
                    }
                    WW.TextField {
                        id: weightId
                        validator: DoubleValidator {
                            bottom: 0
                            top: 9999
                            decimals: 2
                        }
                        Layout.preferredWidth: 80
                        Layout.preferredHeight: 40
                    }
                    WW.Label {
                        text: "Points"
                    }
                    WW.TextField {
                        id: pointsId
                        validator: DoubleValidator {}
                        Layout.preferredWidth: 80
                        Layout.preferredHeight: 40
                    }
                    WW.Label {
                        text: "Free bonus"
                    }
                    WW.TextField {
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
                    WW.Label {
                        text: "Movement bonus"
                    }
                    WW.TextField {
                        id: movementBonusId
                        validator: DoubleValidator {}
                        Layout.preferredWidth: 80
                        Layout.preferredHeight: 40
                    }
                    WW.Label {
                        text: "Left"
                    }
                    WW.TextField {
                        id: leftId
                        validator: DoubleValidator {}
                        Layout.preferredWidth: 80
                        Layout.preferredHeight: 40
                    }
                    WW.Label {
                        text: "Week points"
                    }
                    WW.TextField {
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
                        id: foodListView
                        anchors.fill: parent

                        model: foodModel

                        delegate: delegateId

                        header: RowLayout {
                            Layout.fillWidth: true
                            Layout.preferredWidth: 400
                            WW.Label {
                                id: headerNameId
                                Layout.preferredWidth: 140
                                text: "Name"
                                font.pointSize: 16
                            }

                            WW.Label {
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
                            height: WW.ListView.itemHeight
                            color: "beige"
                            border.color: "yellowgreen"
                            radius: 1

                            RowLayout {
                                Layout.fillWidth: true
                                Layout.preferredWidth: 400
                                WW.Label {
                                    id: textId
                                    Layout.preferredWidth: 140
                                    text: model.name
                                    font.pointSize: 16
                                }

                                WW.Label {
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
                    WW.Label {
                        text: "Total"
                    }
                    WW.TextField {
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
            Layout.preferredHeight : 40
            spacing: 0

            WW.Button {
                id: addFoodButton
                text: "Add &Food"
                Layout.fillWidth: true
                Layout.preferredHeight: buttonBarId.Layout.preferredHeight
                onClicked: {
                    foodDialog.visible = true
                }
            }

            WW.Button {
                id: addManualButton
                text: "Add &Manual"
                Layout.fillWidth: true
                Layout.preferredHeight: buttonBarId.Layout.preferredHeight
                onClicked: {
                    manualDialog.visible = true
                }
            }

            WW.Button {
                id: addRecipeButton
                text: "Add &Recipe"
                Layout.fillWidth: true
                Layout.preferredHeight: buttonBarId.Layout.preferredHeight
                onClicked: {
                    recipeDialog.visible = true
                }
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

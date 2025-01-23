import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Imagine

Rectangle {
    id: personaliaPage
    color: "#bbfadd"

    ColumnLayout {
        anchors.fill: parent
        anchors.topMargin: 20
        anchors.bottomMargin: 60
        anchors.leftMargin: 15
        anchors.rightMargin: 20
        spacing: 10

        RowLayout{
            spacing: 10
            Layout.fillHeight: true
            WWLabel {
                text: "Name"
            }
            WWTextField {
                Layout.preferredWidth: 300
                Layout.preferredHeight: 40
                text: PersonalData.name
            }
            WWLabel {
                text: "Username"
            }
            WWTextField {
                Layout.preferredWidth: 200
                Layout.preferredHeight: 40
                text: PersonalData.userName
            }
        } // RowLayout

        RowLayout {
            Layout.fillHeight: true
            ColumnLayout {
                Layout.fillWidth: true
                Layout.preferredWidth: 1
                WWLabel {
                    Layout.fillHeight: true
                    Layout.minimumHeight: 25
                    text: "Gender"
                }

                WWGroupBox {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.minimumHeight: 95
                    ColumnLayout {
                        spacing: 10
                        Layout.fillHeight: true
                        WWRadioButton {
                            checked: true
                            text: "Male"
                        }
                        WWRadioButton {
                            checked: false
                            text: "Female"
                        }
                        WWRadioButton {
                            checked: false
                            text: "Other"
                        }
                    }
                } // WWGroupBox
                WWLabel {
                    Layout.fillHeight: true
                    Layout.minimumHeight: 25
                    text: "Strategy"
                }

                WWGroupBox {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.minimumHeight: 65
                    ColumnLayout {
                        WWRadioButton {
                            checked: true
                            text: "KCal"
                        }
                        WWRadioButton {
                            checked: false
                            text: "Carbohydrates"
                        }
                    }
                }
                WWLabel {
                    Layout.fillHeight: true
                    Layout.minimumHeight: 25
                    text: "Work"
                }

                WWGroupBox {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.minimumHeight: 125
                    ColumnLayout {
                        spacing: 10
                        WWRadioButton {
                            checked: true
                            text: "Sitting"
                        }
                        WWRadioButton {
                            checked: false
                            text: "Standing"
                        }
                        WWRadioButton {
                            checked: false
                            text: "Walking"
                        }
                        WWRadioButton {
                            checked: false
                            text: "Heavy"
                        }
                    } // ColumnLayout
                } // WWGroupBox
            } // ColumnLayout

            ColumnLayout {
                Layout.preferredWidth: 2
                spacing: 10
                RowLayout {
                    Layout.fillWidth: true
                    WWLabel {
                        text: "Born"
                    }
                    WWTextField {
                        Layout.preferredWidth: 200
                        Layout.preferredHeight: 40
                    }
                }

                RowLayout {
                    WWLabel {
                        text: "Start weight"
                    }
                    WWTextField {
                        Layout.preferredWidth: 200
                        Layout.preferredHeight: 40
                        readOnly: true
                        text: PersonalData.startWeight
                    }
                    WWLabel {
                        text: "kg"
                    }
                }

                RowLayout {
                    WWLabel {
                        text: "Target weight"
                    }
                    WWTextField {
                        Layout.preferredWidth: 200
                        Layout.preferredHeight: 40
                        readOnly: true
                        text: parseFloat(PersonalData.targetWeight)
                    }
                    WWLabel {
                        text: "kg"
                    }
                }

                RowLayout {
                    WWLabel {
                        text: "Length"
                    }
                    WWTextField {
                        Layout.preferredWidth: 100
                        Layout.preferredHeight: 40
                    }
                    WWLabel {
                        text: "cm"
                    }
                }

                RowLayout {
                    WWLabel {
                        text: "Points per day"
                    }
                    WWTextField {
                        Layout.preferredWidth: 100
                        Layout.preferredHeight: 40
                        text: parseFloat(PersonalData.pointsPerDay)
                        onEditingFinished: {
                            PersonalData.pointsPerDay = parseFloat(text);
                        }
                    }
                }

                RowLayout {
                    WWLabel {
                        text: "Extra week points per day"
                    }
                    WWTextField {
                        Layout.preferredWidth: 100
                        Layout.preferredHeight: 40
                        text: parseFloat(PersonalData.extraWeekPointsPerDay)
                        onEditingFinished: {
                            PersonalData.extraWeekPointsPerDay = parseFloat(text);
                        }
                    }
                }
            }
        } // RowLayout
    } // ColumnLayout
}

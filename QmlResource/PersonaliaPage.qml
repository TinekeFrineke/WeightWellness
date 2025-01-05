import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Imagine

import "controls" as WW


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
            WW.Label {
                text: "Name"
            }
            WW.TextField {
                Layout.preferredWidth: 300
                Layout.preferredHeight: 40
            }
            WW.Label {
                text: "Username"
            }
            WW.TextField {
                Layout.preferredWidth: 200
                Layout.preferredHeight: 40
            }
        } // RowLayout

        RowLayout {
            Layout.fillHeight: true
            ColumnLayout {
                Layout.fillWidth: true
                Layout.preferredWidth: 1
                WW.Label {
                    Layout.fillHeight: true
                    Layout.minimumHeight: 25
                    text: "Gender"
                }

                WW.GroupBox {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.minimumHeight: 95
                    ColumnLayout {
                        spacing: 10
                        Layout.fillHeight: true
                        WW.RadioButton {
                            checked: true
                            text: "Male"
                        }
                        WW.RadioButton {
                            checked: false
                            text: "Female"
                        }
                        WW.RadioButton {
                            checked: false
                            text: "Other"
                        }
                    }
                } // GroupBox
                WW.Label {
                    Layout.fillHeight: true
                    Layout.minimumHeight: 25
                    text: "Strategy"
                }

                WW.GroupBox {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.minimumHeight: 65
                    ColumnLayout {
                        WW.RadioButton {
                            checked: true
                            text: "KCal"
                        }
                        WW.RadioButton {
                            checked: false
                            text: "Carbohydrates"
                        }
                    }
                }
                WW.Label {
                    Layout.fillHeight: true
                    Layout.minimumHeight: 25
                    text: "Work"
                }

                WW.GroupBox {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.minimumHeight: 125
                    ColumnLayout {
                        spacing: 10
                        WW.RadioButton {
                            checked: true
                            text: "Sitting"
                        }
                        WW.RadioButton {
                            checked: false
                            text: "Standing"
                        }
                        WW.RadioButton {
                            checked: false
                            text: "Walking"
                        }
                        WW.RadioButton {
                            checked: false
                            text: "Heavy"
                        }
                    } // ColumnLayout
                } // GroupBox
            } // ColumnLayout

            ColumnLayout {
                Layout.preferredWidth: 2
                spacing: 10
                RowLayout {
                    Layout.fillWidth: true
                    WW.Label {
                        text: "Born"
                    }
                    WW.TextField {
                        Layout.preferredWidth: 200
                        Layout.preferredHeight: 40
                    }
                }

                RowLayout {
                    WW.Label {
                        text: "Start weight"
                    }
                    WW.TextField {
                        Layout.preferredWidth: 200
                        Layout.preferredHeight: 40
                    }
                    WW.Label {
                        text: "kg"
                    }
                }

                RowLayout {
                    WW.Label {
                        text: "Target weight"
                    }
                    WW.TextField {
                        Layout.preferredWidth: 200
                        Layout.preferredHeight: 40
                    }
                    WW.Label {
                        text: "kg"
                    }
                }

                RowLayout {
                    WW.Label {
                        text: "Length"
                    }
                    WW.TextField {
                        Layout.preferredWidth: 100
                        Layout.preferredHeight: 40
                    }
                    WW.Label {
                        text: "cm"
                    }
                }

                RowLayout {
                    WW.Label {
                        text: "Points per day"
                    }
                    WW.TextField {
                        Layout.preferredWidth: 100
                        Layout.preferredHeight: 40
                    }
                }

                RowLayout {
                    WW.Label {
                        text: "Extra week points per day"
                    }
                    WW.TextField {
                        Layout.preferredWidth: 100
                        Layout.preferredHeight: 40
                    }
                }
            }
        } // RowLayout
    } // ColumnLayout
}

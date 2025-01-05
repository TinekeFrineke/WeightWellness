import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "controls" as WW

Dialog {
    id: manualDialog
    title: "Title"
    width: 450
    height: 200
    modal: true

    header : WW.Label {
        text: "Manual Item"
    }

    background: Rectangle {
        anchors.fill: parent
        color: "lightgreen"
    }

    ColumnLayout {
        Layout.fillHeight: true
        RowLayout {
            Layout.fillWidth: true

            WW.Label {
                Layout.preferredWidth: 100
                text: "Name"
            }
            WW.TextField {
                id: nameId
                Layout.preferredWidth: 300
                Layout.preferredHeight: 40
            }
        } // RowLayout
        RowLayout {
            Layout.fillWidth: true

            WW.Label {
                Layout.preferredWidth: 100
                text: "Points"
            }
            WW.TextField {
                id: pointsId
                Layout.preferredWidth: 300
                Layout.preferredHeight: 40
            }
        } // RowLayout
    }

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
                WW.Button {
                    Layout.fillWidth: true
                    Layout.minimumHeight: footerId2.Layout.minimumHeight
                    text: "Ok"
                    onClicked: {
                       manualDialog.accept()
                    }
                }
                WW.Button {
                    Layout.fillWidth : true
                    Layout.minimumHeight: footerId2.Layout.minimumHeight
                    text: "Cancel"
                    onClicked: {
                       manualDialog.reject()
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

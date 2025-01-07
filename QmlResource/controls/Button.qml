import QtQuick 2.12
import QtQuick.Templates 2.12 as T
import QtQuick.Controls.impl 2.12

T.Button {
    id: control

    font {
        family: "Century Gothic"
        pointSize: 16
    }

    contentItem: IconLabel {
        spacing: control.spacing
        mirrored: control.mirrored
        display: control.display

        icon: control.icon
        text: control.text
        font: control.font
        color: control.enabled && control.flat && control.highlighted ? control.palette.highlight
            : control.enabled && (control.down || control.checked || control.highlighted) && !control.flat
            ? control.palette.brightText : control.flat ? control.palette.windowText : control.palette.buttonText
    }

    background: Rectangle {
        anchors.fill : control
        opacity: enabled ? 1 : 0.7
        color: control.down ? "red" : control.hovered ? "green" : "orange"
    }
}

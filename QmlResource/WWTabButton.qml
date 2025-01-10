import QtQuick.Templates 2.12 as T
import QtQuick.Controls.impl 2.12
import QtQuick.Controls.Imagine 2.12

T.TabButton {
    id: control

    implicitWidth: Math.max(implicitBackgroundWidth + leftInset + rightInset,
                            implicitContentWidth + leftPadding + rightPadding)
    implicitHeight: Math.max(implicitBackgroundHeight + topInset + bottomInset,
                             implicitContentHeight + topPadding + bottomPadding)

    font {
        family: "Century Gothic"
        pointSize:20
    }

    width: implicitWidth
    leftPadding: 10
    rightPadding: 10

    icon.width: 24
    icon.height: 24
    icon.color: control.palette.buttonText

    contentItem: IconLabel {
        spacing: control.spacing
        mirrored: control.mirrored
        display: control.display

        icon: control.icon
        text: control.text
        font: control.font
        color: "white"//control.palette.buttonText
    }

    background: NinePatchImage {
        source: Imagine.url + "tabbutton-background"
        NinePatchImageSelector on source {
            states: [
                {"disabled": !control.enabled},
                {"pressed": control.down},
                {"checked": control.checked},
                {"focused": control.visualFocus},
                {"mirrored": control.mirrored},
                {"hovered": control.hovered}
            ]
        }
    }
}

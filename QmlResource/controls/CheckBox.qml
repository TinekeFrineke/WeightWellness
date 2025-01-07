
import QtQuick 2.12
import QtQuick.Templates 2.12 as T
import QtQuick.Controls.Imagine 2.12
import QtQuick.Controls.Imagine.impl

T.CheckBox {
    id: control

    implicitWidth: Math.max(implicitBackgroundWidth + leftInset + rightInset,
                            implicitContentWidth + leftPadding + rightPadding)
    implicitHeight: Math.max(implicitBackgroundHeight + topInset + bottomInset,
                             implicitContentHeight + topPadding + bottomPadding,
                             implicitIndicatorHeight + topPadding + bottomPadding)

    spacing: 6 // ###

    font {
        family: "Century Gothic"
        pointSize: 16
    }

    indicator: Image {
        x: text ? (control.mirrored ? control.width - width - control.rightPadding : control.leftPadding) : control.leftPadding + (control.availableWidth - width) / 2
        y: control.topPadding + (control.availableHeight - height) / 2

        source: Imagine.url + "checkbox-indicator"
        ImageSelector on source {
            states: [
                {"disabled": !control.enabled},
                {"pressed": control.down},
                {"checked": control.checkState === Qt.Checked},
                {"partially-checked": control.checkState === Qt.PartiallyChecked},
                {"focused": control.visualFocus},
                {"mirrored": control.mirrored},
                {"hovered": control.hovered}
            ]
        }
    }

    contentItem: Text {
        leftPadding: control.indicator && !control.mirrored ? control.indicator.width + control.spacing : 0
        rightPadding: control.indicator && control.mirrored ? control.indicator.width + control.spacing : 0

        text: control.text
        font: control.font
        color: "darkblue"
        elide: Text.ElideRight
        verticalAlignment: Text.AlignVCenter
    }

    background: NinePatchImage {
        source: Imagine.url + "checkbox-background"
        NinePatchImageSelector on source {
            states: [
                {"disabled": !control.enabled},
                {"pressed": control.down},
                {"checked": control.checkState === Qt.Checked},
                {"partially-checked": control.checkState === Qt.PartiallyChecked},
                {"focused": control.visualFocus},
                {"mirrored": control.mirrored},
                {"hovered": control.hovered}
            ]
        }
    }
}


import QtQuick 2.12
import QtQuick.Templates 2.12 as T
import QtQuick.Controls 2.12
import QtQuick.Controls.Imagine 2.12
import QtQuick.Controls.Imagine.impl 2.12

T.Dialog {
    id: control

    implicitWidth: Math.max(implicitBackgroundWidth + leftInset + rightInset,
                            contentWidth + leftPadding + rightPadding,
                            implicitHeaderWidth,
                            implicitFooterWidth)
    implicitHeight: Math.max(implicitBackgroundHeight + topInset + bottomInset,
                             contentHeight + topPadding + bottomPadding
                             + (implicitHeaderHeight > 0 ? implicitHeaderHeight + spacing : 0)
                             + (implicitFooterHeight > 0 ? implicitFooterHeight + spacing : 0))

    // topPadding: background ? background.topPadding : 0
    // leftPadding: background ? background.leftPadding : 0
    // rightPadding: background ? background.rightPadding : 0
    // bottomPadding: background ? background.bottomPadding : 0

    // topInset: background ? -background.topInset || 0 : 0
    // leftInset: background ? -background.leftInset || 0 : 0
    // rightInset: background ? -background.rightInset || 0 : 0
    // bottomInset: background ? -background.bottomInset || 0 : 0

    background: NinePatchImage {
        source: Imagine.url + "dialog-background"
        NinePatchImageSelector on source {
            states: [
                {"modal": control.modal},
                {"dim": control.dim}
            ]
        }
    }

    header: Label {
        text: control.title
        visible: control.title
        elide: Label.ElideRight
        font.bold: true
        padding: 12

        background: NinePatchImage {
            width: parent.width
            height: parent.height

            source: Imagine.url + "dialog-title"
            NinePatchImageSelector on source {
                states: [
                    {"modal": control.modal},
                    {"dim": control.dim}
                ]
            }
        }
    }

    footer: DialogButtonBox {
        visible: count > 0
    }

    T.Overlay.modal: NinePatchImage {
        source: Imagine.url + "dialog-overlay"
        NinePatchImageSelector on source {
            states: [
                {"modal": true}
            ]
        }
    }

    T.Overlay.modeless: NinePatchImage {
        source: Imagine.url + "dialog-overlay"
        NinePatchImageSelector on source {
            states: [
                {"modal": false}
            ]
        }
    }
}

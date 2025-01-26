
import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Templates 2.15 as T
import QtQuick.Controls 2.15
import QtQuick.Controls.Imagine 2.15
import QtQuick.Controls.Imagine.impl

T.ComboBox {
    id: control

    implicitWidth: Math.max(implicitBackgroundWidth + leftInset + rightInset,
                            contentItem.implicitWidth + background ? (background.leftPadding + background.rightPadding) : 0)
    implicitHeight: Math.max(implicitBackgroundHeight + topInset + bottomInset,
                             Math.max(implicitContentHeight,
                                      implicitIndicatorHeight) + background ? (background.topPadding + background.bottomPadding) : 0)

    leftPadding: padding + (!control.mirrored || !indicator || !indicator.visible ? 0 : indicator.width + spacing)
    rightPadding: padding + (control.mirrored || !indicator || !indicator.visible ? 0 : indicator.width + spacing)

    font {
        family: "Century Gothic"
        pointSize: 16
    }

    delegate: ItemDelegate {
        width: ListView.view.width
        text: control.textRole ? (Array.isArray(control.model) ? modelData[control.textRole] : model[control.textRole]) : modelData
        font {
            family: "Century Gothic"
            pointSize: 16
            weight: control.currentIndex === index ? Font.DemiBold : Font.Normal
        }

        highlighted: control.highlightedIndex === index
        hoverEnabled: control.hoverEnabled
        background : Rectangle {
            anchors.fill: parent
            color: control.currentIndex === index ? "#cc99ff" : "white"
        }
    }

    indicator: Image {
        x: control.mirrored ? control.padding : control.width - width - control.padding
        y: control.topPadding + (control.availableHeight - height) / 2

        source: Imagine.url + "combobox-indicator"
        ImageSelector on source {
            states: [
                {"disabled": !control.enabled},
                {"pressed": control.pressed},
                {"editable": control.editable},
                {"open": control.down},
                {"focused": control.visualFocus},
                {"mirrored": control.mirrored},
                {"hovered": control.hovered},
                {"flat": control.flat}
            ]
        }
    }

    contentItem: WWTextField {
        text: control.editable ? control.editText : control.displayText

        enabled: control.editable
        autoScroll: control.editable
        readOnly: control.down
        inputMethodHints: control.inputMethodHints
        validator: control.validator
        selectByMouse: control.selectTextByMouse

        font: control.font
        color: "black" //control.flat ? control.palette.windowText : control.editable ? control.palette.text : control.palette.buttonText
        selectionColor:"pink" // control.palette.highlight
        selectedTextColor: "yellowgreen" //control.palette.highlightedText
        verticalAlignment: Text.AlignVCenter
    }

    background: NinePatchImage {
        source: Imagine.url + "combobox-background"
        NinePatchImageSelector on source {
            states: [
                {"disabled": !control.enabled},
                {"pressed": control.pressed},
                {"editable": control.editable},
                {"open": control.down},
                {"focused": control.visualFocus || (control.editable && control.activeFocus)},
                {"mirrored": control.mirrored},
                {"hovered": control.hovered},
                {"flat": control.flat}
            ]
        }
    }

    popup: T.Popup {
        width: control.width
        height: Math.min(contentItem.implicitHeight + topPadding + bottomPadding, control.Window.height - topMargin - bottomMargin)

        palette.text: "black"//control.palette.text
        palette.highlight: "blue" //control.palette.highlight
        palette.highlightedText: "orange" //control.palette.highlightedText
        palette.windowText: "red" //control.palette.windowText
        palette.buttonText: "purple" //control.palette.buttonText

        contentItem: ListView {
            clip: true
            implicitHeight: contentHeight
            model: control.delegateModel
            currentIndex: control.highlightedIndex
            highlightMoveDuration: 0

            T.ScrollIndicator.vertical: ScrollIndicator { }
        }
    }
}

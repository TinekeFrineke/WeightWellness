import QtQuick 2.12
import QtQuick.Templates 2.12 as T
import QtQuick.Controls 2.12
import QtQuick.Controls.impl 2.12
import QtQuick.Controls.Imagine 2.12

T.TextField {
    id: control

    implicitWidth: implicitBackgroundWidth + leftInset + rightInset
                   || Math.max(contentWidth, placeholder.implicitWidth) + leftPadding + rightPadding
    implicitHeight: Math.max(implicitBackgroundHeight + topInset + bottomInset,
                             contentHeight + topPadding + bottomPadding,
                             placeholder.implicitHeight + topPadding + bottomPadding)

    color: readOnly ? "black" : "darkblue"
    font {
        family: "Arial"
        pointSize: 16
    }
    padding: 3

    selectionColor: control.palette.highlight
    selectedTextColor: control.palette.highlightedText
    placeholderTextColor: Color.transparent(control.color, 0.5)
    verticalAlignment: Qt.AlignVCenter

    PlaceholderText {
        id: placeholder
        x: control.leftPadding
        y: control.topPadding
        width: control.width - (control.leftPadding + control.rightPadding)
        height: control.height - (control.topPadding + control.bottomPadding)

        text: control.placeholderText
        font: control.font
        color: control.placeholderTextColor
        verticalAlignment: control.verticalAlignment
        visible: !control.length && !control.preeditText && (!control.activeFocus || control.horizontalAlignment !== Qt.AlignHCenter)
        elide: Text.ElideRight
        renderType: control.renderType
    }

    background: Rectangle {
        anchors.fill: parent
        color: control.readOnly ? "#e0eeee" : "white"
    }

//    background: NinePatchImage {
//        source: Imagine.url + "textfield-background"
//        NinePatchImageSelector on source {
//            states: [
//                {"disabled": !control.enabled},
//                {"focused": control.activeFocus},
//                {"mirrored": control.mirrored},
//                {"hovered": control.hovered}
//            ]
//        }
//    }
}

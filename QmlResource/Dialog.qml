import QtQuick 2.0

Window {
    id: mainWindow
    width: 800
    height: 600
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        anchors.fill: parent
        color: "pink"
    }
}

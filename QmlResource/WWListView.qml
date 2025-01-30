import QtQuick
import QtQuick.Layouts


Item {
    id: rootId
    width: parent.width
    height: parent.height

    property alias model: listView.model
    property var columns: [] // Array of column definitions (headerText, width, etc.)
    property color backgroundColor: "#ffff99"

    signal itemDoubleClicked(int index)

    Rectangle {
        id: background
        color: rootId.backgroundColor
        anchors.fill: parent

        ColumnLayout {
            anchors.fill: parent

            // ListView
            ListView {
                id: listView
                property int itemHeight: 30
                Layout.fillWidth: true
                Layout.fillHeight: true
                signal itemDoubleClicked(int index)
                onItemDoubleClicked: rootId.itemDoubleClicked(index)

                Component.onCompleted: {
                    console.log("ListView created!")
                    qDebug() << "Model row count: " << (listView.model ? listView.model.count : "No model");
                    console.log("Model row count: ", listView.model ? listView.model.count : "No model");
                    console.log("Model: ", listView.model);

                    Qt.callLater(() => {
                        console.log("Model row count: ", listView.model ? listView.model.count : "No model");
                        if (listView.model) {
                            for (var i = 0; i < listView.model.count; i++) {
                                console.log("Row " + i + " - Name:", listView.model.get(i).name, 
                                            "Points:", listView.model.get(i).points);
                            }
                        }
                    })
                }
                header: RowLayout {
                    id: headerRow
                    Layout.fillWidth: true
                    Layout.preferredWidth: 400
                    Repeater {
                        model: rootId.columns
                        WWLabel {
                            Layout.preferredWidth: modelData.width || 100
                            text: modelData.headerText
                            font.pointSize: 16
                            horizontalAlignment: Text.AlignHCenter
                        }
                    }
                }

                delegate: Rectangle {
                    height: 40
                    width: parent.width
                    color: index === listView.currentIndex ? "lightblue" : "yellow"
                    border.color: "yellowgreen"

                    RowLayout {
                        Layout.fillWidth: true
                        Repeater {
                            model: rootId.columns  // Columns definition
                            WWLabel {
                                Layout.preferredWidth: modelData.width || 100
                                text: {
                                    if (!model) {
                                        console.log("!!! No model data available!");
                                        return "UNDEFINED";
                                    }
                                    let value = model[modelData.field];  // Get field dynamically
                                    console.log("Item data - Field:", modelData.field, "Value:", model[modelData.field]);

                                    switch (modelData.type) {
                                        case "double":
                                            console.log("WWLabel double text == ", value);
                                            return value !== undefined ? value.toFixed(2) : "UNDEFINED1";
                                        case "string":
                                            console.log("WWLabel string text == ", value);
                                            return value !== undefined ? value : "UNDEFINED2";
                                        default:
                                            console.log("WWLabel unknown type == ", value);
                                            return value !== undefined ? value : "UNDEFINED3";
                                    }
                                }
                                font.pointSize: 14
                                horizontalAlignment: Text.AlignHCenter
                            }
                        }
                    }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            listView.currentIndex = index
                        }
                        onDoubleClicked: {
                            listView.currentIndex = index
                            listView.itemDoubleClicked(index)
                        }
                    }
                }
            }
        }
    }
}

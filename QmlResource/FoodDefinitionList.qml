import QtQuick
import QtQuick.Layouts


ListView {
    id: foodListView
    Layout.fillWidth: true
    Layout.fillHeight: true
    Layout.preferredHeight: 400
    Layout.preferredWidth: diaryMain.width - Layout.leftMargin - Layout.rightMargin

    signal onItemDblClick(string name)

    readonly property int nameColumnWidth: 4
    readonly property int categoryColumnWidth: 3
    readonly property int unitColumnWidth: 1
    readonly property int pointsColumnWidth: 1

    delegate: Item {
        id: delegateId
        width: ListView.view.width // Match the width of the ListView
        height: WWListView.itemHeight // Fixed row height

        RowLayout {
            anchors.fill: parent
            spacing: 10
            WWLabel {
                id: textId
                Layout.fillWidth: true
                Layout.preferredWidth: foodListView.nameColumnWidth
                text: model.name
            }

            WWLabel {
                Layout.fillWidth: true
                Layout.preferredWidth: foodListView.categoryColumnWidth
                // Layout.leftMargin: foodListView.categoryColumnStart
                id: categoryId
                text: model.category
            }
            WWLabel {
                Layout.fillWidth: true
                Layout.preferredWidth: foodListView.unitColumnWidth
                id: unitId
                text: model.unit
            }
            WWLabel {
                Layout.fillWidth: true
                Layout.preferredWidth: foodListView.pointsColumnWidth
                horizontalAlignment: Text.AlignRight
                id: pointsId
                text: model.points
            }
        }

        MouseArea {
            anchors.fill: parent
            onDoubleClicked: {
                onItemDblClick(name)
            }
        }
    }
    header: RowLayout {
        height: ListView.itemHeight // Set a fixed height for the header
        anchors.left: parent.left
        anchors.right: parent.right

        WWLabel {
            text: "Name"
            font.bold: true
            Layout.preferredWidth: foodListView.nameColumnWidth // Match proportions with rows
            Layout.fillWidth: true
        }
        WWLabel {
            text: "Category"
            font.bold: true
            Layout.preferredWidth: foodListView.categoryColumnWidth // Match proportions with rows
            Layout.fillWidth: true
        }
        WWLabel {
            text: "Unit"
            font.bold: true
            Layout.preferredWidth: foodListView.unitColumnWidth // Match proportions with rows
            Layout.fillWidth: true
        }
        WWLabel {
            text: "Points"
            font.bold: true
            Layout.preferredWidth: foodListView.pointsColumnWidth // Match proportions with rows
            Layout.fillWidth: true
            horizontalAlignment: Text.AlignRight
        }
    }
}


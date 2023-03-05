import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Item {
        width: 200
        height: 200

        Button {
            id: load_
            text: "LOAD"
            anchors.left: parent.left
            anchors.top: parent.top

            onClicked: {
                radioService.addCommand("load")
            }
        }
    }
    Item {
        width: 200
        height: 200

        Button {
            id: open_
            text: "OPEN"
            anchors.left: parent.left
            anchors.leftMargin: 50
            anchors.top: parent.top

            onClicked: {
                radioService.addCommand("open")
            }
        }
    }
}

import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.15

Window {
    width: 1920
    height: 1080
    visible: true
    title: qsTr("Register")

    Item {
            width: parent.width
            height: parent.height


            Image {
                id: register_bg
                source: "qrc:/UI/assets/register_bg.png"
                anchors.fill: parent

            }

            Image {
                id: arrow
                opacity: 0.5
                source: "qrc:/UI/assets/arrow.png"
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.leftMargin: 45
                anchors.topMargin: 30
                width: 75
                height: 110

                MouseArea {
                        anchors.fill: parent
                        onClicked: classA.mainMenu()
                }
            }
        }
}

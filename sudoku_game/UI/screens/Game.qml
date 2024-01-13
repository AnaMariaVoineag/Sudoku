import QtQuick 2.15
import QtQuick.Controls 2.15
import Qt.labs.qmlmodels
import SudokuGrid 1.0

Window {
    visible: true
    width: 1920
    height: 1080
    title: qsTr("Game")
    color: "#1D2238"

   Item {
        anchors.fill: parent

        Rectangle {
            anchors.centerIn: parent
            width: 460
            height: 460
            color: "#1D2238"

            Text {
                anchors.fill: parent
                font.pixelSize: 32
                text: "Sudoku"
                color: "white"
                fontSizeMode: Text.Fit
                minimumPixelSize: 10
                wrapMode: Text.WordWrap
                anchors.rightMargin: 0
                anchors.leftMargin: 0
                anchors.topMargin: -236
                anchors.bottomMargin: 299

                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }


            TableView {
                anchors.fill: parent
                columnSpacing: 1
                rowSpacing: 1
                clip: true

                model: SudokuGrid {}

                delegate: Rectangle {
                    implicitWidth: 50
                    implicitHeight: 50
                    border {
                         color: "white"
                         width: 1
                    }
                    color: model.row % 2 ? "lightpink" : "lightblue"
                    Text {
                        anchors.centerIn: parent
                        text: display
                        font.pointSize: 12

                    }

                }
            }
        }
    }
}

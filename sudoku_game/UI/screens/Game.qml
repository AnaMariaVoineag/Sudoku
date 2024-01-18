import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls.Basic 6.0
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
                clip: true

                model: SudokuGrid {
                    id: grid
                }

                delegate: Rectangle {
                    required property var model
                    implicitWidth: 50
                    implicitHeight: 50

                    border {
                        color: "white"
                    }

                    TextField {
                        anchors.fill: parent
                        text: model.display !== undefined ? model.display.toString() : ""

                        readOnly: model.display !== undefined && model.display !== 0

                        horizontalAlignment: TextInput.AlignHCenter
                        verticalAlignment: TextInput.AlignVCenter

                        background: Rectangle {
                            color: model.row % 2 ? "lightpink" : "lightblue"
                        }

                        color: "black"

                        onEditingFinished: {
                            if (text !== "" && model.display === 0) {
                                model.text = text
                            }
                        }

                        TableView.onCommit: {
                            if (text !== "" && model.display === 0) {
                                model.text = text
                            }
                        }
                    }

                    Rectangle {
                        width: 1
                        height: parent.height
                        color: model.column % 3 == 0 ? "black" : "transparent"
                    }

                    Rectangle {
                        width: parent.width
                        height: 1
                        color: model.row % 3 == 0 ? "black" : "transparent"
                    }
                }
            }
        }
    }
}

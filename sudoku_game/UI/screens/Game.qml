import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls.Basic 6.0
import SudokuGrid 1.0
import Timer 1.0

Window {
    visible: true
    width: 1920
    height: 1080
    title: qsTr("Game")
    color: "#1D2238"

    Item {
        anchors.fill: parent

        Image {
            source: "qrc:/UI/assets/bg.png"
            anchors.fill: parent

            Button {
                id: solve
                x: 406
                y: 656

                onClicked: grid.solveSudoku()
                Layout.fillWidth: true

                background: Rectangle {
                    color: "transparent"
                }

                contentItem: Text {
                    color: solve.hovered ? "#606372" : "#ffffff"
                    text: qsTr("Solve")
                    font.family: "Inria Serif"
                    font.pixelSize: 30
                    scale: 1.4
                }

            }

            Timer {
                id: timer
            }

            Text {
                id: timeText
                font.pixelSize: 24
                color: "white"
                font.family: "Inria Serif"
                text: "Total Time<br>" + timer.timeDisplay

                anchors {
                    top: parent.top
                    left: parent.left
                    margins: 15
                }

            }
        }

        Rectangle {
            anchors.centerIn: parent
            width: 460
            height: 460
            color: "transparent"

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

                    TextField {
                        id: textField
                        anchors.fill: parent

                        validator: IntValidator { bottom: 1; top: 9 }
                        text: model.display !== undefined ? model.display.toString() : ""

                        readOnly: model.display !== undefined && model.display !== 0

                        onEditingFinished: {
                            var num = parseInt(textField.text);

                            if (!isNaN(num)) {
                                if (grid.verif(row, column, num)) {
                                    console.log("Valid number!");
                                    textField.color = "green";
                                } else {
                                    console.log("Invalid number!");
                                    textField.color = "red";
                                }
                            }
                        }


                        horizontalAlignment: TextInput.AlignHCenter
                        verticalAlignment: TextInput.AlignVCenter

                        background: Rectangle {
                            color: model.row % 2 ? "lightpink" : "#bfa6ac" && textField.acceptableInput ? "#FFEFD5" : "#bfa6ac"
                            border {
                                width: 1
                                color: "white"
                            }

                        }


                        color: "black"

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

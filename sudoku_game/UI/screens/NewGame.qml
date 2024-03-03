import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.15
import QtQuick.Controls.Basic 6.0

Window {
    width: 1920
    height: 1080
    visible: true
    title: qsTr("New Game")

    Item {
            width: parent.width
            height: parent.height

            Rectangle {
                   width: parent.width
                   height: parent.height
                   color: "transparent"
            Image {
                id: newGame_bg
                source: "qrc:/UI/assets/newGame_bg.png"
                anchors.fill: parent

                ColumnLayout{
                    spacing: 400
                    anchors {
                           right: parent.right
                           top: parent.top
                       }

                       x: -530
                       y: 325
                       anchors.rightMargin: 230
                       anchors.topMargin: 267
                       RowLayout{
                           spacing: 100
                           DropDownMenu{
                               id: selectionCombo
                               model: ["Very Easy", "Easy", "Medium", "Difficult", "May God have mercy"]
                           }
                       }
                   }

                Button {
                         id: btn1
                         x: 1005
                         y: 591
                         width: 211
                         height: 38
                         property int difficulty: 0;
                         onClicked: {
                                switch (qsTr(selectionCombo.currentText)) {
                                    case "Very Easy":
                                        btn1.difficulty = 1;
                                        break;
                                    case "Easy":
                                        btn1.difficulty = 2;
                                        break;
                                    case "Medium":
                                        btn1.difficulty = 3;
                                        break;
                                    case "Difficult":
                                        btn1.difficulty = 4;
                                        break;
                                    case "May God have mercy":
                                        btn1.difficulty = 5;
                                        break;
                                }

                             classA.gameWindow(difficulty);
                         }
                         text: qsTr(" NEXT ")
                         background: Rectangle {
                                color: "transparent"
                             }

                         font.family: "Inria Serif"
                         font.pixelSize: 30


                         contentItem: Text {
                                text: btn1.text
                                color: btn1.hovered ? "#ccccb3" : "#ffffff"
                                font.family: "Inria Serif"
                                font.pixelSize: 30
                                horizontalAlignment: Text.AlignLeft
                                verticalAlignment: Text.AlignTop
                                wrapMode: Text.Wrap
                                font.weight: Font.Normal
                            }

                        }
                }
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

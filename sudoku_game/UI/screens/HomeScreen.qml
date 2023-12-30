import QtQuick 2.15
import QtQuick.Controls.Basic 6.0

Item {

        Image {
                id: mainScreen
                source: "qrc:/UI/assets/mainMenuScreen.png"
                anchors.fill: parent

                Image {
                    id: component
                    x: 386
                    y: 287
                    width: 992
                    height: 204
                    source: "qrc:/UI/assets/component.png"
                    fillMode: Image.PreserveAspectFit
                }

                Image {
                    id: scores_leaderboard
                    x: 419
                    y: 617
                    width: 536
                    height: 168
                    source: "qrc:/UI/assets/scores_leaderboard.png"
                    fillMode: Image.Stretch
                }

        }

        Text {
            id: motto_text
            color: "white"
            x: 399
            y: 150
            width: 538
            height: 67
            text: "Embark on a journey of Sudoku, where numbers\ncan play with the logic of your mind."
            font.pixelSize: 20
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignTop
            wrapMode: Text.Wrap
            font.weight: Font.Normal
            font.family: "Inria Serif"
        }

        Text {
            id: very_easy_level
            color: "white"
            x: 426
            y: 500
            width: 118
            height: 29
            text: "Very Easy"
            font.pixelSize: 20
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignTop
            wrapMode: Text.Wrap
            font.weight: Font.Normal
            font.family: "Inria Serif"
        }

        Text {
            id: easy_level
            color: "white"
            x: 663
            y: 500
            width: 57
            height: 30
            text: "Easy"
            font.pixelSize: 20
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignTop
            wrapMode: Text.Wrap
            font.weight: Font.Normal
            font.family: "Inria Serif"
        }


        Text {
            id: medium_level
            color: "white"
            x: 1036
            y: 500
            width: 90
            height: 30
            text: "Medium"
            font.pixelSize: 20
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignTop
            wrapMode: Text.Wrap
            font.weight: Font.Normal
            font.family: "Inria Serif"

        }


        Text {
            id: hard_level
            color: "white"
            x: 835
            y: 500
            width: 102
            height: 20
            text: "Difficult"
            font.pixelSize: 20
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignTop
            wrapMode: Text.Wrap
            font.weight: Font.Normal
            font.family: "Inria Serif"

        }

        Text {
            id: very_hard_level
            color: "white"
            x: 1018
            y: 500
            width: 554
            height: 67
            text: "May God\nHave Mercy"
            font.pixelSize: 20
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignTop
            wrapMode: Text.Wrap
            font.weight: Font.Normal
            font.family: "Inria Serif"

        }

        Text {
               id: sudoku_text
               x: 396
               y: 80
               color: "white"
               width: 404
               height: 61
               text: "Sudoku"
               font.pixelSize: 48
               horizontalAlignment: Text.AlignLeft
               verticalAlignment: Text.AlignTop
               wrapMode: Text.Wrap
               font.weight: Font.Normal
               font.family: "Inria Serif"

        }

        Rectangle {
             id: rectangle_purple
             x: 395
             y: 229
             width: 203
             height: 38
             color: "#783b67"
             radius: 33
         }


        Text {
               id: select_dificulty
               x: 406
               y: 234
               color: "white"
               width: 197
               height: 28
               text: "Select the difficulty:"
               font.pixelSize: 20
               horizontalAlignment: Text.AlignLeft
               verticalAlignment: Text.AlignTop
               wrapMode: Text.Wrap
               font.weight: Font.Normal
               font.family: "Inria Serif"

        }

        Rectangle {
            id: menu_Bar
            x: 0
            y: 0
            width: 299
            height: 1080
            color: "#1f2641"
        }

        Text {
            id: scoresText
            x: 419
            y: 568
            color: "white"
            text: "Scores leaderboard"
            font.pixelSize: 24
        }

             Button {
                      id: btn1
                      x: 46
                      y: 195
                      width: 211
                      height: 38
                      onClicked: classA.howToPlayWindow()
                      text: qsTr(" How to play ")
                      background: Rectangle {
                             color: "transparent"
                          }

                      font.family: "Inria Serif"
                      font.pixelSize: 30


                      Text {
                             id: how_to_play
                             color: "#ffffff"
                             horizontalAlignment: Text.AlignLeft
                             verticalAlignment: Text.AlignTop
                             wrapMode: Text.Wrap
                             font.weight: Font.Normal
                      }
               }



               Button {
                        x: 58
                        y: 246
                        width: 188
                        height: 34
                        onClicked: classA.newGameWindow()
                        text: qsTr(" New Game ")
                        background: Rectangle {
                               color: "transparent"
                        }

                        font.family: "Inria Serif"
                        font.pixelSize: 26

                        Text {
                               id: new_Game
                               color: "#ffffff"
                               horizontalAlignment: Text.AlignLeft
                               verticalAlignment: Text.AlignTop
                               wrapMode: Text.Wrap
                               font.weight: Font.Normal
                        }
                 }




        Text {
               id: load_game
               x: 89
               y: 291
               width: 127
               height: 25
               color: "#ffffff"
               text: qsTr("Load Game")
               font.pixelSize: 24
               horizontalAlignment: Text.AlignLeft
               verticalAlignment: Text.AlignTop
               wrapMode: Text.Wrap
               font.weight: Font.Normal
               font.family: "Inria Serif"
        }

        Button {
            x: -51
            y: 332
            width: 350
            height: 24
            property bool isPlaying: false
             onClicked: {
                 isPlaying ? classB.stopMusic() : classB.playMusic();
                 isPlaying = !isPlaying;
             }

            text: qsTr("Sound")
            background: Rectangle {
                color: "transparent"
            }

            font.pixelSize: 24
            font.family: "Inria Serif"

            Text {
                id: musical_sound
                color: "#ffffff"
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignTop
                wrapMode: Text.Wrap
                font.weight: Font.Normal
            }
        }

        Text {
                id: enter_keywords
                x: 396
                y: 45
                width: 177
                height: 29
                color: "#9396a9"
                text: qsTr("Enter keywords")
                font.pixelSize: 24
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignTop
                wrapMode: Text.NoWrap
                font.weight: Font.Normal
                font.family: "Inter"
        }

}


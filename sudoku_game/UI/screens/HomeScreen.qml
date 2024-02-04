import QtQuick 2.15
import QtQuick.Controls.Basic 6.0

Item {

    Image {
        id: mainScreen
        source: "/UI/assets/mainMenuScreen.png"
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
        id: diff_level
        color: "white"
        x: 1036
        y: 500
        width: 90
        height: 30
        text: "Difficult"
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
        x: 835
        y: 500
        width: 102
        height: 20
        text: "Medium"
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
        width: 136
        height: 38
        color: "#783b67"
        radius: 33
    }


    Text {
        id: dificulty
        x: 406
        y: 234
        color: "white"
        width: 197
        height: 28
        text: "Game levels:"
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

        contentItem: Text {
            text: btn1.text
            color: btn1.hovered ? "#ea74de" : "#ffffff"
            font.family: "Inria Serif"
            font.pixelSize: 30
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignTop
            wrapMode: Text.Wrap
            font.weight: Font.Normal
        }
    }

    Button {
        id: newGame
        x: 81
        y: 244

        width: 147
        height: 34
        onClicked: {
            classA.newGameWindow()
            Window.window.close()
        }

        text: "New Game"
        background: Rectangle {
            color: "transparent"

        }

        contentItem: Text {
            color: newGame.hovered ? "#a9caf9" : "#ffffff"
            text: "New Game"
            font.family: "Inria Serif"
            font.pixelSize: 26
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignTop
            wrapMode: Text.Wrap
            font.weight: Font.Normal
        }
    }

    signal loadSignal();


    Button {
        id: btnMusic
        x: 81
        y: 284
        width: 117
        height: 33
        property bool isPlaying: false
        onClicked: {
            isPlaying ? classB.stopMusic() : classB.playMusic();
            isPlaying = !isPlaying;
        }

        text: "Sound"
        background: Rectangle {
            color: "transparent"
        }

        contentItem: Text {
            color: btnMusic.hovered ? "#a9caf9" : "#ffffff"
            text: btnMusic.text
            font.pixelSize: 26
            font.family: "Inria Serif"
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignTop
            wrapMode: Text.Wrap
            font.weight: Font.Normal
        }
    }

    Text {
        id: ourMotto
        x: 527
        y: 675
        width: 308
        height: 61
        color: "#ffffff"
        text: "Embrace the Grid, Conquer the Numbers: Sudoku Triumphs."
        font.pixelSize: 20
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignTop
        wrapMode: Text.Wrap
        scale: 1.7
        font.weight: Font.Normal
        font.family: "Inria Serif"
    }


}

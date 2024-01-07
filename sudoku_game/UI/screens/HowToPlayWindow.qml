import QtQuick
import QtQuick.Window
import QtQuick.Controls 6.0

Window {
    width: 1920
    height: 1080
    visible: true
    title: qsTr("Instructions")

    Item {
        x: 0
        y: 0
        width: parent.width
        height: parent.height


        Rectangle {
            id: background
            x: 0
            y: 0
            width: 1920
            height: 1080
            color: "#1D2238"

            Text {
                id: instructions_content
                color: "#ffffff"
                text: qsTr("\n- start with a 9x9 grid, divided into nine 3x3 subgrids called regions or boxes. Each box is further divided into 3x3 cells, making a total of 81 cells in the entire grid.\n- fill in the grid with the numbers 1 through 9. Each row, column, and region must contain all of the numbers from 1 to 9 without repetition.\n- if some numbers are already filled in you cannot change them.\n- no row, column, or region can have repeated numbers. Each number must appear only once in each row, column, and region.\n- solve the puzzle using logic and deduction. You don't need to guess. If you reach a point where you have to guess, then you may have made a mistake.\n")
                anchors {
                    left: parent.left
                    right: parent.right
                    top: parent.top
                    bottom: parent.bottom
                    leftMargin: 85
                    rightMargin: 856
                    topMargin: 96
                    bottomMargin: 621
                }
                font.letterSpacing: 0.313
                font.pixelSize: 22
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignTop
                lineHeight: 38
                lineHeightMode: Text.FixedHeight
                wrapMode: Text.Wrap
                minimumPixelSize: 16
                font.weight: Font.Normal
                font.family: "Times New Roman"
            }

            Text {
                id: instructions
                color: "#ffffff"
                text: qsTr("Instructions")
                anchors {
                    left: parent.left
                    right: parent.right
                    top: parent.top
                    bottom: parent.bottom
                    leftMargin: 88
                    rightMargin: 1113
                    topMargin: 52
                    bottomMargin: 980
                }

                font.letterSpacing: 31
                font.pixelSize: 62
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignTop
                wrapMode: Text.Wrap
                font.weight: Font.Normal
                font.family: "Times New Roman"
            }


                Image {
                    id: vj_photo
                    x: 849
                    y: 17
                    width: 709
                    height: 962
                    source: "qrc:/UI/assets/vj_photo.png"
                    fillMode: Image.Stretch
                }



                Rectangle {
                     id: rectangle_purple
                     x: 85
                     y: 484
                     width: 779
                     height: 260
                     opacity: 0.4
                     visible: true
                     color: "#000000"
                }

                Image {
                    id: dwight_photo
                    x: 180
                    y: 404
                    width: 1451
                    height: 629
                    source: "qrc:/UI/assets/dwight_photo.png"
                    fillMode: Image.PreserveAspectFit
                }

                Text {
                    id: quote
                    x: 59
                    y: 529
                    color: "#ffffff"
                    text: qsTr("You have to learn the rules of the game. And then\nyou have to play better than anyone else.\n-Albert Einstein")
                    font.pixelSize: 38
                    scale: 0.8
                }
       }

    }
}

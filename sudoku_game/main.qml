import QtQuick
import QtQuick.Window
import QtQuick.Controls 6.0

Window {
    width: 1920
    height: 1080
    visible: true
    title: qsTr("Main Menu")

    Loader {
        id: mainLoader
        anchors.fill: parent
        source: "qrc:/UI/screens/HomeScreen.qml"
    }
}

import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.4
import QtQuick.Controls.Material 2.3
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3
import Qt.labs.platform 1.0
import QtLocation 5.9
import QtGraphicalEffects 1.0

ApplicationWindow {
    //flags: Qt.BypassWindowManagerHint | Qt.FramelessWindowHint | Qt.WindowStaysOnTopHint
    modality: Qt.ApplicationModal
    //flags: Qt.FramelessWindowHint | Qt.Window

    //color: "#efd3ff"
    Material.theme: "Dark"
    property int desktopWidth: 1280
    property int desktopHeight: 720

    property int elevationValue: 3
    id: window
    visible: true
    width: desktopWidth
    height: desktopHeight

    Row {
        id: hana_top
        x: 10
        y: 10
        spacing: 600
        anchors.margins: 30

        Image {
            id: main_icon
            source: "qrc:/icons/hana.ico"
            width: window.width * 0.05
            height: width
        }

        BaseTabBar{
            id: bar
            background: Rectangle {
                color: "transparent"
            }
            padding: 20
            rightPadding: 40
            anchors.right: window.right
            height: 40
            width: window.width * 0.4
            Component.onCompleted: {
                myModel.append({ "modelText": "Dashboard", "modelColor": "#000000", "modelColorG": "#B39DDB", "modelSrc": "qrc:/images/Chat_MsgRecord.svg", "modelSrcG": "qrc:/images/Chat_MsgRecordG.svg"})
                myModel.append({ "modelText": "Background", "modelColor": "#000000", "modelColorG": "#B39DDB", "modelSrc": "qrc:/images/Chat_FriendManager.svg", "modelSrcG": "qrc:/images/Chat_FriendManagerG.svg"})
                myModel.append({ "modelText": "Quote", "modelColor": "#000000", "modelColorG": "#B39DDB", "modelSrc": "qrc:/images/Mobile_Find.svg", "modelSrcG": "qrc:/images/Mobile_FindG.svg"})
                myModel.append({ "modelText": "Infomation", "modelColor": "#000000", "modelColorG": "#B39DDB", "modelSrc": "qrc:/images/Main_P2PChat.svg", "modelSrcG": "qrc:/images/Main_P2PChatG.svg"})
            }
        }
    }
    StackLayout {
        id: view
        anchors.fill: parent
        //anchors.centerIn: parent
        //initialItem: bar.currentItem
        currentIndex: bar.currentIndex

        z: hana_top.z - 1

        Hana_Main {
            id: hana_main
        }
        Rectangle{
            Text {
                text: qsTr("뭐 넣지")
                anchors.centerIn: parent
            }
        }
        Hana_Quote {
            id: quote
        }
        Hana_Infomation {
            id: infomation
        }
    }
    PageIndicator {
        id: indicator

        count: view.count
        currentIndex: view.currentIndex

        anchors.bottom: view.bottom
        anchors.horizontalCenter: parent.horizontalCenter
    }
    SystemTrayIcon {
        visible: true
        iconSource: "qrc:/icons/hana.ico"
        iconName: "hana"

        onActivated: {
            window.show()
            window.raise()
            window.requestActivate()
        }
        tooltip: "HANA가 실행 중입니다."
        menu: Menu {
            MenuItem {
                text: qsTr("Quit")
                onTriggered: Qt.quit()
            }
        }
        onMessageClicked: console.log("Message clicked")

        Component.onCompleted: showMessage("HANA",
                                           "HANA가 실행 중입니다.",
                                           SystemTrayIcon.Critical,
                                           1)

        //Component.onCompleted: TrayIcon.showTrayMessage();
        Component.onDestruction: showMessage("HANA",
                                             "HANA가 마음에 드시나요?",
                                             Icon.url("qrc:/icons/hana.ico"),
                                             1)
    }
}



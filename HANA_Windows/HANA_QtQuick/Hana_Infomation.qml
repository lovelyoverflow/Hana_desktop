import QtQuick 2.0
import QtQuick.Controls 2.4
import QtQuick.Controls.Material 2.3

Item {
    Pane {
        x: window.width * 0.06
        y: x

        width: window.width * 0.2
        height: width

        enabled: true
        hoverEnabled: true
        Material.elevation: 10

        BorderImage {
            id: profile
            source: "qrc:/images/profile.jpg"
            anchors.fill: parent
            border.left: 5; border.top: 5
            border.right: 5; border.bottom: 5
        }
    }

    Text {
        id: name
        x: 382
        y: 133
        text: qsTr("박재훈 캘리그라퍼님")
        font.family: "맑은 고딕"
        font.pixelSize: window.width * 0.02
        font.bold: true
    }
    Text {
        x: 362
        y: 180
        text: "계정"
        color: "#feffef"
        font.family: "맑은 고딕"
        font.pixelSize: window.width * 0.015
    }
    Text {
        x: 420
        y: 180
        text: "lovelyoverflow@gmail.com"
        font.family: "맑은 고딕"
        font.pixelSize: window.width * 0.015
        font.bold: true
    }
}

/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/

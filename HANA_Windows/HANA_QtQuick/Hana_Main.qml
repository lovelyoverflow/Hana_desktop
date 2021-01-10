import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick.Controls 2.4
import QtQuick.Controls.Material 2.3

Item {
    Pane {
        id:servicePane
        x: parent.width * 0.07
        y: parent.height * 0.14
        width: parent.width * 0.2
        height: parent.height * 0.34
        enabled: true
        hoverEnabled: true
        Material.elevation: 5

        onHoveredChanged: {
            Material.elevation = hovered ? 10 : 5
        }
        Material.background: {
            color: window.color
            //color: "#8BC34A"
            //radius: 20
        }

        Column {
            spacing: 30

            Text {
                //anchors.fill: parent
                text: "Service Status of HANA"
                font.family: "Arial"
                font.pixelSize: window.width * 0.015
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
            }
            Text {
                text: "토글 버튼을 클릭하여\nHANA의 서비스 상태를 제어합니다."
                font.family: "맑은 고딕"
                font.pixelSize: window.width * 0.011
                font.bold: false
                horizontalAlignment: Text.AlignLeft
            }
        }
        Row {
            anchors.bottom: parent.bottom
            anchors.centerIn: parent.horizontalCenter

            Switch {
                id: service
                spacing: 10
                onCheckedChanged: {
                    if(checked)
                        CalliWidget.drawCalliWidget();
                    else
                        CalliWidget.deleteCalliWidget();
                }
            }
            Text {
                id: hanaStatus
                color: service.checked ? "#8BC34A" : "#9E9E9E"
                text: service.checked ? "HANA 활성화" : "HANA 비활성화"
                font.family: "Arial"
                font.pixelSize: window.width * 0.01
                verticalAlignment: Text.AlignVCenter
                font.bold: true
                height: parent.height
            }
        }
    }

    Column {
        id: calliInfo
        x: window.width * 0.05
        y: window.height * 0.6
        Text {
            text: TodayCalli.getTodayKor();
            font.family: "맑은 고딕"
            font.pixelSize: window.width * 0.015
        }
        Text {
            text: TodayCalli.getTodayPro()
            font.family: "Arial"
            font.pixelSize: window.width * 0.015
        }
        Text {
            text: TodayCalli.getTodayEng();
            font.family: "Arial"
            font.pixelSize: window.width * 0.015
        }
    }

    Pane {
        x: 769
        y: 469

        Material.elevation: 0

        Material.background: {
            color: window.color

        }
        BorderImage {
            id: mainCalli
            source: "qrc:/images/hana_calli.png"
            anchors.centerIn: parent
            border.left: 5; border.top: 5
            border.right: 5; border.bottom: 5
        }
    }
}



/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/

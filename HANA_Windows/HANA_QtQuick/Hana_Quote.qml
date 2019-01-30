import QtQuick 2.0
import QtQuick.Controls 2.4
import QtQuick.Controls.Material 2.3
import QtQuick.Layouts 1.3

Item {
    anchors.fill: window

    Column {
        anchors.centerIn: parent
        spacing: 30
        Row {
            spacing: 30
            Pane {
                width: window.width * 0.2
                height: window.height * 0.34
                enabled: true
                hoverEnabled: true
                Material.elevation: 5

                Image {
                    id: calli_1
                    sourceSize.width: parent.width
                    sourceSize.height: parent.height

                    source: "qrc:/images/hana_calli.png"
                }

                TabButton {
                    id: applyButton_1
                    height: 34
                    text: "Apply"
                    font.family: "Arial"
                    anchors.right: parent.right
                    anchors.bottom: parent.bottom
                    Material.accent: Material.Green

                    visible: false
                }

                onHoveredChanged: {
                    Material.elevation = hovered ? 10 : 5

                    applyButton_1.visible = hovered ? true : false
                }

                Material.background: {
                    color: window.color
                }
            }
            Pane {
                width: window.width * 0.2
                height: window.height * 0.34
                hoverEnabled: true
                enabled: true

                Material.elevation: 5

                onHoveredChanged: {
                    Material.elevation = hovered ? 10 : 5
                }
                Material.background: {
                    color: window.color

                }
            }

            Pane {
                width: window.width * 0.2
                height: window.height * 0.34
                hoverEnabled: true
                enabled: true

                Material.elevation: 5

                onHoveredChanged: {
                    Material.elevation = hovered ? 10 : 5
                }
                Material.background: {
                    color: window.color

                }
            }
        }
        Row {
            spacing: 30
            Pane {
                width: window.width * 0.2
                height: window.height * 0.34
                hoverEnabled: true
                enabled: true

                Material.elevation: 5

                onHoveredChanged: {
                    Material.elevation = hovered ? 10 : 5
                }
                Material.background: {
                    color: window.color

                }
            }

            Pane {
                width: window.width * 0.2
                height: window.height * 0.34
                hoverEnabled: true
                enabled: true

                Material.elevation: 5

                onHoveredChanged: {
                    Material.elevation = hovered ? 10 : 5
                }
                Material.background: {
                    color: window.color

                }
            }

            Pane {
                width: window.width * 0.2
                height: window.height * 0.34
                hoverEnabled: true
                enabled: true

                Material.elevation: 5

                onHoveredChanged: {
                    Material.elevation = hovered ? 10 : 5
                }
                Material.background: {
                    color: window.color
                }
            }
        }
    }
}

import QtQuick
import QtQuick.Controls

import Style 1.0
import Theme 1.0

Flow {
    id: root

    property string current

    signal selected(string accent)

    spacing: 12

    Repeater {
        model: Theme.accents

        AbstractButton {
            id: swatch

            width: 44
            height: 44

            hoverEnabled: true
            focusPolicy: Qt.NoFocus

            onClicked: root.selected(modelData)

            background: Rectangle {
                anchors.centerIn: parent

                width: 44
                height: 44
                radius: 22

                color: swatch.hovered ? AmneziaStyle.color.bgStateLayer : "transparent"
            }

            contentItem: Item {
                Rectangle {
                    anchors.centerIn: parent

                    width: 32
                    height: 32
                    radius: 16

                    color: modelData
                    border.width: root.current.toLowerCase() === modelData.toLowerCase() ? 3 : 0
                    border.color: AmneziaStyle.color.textPrimary
                }
            }
        }
    }
}

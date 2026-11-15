import QtQuick
import QtQuick.Controls
import QtQuick.Controls.impl
import QtQuick.Layouts

import Style 1.0

import "../Controls2/TextTypes"

AbstractButton {
    id: root

    property var themeData
    property bool selected

    implicitHeight: 64

    leftPadding: 16
    rightPadding: 16

    hoverEnabled: true
    focusPolicy: Qt.NoFocus

    background: Rectangle {
        radius: 16

        color: root.hovered ? AmneziaStyle.color.bgSurfaceAlt : AmneziaStyle.color.bgSurface
        border.width: root.selected ? 2 : 1
        border.color: root.selected ? AmneziaStyle.color.borderAccent : AmneziaStyle.color.borderFaint
    }

    contentItem: RowLayout {
        spacing: 16

        Row {
            Layout.alignment: Qt.AlignVCenter
            spacing: 6

            Repeater {
                model: root.themeData ? root.themeData.preview : []

                Rectangle {
                    width: 18
                    height: 18
                    radius: 5

                    color: modelData
                    border.width: 1
                    border.color: AmneziaStyle.color.borderFaint
                }
            }
        }

        BodyTextType {
            Layout.fillWidth: true

            text: root.themeData ? root.themeData.name : ""
            color: AmneziaStyle.color.textPrimary
            elide: Text.ElideRight
            maximumLineCount: 1
        }

        IconImage {
            Layout.alignment: Qt.AlignVCenter

            width: 24
            height: 24
            sourceSize: Qt.size(24, 24)

            visible: root.selected

            source: "qrc:/images/controls/check.svg"
            color: AmneziaStyle.color.accentDefault
        }
    }
}

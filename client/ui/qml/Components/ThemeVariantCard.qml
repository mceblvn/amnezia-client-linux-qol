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

    leftPadding: 12
    rightPadding: 12
    topPadding: 12
    bottomPadding: 12

    hoverEnabled: true
    focusPolicy: Qt.NoFocus

    background: Rectangle {
        radius: 16

        color: root.hovered ? AmneziaStyle.color.bgSurfaceAlt : AmneziaStyle.color.bgSurface
        border.width: root.selected ? 2 : 1
        border.color: root.selected ? AmneziaStyle.color.borderAccent : AmneziaStyle.color.borderFaint
    }

    contentItem: ColumnLayout {
        spacing: 8

        Row {
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
            wrapMode: Text.WordWrap
            maximumLineCount: 2
            elide: Text.ElideRight
        }
    }

    IconImage {
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.topMargin: 8
        anchors.rightMargin: 8

        width: 16
        height: 16
        sourceSize: Qt.size(16, 16)

        visible: root.selected

        source: "qrc:/images/controls/check.svg"
        color: AmneziaStyle.color.accentDefault
    }
}

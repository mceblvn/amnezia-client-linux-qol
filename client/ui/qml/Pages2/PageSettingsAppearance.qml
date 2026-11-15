import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import PageEnum 1.0
import Style 1.0
import Theme 1.0

import "./"
import "../Controls2"
import "../Controls2/TextTypes"
import "../Config"
import "../Components"

PageType {
    id: root

    FlickableType {
        id: flickable

        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right

        contentHeight: content.implicitHeight

        ColumnLayout {
            id: content

            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right

            spacing: 0

            NavigationBarType {
                Layout.fillWidth: true

                title: qsTr("Appearance")
            }

            ColumnLayout {
                Layout.fillWidth: true
                Layout.leftMargin: 16
                Layout.rightMargin: 16
                Layout.bottomMargin: 24 + PageController.safeAreaBottomMargin

                spacing: 8

                HeaderType {
                    Layout.fillWidth: true
                    Layout.topMargin: 8

                    headerText: qsTr("Theme")
                }

                ThemePreviewCard {
                    Layout.fillWidth: true

                    themeData: Theme.defaultTheme
                    selected: Theme.isDefaultTheme

                    onClicked: Theme.themeId = "default"
                }

                SegmentedControlType {
                    Layout.fillWidth: true

                    visible: Theme.isDefaultTheme
                    model: [qsTr("Dark"), qsTr("Light")]
                    currentIndex: Theme.scheme === "light" ? 1 : 0

                    onActivated: function(index) {
                        Theme.scheme = index === 1 ? "light" : "dark"
                    }
                }

                AccentSwatchGrid {
                    Layout.fillWidth: true

                    visible: Theme.isDefaultTheme
                    current: Theme.accent

                    onSelected: function(accent) {
                        Theme.accent = accent
                    }
                }

                Repeater {
                    model: Theme.themeFamilies

                    ColumnLayout {
                        id: familyBlock

                        Layout.fillWidth: true
                        Layout.topMargin: 8

                        spacing: 8

                        readonly property var variants: modelData.variants
                        readonly property var firstVariant: modelData.variants[0]

                        ThemePreviewCard {
                            Layout.fillWidth: true

                            visible: familyBlock.variants.length === 1
                            themeData: familyBlock.firstVariant
                            selected: Theme.themeId === familyBlock.firstVariant.id

                            onClicked: Theme.themeId = familyBlock.firstVariant.id
                        }

                        RowLayout {
                            Layout.fillWidth: true
                            spacing: 8

                            visible: familyBlock.variants.length > 1

                            Repeater {
                                model: familyBlock.variants

                                ThemeVariantCard {
                                    Layout.fillWidth: true
                                    Layout.fillHeight: true
                                    Layout.preferredWidth: 0

                                    themeData: modelData
                                    selected: Theme.themeId === modelData.id

                                    onClicked: Theme.themeId = modelData.id
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

pragma Singleton

import QtQuick

import Theme 1.0

QtObject {
    property QtObject color: QtObject {
        readonly property color transparent: Theme.palette.transparent

        readonly property color textPrimary: Theme.palette.textPrimary
        readonly property color textSecondary: Theme.palette.textSecondary
        readonly property color textTertiary: Theme.palette.textTertiary
        readonly property color textQuaternary: Theme.palette.textQuaternary
        readonly property color textInverted: Theme.palette.textInverted
        readonly property color textAccent: Theme.palette.textAccent
        readonly property color textInfoInverse: Theme.palette.textInfoInverse
        readonly property color textStaticWhite: Theme.palette.textStaticWhite

        readonly property color bgBase: Theme.palette.bgBase
        readonly property color bgSurface: Theme.palette.bgSurface
        readonly property color bgSurfaceAlt: Theme.palette.bgSurfaceAlt
        readonly property color bgSheet: Theme.palette.bgSheet
        readonly property color bgPanel: Theme.palette.bgPanel
        readonly property color bgPanelAlt: Theme.palette.bgPanelAlt
        readonly property color bgOverlay: Theme.palette.bgOverlay
        readonly property color bgStateLayer: Theme.palette.bgStateLayer
        readonly property color bgStateLayerPressed: Theme.palette.bgStateLayerPressed
        readonly property color bgStateLayerAccent: Theme.palette.bgStateLayerAccent
        readonly property color bgSurfaceInverse: Theme.palette.bgSurfaceInverse
        readonly property color bgSurfaceInverseAlt: Theme.palette.bgSurfaceInverseAlt
        readonly property color bgControlTrack: Theme.palette.bgControlTrack
        readonly property color bgField: Theme.palette.bgField
        readonly property color bgSelected: Theme.palette.bgSelected
        readonly property color bgAccentSubtle: Theme.palette.bgAccentSubtle
        readonly property color bgStaticWhite: Theme.palette.bgStaticWhite

        readonly property color bgAction: Theme.palette.bgAction
        readonly property color bgActionHover: Theme.palette.bgActionHover
        readonly property color bgActionPress: Theme.palette.bgActionPress

        readonly property color borderFaint: Theme.palette.borderFaint
        readonly property color borderSoft: Theme.palette.borderSoft
        readonly property color borderMedium: Theme.palette.borderMedium
        readonly property color borderBold: Theme.palette.borderBold
        readonly property color borderEmphasis: Theme.palette.borderEmphasis
        readonly property color borderAccent: Theme.palette.borderAccent
        readonly property color borderField: Theme.palette.borderField
        readonly property color borderFocus: Theme.palette.borderFocus

        readonly property color accentLight: Theme.palette.accentLight
        readonly property color accentDefault: Theme.palette.accentDefault
        readonly property color accentDark: Theme.palette.accentDark
        readonly property color accentDeep: Theme.palette.accentDeep

        readonly property color statusDestructive: Theme.palette.statusDestructive
        readonly property color statusWarning: Theme.palette.statusWarning
        readonly property color statusSuccess: Theme.palette.statusSuccess

        readonly property color promoRecommendation: Theme.palette.promoRecommendation
        readonly property color promoUpdate: Theme.palette.promoUpdate
        readonly property color promoOverlay: Theme.palette.promoOverlay
        readonly property color promoPink: Theme.palette.promoPink
        readonly property color promoPinkDeep: Theme.palette.promoPinkDeep

        readonly property color iconDefault: Theme.palette.iconDefault
        readonly property color iconSecondary: Theme.palette.iconSecondary
        readonly property color iconTertiary: Theme.palette.iconTertiary
        readonly property color iconInverted: Theme.palette.iconInverted

        readonly property color shadowLayer1: Theme.palette.shadowLayer1
        readonly property color shadowLayer2: Theme.palette.shadowLayer2
        readonly property color shadowGlow: Theme.palette.shadowGlow
    }
}

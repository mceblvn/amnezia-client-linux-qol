#include "themePalette.h"

namespace
{
QColor color(const char *value)
{
    return QColor(QString::fromLatin1(value));
}

QColor mixed(const QColor &from, const QColor &to, qreal ratio)
{
    return QColor::fromRgbF(from.redF() + (to.redF() - from.redF()) * ratio,
                            from.greenF() + (to.greenF() - from.greenF()) * ratio,
                            from.blueF() + (to.blueF() - from.blueF()) * ratio);
}

QColor withAlpha(const QColor &color, int alpha)
{
    QColor result = color;
    result.setAlpha(alpha);
    return result;
}
}

namespace ThemePalettes
{

ThemePalette amnezia(bool isLight)
{
    if (isLight) {
        return { "default", "Amnezia", "Amnezia", true,
                 color("#FAFAFA"), color("#F4F4F5"), color("#EBEBED"), color("#E1E1E4"), color("#D6D6DA"), color("#C9C9CE"),
                 color("#101012"), color("#3F3F46"), color("#6B6B76"), color("#86868F"),
                 color("#F59E0B"),
                 color("#DC2626"), color("#CA8A04"), color("#15803D") };
    }

    return { "default", "Amnezia", "Amnezia", false,
             color("#101012"), color("#18181B"), color("#1F1F23"), color("#313136"), color("#3F3F46"), color("#52525B"),
             color("#FAFAFA"), color("#E4E4E7"), color("#A1A1AA"), color("#86868F"),
             color("#F59E0B"),
             color("#F87171"), color("#EAB308"), color("#4ADE80") };
}

QList<ThemePalette> presets()
{
    return {
        { "catppuccin-latte", "Catppuccin Latte", "Catppuccin", true,
          color("#EFF1F5"), color("#E6E9EF"), color("#DCE0E8"), color("#CCD0DA"), color("#BCC0CC"), color("#ACB0BE"),
          color("#4C4F69"), color("#5C5F77"), color("#6C6F85"), color("#8C8FA1"),
          color("#8839EF"),
          color("#D20F39"), color("#DF8E1D"), color("#40A02B") },

        { "catppuccin-mocha", "Catppuccin Mocha", "Catppuccin", false,
          color("#1E1E2E"), color("#24243A"), color("#313244"), color("#45475A"), color("#585B70"), color("#6C7086"),
          color("#CDD6F4"), color("#BAC2DE"), color("#A6ADC8"), color("#7F849C"),
          color("#CBA6F7"),
          color("#F38BA8"), color("#F9E2AF"), color("#A6E3A1") },

        { "dracula", "Dracula", "Dracula", false,
          color("#282A36"), color("#2E3040"), color("#343746"), color("#44475A"), color("#4E5166"), color("#6272A4"),
          color("#F8F8F2"), color("#D8D8E0"), color("#A8A8B8"), color("#6272A4"),
          color("#BD93F9"),
          color("#FF5555"), color("#F1FA8C"), color("#50FA7B") },

        { "dracula-alucard", "Dracula Alucard", "Dracula", true,
          color("#FFFBEB"), color("#F7F1DE"), color("#EFE9D5"), color("#CFCFDE"), color("#C0C0D0"), color("#A8A8B8"),
          color("#1F1F1F"), color("#3A3A3A"), color("#6C664B"), color("#8A8570"),
          color("#644AC9"),
          color("#CB3A2A"), color("#846E15"), color("#14710A") },

        { "everforest", "Everforest", "Everforest", false,
          color("#272E33"), color("#2E383C"), color("#374145"), color("#414B50"), color("#4F5B58"), color("#5C6A72"),
          color("#D3C6AA"), color("#C5B89E"), color("#A6A08A"), color("#859289"),
          color("#A7C080"),
          color("#E67E80"), color("#DBBC7F"), color("#A7C080") },

        { "graphite-violet", "Graphite Violet", "Graphite Violet", false,
          color("#0D0D10"), color("#131317"), color("#1A1A20"), color("#232329"), color("#2E2E37"), color("#3A3A45"),
          color("#E2E0EA"), color("#A7A3B3"), color("#6E6A7B"), color("#55515F"),
          color("#8B5CF6"),
          color("#F07178"), color("#FFD580"), color("#7EE787") },

        { "kanagawa", "Kanagawa", "Kanagawa", false,
          color("#1F1F28"), color("#2A2A37"), color("#363646"), color("#54546D"), color("#62627D"), color("#727169"),
          color("#DCD7BA"), color("#C8C093"), color("#A6A69C"), color("#727169"),
          color("#7E9CD8"),
          color("#E46876"), color("#E6C384"), color("#98BB6C") },

        { "nord", "Nord", "Nord", false,
          color("#2E3440"), color("#3B4252"), color("#434C5E"), color("#4C566A"), color("#5A6478"), color("#6A7488"),
          color("#ECEFF4"), color("#E5E9F0"), color("#D8DEE9"), color("#A3AEC2"),
          color("#88C0D0"),
          color("#BF616A"), color("#EBCB8B"), color("#A3BE8C") },

        { "rose-pine-dawn", "Rosé Pine Dawn", "Rosé Pine", true,
          color("#FAF4ED"), color("#F2E9E1"), color("#EAE0D8"), color("#E0D6CE"), color("#D5CBC4"), color("#C9BFB8"),
          color("#464261"), color("#575279"), color("#797593"), color("#9893A5"),
          color("#907AA9"),
          color("#B4637A"), color("#EA9D34"), color("#286983") },

        { "rose-pine-moon", "Rosé Pine Moon", "Rosé Pine", false,
          color("#232136"), color("#2A273F"), color("#393552"), color("#44415A"), color("#524F67"), color("#5F5C74"),
          color("#E0DEF4"), color("#C8C4E0"), color("#908CAA"), color("#6E6A86"),
          color("#C4A7E7"),
          color("#EB6F92"), color("#F6C177"), color("#9CCFD8") },

        { "tokyo-night", "Tokyo Night", "Tokyo Night", false,
          color("#1A1B26"), color("#1F2335"), color("#24283B"), color("#292E42"), color("#414868"), color("#545C7E"),
          color("#C0CAF5"), color("#A9B1D6"), color("#737AA2"), color("#565F89"),
          color("#7AA2F7"),
          color("#F7768E"), color("#E0AF68"), color("#9ECE6A") },
    };
}

ThemePalette byId(const QString &id)
{
    for (const ThemePalette &palette : presets()) {
        if (palette.id == id) {
            return palette;
        }
    }

    return amnezia(false);
}

QString hexColor(const QColor &color)
{
    return color.alpha() == 255 ? color.name(QColor::HexRgb) : color.name(QColor::HexArgb);
}

QVariantMap tokens(const ThemePalette &palette)
{
    const bool isLight = palette.isLight;

    const QColor accent = palette.accent;
    const QColor accentLight = mixed(accent, Qt::white, isLight ? 0.10 : 0.35);
    const QColor accentDark = mixed(accent, Qt::black, 0.25);
    const QColor accentDeep = mixed(accent, Qt::black, isLight ? 0.55 : 0.65);
    const QColor accentText = isLight ? accentDark : accentLight;
    const QColor accentBorder = isLight ? accent : accentLight;

    QVariantMap tokens;
    tokens.insert(QStringLiteral("transparent"), QStringLiteral("transparent"));

    tokens.insert(QStringLiteral("textPrimary"), hexColor(palette.fg0));
    tokens.insert(QStringLiteral("textSecondary"), hexColor(palette.fg1));
    tokens.insert(QStringLiteral("textTertiary"), hexColor(palette.fg2));
    tokens.insert(QStringLiteral("textQuaternary"), hexColor(palette.fg3));
    tokens.insert(QStringLiteral("textInverted"), hexColor(palette.bg0));
    tokens.insert(QStringLiteral("textAccent"), hexColor(accentText));
    tokens.insert(QStringLiteral("textInfoInverse"), QStringLiteral("#0369A1"));
    tokens.insert(QStringLiteral("textStaticWhite"), QStringLiteral("#FFFFFF"));

    tokens.insert(QStringLiteral("bgBase"), hexColor(palette.bg0));
    tokens.insert(QStringLiteral("bgSurface"), hexColor(palette.bg1));
    tokens.insert(QStringLiteral("bgSurfaceAlt"), hexColor(palette.bg2));
    tokens.insert(QStringLiteral("bgSheet"), hexColor(palette.bg3));
    tokens.insert(QStringLiteral("bgPanel"), hexColor(palette.bg4));
    tokens.insert(QStringLiteral("bgPanelAlt"), hexColor(palette.bg5));
    tokens.insert(QStringLiteral("bgOverlay"), isLight ? QStringLiteral("#66000000") : QStringLiteral("#8009090B"));
    tokens.insert(QStringLiteral("bgStateLayer"), hexColor(withAlpha(palette.fg0, 0x14)));
    tokens.insert(QStringLiteral("bgStateLayerPressed"), hexColor(withAlpha(palette.fg0, 0x1A)));
    tokens.insert(QStringLiteral("bgStateLayerAccent"), hexColor(withAlpha(accent, 0x14)));
    tokens.insert(QStringLiteral("bgSurfaceInverse"), hexColor(palette.fg1));
    tokens.insert(QStringLiteral("bgSurfaceInverseAlt"), hexColor(palette.fg2));
    tokens.insert(QStringLiteral("bgControlTrack"), hexColor(palette.bg2));
    tokens.insert(QStringLiteral("bgField"), hexColor(palette.bg2));
    tokens.insert(QStringLiteral("bgSelected"), hexColor(palette.bg2));
    tokens.insert(QStringLiteral("bgAccentSubtle"), hexColor(withAlpha(accentDeep, 0x4D)));
    tokens.insert(QStringLiteral("bgStaticWhite"), QStringLiteral("#FFFFFF"));

    tokens.insert(QStringLiteral("bgAction"), hexColor(palette.fg1));
    tokens.insert(QStringLiteral("bgActionHover"), hexColor(mixed(palette.fg1, palette.fg2, 0.5)));
    tokens.insert(QStringLiteral("bgActionPress"), hexColor(palette.fg2));

    tokens.insert(QStringLiteral("borderFaint"), hexColor(palette.bg3));
    tokens.insert(QStringLiteral("borderSoft"), hexColor(palette.bg4));
    tokens.insert(QStringLiteral("borderMedium"), hexColor(palette.bg5));
    tokens.insert(QStringLiteral("borderBold"), hexColor(palette.fg2));
    tokens.insert(QStringLiteral("borderEmphasis"), hexColor(palette.fg1));
    tokens.insert(QStringLiteral("borderAccent"), hexColor(accentBorder));
    tokens.insert(QStringLiteral("borderField"), hexColor(palette.bg5));
    tokens.insert(QStringLiteral("borderFocus"), hexColor(palette.fg1));

    tokens.insert(QStringLiteral("accentLight"), hexColor(accentLight));
    tokens.insert(QStringLiteral("accentDefault"), hexColor(accent));
    tokens.insert(QStringLiteral("accentDark"), hexColor(accentDark));
    tokens.insert(QStringLiteral("accentDeep"), hexColor(accentDeep));

    tokens.insert(QStringLiteral("statusDestructive"), hexColor(palette.destructive));
    tokens.insert(QStringLiteral("statusWarning"), hexColor(palette.warning));
    tokens.insert(QStringLiteral("statusSuccess"), hexColor(palette.success));

    tokens.insert(QStringLiteral("promoRecommendation"), hexColor(accentLight));
    tokens.insert(QStringLiteral("promoUpdate"), hexColor(accent));
    tokens.insert(QStringLiteral("promoOverlay"), hexColor(withAlpha(accent, 0x14)));
    tokens.insert(QStringLiteral("promoPink"), QStringLiteral("#DB2777"));
    tokens.insert(QStringLiteral("promoPinkDeep"), QStringLiteral("#9D174D"));

    tokens.insert(QStringLiteral("iconDefault"), hexColor(palette.fg1));
    tokens.insert(QStringLiteral("iconSecondary"), hexColor(palette.fg2));
    tokens.insert(QStringLiteral("iconTertiary"), hexColor(palette.bg4));
    tokens.insert(QStringLiteral("iconInverted"), hexColor(palette.bg0));

    tokens.insert(QStringLiteral("shadowLayer1"), isLight ? QStringLiteral("#14000000") : QStringLiteral("#26000000"));
    tokens.insert(QStringLiteral("shadowLayer2"), isLight ? QStringLiteral("#29000000") : QStringLiteral("#4D000000"));
    tokens.insert(QStringLiteral("shadowGlow"), hexColor(accent));

    return tokens;
}

}

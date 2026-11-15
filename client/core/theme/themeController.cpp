#include "themeController.h"

#include <QColor>
#include <QMap>

#include "secureQSettings.h"

namespace
{
const QStringList &accentColors()
{
    static const QStringList colors = {
        QStringLiteral("#F59E0B"), QStringLiteral("#FB923C"), QStringLiteral("#EF4444"),
        QStringLiteral("#EC4899"), QStringLiteral("#A855F7"), QStringLiteral("#8B5CF6"),
        QStringLiteral("#6366F1"), QStringLiteral("#3B82F6"), QStringLiteral("#0EA5E9"),
        QStringLiteral("#14B8A6"), QStringLiteral("#22C55E"), QStringLiteral("#84CC16")
    };
    return colors;
}
}

namespace
{
QVariantMap variantEntry(const ThemePalette &palette)
{
    QVariantMap entry;
    entry.insert(QStringLiteral("id"), palette.id);
    entry.insert(QStringLiteral("name"), palette.name);
    entry.insert(QStringLiteral("family"), palette.family);
    entry.insert(QStringLiteral("isLight"), palette.isLight);
    entry.insert(QStringLiteral("accent"), ThemePalettes::hexColor(palette.accent));
    entry.insert(QStringLiteral("preview"), QVariantList { ThemePalettes::hexColor(palette.bg0),
                                                           ThemePalettes::hexColor(palette.bg2),
                                                           ThemePalettes::hexColor(palette.accent),
                                                           ThemePalettes::hexColor(palette.fg0) });
    return entry;
}
}

ThemeController::ThemeController(SecureQSettings *settings, QObject *parent)
    : QObject(parent),
      m_settings(settings)
{
    m_themeId = m_settings->value(QStringLiteral("Conf/themeId"), QStringLiteral("default")).toString();
    m_accent = m_settings->value(QStringLiteral("Conf/accentColor"), QStringLiteral("#F59E0B")).toString();
    m_scheme = m_settings->value(QStringLiteral("Conf/colorScheme"), QStringLiteral("dark")).toString();

    if (m_scheme != QLatin1String("light")) {
        m_scheme = QStringLiteral("dark");
    }
    if (!QColor(m_accent).isValid()) {
        m_accent = QStringLiteral("#F59E0B");
    }

    rebuild();
}

void ThemeController::setThemeId(const QString &themeId)
{
    const QString normalized = themeId == QLatin1String("default")
            ? QStringLiteral("default")
            : ThemePalettes::byId(themeId).id;

    if (m_themeId == normalized) {
        return;
    }

    m_themeId = normalized;
    store(QStringLiteral("Conf/themeId"), m_themeId);
    rebuild();
    emit themeIdChanged();
    emit paletteChanged();
}

void ThemeController::setAccent(const QString &accent)
{
    if (m_accent == accent || !QColor(accent).isValid()) {
        return;
    }

    m_accent = accent;
    store(QStringLiteral("Conf/accentColor"), m_accent);
    rebuild();
    emit accentChanged();
    emit paletteChanged();
}

void ThemeController::setScheme(const QString &scheme)
{
    const QString normalized = scheme == QLatin1String("light") ? QStringLiteral("light") : QStringLiteral("dark");

    if (m_scheme == normalized) {
        return;
    }

    m_scheme = normalized;
    store(QStringLiteral("Conf/colorScheme"), m_scheme);
    rebuild();
    emit schemeChanged();
    emit paletteChanged();
}

bool ThemeController::isDefaultTheme() const
{
    return m_themeId == QLatin1String("default");
}

QStringList ThemeController::accents() const
{
    return accentColors();
}

QVariantMap ThemeController::defaultTheme() const
{
    ThemePalette palette = ThemePalettes::amnezia(m_scheme == QLatin1String("light"));
    palette.accent = QColor(m_accent);

    return variantEntry(palette);
}

QVariantList ThemeController::themeFamilies() const
{
    QMap<QString, QVariantList> grouped;

    for (const ThemePalette &palette : ThemePalettes::presets()) {
        QVariantList variants = grouped.value(palette.family);
        if (palette.isLight) {
            variants.append(variantEntry(palette));
        } else {
            variants.prepend(variantEntry(palette));
        }
        grouped.insert(palette.family, variants);
    }

    QVariantList families;
    for (auto it = grouped.constBegin(); it != grouped.constEnd(); ++it) {
        QVariantMap family;
        family.insert(QStringLiteral("name"), it.key());
        family.insert(QStringLiteral("variants"), it.value());
        families.append(family);
    }

    return families;
}

ThemePalette ThemeController::activePalette() const
{
    if (isDefaultTheme()) {
        ThemePalette palette = ThemePalettes::amnezia(m_scheme == QLatin1String("light"));
        palette.accent = QColor(m_accent);
        return palette;
    }

    return ThemePalettes::byId(m_themeId);
}

void ThemeController::rebuild()
{
    m_palette = ThemePalettes::tokens(activePalette());
}

void ThemeController::store(const QString &key, const QVariant &value)
{
    m_settings->setValue(key, value);
}

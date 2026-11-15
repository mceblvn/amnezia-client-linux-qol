#ifndef THEMECONTROLLER_H
#define THEMECONTROLLER_H

#include <QObject>
#include <QStringList>
#include <QVariantList>
#include <QVariantMap>

#include "themePalette.h"

class SecureQSettings;

class ThemeController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantMap palette READ palette NOTIFY paletteChanged)
    Q_PROPERTY(QString themeId READ themeId WRITE setThemeId NOTIFY themeIdChanged)
    Q_PROPERTY(QString accent READ accent WRITE setAccent NOTIFY accentChanged)
    Q_PROPERTY(QString scheme READ scheme WRITE setScheme NOTIFY schemeChanged)
    Q_PROPERTY(bool isDefaultTheme READ isDefaultTheme NOTIFY themeIdChanged)
    Q_PROPERTY(QVariantMap defaultTheme READ defaultTheme NOTIFY paletteChanged)
    Q_PROPERTY(QVariantList themeFamilies READ themeFamilies NOTIFY paletteChanged)
    Q_PROPERTY(QStringList accents READ accents CONSTANT)

public:
    explicit ThemeController(SecureQSettings *settings, QObject *parent = nullptr);

    QVariantMap palette() const { return m_palette; }

    QString themeId() const { return m_themeId; }
    void setThemeId(const QString &themeId);

    QString accent() const { return m_accent; }
    void setAccent(const QString &accent);

    QString scheme() const { return m_scheme; }
    void setScheme(const QString &scheme);

    bool isDefaultTheme() const;
    QVariantMap defaultTheme() const;
    QVariantList themeFamilies() const;
    QStringList accents() const;

signals:
    void paletteChanged();
    void themeIdChanged();
    void accentChanged();
    void schemeChanged();

private:
    ThemePalette activePalette() const;
    void rebuild();
    void store(const QString &key, const QVariant &value);

    SecureQSettings *m_settings = nullptr;
    QString m_themeId;
    QString m_accent;
    QString m_scheme;
    QVariantMap m_palette;
};

#endif

#ifndef THEMEPALETTE_H
#define THEMEPALETTE_H

#include <QColor>
#include <QList>
#include <QString>
#include <QVariantMap>

struct ThemePalette
{
    QString id;
    QString name;
    QString family;
    bool isLight = false;
    QColor bg0;
    QColor bg1;
    QColor bg2;
    QColor bg3;
    QColor bg4;
    QColor bg5;
    QColor fg0;
    QColor fg1;
    QColor fg2;
    QColor fg3;
    QColor accent;
    QColor destructive;
    QColor warning;
    QColor success;
};

namespace ThemePalettes
{
    QList<ThemePalette> presets();
    ThemePalette byId(const QString &id);
    ThemePalette amnezia(bool isLight);
    QVariantMap tokens(const ThemePalette &palette);
    QString hexColor(const QColor &color);
}

#endif

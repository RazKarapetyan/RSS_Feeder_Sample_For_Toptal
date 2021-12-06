#ifndef RSSCOMMON_H
#define RSSCOMMON_H

#include <QString>
#include <QSet>
#include <QDebug>
#include <QUrl>

// Mapping between description and URL
using RSSNewsDescription = QString;
using News = QHash<RSSNewsDescription, QString>;
using NewsIterator = QHashIterator<RSSNewsDescription, QString>;

#endif // RSSCOMMON_H

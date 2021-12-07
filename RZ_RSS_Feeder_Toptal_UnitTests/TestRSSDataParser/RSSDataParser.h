#ifndef RSSDATAPARSER_H
#define RSSDATAPARSER_H

#include <QByteArray>

/**
 * Simple parser of RSS XML
 *
 * Retrievs descriptions and URLs from the data
 */
class RSSDataParser
{
public:
    using News = QHash<QString, QString>;

    RSSDataParser() = default;

public:
    static News Parse(const QByteArray& data);
    static bool Validate(const QByteArray& data);
};

#endif // RSSDATAPARSER_H

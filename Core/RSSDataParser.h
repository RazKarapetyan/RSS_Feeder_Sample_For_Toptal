#ifndef RSSDATAPARSER_H
#define RSSDATAPARSER_H

#include <QByteArray>

#include "Common/RSSCommon.h"

/**
 * Simple parser of RSS XML
 *
 * Retrievs descriptions and URLs from the data
 */
class RSSDataParser
{
public:
    RSSDataParser() = default;

public:
    static News Parse(const QByteArray& data);
    static bool Validate(const QByteArray& data);
};

#endif // RSSDATAPARSER_H

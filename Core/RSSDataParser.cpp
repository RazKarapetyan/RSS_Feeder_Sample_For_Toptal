#include "RSSDataParser.h"

#include <QXmlStreamReader>
#include <QSet>

/*static*/ NewsUrls RSSDataParser::Parse(const QByteArray& data)
{
    const auto xmlReader = new QXmlStreamReader(data);
    NewsUrls availableUrls;

    //Parse the XML until we reach end of it
    while(!xmlReader->atEnd() && !xmlReader->hasError()) {
        // Read next element
        QXmlStreamReader::TokenType token = xmlReader->readNext();
        //If token is just StartDocument - go to next
        if(token == QXmlStreamReader::StartDocument) {
            continue;
        }
        //If token is StartElement - read it
        if(token == QXmlStreamReader::StartElement) {
            if(xmlReader->name() == "link") {
                availableUrls << xmlReader->readElementText();
            }
        }
    }

    if(xmlReader->hasError()) {
        //showMessage(tr("Parse error"), xmlReader->errorString());
    }

    xmlReader->clear();
    return availableUrls;
}


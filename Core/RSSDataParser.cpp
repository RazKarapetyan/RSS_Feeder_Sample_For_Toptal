#include "RSSDataParser.h"

#include <QXmlStreamReader>

namespace  {
    /**
     * Simple TokenType enum converter to human readable string
     * Used for debugging puposes
     */
    QString EnumToString(QXmlStreamReader::TokenType enumVal)
    {
        switch (enumVal) {
        case  QXmlStreamReader::NoToken:
            return "NoToken";
        case  QXmlStreamReader::Invalid:
            return "Invalid";
        case  QXmlStreamReader::StartDocument:
            return "StartDocument";
        case  QXmlStreamReader::EndDocument:
            return "EndDocument";
        case  QXmlStreamReader::StartElement:
            return "StartElement";
        case  QXmlStreamReader::EndElement:
            return "EndElement";
        case  QXmlStreamReader::Characters:
            return "Characters";
        case  QXmlStreamReader::Comment:
            return "Comment";
        case  QXmlStreamReader::DTD:
            return "DTD";
        case  QXmlStreamReader::EntityReference:
            return "EntityReference";
        case  QXmlStreamReader::ProcessingInstruction:
            return "ProcessingInstruction";
        }
    }
}

/*static*/ News RSSDataParser::Parse(const QByteArray& data)
{
    const auto xmlReader = new QXmlStreamReader(data);
    News availableNews;

    while(!xmlReader->atEnd() && !xmlReader->hasError())
    {
        if (xmlReader->readNextStartElement())
        {
            if (xmlReader->name() == "item")
            {
                RSSNewsDescription description {};
                QString url {};
                while(xmlReader->readNextStartElement())
                {
                    if(xmlReader->name() == "title")
                    {
                        description = xmlReader->readElementText();
                    } else if(xmlReader->name() == "link")
                    {
                        url = xmlReader->readElementText();
                    } else
                    {
                        xmlReader->skipCurrentElement();
                    }
                }
                availableNews.insert(description, url);
            }
        }
    }

    if(xmlReader->hasError())
    {
        qDebug() << xmlReader->errorString();
        return News();
    }

    xmlReader->clear();
    delete xmlReader;
    return availableNews;
}

#include <QMetaEnum>

/*static*/ bool RSSDataParser::Validate(const QByteArray &data)
{
    // RSS XML first start element should be rss
    QXmlStreamReader xmlReader(data);
    xmlReader.readNextStartElement();
    return xmlReader.name() == "rss";
}



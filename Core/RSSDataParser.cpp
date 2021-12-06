#include "RSSDataParser.h"

#include <QXmlStreamReader>

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
        return availableNews;
    }

    xmlReader->clear();
    return availableNews;
}


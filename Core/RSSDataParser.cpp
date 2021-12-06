#include "RSSDataParser.h"

#include <QXmlStreamReader>

/*static*/ News RSSDataParser::Parse(const QByteArray& data)
{
    const auto xmlReader = new QXmlStreamReader(data);
    News availableNews;

    //Parse the XML until we reach end of it
    while(!xmlReader->atEnd() && !xmlReader->hasError())
    {
        // Read next element
        QXmlStreamReader::TokenType token = xmlReader->readNext();
        //If token is just StartDocument - go to next
        if(token == QXmlStreamReader::StartDocument)
        {
            continue;
        }
        //If token is StartElement - read it
        if(token == QXmlStreamReader::StartElement)
        {
            RSSNewsDescription description {};
            QString url {};
            if(xmlReader->name() == "title")
            {
                description = xmlReader->readElementText();
            }
            if(xmlReader->name() == "link")
            {
                url = xmlReader->readElementText();
            }

            qDebug() << "description: " << description << " link: " << url ;
        }
    }

    if(xmlReader->hasError())
    {
        return availableNews;
    }

    xmlReader->clear();
    return availableNews;
}


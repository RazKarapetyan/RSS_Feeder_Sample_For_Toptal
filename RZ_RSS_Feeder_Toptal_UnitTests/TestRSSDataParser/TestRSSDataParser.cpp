#include "TestRSSDataParser.h"

void TestRSSDataParser::testParsingFlow()
{
    QFile testdataFile(":/testData/testParsingData.xml");
    if(testdataFile.open(QIODevice::ReadOnly))
    {
        QByteArray testData = testdataFile.readAll();
        QHash<QString, QString> parsingResult = RSSDataParser::Parse(testData);
        QHash<QString, QString> expectedResult;
        expectedResult.insert("RSS Tutorial", "https://www.w3schools.com/xml/xml_rss.asp");
        expectedResult.insert("XML Tutorial", "https://www.w3schools.com/xml");
        QVERIFY(parsingResult == expectedResult);
    }
    else
    {
        QFAIL("Cant open file to read the test data");
    }
}

void TestRSSDataParser::testValidatingFlow()
{
    QFile testdataFileRSS(":/testData/testValidatingDataRSS.xml");
    QFile testdataFileNonRSS(":/testData/testValidatingDataNonRSS.xml");

    if(testdataFileRSS.open(QIODevice::ReadOnly))
    {
        bool validatingResult = RSSDataParser::Validate(testdataFileRSS.readAll());
        QCOMPARE(validatingResult, true);
    }
    else
    {
        QFAIL("Cant open file to read the test data");
    }

    if(testdataFileNonRSS.open(QIODevice::ReadOnly))
    {
        bool validatingResult = RSSDataParser::Validate(testdataFileNonRSS.readAll());
        QCOMPARE(validatingResult, false);
    }
    else
    {
        QFAIL("Cant open file to read the test data");
    }

}

// generate basic main: no GUI, no events
QTEST_APPLESS_MAIN(TestRSSDataParser)

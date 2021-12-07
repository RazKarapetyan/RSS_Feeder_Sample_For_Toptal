#pragma once

#include "RSSDataParser.h"

#include <QtTest>

class TestRSSDataParser: public QObject
{
	Q_OBJECT

private slots:
    void testParsingFlow();
    void testValidatingFlow();
};

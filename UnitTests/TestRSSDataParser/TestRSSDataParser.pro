QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \ 
    TestRSSDataParser.cpp \
    RSSDataParser.cpp

HEADERS += \
    RSSDataParser.h \
    TestRSSDataParser.h

RESOURCES += \
    testResources.qrc

QT += testlib network
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    NetworkManager.cpp \
    TestNetworkManager.cpp

HEADERS += \
    NetworkManager.h \
    TestNetworkManager.h

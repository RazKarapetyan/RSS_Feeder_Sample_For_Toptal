#pragma once

#include "NetworkManager.h"

#include <QtTest>

class TestNetworkManager: public QObject
{
	Q_OBJECT

private slots:
	void init();

    void testGoodURL();
    void testBadURL();

private:
    NetworkManager* m_network;
    bool m_expectedNetworkFailure;
};

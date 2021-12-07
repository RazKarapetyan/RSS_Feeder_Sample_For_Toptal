#include "TestNetworkManager.h"

void TestNetworkManager::init()
{
    m_network = new NetworkManager;
    QObject::connect(m_network, &NetworkManager::finished,
                this, [=](QNetworkReply* reply) {
                    if (reply->error())
                    {
                        if(m_expectedNetworkFailure != true)
                        {
                            QString msg = QString("Network test was failed when reaching out to ") + reply->url().toString();
                            QFAIL(msg.toStdString().c_str());
                        }
                        else
                        {
                            qDebug() << QString("Network test was successful when reaching out to ") + reply->url().toString();
                        }
                        return;
                    }
                    qDebug() << reply->readAll();
        });
}

void TestNetworkManager::testGoodURL()
{
    m_expectedNetworkFailure = true;
    m_network->performRequest("https://www.google.com/");
}

void TestNetworkManager::testBadURL()
{
    m_expectedNetworkFailure = false;
    m_network->performRequest("https://www.google.xxx/");
}

// generate basic main: no GUI, no events
QTEST_APPLESS_MAIN(TestNetworkManager)

// uncomment next line if class declaration is in .cpp (no .h)
//#include "TestCalculator.moc"

#include "NetworkManager.h"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

NetworkManager::NetworkManager()
{
    m_manager = new QNetworkAccessManager();

    QObject::connect(m_manager, &QNetworkAccessManager::finished,
            this, [=](QNetworkReply* reply) {
                emit finished(reply);
            }
     );
}

void NetworkManager::performRequest(QString url)
{
    QNetworkRequest request(url);
    if(request.url().isValid())
    {
        m_manager->get(request);
    }
}


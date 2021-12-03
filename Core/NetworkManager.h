#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

class QNetworkAccessManager;

#include <QObject>

class NetworkManager : public QObject
{
    Q_OBJECT

public:
    NetworkManager();
    void performRequest(QString url);

private:
    QNetworkAccessManager* m_manager;
};

#endif // NETWORKMANAGER_H

#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

class QNetworkAccessManager;
class QNetworkReply;

#include <QObject>

/**
 * Simple wrapper over Qt QNetworkAccessManager
 *
 * Now it is on top of QNetworkAccessManager, later on we can change the underlying engine to use CURL,
 * or some socket connection, without affecting the NetworkManager interface.
 *
 */
class NetworkManager : public QObject
{
    Q_OBJECT

public:
    NetworkManager();
    void performRequest(QString url);

signals:
    void finished(QNetworkReply* reply);

private:
    QNetworkAccessManager* m_manager;
};

#endif // NETWORKMANAGER_H

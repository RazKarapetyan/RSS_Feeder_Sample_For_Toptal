#ifndef RSSFEEDER_H
#define RSSFEEDER_H

#include <QWidget>
#include <memory>

class QLineEdit;
class QTreeWidget;
class QPushButton;
class NetworkManager;

class RSSFeeder : public QWidget
{
    Q_OBJECT

public:
    RSSFeeder(QWidget* parent = nullptr);
    ~RSSFeeder() = default;

public slots:
    void configureFetchButton(QString url);

private:
    void setupLayout();
    void setupNetwork();

    void showMessage(QString msgTitle, QString msg);

    void fetchData();

private:
    QLineEdit* m_urlControl;
    QPushButton* m_fetchButton;
    QTreeWidget* m_newsTree;

    NetworkManager* m_network;
};

#endif // RSSFEEDER_H

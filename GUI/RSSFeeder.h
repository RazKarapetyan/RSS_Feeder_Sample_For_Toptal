#ifndef RSSFEEDER_H
#define RSSFEEDER_H

#include <QWidget>
#include <memory>

class QLineEdit;
class QTreeWidget;
class NetworkManager;

class RSSFeeder : public QWidget,
                  public std::enable_shared_from_this<RSSFeeder>
{
    Q_OBJECT

public:
    RSSFeeder(QWidget* parent = nullptr);
    ~RSSFeeder() = default;

private:
    void setupLayout();
    void setupNetwork();

    void fetchData();

private:
    QLineEdit* m_urlControl;
    QTreeWidget* m_newsTree;

    NetworkManager* m_network;
};

#endif // RSSFEEDER_H

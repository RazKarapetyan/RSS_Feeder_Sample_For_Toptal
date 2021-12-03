#ifndef RSSFEEDER_H
#define RSSFEEDER_H

#include <QWidget>

class QLineEdit;
class QTreeWidget;

class RSSFeeder : public QWidget
{
    Q_OBJECT

public:
    RSSFeeder(QWidget* parent = nullptr);
    ~RSSFeeder() = default;

private:
    void setupLayout();

private:
    QLineEdit* m_urlControl;
    QTreeWidget* m_newsTree;
};

#endif // RSSFEEDER_H

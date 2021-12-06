#include "RSSFeeder.h"

#include <QLineEdit>
#include <QPushButton>
#include <QTreeWidget>

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QNetworkReply>
#include <QMessageBox>
#include <QDebug>

#include <iostream> //raz
#include "Core/NetworkManager.h"

namespace  {
    constexpr uint WindowMinWidth = 700;
    constexpr uint WindowMinHeight = 350;
}

RSSFeeder::RSSFeeder(QWidget* parent)
    : QWidget(parent)
{
    setupLayout();
    setupNetwork();
    setupConnections();
}

void RSSFeeder::setupLayout()
{
    m_urlControl = new QLineEdit(this);
    m_urlControl->setPlaceholderText(tr("Enter RSS Feed url"));

    m_fetchButton = new QPushButton(this);
    m_fetchButton->setText(tr("Retrieve"));
    m_fetchButton->setEnabled(false);

    const auto horizontalLayout = new QHBoxLayout;
    horizontalLayout->addWidget(m_urlControl);
    horizontalLayout->addWidget(m_fetchButton);

    m_newsTree = new QTreeWidget(this);
    m_newsTree->setHeaderLabel(tr("News"));
    m_newsTree->setEnabled(false);

    const auto mainLayout = new QVBoxLayout;
    mainLayout->addLayout(horizontalLayout);
    mainLayout->addWidget(m_newsTree);

    setLayout(mainLayout);
    setMinimumSize(WindowMinWidth, WindowMinHeight);
}

void RSSFeeder::setupNetwork()
{
    m_network = new NetworkManager;
    QObject::connect(m_network, &NetworkManager::finished,
            this, [=](QNetworkReply* reply) {
                if (reply->error()) {
                    showMessage(tr("Network Error"), reply->errorString());
                    return;
                }

                QString answer = reply->readAll();
                qDebug() << answer;
            }
        );
}

void RSSFeeder::setupConnections()
{
    connect(m_fetchButton, &QPushButton::clicked, [=]() {
        fetchData();
    });

    connect(m_urlControl, &QLineEdit::textChanged, this, &RSSFeeder::configureFetchButton);
}

void RSSFeeder::fetchData()
{
    m_network->performRequest(m_urlControl->text());
}

void RSSFeeder::showMessage(QString msgTitle, QString msg)
{
    QMessageBox::critical(this, msgTitle, msg);
}

void RSSFeeder::configureFetchButton(QString url)
{
    m_fetchButton->setEnabled(!url.isEmpty());
}

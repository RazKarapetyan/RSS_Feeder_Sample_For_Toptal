#include "RSSFeeder.h"

#include <QLineEdit>
#include <QPushButton>
#include <QTreeWidget>

#include <QHBoxLayout>
#include <QVBoxLayout>

RSSFeeder::RSSFeeder(QWidget* parent)
    : QWidget(parent)
{
    setupLayout();
}

void RSSFeeder::setupLayout()
{
    m_urlControl = new QLineEdit(this);
    m_urlControl->setPlaceholderText("Enter RSS Feed url");

    QPushButton* fetchButton = new QPushButton(this);
    fetchButton->setText("Retrieve");
    const auto horizontalLayout = new QHBoxLayout;

    horizontalLayout->addWidget(m_urlControl);
    horizontalLayout->addWidget(fetchButton);

    m_newsTree = new QTreeWidget(this);
    m_newsTree->setHeaderLabel("News");
    m_newsTree->setEnabled(false);

    const auto mainLayout = new QVBoxLayout;
    mainLayout->addLayout(horizontalLayout);
    mainLayout->addWidget(m_newsTree);

    setLayout(mainLayout);
    setMinimumSize(700, 350);
}

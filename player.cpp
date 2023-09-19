#include "controller.h"
#include "movewinwidget.h"
#include "player.h"

#include <QDebug>
#include <QApplication>
#include <QDesktopWidget>
#include <QGraphicsDropShadowEffect>
#include <QLabel>
#include <QLayout>
#include <QScrollArea>
#include <QStackedWidget>

Player::Player(QWidget *parent)
    : QFrame(parent)
{
    setWindowFlags(Qt::FramelessWindowHint);
    setFrameStyle(QFrame::StyledPanel | QFrame::Raised);
    setStyleSheet("background: qlineargradient( x1:0 y1:0, x2:1 y2:0, stop:0 black, stop:1 gray)");
    resize(1280, 768);
    move(QApplication::desktop()->rect().center() - this->rect().center());

    m_gridLayout = new QGridLayout(this);
    m_gridLayout->setContentsMargins(0, 0, 0, 0);
    m_gridLayout->setSpacing(0);

    m_logoLabel = new QLabel(this);
    m_logoLabel->setPixmap(QPixmap(":/images/logo2.png").scaled(200, 80, Qt::KeepAspectRatioByExpanding));
    m_logoLabel->setMaximumSize(200, 80);
    m_logoLabel->setMinimumSize(200, 80);
    m_logoLabel->setStyleSheet("background: black");
    m_gridLayout->addWidget(m_logoLabel, 0, 0, Qt::AlignCenter);

    m_topWidget = new MoveWinWidget(this);
    m_topWidget->setWin(this);
    m_topWidget->setMaximumHeight(100);
    m_topWidget->setMinimumHeight(100);
    m_gridLayout->addWidget(m_topWidget, 0, 1);

    m_leftScrollArea = new QScrollArea(this);
    m_leftScrollArea->setStyleSheet("background: cyan");
    m_leftScrollArea->setMaximumWidth(300);
    m_leftScrollArea->setMinimumWidth(300);
    m_gridLayout->addWidget(m_leftScrollArea, 1, 0, 2, 1);

    m_contentWidget = new QStackedWidget(this);
    m_contentWidget->setStyleSheet("background: yellow");
    m_gridLayout->addWidget(m_contentWidget, 1, 1);

    m_controller = new Controller(this);
    m_controller->setStyleSheet("background: pink");
    m_controller->setMaximumHeight(100);
    m_controller->setMinimumHeight(100);
    m_gridLayout->addWidget(m_controller, 2, 1);
}

Player::~Player()
{
}

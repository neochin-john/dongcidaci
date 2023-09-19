#include "player.h"
#include "topbar.h"
#include "controlpanel.h"
#include "leftpanel.h"

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
    setObjectName("mainwin");
    setWindowFlags(Qt::FramelessWindowHint);
    setFrameStyle(QFrame::StyledPanel | QFrame::Raised);
    setStyleSheet("#mainwin {background: qlineargradient( x1:0 y1:0, x2:1 y2:0, stop:0 #141b28, stop:1 #141b28)}");
    resize(1280, 768);
    move(QApplication::desktop()->rect().center() - this->rect().center());

    m_gridLayout = new QGridLayout(this);
    m_gridLayout->setContentsMargins(0, 0, 0, 0);
    m_gridLayout->setSpacing(0);

    m_logoLabel = new QLabel(this);
    m_logoLabel->setPixmap(QPixmap(":/images/logo2.png").scaled(200, 80, Qt::KeepAspectRatio));
    m_logoLabel->setMaximumSize(200, 80);
    m_logoLabel->setMinimumSize(200, 80);
    m_logoLabel->setStyleSheet("background: transparent");
    m_gridLayout->addWidget(m_logoLabel, 0, 0, Qt::AlignCenter);

//    QGraphicsBlurEffect *blurEffect = new QGraphicsBlurEffect(this);
//    blurEffect->setBlurRadius(1.2);
//    blurEffect->setBlurHints(QGraphicsBlurEffect::AnimationHint);
//    m_logoLabel->setGraphicsEffect(blurEffect);

    m_topBar = new TopBar(this);
    m_topBar->setWin(this);
    m_topBar->setMaximumHeight(100);
    m_topBar->setMinimumHeight(100);
    m_gridLayout->addWidget(m_topBar, 0, 1);

    m_leftPanel = new LeftPanel(this);
    m_leftPanel->setStyleSheet("background: transparent; color: white");
    m_leftPanel->setMaximumWidth(300);
    m_leftPanel->setMinimumWidth(300);
    m_gridLayout->addWidget(m_leftPanel, 1, 0, 2, 1);

    m_contentWidget = new QStackedWidget(this);
    m_contentWidget->setStyleSheet("background: transparent");
    m_gridLayout->addWidget(m_contentWidget, 1, 1);

    m_controlPanel = new ControlPanel(this);
    m_controlPanel->setStyleSheet("ControlPanel {background: transparent}");
    m_controlPanel->setMaximumHeight(100);
    m_controlPanel->setMinimumHeight(100);
    m_gridLayout->addWidget(m_controlPanel, 2, 1);
}

Player::~Player()
{
}

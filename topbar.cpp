#include "topbar.h"

#include <QDebug>
#include <QApplication>
#include <QHBoxLayout>
#include <QHoverEvent>
#include <QLineEdit>
#include <QPushButton>

TopBar::TopBar(QWidget *parent) : MoveWinWidget(parent)
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addSpacing(20);

    m_searchEdit = new QLineEdit(this);
    m_searchEdit->setMaximumWidth(300);
    m_searchEdit->setPlaceholderText("搜索");
    m_searchEdit->setStyleSheet("QLineEdit {padding: 8; border-radius: 16}");
    m_searchEdit->setAttribute(Qt::WA_MacShowFocusRect, false);
    layout->addWidget(m_searchEdit, Qt::AlignLeft | Qt::AlignVCenter);

    layout->addStretch(0);

    m_settingBtn = new QPushButton(this);
    m_settingBtn->setMaximumWidth(32);
    m_settingBtn->setIcon(QIcon(":/images/settings.png"));
    m_settingBtn->setIconSize(QSize(20, 20));
    m_settingBtn->setStyleSheet("QPushButton {background: transparent} QPushButton:hover {background: rgba(255, 255, 255, 20%)}");
    layout->addWidget(m_settingBtn, Qt::AlignRight | Qt::AlignVCenter);

    m_minimizeBtn = new QPushButton(this);
    m_minimizeBtn->setMaximumWidth(32);
    m_minimizeBtn->setIcon(QIcon(":/images/win-minimize.png"));
    m_minimizeBtn->setIconSize(QSize(20, 20));
    m_minimizeBtn->setStyleSheet("QPushButton {background: transparent} QPushButton:hover {background: rgba(255, 255, 255, 20%)}");
    layout->addWidget(m_minimizeBtn, Qt::AlignRight | Qt::AlignVCenter);

    m_toggleFullScreenBtn = new QPushButton(this);
    m_toggleFullScreenBtn->setMaximumWidth(32);
    m_toggleFullScreenBtn->setIcon(QIcon(":/images/win-fullscreen.png"));
    m_toggleFullScreenBtn->setIconSize(QSize(20, 20));
    m_toggleFullScreenBtn->setStyleSheet("QPushButton {background: transparent} QPushButton:hover {background: rgba(255, 255, 255, 20%)}");
    connect(m_toggleFullScreenBtn, &QPushButton::clicked, this, &TopBar::toggleFullScreen);
    layout->addWidget(m_toggleFullScreenBtn, Qt::AlignRight | Qt::AlignVCenter);

    m_closeBtn = new QPushButton(this);
    m_closeBtn->setMaximumWidth(32);
    m_closeBtn->setIcon(QIcon(":/images/win-close.png"));
    m_closeBtn->setIconSize(QSize(20, 20));
    m_closeBtn->setStyleSheet("QPushButton {background: transparent} QPushButton:hover {background: rgba(255, 255, 255, 20%)}");
    connect(m_closeBtn, &QPushButton::clicked, this, &TopBar::closeWin);
    layout->addWidget(m_closeBtn, Qt::AlignRight | Qt::AlignVCenter);

    layout->addSpacing(20);
}

void TopBar::mouseDoubleClickEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    toggleFullScreen();
}

void TopBar::closeWin()
{
    if (win())
    {
        win()->close();
    }
}

void TopBar::toggleFullScreen()
{
    if (!win())
    {
        return;
    }

    Qt::WindowStates winStates = win()->windowState();
    QApplication::instance()->notify(m_toggleFullScreenBtn, new QEvent(QEvent::Leave));
    if (winStates & Qt::WindowFullScreen)
    {
        m_toggleFullScreenBtn->setIcon(QIcon(":/images/win-fullscreen.png"));
        win()->setWindowState(winStates & ~Qt::WindowFullScreen);
    }
    else
    {
        m_toggleFullScreenBtn->setIcon(QIcon(":/images/win-multiwin.png"));
        win()->setWindowState(winStates | Qt::WindowFullScreen);
    }
}

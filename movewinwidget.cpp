#include "movewinwidget.h"

#include <QDebug>
#include <QMouseEvent>
#include <QStyleOption>
#include <QStylePainter>

MoveWinWidget::MoveWinWidget(QWidget *parent)
    : QWidget(parent), m_isMoving(false), m_win(nullptr)
{

}

void MoveWinWidget::setWin(QWidget *win)
{
    m_win = win;
}

QWidget* MoveWinWidget::win()
{
    return m_win;
}

void MoveWinWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QStylePainter painter(this);
    QStyleOption opt;
    opt.initFrom(this);
    painter.drawPrimitive(QStyle::PE_Widget, opt);
}

void MoveWinWidget::mousePressEvent(QMouseEvent *event)
{
    if (!m_win)
    {
        return;
    }

    m_isMoving = true;
    setCursor(Qt::SizeAllCursor);
    m_mousePosToWin = event->globalPos() - m_win->pos();
}

void MoveWinWidget::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    if (!m_isMoving || !m_win)
    {
        return;
    }

    m_isMoving = false;
    setCursor(Qt::ArrowCursor);
}

void MoveWinWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (!m_isMoving || !m_win)
    {
        return;
    }

    m_win->move(event->globalPos() - m_mousePosToWin);
}

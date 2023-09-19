#include "controller.h"

#include <QStyleOption>
#include <QStylePainter>

Controller::Controller(QWidget *parent) : QWidget(parent)
{

}

void Controller::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QStylePainter painter(this);
    QStyleOption opt;
    opt.initFrom(this);
    painter.drawPrimitive(QStyle::PE_Widget, opt);
}

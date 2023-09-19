#include "controlpanel.h"

#include <QLabel>
#include <QPushButton>
#include <QStyleOption>
#include <QStylePainter>
#include <QVBoxLayout>

ControlPanel::ControlPanel(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setSpacing(0);
    layout->setContentsMargins(0,0,0,0);

    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setMaximumHeight(6);
    slider->setStyleSheet(R"(
QSlider::groove:horizontal{
    background: red;
    position: absolute; /* absolutely position 4px from the left and right of the widget. setting margins on the widget should work too... */
    left: 4px; right: 4px;
}

QSlider::handle:horizontal{
    height: 6px;
    background: green;
    margin: 0 -4px; /* expand outside the groove */
}

QSlider::add-page:horizontal{
    background: white;
}

QSlider::sub-page:horizontal{
    background: pink;
}
)");
    layout->addWidget(slider);


    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->setSpacing(10);
    hLayout->setContentsMargins(0, 0, 0, 0);

    QLabel *label = new QLabel;
    label->resize(80, 80);
    label->setPixmap(QPixmap(":/images/logo.png").scaled(80, 80, Qt::IgnoreAspectRatio));
    hLayout->addWidget(label, 0, Qt::AlignLeft);

    hLayout->addStretch(0);

    QPushButton *prevBtn = new QPushButton;
    prevBtn->setIcon(QIcon(":/images/skip-previous.png"));
    prevBtn->setIconSize(QSize(32, 32));
    prevBtn->setStyleSheet("QPushButton{background: transparent}");
    hLayout->addWidget(prevBtn, 0, Qt::AlignCenter);

    QPushButton *playBtn = new QPushButton;
    playBtn->setIcon(QIcon(":/images/play-filling.png"));
    playBtn->setIconSize(QSize(32, 32));
    playBtn->setStyleSheet("QPushButton {background: transparent}");
    hLayout->addWidget(playBtn, 0, Qt::AlignCenter);

    QPushButton *nextBtn = new QPushButton;
    nextBtn->setIcon(QIcon(":/images/skip-next.png"));
    nextBtn->setIconSize(QSize(32, 32));
    nextBtn->setStyleSheet("QPushButton {background: transparent}");
    hLayout->addWidget(nextBtn, 0, Qt::AlignCenter);

    hLayout->addStretch(0);

    QPushButton *playQueueBtn = new QPushButton;
    playQueueBtn->setIcon(QIcon(":/images/play-queue.png"));
    playQueueBtn->setIconSize(QSize(32, 32));
    playQueueBtn->setStyleSheet("QPushButton {background: transparent}");
    hLayout->addWidget(playQueueBtn, 0, Qt::AlignRight);

    layout->addLayout(hLayout, 0);
}

void ControlPanel::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QStylePainter painter(this);
    QStyleOption opt;
    opt.initFrom(this);
    painter.drawPrimitive(QStyle::PE_Widget, opt);
}

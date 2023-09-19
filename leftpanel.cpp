#include "leftpanel.h"

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QScrollBar>
#include <QVariant>

LeftPanel::LeftPanel(QWidget *parent) : QScrollArea(parent)
{
    QWidget *widget = new QWidget;

    this->verticalScrollBar()->setStyleSheet(R"(
 QScrollBar:vertical {
     border: 2px solid grey;
     background: #32CC99;
     width: 15px;
     margin: 22px 0 22px 0;
 }
 QScrollBar::handle:vertical {
     background: white;
     min-height: 20px;
 }
 QScrollBar::add-line:vertical {
     border: 2px solid grey;
     background: #32CC99;
     height: 20px;
     subcontrol-position: bottom;
     subcontrol-origin: margin;
 }

 QScrollBar::sub-line:vertical {
     border: 2px solid grey;
     background: #32CC99;
     height: 20px;
     subcontrol-position: top;
     subcontrol-origin: margin;
 }
 QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical {
     border: 2px solid grey;
     width: 3px;
     height: 3px;
     background: white;
 }

 QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {
     background: none;
 })");
    this->setWidget(widget);
    this->setWidgetResizable(true);
    widget->setObjectName("centerWidget");
    widget->setStyleSheet("QWidget#centerWidget{background: transparent}");

    QVBoxLayout *layout = new QVBoxLayout(widget);
    layout->setContentsMargins(40, 20, 40, 20);

    QLabel *label = new QLabel("hello");
    label->setStyleSheet("padding: 3");
    layout->setAlignment(Qt::AlignTop);

    layout->addWidget(label);
    layout->setSpacing(10);

    QStringList slist;
    slist << "列表1" << "列表2" <<"列表3";
    slist << "列表1" << "列表2" <<"列表3";
    slist << "列表1" << "列表2" <<"列表3";
    slist << "列表1" << "列表2" <<"列表3";
    slist << "列表1" << "列表2" <<"列表3";
    slist << "列表1" << "列表2" <<"列表3";
    slist << "列表1" << "列表2" <<"列表3";
    slist << "列表1" << "列表2" <<"列表3";
    slist << "列表1" << "列表2" <<"列表3";
    slist << "列表1" << "列表2" <<"列表3";
    slist << "列表1" << "列表2" <<"列表3";
    slist << "列表1" << "列表2" <<"列表3";
    int i = 0;
    for (QString &s : slist)
    {
        QPushButton *btn = new QPushButton(s);
        btn->setStyleSheet(R"(
QPushButton {background:transparent; border: none; text-align: left; padding: 5}
QPushButton:hover {background: rgba(255, 255, 255, 10%); border: none; text-align: left; padding: 5}
QPushButton[active=true] {background: rgba(255, 255, 255, 20%); border: none; text-align: left; padding: 5}
)");
        ++i;
        if (i == 3)
        {
            btn->setProperty("active", QVariant::fromValue(true));
        }
        layout->addWidget(btn);
    }
}

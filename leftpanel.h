#ifndef LEFTPANEL_H
#define LEFTPANEL_H

#include <QScrollArea>

class LeftPanel : public QScrollArea
{
    Q_OBJECT
public:
    explicit LeftPanel(QWidget *parent = nullptr);
};

#endif // LEFTPANEL_H

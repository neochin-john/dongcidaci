#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <QWidget>

class ControlPanel : public QWidget
{
    Q_OBJECT
public:
    explicit ControlPanel(QWidget *parent = nullptr);

signals:

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // CONTROLPANEL_H

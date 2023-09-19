#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QWidget>

class Controller : public QWidget
{
    Q_OBJECT
public:
    explicit Controller(QWidget *parent = nullptr);

signals:

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // CONTROLLER_H

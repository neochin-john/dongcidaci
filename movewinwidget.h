#ifndef MOVEWINWIDGET_H
#define MOVEWINWIDGET_H

#include <QWidget>

class MoveWinWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MoveWinWidget(QWidget *parent = nullptr);
    void setWin(QWidget *win);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    bool m_isMoving;
    QPoint m_mousePosToWin;
    QWidget *m_win;
};

#endif // MOVEWINWIDGET_H

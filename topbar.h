#ifndef TOPBAR_H
#define TOPBAR_H

#include "movewinwidget.h"

class QLineEdit;
class QPushButton;
class TopBar : public MoveWinWidget
{
    Q_OBJECT
public:
    explicit TopBar(QWidget *parent = nullptr);

protected:
    void mouseDoubleClickEvent(QMouseEvent *event) override;

private slots:
    void closeWin();
    void toggleFullScreen();

private:
    QLineEdit *m_searchEdit;
    QPushButton *m_settingBtn;
    QPushButton *m_minimizeBtn;
    QPushButton *m_toggleFullScreenBtn;
    QPushButton *m_closeBtn;
};

#endif // TOPBAR_H

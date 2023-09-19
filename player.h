#ifndef PLAYER_H
#define PLAYER_H

#include <QFrame>

class QLabel;
class QGridLayout;
class QStackedWidget;
class TopBar;
class ControlPanel;
class LeftPanel;
class Player : public QFrame
{
    Q_OBJECT

public:
    Player(QWidget *parent = nullptr);
    ~Player();

private:
    QGridLayout *m_gridLayout;
    QLabel *m_logoLabel;
    LeftPanel *m_leftPanel;
    TopBar *m_topBar;
    QStackedWidget *m_contentWidget;
    ControlPanel *m_controlPanel;
};
#endif // PLAYER_H

#ifndef PLAYER_H
#define PLAYER_H

#include <QFrame>

class QLabel;
class QGridLayout;
class QScrollArea;
class QStackedWidget;
class MoveWinWidget;
class Controller;
class Player : public QFrame
{
    Q_OBJECT

public:
    Player(QWidget *parent = nullptr);
    ~Player();

private:
    QGridLayout *m_gridLayout;
    QLabel *m_logoLabel;
    QScrollArea *m_leftScrollArea;
    MoveWinWidget *m_topWidget;
    QStackedWidget *m_contentWidget;
    Controller *m_controller;
};
#endif // PLAYER_H

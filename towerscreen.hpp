#ifndef TOWERSCREEN_HPP
#define TOWERSCREEN_HPP

#include <QWidget>

class TowerScreen : public QWidget
{
    Q_OBJECT
public:
    explicit TowerScreen(QWidget *parent = 0);

Q_SIGNALS:
    void changeEtat(quint8 type);

public Q_SLOTS:

};

#endif // TOWERSCREEN_HPP

#ifndef TOWERSCREEN_HPP
#define TOWERSCREEN_HPP

#include <QWidget>

class TowerScreen : public QWidget
{
    Q_OBJECT
public:
    explicit TowerScreen(QWidget *parent = 0);

signals:
    void changeEtat(quint8 type);

public slots:

};

#endif // TOWERSCREEN_HPP

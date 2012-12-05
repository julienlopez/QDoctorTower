#ifndef TOWERSCREEN_HPP
#define TOWERSCREEN_HPP

#include <QWidget>

class Tower;

class QGroupBox;
class QLabel;
class QPushButton;

class TowerScreen : public QWidget
{
    Q_OBJECT
public:
    explicit TowerScreen(QWidget *parent = 0);

private:
    struct Selection
    {
        Selection();

        Tower* tower;

        QLabel* id;
        QPushButton* levelUp;
    };

    QGroupBox* createGroupBoxCreation();
    QGroupBox* createGroupBoxSelection();

    Selection m_selection;

Q_SIGNALS:
    void changeEtat(quint8 type);

public Q_SLOTS:
    void onTowerSelected(Tower* t);

private Q_SLOTS:
    void onLevelUp();
};

#endif // TOWERSCREEN_HPP

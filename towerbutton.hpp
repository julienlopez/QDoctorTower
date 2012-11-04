#ifndef TOWERBUTTON_HPP
#define TOWERBUTTON_HPP

#include <QPushButton>

class TowerButton : public QPushButton
{
    Q_OBJECT
public:
    TowerButton(quint8 towerType, QString icone, QWidget *parent = 0);

private:
    quint8 m_towerType;
    QString m_icone;

Q_SIGNALS:
    void changeEtat(quint8 type);

private Q_SLOTS:
    void onClick();
};

#endif // TOWERBUTTON_HPP

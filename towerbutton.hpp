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

signals:

public slots:

};

#endif // TOWERBUTTON_HPP

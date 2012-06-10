#include "towerbutton.hpp"
#include <QIcon>

TowerButton::TowerButton(quint8 towerType, QString icone, QWidget *parent) :
    QPushButton(QIcon(icone), "", parent), m_towerType(towerType), m_icone(icone)
{
    setAutoExclusive(true);
    setFixedSize(100,100);
    setCheckable(true);
    connect(this, SIGNAL(clicked()), this, SLOT(onClick()));
}

void TowerButton::onClick()
{
    emit changeEtat(m_towerType);
}

#include "towerscreen.hpp"
#include "towers/towerfactory.hpp"
#include "towers/tower.hpp"
#include "towerbutton.hpp"

#include <cassert>

#include <QGridLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QLabel>

#include <QDebug>

TowerScreen::Selection::Selection()
{
    tower = 0;
    id = 0;
    levelUp = 0;
}

TowerScreen::TowerScreen(QWidget *parent) :
    QWidget(parent)
{
    setFixedWidth(250);
    QVBoxLayout* layout = new QVBoxLayout;


    layout->addWidget(createGroupBoxCreation());
    layout->addWidget(createGroupBoxSelection());
    layout->addStretch();
    setLayout(layout);

    onTowerSelected(0);
}

QGroupBox* TowerScreen::createGroupBoxCreation()
{
    QGroupBox* gb = new QGroupBox(tr("Tours"));

    TowerFactory::type_map_icones icones = TowerFactory::icones();
    QGridLayout* gl = new QGridLayout;

    quint8 cpt = 0;
    TowerButton* b;
    for(TowerFactory::type_map_icones::const_iterator i = icones.begin(); i != icones.end(); ++i)
    {
        b = new TowerButton(i.key(), i.value());
        connect(b, SIGNAL(changeEtat(quint8)), this, SIGNAL(changeEtat(quint8)));
        gl->addWidget(b, cpt/2, cpt%2);
        cpt++;
    }

    gb->setLayout(gl);
    return gb;
}

QGroupBox* TowerScreen::createGroupBoxSelection()
{
    QGroupBox* gb = new QGroupBox(tr("Sélection"));
    QVBoxLayout* l = new QVBoxLayout;

    m_selection.id = new QLabel;
    l->addWidget(m_selection.id, 0, Qt::AlignCenter);

    m_selection.levelUp = new QPushButton(tr("Level up"));
    connect(m_selection.levelUp, SIGNAL(clicked()), this, SLOT(onLevelUp()));
    l->addWidget(m_selection.levelUp, 0, Qt::AlignCenter);

    gb->setLayout(l);
    return gb;
}

void TowerScreen::onTowerSelected(Tower* t)
{
    if(!t)
    {
        m_selection.id->setText("");
        m_selection.levelUp->hide();
        return;
    }
    m_selection.tower = t;
    m_selection.id->setText(QString::fromStdString(t->label() + " lvl ") + QString::number(t->level()));
    if(t->canLevelUp()) m_selection.levelUp->show();
    else m_selection.levelUp->hide();
}

void TowerScreen::onLevelUp()
{
    assert(m_selection.tower);
    m_selection.tower->levelUp();
    onTowerSelected(m_selection.tower);
}

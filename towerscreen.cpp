#include "towerscreen.hpp"
#include "towers/towerfactory.hpp"
#include "towerbutton.hpp"

#include <QGridLayout>
#include <QVBoxLayout>
#include <QGroupBox>

#include <QDebug>

TowerScreen::TowerScreen(QWidget *parent) :
    QWidget(parent)
{
    setFixedWidth(250);
    QVBoxLayout* layout = new QVBoxLayout;

    QGroupBox* gb = new QGroupBox(tr("Tours"));

    TowerFactory::type_map_icones icones = TowerFactory::icones();
    QGridLayout* gl = new QGridLayout;

    quint8 cpt = 0;
    TowerButton* b;
    for(TowerFactory::type_map_icones::const_iterator i = icones.begin(); i != icones.end(); ++i)
    {
        b = new TowerButton(i.key(), i.value());
        gl->addWidget(b, cpt/2, cpt%2);
        cpt++;
    }

    gb->setLayout(gl);
    layout->addWidget(gb);
    layout->addStretch();
    setLayout(layout);
}

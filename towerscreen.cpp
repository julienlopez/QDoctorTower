#include "towerscreen.hpp"
#include "towers/towerfactory.hpp"
#include "towerbutton.hpp"

#include <QGridLayout>

#include <QDebug>

TowerScreen::TowerScreen(QWidget *parent) :
    QWidget(parent)
{
    setFixedWidth(220);

    TowerFactory::type_map_icones icones = TowerFactory::icones();
    QGridLayout* layout = new QGridLayout;

    quint8 cpt = 0;
    TowerButton* b;
    for(TowerFactory::type_map_icones::const_iterator i = icones.begin(); i != icones.end(); ++i)
    {
        b = new TowerButton(i.key(), "images/icones/"+i.value());
        layout->addWidget(b, cpt/2, cpt%2);
        cpt++;
    }

    setLayout(layout);
}

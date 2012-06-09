#include "screen.hpp"
#include "map.hpp"
#include "tiles/tile.hpp"
#include "creeps/creep.h"
#include "engine.h"

#include <QPainter>

Screen::EngineMessage::EngineMessage(QString _titre, QString _message, quint8 _compteur)
{
    titre = _titre;
    message = _message;
    compteur = _compteur;
}

Screen::Screen(Map *map, QWidget *parent) :
    QWidget(parent), m_currentMessage("","",0)
{
    m_map = map;
    setMinimumSize(800, 600);
}

void Screen::onEngineMessage(QString titre, QString message)
{
    m_currentMessage.titre = titre;
    m_currentMessage.message = message;
    m_currentMessage.compteur = 50;
}

#include <QDebug>

void Screen::paintEvent(QPaintEvent* evt)
{
    Q_UNUSED(evt);
    QPainter p(this);
    p.save();
    double tailleCase = qMin((double)(width()-2)/m_map->largeur(), (double)(height()-2)/m_map->hauteur());
    double offsetX = width() - tailleCase*m_map->largeur();
    double offsetY = height() - tailleCase*m_map->hauteur();
    p.translate(offsetX/2, offsetY/2);
    p.scale(tailleCase, tailleCase);
    for(quint8 x = 0; x < m_map->largeur(); x++)
        for(quint8 y = 0; y < m_map->hauteur(); y++)
            (*m_map)(x, y)->draw(&p);

    p.setPen(Qt::black);
    QList<Creep*>& creeps = Engine::instance()->creeps();
    foreach(Creep* c, creeps)
        c->draw(&p);

    p.restore();
    if(m_currentMessage.compteur > 0)
    {
        p.setPen(Qt::black);
        p.setBrush(Qt::yellow);
        QFont font = p.font();
        font.setPixelSize(60);
        p.setFont(font);
        p.drawText(QRect(0, height()/4, width(), height()/4), Qt::AlignCenter, m_currentMessage.titre);
        font.setPixelSize(40);
        p.setFont(font);
        p.drawText(QRect(0, height()/2, width(), height()/4), Qt::AlignCenter, m_currentMessage.message);
        m_currentMessage.compteur--;
    }
}

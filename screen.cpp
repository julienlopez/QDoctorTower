#include "screen.hpp"
#include "map.hpp"
#include "tiles/tile.hpp"
#include "creeps/creep.h"
#include "engine/engine.hpp"
#include "towers/towerfactory.hpp"
#include "towers/tower.hpp"

#include <QPainter>
#include <QMouseEvent>

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
    m_currentTowerState = 0;
    setMinimumSize(800, 600);
    setMouseTracking(true);
}

void Screen::onEngineMessage(QString titre, QString message)
{
    m_currentMessage.titre = titre;
    m_currentMessage.message = message;
    m_currentMessage.compteur = 50;
}

void Screen::setTowerState(quint8 state)
{
    m_currentTowerState = state;
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

    Engine::instance()->draw(&p);

    if(m_currentTowerState != 0 && m_mousePos.x() >= 0 && m_mousePos.x() < m_map->largeur() && m_mousePos.y() >= 0 && m_mousePos.y() < m_map->hauteur())
    {
        QPixmap pix(TowerFactory::icones()[m_currentTowerState]);
        p.drawPixmap(m_mousePos, pix, QRect(0, 0, 1, 1));
    }

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

void Screen::mouseMoveEvent(QMouseEvent * evt)
{
    QPoint pos = evt->pos();
    double tailleCase = qMin((double)(width()-2)/m_map->largeur(), (double)(height()-2)/m_map->hauteur());
    double offsetX = (width() - tailleCase*m_map->largeur())/2;
    double offsetY = (height() - tailleCase*m_map->hauteur())/2;

    QPoint mousePos((pos.x()-offsetX)/tailleCase, (pos.y()-offsetY)/tailleCase);

    if(mousePos != m_mousePos)
    {
        m_mousePos = mousePos;
        update();
    }
}

void Screen::mouseReleaseEvent(QMouseEvent* evt)
{
    if(evt->button() == Qt::RightButton)
    {
        m_currentTowerState = 0;
        update();
        return;
    }
    if(m_mousePos.x() >= m_map->largeur() || m_mousePos.y() >= m_map->hauteur()) return;


    if(m_currentTowerState == 0) selectTower();
    else createTower();

}

void Screen::createTower()
{
    Tower* tower = TowerFactory::createTower(m_currentTowerState, m_mousePos);
    Q_ASSERT(tower);
    try
    {
        Engine::instance()->buildTower(tower, m_mousePos.x(), m_mousePos.y());
    }
    catch(Exception::NotEnoughGold& ex)
    {
        onEngineMessage("Not enough gold", ex.message());
        m_currentMessage.compteur = 20;
    }
}

void Screen::selectTower()
{
    Tile* tile = (*m_map)(m_mousePos.x(), m_mousePos.y());
    if(!tile) return;
    Tower* t = tile->tower();
    Q_EMIT towerSelected(t);
}

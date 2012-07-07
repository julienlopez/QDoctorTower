#include "engine.hpp"
#include "joueur.h"
#include "map.hpp"
#include "creeps/creepfactory.h"
#include "creeps/creep.h"
#include "towers/tower.hpp"
#include "towers/attackers/attacker.hpp"
#include "bullets/bullet.hpp"

#include <QTimer>

Engine* Engine::s_instance = 0;

Engine::Engine(Joueur* player, Map* map, QObject *parent) :
    QObject(parent)
{
    Q_ASSERT_X(!s_instance, "Erreur avec l'engine", "l'Engine a déj�  été créé");
    s_instance = this;
    m_started = false;
    m_player = player;
    m_map = map;
    m_timer = new QTimer(this);
    m_timer->setInterval(40);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(onTimerClick()));
}

Engine* Engine::instance()
{
    return s_instance;
}

double Engine::dt() const
{
    return 0.04;
}

QPoint Engine::getNextGoal(const QPoint& p) const throw(AucunPointSuivant)
{
    for(Map::type_path::const_iterator i = m_map->pathBegin(); i != m_map->pathEnd(); ++i)
        if(*i == p)
        {
            if(++i == m_map->pathEnd()) break;
            return *i;
        }
    throw AucunPointSuivant();
}

void Engine::addBullet(Bullet* b)
{
    Q_ASSERT(b);
    connect(b, SIGNAL(hasHit()), this, SLOT(onBulletHit()));
    m_bullets << b;
}

const QList<Creep*>& Engine::creeps() const
{
    return CreepHandler::creeps();
}

Creep* Engine::closestCreep(const QPointF& p) const
{
    return CreepHandler::closestCreep(p);
}

QList<Creep*>& Engine::creeps()
{
    return CreepHandler::creeps();
}

void Engine::start()
{
    if(!m_started)
    {
        init();
        m_started = true;
    }
    m_timer->start();
}

void Engine::pause()
{
    m_timer->stop();
}

void Engine::init()
{
    m_player->addGold(300);
    emit message("Niveau 1!", "rats");
    m_compteur = 20;
}

#include <QDebug>

void Engine::onTimerClick()
{
    if(m_compteur > 0 && (creeps().empty() || creeps().last()->coords().y() > 0.5))
    {
        Creep* c = createCreep(m_map->spawnPoint(), *(++m_map->pathBegin()), 1);
        connect(c, SIGNAL(escaped()), this, SLOT(onCreepEscaped()));
        connect(c, SIGNAL(dead()), this, SLOT(onCreepDied()));
        m_compteur--;
    }

    CreepHandler::maj();

    qDebug() << "mise �  jour des balles {";
    qDebug() << m_bullets;
    qDebug() << "}";
    Bullet* b;
    for(QList<Bullet*>::iterator i = m_bullets.begin(); i != m_bullets.end();)
    {
        b = *i;
        if(b)
        {
            qDebug() << m_bullets.indexOf(b) << ": " << b;
            b->update(dt());
            ++i;
        }
        else ++i;//else m_bullets.erase(i++);
    }

    TowerHandler::maj();

    emit updated();
}

void Engine::onCreepEscaped()
{
    Creep* c = qobject_cast<Creep*>(sender());
    Q_ASSERT(c);
    removeCreep(c);
    m_player->addEscaped();
}

void Engine::onCreepDied()
{
    Creep* c = qobject_cast<Creep*>(sender());
    Q_ASSERT(c);
    removeCreep(c);
    m_player->addKilled();
}

void Engine::onBulletHit()
{
    qDebug() << "Engine::onBulletHit() {";
    Bullet* b = qobject_cast<Bullet*>(sender());
    int i = m_bullets.indexOf(b);
    qDebug() << i << ": " << b;
    m_bullets[i] = 0;
    b->deleteLater();
    qDebug() << m_bullets[i];
    qDebug() << m_bullets;
    qDebug() << "}";
}

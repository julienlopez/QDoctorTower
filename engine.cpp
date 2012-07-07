#include "engine.h"
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

QList<Creep*>& Engine::creeps()
{
    return m_creeps;
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

namespace {
struct DistCreep {
    Creep* creep;
    double distance;
};
}

Creep* Engine::closestCreep(const QPointF& p) const
{
    QList<Creep*>::const_iterator i = m_creeps.begin();
    while(i != m_creeps.end() && !(*i)) ++i;
    if(i == m_creeps.end()) return 0;
    DistCreep dc;
    dc.creep = *i;
    dc.distance = ((*i)->coords()-p).manhattanLength();
    ++i;
    double dist;
    for(; i != m_creeps.end(); ++i)
    {
        if(!(*i)) continue;
        dist = ((*i)->coords()-p).manhattanLength();
        if(dist < dc.distance)
        {
            dc.creep = *i;
            dc.distance = dist;
        }
    }
    return dc.creep;
}

void Engine::addTower(Tower* t)
{
    Q_ASSERT(t);
    m_towers << t;
}

void Engine::addBullet(Bullet* b)
{
    Q_ASSERT(b);
    connect(b, SIGNAL(hasHit()), this, SLOT(onBulletHit()));
    m_bullets << b;
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
    if(m_compteur > 0 && (m_creeps.empty() || m_creeps.last()->coords().y() > 0.5))
    {
        Creep* c = CreepFactory::createCreep(1, m_map->spawnPoint());
        connect(c, SIGNAL(escaped()), this, SLOT(onCreepEscaped()));
        connect(c, SIGNAL(dead()), this, SLOT(onCreepDied()));
        c->setGoal(*(++m_map->pathBegin()));
        m_creeps << c;
        m_compteur--;
    }

    for(QList<Creep*>::iterator i = m_creeps.begin(); i != m_creeps.end();)
        if(*i)
        {
            (*i)->update(dt());
            ++i;
        }
        else m_creeps.erase(i++);

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

    foreach(Tower* t, m_towers)
    {
        if(!m_creeps.isEmpty() && t->canTarget())
        {
            Attacker* a = qobject_cast<Attacker*>(t);
            Q_ASSERT(a);
            Creep* c = a->cible();
            if(c) //gestion de la cible sortant de la zone de portée
            {
                QPointF p(c->coords() - t->coords());
                if(p.manhattanLength() > a->portee()*a->portee())
                {
                    a->setCible(0);
                }
            }
            if(!c) //si pas de cible, on en cherche une nouvelle
            {
                c = closestCreep(a->coords());
                if(c)
                {
                    a->setCible(c);
                }
            }
        }
        t->update(dt());
    }

    emit updated();
}

void Engine::onCreepEscaped()
{
    Creep* c = qobject_cast<Creep*>(sender());
    Q_ASSERT(c);
    m_creeps[m_creeps.indexOf(c)] = 0;
    c->deleteLater();
    m_player->addEscaped();
}

void Engine::onCreepDied()
{
    Creep* c = qobject_cast<Creep*>(sender());
    Q_ASSERT(c);
    m_creeps[m_creeps.indexOf(c)] = 0;
    c->deleteLater();
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

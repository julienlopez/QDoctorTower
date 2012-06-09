#include "engine.h"
#include "joueur.h"
#include "map.hpp"
#include "creeps/creepfactory.h"
#include "creeps/creep.h"
#include "towers/tower.hpp"

#include <QTimer>

Engine* Engine::s_instance = 0;

Engine::Engine(Joueur* player, Map* map, QObject *parent) :
    QObject(parent)
{
    Q_ASSERT_X(!s_instance, "Erreur avec l'engine", "l'Engine a déjà été créé");
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

    foreach(Creep* c, m_creeps) c->update(dt());

    foreach(Tower* t, m_towers) t->update(dt());

    emit updated();
}

void Engine::onCreepEscaped()
{
    Creep* c = qobject_cast<Creep*>(sender());
    Q_ASSERT(c);
    m_creeps.removeOne(c);
    c->deleteLater();
    m_player->addEscaped();
}

void Engine::onCreepDied()
{
    Creep* c = qobject_cast<Creep*>(sender());
    Q_ASSERT(c);
    m_creeps.removeOne(c);
    c->deleteLater();
    m_player->addKilled();
}

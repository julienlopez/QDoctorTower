#include "engine.hpp"
#include "joueur.h"
#include "map.hpp"
#include "creeps/creep.h"
#include "bullets/bullet.hpp"
#include "tiles/tile.hpp"
#include "towers/tower.hpp"
#include "gameturn/state.hpp"

#include <boost/bind.hpp>

#include <QTimer>

Engine* Engine::s_instance = 0;

Engine::Engine(Joueur* player, Map* map, QObject *parent) :
    QObject(parent)
{
    Q_ASSERT_X(!s_instance, "Erreur avec l'engine", "l'Engine a déjà  été créé");
    s_instance = this;
    m_player = player;
    m_map = map;
    m_compteur = 0;
    m_nbCreepToSpawn = 0;
    m_timer = new QTimer(this);
    m_timer->setInterval(40);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(onTimerClick()));

    m_gameturnSM.init();
    connect(&m_gameturnSM, SIGNAL(newStateEntered()), this, SLOT(onNewGameTurn()));
    connect(&m_gameturnSM, SIGNAL(finished()), this, SLOT(onGameTurnSMFinished()));

    m_timerCreepSpawn = new QTimer(this);
    m_timerCreepSpawn->setInterval(5000);
    m_timerCreepSpawn->setSingleShot(true);
    connect(m_timerCreepSpawn, SIGNAL(timeout()), this, SLOT(onTimerCreepSpawnClick()));
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

const Engine::type_liste_creep& Engine::creeps() const
{
    return CreepHandler::creeps();
}

iEngine::sp_creep Engine::closestCreep(const QPointF& p) const
{
    return CreepHandler::closestCreep(p);
}

Engine::type_liste_creep& Engine::creeps()
{
    return CreepHandler::creeps();
}

void Engine::onCreepEscaped(wp_creep creep)
{
    sp_creep c = creep.lock();
    Q_ASSERT(c);
    removeCreep(c);
    cleanUpBullets(c);
    m_player->addEscaped();
}

void Engine::onCreepDied(wp_creep creep)
{
    sp_creep c = creep.lock();
    Q_ASSERT(c);
    removeCreep(c);
    cleanUpBullets(c);
    m_player->addKilled();
    m_player->addGold(c->reward());
    if(creeps().empty()) m_gameturnSM.next();
}

void Engine::draw(QPainter* p) const
{
    drawCreeps(p);
    drawBullets(p);
    NetworkHandler::draw(p);
}

void Engine::buildTower(Tower* tower, quint8 x, quint8 y) throw(Exception::NotEnoughGold)
{
    Q_ASSERT(tower);
    if(tower->cost() > m_player->gold()) throw Exception::NotEnoughGold(tower->cost(), m_player->gold());
    m_player->retrieveGold(tower->cost());
    Tile* tile = (*m_map)(x, y);
    Q_ASSERT(tile);
    tile->addTower(tower);
    NetworkHandler::addTowerToNetwork(tower, x, y);
}

#include <QDebug>

void Engine::start()
{
    if(!m_gameturnSM.isRunning()) {
        qDebug() << "demarage de la SM";
        m_gameturnSM.start();
    }
    m_timer->start();
}

void Engine::pause()
{
    m_timer->stop();
}

void Engine::onTimerClick()
{
    if(m_compteur > 0 && (creeps().empty() || creeps().back().get()->coords().y() > 0.5))
    {
        Creep* c = createCreep(m_map->spawnPoint(), *(++m_map->pathBegin()));
        c->dead().connect(boost::bind(&Engine::onCreepDied, this, _1));
        c->escaped().connect(boost::bind(&Engine::onCreepEscaped, this, _1));
        m_compteur--;
    }

    BulletHandler::maj();

    CreepHandler::maj();

    TowerHandler::maj();

    NetworkHandler::update(dt());

    Q_EMIT updated();
}

void Engine::onNewGameTurn()
{
    qDebug() << "Engine::onNewGameTurn()";
    GameTurn::State* s = m_gameturnSM.currentState();
    if(!s) return;
    setCurrentCreepToCreate(s->typeCreep());
    m_player->addGold(s->gold());
    m_nbCreepToSpawn = s->nbCreep();
    Q_EMIT message("Level " + QString::number(s->level()) + "!", "rats");
    m_timerCreepSpawn->start();
}

void Engine::onTimerCreepSpawnClick()
{
    GameTurn::State* s = m_gameturnSM.currentState();
    Q_ASSERT(s);
    m_compteur = m_nbCreepToSpawn;
    qDebug() << "Engine::onTimerCreepSpawnClick(): " << m_compteur;
}

void Engine::onGameTurnSMFinished()
{
    Q_EMIT message("done", "YAY!");
}

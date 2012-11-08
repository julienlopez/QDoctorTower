#ifndef ENGINE_H
#define ENGINE_H

#include "creephandler.hpp"
#include "towerhandler.hpp"
#include "bullethandler.hpp"
#include "networkhandler.hpp"
#include "gameturn/statemachine.hpp"
#include <utils/exceptions/notenoughgold.hpp>

#include <QObject>
#include <QPoint>

class Joueur;
class Map;
class QTimer;

class Engine : public QObject, public CreepHandler, public TowerHandler, public BulletHandler, private NetworkHandler
{
    Q_OBJECT
public:

    class AucunPointSuivant : public Exception::Exception
    {
    public:
        AucunPointSuivant(): Exception::Exception("Aucun point suivant")
        {}
    };

    Engine(Joueur* player, Map* map, QObject *parent = 0);

    static Engine* instance();

    virtual double dt() const;

    QPoint getNextGoal(const QPoint& p) const throw(AucunPointSuivant);

    virtual const type_liste_creep& creeps() const;

    void draw(QPainter* p) const;

    void buildTower(Tower* tower, quint8 x, quint8 y) throw(Exception::NotEnoughGold);

protected:
    virtual sp_creep closestCreep(const QPointF& p) const;

    virtual type_liste_creep& creeps();

    void onCreepEscaped(wp_creep creep);

    void onCreepDied(wp_creep creep);

Q_SIGNALS:
    void end();
    void updated();
    void message(QString titre, QString message);

public Q_SLOTS:
    void start();
    void pause();

private:
    GameTurn::StateMachine m_gameturnSM;
    quint8 m_compteur;
    Joueur* m_player;
    Map* m_map;
    QTimer* m_timer;
    QTimer* m_timerCreepSpawn;

    quint8 m_nbCreepToSpawn;

    static Engine* s_instance;

private Q_SLOTS:
    void onTimerClick();
    void onNewGameTurn();
    void onTimerCreepSpawnClick();
    void onGameTurnSMFinished();
};

#endif // ENGINE_H

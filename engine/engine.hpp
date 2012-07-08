#ifndef ENGINE_H
#define ENGINE_H

#include "creephandler.hpp"
#include "towerhandler.hpp"
#include "bullethandler.hpp"

#include <utils/exception.hpp>

#include <QObject>
#include <QPoint>

class Joueur;
class Map;
class QTimer;

class Engine : public QObject, public CreepHandler, public TowerHandler, public BulletHandler
{
    Q_OBJECT
public:

    class AucunPointSuivant : public Exception
    {
    public:
        AucunPointSuivant(): Exception("Aucun point suivant")
        {}
    };

    Engine(Joueur* player, Map* map, QObject *parent = 0);

    static Engine* instance();

    virtual double dt() const;

    QPoint getNextGoal(const QPoint& p) const throw(AucunPointSuivant);

    virtual void addBullet(Bullet* b);

    virtual const QList<Creep*>& creeps() const;

    void draw(QPainter* p) const;

protected:
    virtual Creep* closestCreep(const QPointF& p) const;

    virtual QList<Creep*>& creeps();

signals:
    void end();
    void updated();
    void message(QString titre, QString message);

public slots:
    void start();
    void pause();

private:
    bool m_started;
    quint8 m_compteur;
    Joueur* m_player;
    Map* m_map;
    QTimer* m_timer;

    void init();

    static Engine* s_instance;

private slots:
    void onTimerClick();
    void onCreepEscaped();
    void onCreepDied();
    void onBulletHit();
};

#endif // ENGINE_H

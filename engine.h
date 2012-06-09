#ifndef ENGINE_H
#define ENGINE_H

#include <utils/exception.hpp>

#include <QObject>
#include <QPoint>

class Joueur;
class Map;
class Creep;
class QTimer;
class Tower;

class Engine : public QObject
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

    QList<Creep*>& creeps();

    static Engine* instance();

    double dt() const;

    QPoint getNextGoal(const QPoint& p) const throw(AucunPointSuivant);

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
    QList<Creep*> m_creeps;
    Joueur* m_player;
    Map* m_map;
    QTimer* m_timer;
    QList<Tower*> m_towers;

    void init();

    static Engine* s_instance;

private slots:
    void onTimerClick();
    void onCreepEscaped();
    void onCreepDied();
};

#endif // ENGINE_H

#ifndef TOWER_HPP
#define TOWER_HPP

#include "energyhandler.hpp"
#include <utils/hascoords.hpp>
#include <utils/updateable.hpp>

#include <QPoint>

class Tile;

class QString;

class Tower : public HasCoords<QPoint>, public EnergyHandler, public Updateable
{
public:
    Tower(const QPoint& p, quint32 cost);

    virtual bool canGoOnWater() const =0;

    const Tile* tile() const;

    void setTile(const Tile* tile);

    virtual const QString& icone() const =0;

    virtual bool canTarget() const = 0;

    quint32 cost() const;

    virtual bool canLevelUp() const =0;

    virtual void levelUp() =0;

    virtual quint8 level() const;

    virtual std::string label() const =0;

protected:
    void setLevel(quint8 level);
    void setCost(quint32 cost);

private:
    quint32 m_cost;
    quint8 m_level;
    const Tile* m_tile;
};

#endif // TOWER_HPP

#ifndef TOWER_HPP
#define TOWER_HPP

#include <utils/hascoords.hpp>
#include <utils/updateable.hpp>

#include <QPoint>

class Tile;

class Tower : public HasCoords<QPoint>, public Updateable
{
public:
    Tower(const QPoint& p, quint32 cost);

    virtual bool canGoOnWater() const =0;

    const Tile* tile() const;

    void setTile(const Tile* tile);

    virtual QString icone() const =0;

    virtual bool canTarget() const = 0;

    quint32 cost() const;

private:
    quint32 m_cost;
    const Tile* m_tile;
};

#endif // TOWER_HPP

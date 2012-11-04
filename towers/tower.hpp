#ifndef TOWER_HPP
#define TOWER_HPP

#include <utils/hascoords.hpp>
#include <utils/updateable.hpp>

#include <QPoint>

class Tile;

class Tower : public HasCoords<QPoint>, public Updateable
{
public:
    Tower(const QPoint& p);

    virtual bool canGoOnWater() const =0;

    const Tile* tile() const;

    void setTile(const Tile* tile);

    virtual QString icone() const =0;

    virtual bool canTarget() const = 0;

private:
    const Tile* m_tile;
};

#endif // TOWER_HPP

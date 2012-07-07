#ifndef TOWER_HPP
#define TOWER_HPP

#include <utils/hascoords.hpp>
#include <utils/updateable.hpp>

#include <QPoint>
#include <QObject>

class Tile;

class Tower : public QObject, public HasCoords<QPoint>, public Updateable
{
    Q_OBJECT
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

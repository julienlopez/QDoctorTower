#ifndef __TILE_HPP__
#define __TILE_HPP__

#include <utils/drawable.hpp>
#include <utils/hascoords.hpp>

#include <QPoint>
#include <QColor>

class Tower;

class Tile : public HasCoords<QPoint>, public Drawable
{
public:

    Tile(const QPoint& coords);

    virtual Tile* clone() const =0;

    Tower* tower();

    virtual bool addTower(Tower* tower) =0;

    virtual bool hasTower() const;

    virtual void draw(QPainter *painter) const =0;

    void draw(QPainter *painter, const QColor& couleur) const;

protected:
    void setTower(Tower* tower);

private:
    Tower* m_tower;
};

#endif

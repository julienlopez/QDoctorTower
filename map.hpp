#ifndef MAP_HPP
#define MAP_HPP

#include <QVector>
#include <QPoint>

class Tile;

class Map
{
public:
    typedef QList<QPoint> type_path;

    Map(quint8 largeur, quint8 hauteur);

    quint8 largeur() const;
    quint8 hauteur() const;

    Tile* operator()(quint8 x, quint8 y) const;

    Tile*& operator()(quint8 x, quint8 y);

    static Map* loadMap();

    QPoint spawnPoint() const;
    QPoint escapePoint() const;
    type_path::const_iterator pathBegin() const;
    type_path::const_iterator pathEnd() const;

    const type_path& path() const;

private:
    quint8 m_largeur;
    quint8 m_hauteur;
    QVector<QVector<Tile*> > m_tiles;
    type_path m_path;
};

#endif // MAP_HPP

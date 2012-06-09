#include "map.hpp"
#include <tiles/tilefactory.hpp>

#include <QPoint>

Map::Map(quint8 largeur, quint8 hauteur): m_largeur(largeur), m_hauteur(hauteur), m_tiles(largeur)
{
    for(quint8 x = 0; x < largeur; x++) {
        m_tiles[x] = QVector<Tile*>(hauteur, 0);
    }
}

quint8 Map::largeur() const
{
    return m_largeur;
}

quint8 Map::hauteur() const
{
    return m_hauteur;
}

Tile* Map::operator()(quint8 x, quint8 y) const
{
    Q_ASSERT(x < m_largeur);
    Q_ASSERT(y < m_hauteur);
    return m_tiles[x][y];
}

Tile*& Map::operator()(quint8 x, quint8 y)
{
    Q_ASSERT(x < m_largeur);
    Q_ASSERT(y < m_hauteur);
    return m_tiles[x][y];
}

#include <QDebug>

Map* Map::loadMap()
{
    quint8 X = 20;
    quint8 Y = 20;
    Map* m = new Map(X, Y);

    try {
        for(quint8 x = 0; x < X; ++x)
            for(quint8 y = 0; y < Y; ++y)
                if(((x == 2 || x == 17) && y < 17) || (x > 2 && x < 17 && y == 16)) {
                    (*m)(x,y) = TileFactory::createRoadTile(QPoint(x,y));
                }
                else (*m)(x,y) = TileFactory::createGrassTile(QPoint(x,y));
    }
    catch(TileFactory::type_factory::error_policy::Exception& ex)
    {
        qDebug() << ex.what() << " => " << ex.getId();
    }

    m->m_path << QPoint(2,0) << QPoint(2,16) << QPoint(17,16) << QPoint(17,0);
    return m;
}


QPoint Map::spawnPoint() const
{
    return m_path.front();
}

QPoint Map::escapePoint() const
{
    return m_path.back();
}

Map::type_path::const_iterator Map::pathBegin() const
{
    return m_path.begin();
}

Map::type_path::const_iterator Map::pathEnd() const
{
    return m_path.end();
}

const Map::type_path& Map::path() const
{
    return m_path;
}

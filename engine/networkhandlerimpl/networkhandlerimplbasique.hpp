#ifndef NETWORKHANDLERIMPLBASIQUE_HPP
#define NETWORKHANDLERIMPLBASIQUE_HPP

#include <list>
#include <map>

#include <QtGlobal>

class Tower;

class QPainter;

class NetworkHandlerImplBasique
{
public:
    struct Vertex
    {
        Vertex(Tower* _tower, quint8 _x, quint8 _y): tower(_tower), x(_x), y(_y)
        {}

        Tower* tower;
        quint8 x;
        quint8 y;
    };

    typedef std::list<Vertex> type_list_vertex;
    typedef std::map<Vertex, std::list<Vertex> > type_map_link_to;

    struct Connection
    {
        Connection(const Vertex& _from, const Vertex& _to, quint32 _capacity): from(_from), to(_to), capacity(_capacity)
        {}

        Vertex from;
        Vertex to;
        quint32 capacity;
    };
    typedef std::list<Connection> type_list_connections;

    NetworkHandlerImplBasique();

    void addTowerToNetwork(Tower* tower, quint8 x, quint8 y);

    void update(double dt);

    void draw(QPainter* painter) const;

private:
    type_list_vertex m_vertexes;
    type_list_connections m_connections;
    type_list_connections m_effectiveConnections;

    void updateConnections();

    bool testEffectiveConnectionsAreValid();

    void applyEffectiveConnections(double dt);
};

#endif // NETWORKHANDLERIMPLBASIQUE_HPP

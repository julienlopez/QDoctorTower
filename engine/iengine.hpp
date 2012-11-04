#ifndef IENGINE_HPP
#define IENGINE_HPP

#include <boost/shared_ptr.hpp>

#include <list>

class Creep;

class QPointF;

class iEngine
{
public:
    typedef boost::shared_ptr<Creep> sp_creep;
    typedef boost::weak_ptr<Creep> wp_creep;
    typedef std::list<sp_creep> type_liste_creep;

    virtual const type_liste_creep& creeps() const =0;

    virtual double dt() const =0;

protected:
    virtual sp_creep closestCreep(const QPointF& p) const =0;

    virtual type_liste_creep& creeps() =0;
};

#endif // IENGINE_HPP

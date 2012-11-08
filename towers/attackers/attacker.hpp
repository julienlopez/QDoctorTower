#ifndef ATTACKER_HPP
#define ATTACKER_HPP

#include <utils/hasrechargetime.hpp>
#include <creeps/creep.h>
#include <towers/tower.hpp>

class Attacker : public Tower, protected HasRechargeTime
{
public:
    typedef boost::weak_ptr<Creep> wp_creep;

    Attacker(const QPoint& p, quint32 cost);

    virtual void update(double dt);

    double portee() const;

    wp_creep cible() const;

    void setCible(wp_creep creep);

    virtual void tirer() =0;

    virtual bool canTarget() const;

    bool isCreepInRange(wp_creep creep) const;

protected:
    void setPortee(double t);

private:
    double m_portee;
    wp_creep m_cible;
};

#endif // ATTACKER_HPP

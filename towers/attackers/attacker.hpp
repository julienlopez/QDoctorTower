#ifndef ATTACKER_HPP
#define ATTACKER_HPP

#include <creeps/creep.h>
#include <towers/tower.hpp>

class Attacker : public Tower
{
public:
    typedef boost::weak_ptr<Creep> wp_creep;

    Attacker(const QPoint& p);

    virtual void update(double dt);

    double tempsRecharge() const;

    double portee() const;

    double compteurRecharge() const;

    wp_creep cible() const;

    void setCible(wp_creep creep);

    virtual void tirer() =0;

    virtual bool canTarget() const;

    bool isCreepInRange(wp_creep creep) const;

protected:
    void setTempsRecharge(double t);

    void setPortee(double t);

    void setCompteurRecharge(double d);

private:
    double m_tempsRecharge;
    double m_portee;
    double m_compteurRecharge;
    wp_creep m_cible;
};

#endif // ATTACKER_HPP

#ifndef ATTACKER_HPP
#define ATTACKER_HPP

#include <towers/tower.hpp>

class Creep;

class Attacker : public Tower
{
    Q_OBJECT
public:
    Attacker(const QPoint& p);

    virtual void update(double dt);

    double tempsRecharge() const;

    double portee() const;

    double compteurRecharge() const;

    Creep* cible() const;

    void setCible(Creep* creep);

    virtual void tirer() =0;

    virtual bool canTarget() const;

    bool isCreepInRange(Creep* creep) const;

protected:
    void setTempsRecharge(double t);

    void setPortee(double t);

    void setCompteurRecharge(double d);

private:
    double m_tempsRecharge;
    double m_portee;
    double m_compteurRecharge;
    Creep* m_cible;

private slots:
    void onCreepDead();
};

#endif // ATTACKER_HPP

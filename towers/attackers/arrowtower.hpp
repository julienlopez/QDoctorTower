#ifndef ARROWTOWER_HPP
#define ARROWTOWER_HPP

#include "attacker.hpp"

class ArrowTower : public Attacker
{
public:

    ArrowTower(const QPoint& p, double range = 5, double rechargeTime = 0.5, quint32 cost = 50);

    void affecteValues(const ArrowTower* at);

    virtual bool canGoOnWater() const;

    virtual void tirer();

    virtual const QString& icone() const;

    static const quint8 s_idType;
    static const bool s_registered;

    static const QString s_icone;

    virtual bool canLevelUp() const;

    virtual void levelUp();

    virtual std::string label() const;

    typedef std::map<quint8, boost::shared_ptr<ArrowTower> > type_containr_levels;

private:
    static const type_containr_levels s_levels;
};

#endif // ARROWTOWER_HPP

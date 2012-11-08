#ifndef ARROWTOWER_HPP
#define ARROWTOWER_HPP

#include "attacker.hpp"

class ArrowTower : public Attacker
{
public:
    ArrowTower(const QPoint& p);

    virtual bool canGoOnWater() const;

    virtual void tirer();

    virtual const QString& icone() const;

    static const quint8 s_idType;
    static const bool s_registered;

    static const QString s_icone;
};

#endif // ARROWTOWER_HPP

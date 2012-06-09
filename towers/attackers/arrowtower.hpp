#ifndef ARROWTOWER_HPP
#define ARROWTOWER_HPP

#include "attacker.hpp"

class ArrowTower : public Attacker
{
    Q_OBJECT

public:
    ArrowTower(const QPoint& p);

    virtual bool canGoOnWater() const;

    virtual void tirer();

    static const quint8 s_idType;
    static const bool s_registered;

    static const QString s_icone;
};

#endif // ARROWTOWER_HPP

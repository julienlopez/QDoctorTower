#ifndef CANONTOWER_HPP
#define CANONTOWER_HPP

#include "attacker.hpp"

class CanonTower : public Attacker
{
    Q_OBJECT
public:
    explicit CanonTower(const QPoint& p);

    virtual bool canGoOnWater() const;

    virtual void tirer();

    static const quint8 s_idType;
    static const bool s_registered;

    static const QString s_icone;

};

#endif // CANONTOWER_HPP

#ifndef CANONTOWER_HPP
#define CANONTOWER_HPP

#include "attacker.hpp"

class CanonTower : public Attacker
{
public:
    explicit CanonTower(const QPoint& p);

    virtual bool canGoOnWater() const;

    virtual void tirer();

    virtual const QString& icone() const;

    static const quint8 s_idType;
    static const bool s_registered;

    static const QString s_icone;

    virtual bool canLevelUp() const;

    virtual void levelUp();

    virtual std::string label() const;

};

#endif // CANONTOWER_HPP

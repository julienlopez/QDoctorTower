#ifndef BLASTERTOWER_HPP
#define BLASTERTOWER_HPP

#include "attacker.hpp"

class BlasterTower : public Attacker
{
public:
    BlasterTower(const QPoint& p);

    virtual bool canGoOnWater() const;

    virtual void tirer();

    virtual const QString& icone() const;

    static const quint8 s_idType;
    static const bool s_registered;

    static const QString s_icone;

protected:
    virtual bool canFire() const;
};

#endif // BLASTERTOWER_HPP

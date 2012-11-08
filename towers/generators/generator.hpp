#ifndef GENERATOR_HPP
#define GENERATOR_HPP

#include <towers/tower.hpp>
#include <utils/hasrechargetime.hpp>

class Generator : public Tower, protected HasRechargeTime
{
public:
    Generator(const QPoint& p, quint32 cost, quint32 energyMax);

    virtual bool canTarget() const;

    virtual void update(double dt);

    virtual quint32 produceEnergy() =0;
};

#endif // GENERATOR_HPP

#include "hasrechargetime.hpp"

#include <cassert>

HasRechargeTime::HasRechargeTime(): m_rechargeTime(0), m_rechargeCounter(0)
{}

double HasRechargeTime::rechargeTime() const
{
    return m_rechargeTime;
}

double HasRechargeTime::rechargeCounter() const
{
    return m_rechargeCounter;
}

void HasRechargeTime::setRechargeTime(double t)
{
    m_rechargeTime = t;
}

void HasRechargeTime::addToRechargeCounter(double dt)
{
    m_rechargeCounter += dt;
}

void HasRechargeTime::useRechargeTime()
{
    assert(m_rechargeCounter >= m_rechargeTime);
    m_rechargeCounter -= m_rechargeTime;
}

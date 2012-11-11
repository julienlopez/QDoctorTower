#include "ability.hpp"

Ability::Ability(type_fct_action action, type_fct_condition condition): m_action(action), m_condition(condition)
{}

void Ability::update(double dt)
{
    if(rechargeCounter() < rechargeTime()) addToRechargeCounter(dt);
    if(rechargeCounter() >= rechargeTime() && m_condition())
    {
        m_action();
        useRechargeTime();
    }
}

void Ability::setCondition(type_fct_condition c)
{
    m_condition = c;
}

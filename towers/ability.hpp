#ifndef ABILITY_HPP
#define ABILITY_HPP

#include <utils/hasrechargetime.hpp>

#include <boost/function.hpp>

class Ability : public HasRechargeTime
{
public:
    typedef boost::function<bool ()> type_fct_condition;
    typedef boost::function<void ()> type_fct_action;

    Ability(type_fct_action action, type_fct_condition condition);

    void update(double dt);

private:
    type_fct_action m_action;
    type_fct_condition m_condition;
};

#endif // ABILITY_HPP

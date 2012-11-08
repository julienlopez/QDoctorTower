#ifndef HASRECHARGETIME_HPP
#define HASRECHARGETIME_HPP

/**
* \brief utility class for objects that have ability with a cooldown time
*
*
*/
class HasRechargeTime
{
public:
    HasRechargeTime();

    double rechargeTime() const;

    double rechargeCounter() const;

    void setRechargeTime(double t);

    void addToRechargeCounter(double dt);

    /**
    * \brief substract the recharge time from the recharge counter
    *
    * Should be used when the ability is used, to reset the wait timer.
    * just performs m_rechargeCounter -= m_rechargeTime
    */
    void useRechargeTime();

private:
    double m_rechargeTime;
    double m_rechargeCounter;
};

#endif // HASRECHARGETIME_HPP

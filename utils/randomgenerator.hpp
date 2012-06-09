#ifndef RANDOMGENERATOR_HPP
#define RANDOMGENERATOR_HPP

/*
Pas utilisable avec c++ standard, peut-être c++11

template<typename T, T min, T max> class RandomGenerator
{
    T operator()() const
    {

    }
};
*/

#include "traits/parametertrait.hpp"

template<typename T> class RandomGenerator
{
public:
    RandomGenerator(typename ParameterTrait<T>::const_reference min, typename ParameterTrait<T>::const_reference max)
    {
        m_range = (max - min)*1000;
        m_bias = min;
    }

    T operator()() const
    {
        return ((T)(qrand() % m_range))/1000 + m_bias;
    }

private:
    long m_range;
    T m_bias;
};

#endif // RANDOMGENERATOR_HPP

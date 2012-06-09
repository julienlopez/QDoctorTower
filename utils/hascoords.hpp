#ifndef HASCOORDS_HPP
#define HASCOORDS_HPP

#include "traits/parametertrait.hpp"

template<class T> class HasCoords
{
public:
    HasCoords(typename ParameterTrait<T>::const_reference coords)
    {
        m_coords = coords;
    }

    typename ParameterTrait<T>::const_reference coords() const
    {
        return m_coords;
    }

protected:
    HasCoords& operator+=(typename ParameterTrait<T>::const_reference c)
    {
        m_coords += c;
        return *this;
    }

    void setCoords(typename ParameterTrait<T>::const_reference c)
    {
        m_coords = c;
    }

private:
    T m_coords;
};

#endif // HASCOORDS_HPP

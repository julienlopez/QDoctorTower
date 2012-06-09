#ifndef MOVING_HPP
#define MOVING_HPP

#include "updateable.hpp"
#include "hascoords.hpp"
template<class T> class Moving : public HasCoords<T>, public Updateable
{
public:
    Moving(typename ParameterTrait<T>::const_reference coords): HasCoords<T>(coords)
    {}

    double vitesse() const
    {
        return m_vitesse;
    }

protected:
    void setVitesse(double vitesse)
    {
        m_vitesse = vitesse;
    }

private:
    double m_vitesse;
};

#endif // MOVING_HPP

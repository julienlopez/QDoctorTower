#ifndef RAT_HPP
#define RAT_HPP

#include "creep.h"

class Rat : public Creep
{
public:
    Rat(const QPointF& p);

    static const quint8 s_idType;
    static const bool s_registered;
};

#endif // RAT_HPP

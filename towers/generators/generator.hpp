#ifndef GENERATOR_HPP
#define GENERATOR_HPP

#include <towers/tower.hpp>

class Generator : public Tower
{
public:
    Generator(const QPoint& p, quint32 cost);
};

#endif // GENERATOR_HPP

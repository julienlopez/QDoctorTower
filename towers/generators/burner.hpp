#ifndef BURNER_HPP
#define BURNER_HPP

#include "generator.hpp"

class Burner : public Generator
{
public:
    Burner(const QPoint& p);

    virtual bool canGoOnWater() const;

    virtual const QString& icone() const;

    virtual double produceEnergy();

    static const quint8 s_idType;
    static const bool s_registered;

    static const QString s_icone;
};

#endif // BURNER_HPP

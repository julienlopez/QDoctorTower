#ifndef ENERGYHANDLER_HPP
#define ENERGYHANDLER_HPP

#include <QtGlobal>

class EnergyHandler
{
public:
    EnergyHandler();

    bool hasEnergy() const;

    quint32 energy() const;

    quint32 energyMax() const;

    void addEnergy(quint32 de);

    quint32 energyInputMax() const;

    quint32 energyOutputMax() const;

protected:
    void setEnergyMax(quint32 energyMax);

    void setEnergyInputMax(quint32 energyInputMax);

    void setEnergyOutputMax(quint32 energyOutputMax);

private:
    quint32 m_energy;
    quint32 m_energyMax;
    quint32 m_energyInputMax;
    quint32 m_energyOutputMax;
};

#endif // ENERGYHANDLER_HPP

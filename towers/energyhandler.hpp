#ifndef ENERGYHANDLER_HPP
#define ENERGYHANDLER_HPP

#include <stdexcept>

class EnergyHandler
{
public:
    EnergyHandler();

    bool hasEnergy() const;

    double energy() const;

    double energyMax() const;

    void addEnergy(double de);

    void subtractEnergy(double de) throw(std::invalid_argument);

    double energyInputMax() const;

    double energyOutputMax() const;

protected:
    void setEnergyMax(double energyMax);

    void setEnergyInputMax(double energyInputMax);

    void setEnergyOutputMax(double energyOutputMax);

private:
    double m_energy;
    double m_energyMax;
    double m_energyInputMax;
    double m_energyOutputMax;
};

#endif // ENERGYHANDLER_HPP

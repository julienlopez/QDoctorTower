#include "energyhandler.hpp"

EnergyHandler::EnergyHandler(): m_energy(0), m_energyMax(0), m_energyInputMax(0), m_energyOutputMax(0)
{}

bool EnergyHandler::hasEnergy() const
{
    return m_energyMax > 0;
}

double EnergyHandler::energy() const
{
    return m_energy;
}

double EnergyHandler::energyMax() const
{
    return m_energyMax;
}

void EnergyHandler::setEnergyMax(double energyMax)
{
    m_energyMax = energyMax;
}

void EnergyHandler::addEnergy(double de)
{
    m_energy += de;
    if(m_energy > m_energyMax) m_energy = m_energyMax;
}

void EnergyHandler::subtractEnergy(double de) throw(std::invalid_argument)
{
    if(m_energy < de) throw std::invalid_argument("Not enough energy");
    m_energy -= de;
}

double EnergyHandler::energyInputMax() const
{
    return m_energyInputMax;
}

double EnergyHandler::energyOutputMax() const
{
    return m_energyOutputMax;
}

void EnergyHandler::setEnergyInputMax(double energyInputMax)
{
    m_energyInputMax = energyInputMax;
}

void EnergyHandler::setEnergyOutputMax(double energyOutputMax)
{
    m_energyOutputMax = energyOutputMax;
}

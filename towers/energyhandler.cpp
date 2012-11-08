#include "energyhandler.hpp"

EnergyHandler::EnergyHandler(): m_energy(0), m_energyMax(0), m_energyInputMax(0), m_energyOutputMax(0)
{}

bool EnergyHandler::hasEnergy() const
{
    return m_energyMax > 0;
}

quint32 EnergyHandler::energy() const
{
    return m_energy;
}

quint32 EnergyHandler::energyMax() const
{
    return m_energyMax;
}

void EnergyHandler::setEnergyMax(quint32 energyMax)
{
    m_energyMax = energyMax;
}

void EnergyHandler::addEnergy(quint32 de)
{
    m_energy += de;
    if(m_energy > m_energyMax) m_energy = m_energyMax;
}

quint32 EnergyHandler::energyInputMax() const
{
    return m_energyInputMax;
}

quint32 EnergyHandler::energyOutputMax() const
{
    return m_energyOutputMax;
}

void EnergyHandler::setEnergyInputMax(quint32 energyInputMax)
{
    m_energyInputMax = energyInputMax;
}

void EnergyHandler::setEnergyOutputMax(quint32 energyOutputMax)
{
    m_energyOutputMax = energyOutputMax;
}

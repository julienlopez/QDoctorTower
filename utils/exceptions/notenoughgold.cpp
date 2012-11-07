#include "notenoughgold.hpp"

Exception::NotEnoughGold::NotEnoughGold(quint32 needed, quint32 available) : Exception::Exception(QString::number(needed) + " needed for only " + QString::number(available) + " available.")
{
}

#include "state.hpp"

GameTurn::State::State(quint32 gold, quint8 nbCreep, quint8 typeCreep, QState *parent) :
    QState(parent), m_gold(gold), m_nbCreep(nbCreep), m_typeCreep(typeCreep), m_level(0)
{
}

quint32 GameTurn::State::gold() const
{
    return m_gold;
}

quint8 GameTurn::State::nbCreep() const
{
    return m_nbCreep;
}

quint8 GameTurn::State::typeCreep() const
{
    return m_typeCreep;
}

quint8 GameTurn::State::level() const
{
    return m_level;
}

void GameTurn::State::setLevel(quint8 level)
{
    m_level = level;
}

void GameTurn::State::finish()
{
    Q_EMIT finished();
}

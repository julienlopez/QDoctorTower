#ifndef STATE_HPP
#define STATE_HPP

#include <QState>

namespace GameTurn {

class State : public QState
{
    Q_OBJECT
public:
    explicit State(quint32 gold, quint8 nbCreep, quint8 typeCreep, QState *parent = 0);

    quint32 gold() const;
    quint8 nbCreep() const;
    quint8 typeCreep() const;

    quint8 level() const;
    void setLevel(quint8 level);

    void finish();

private:
    quint32 m_gold;
    quint8 m_nbCreep;
    quint8 m_typeCreep;
    quint8 m_level;

Q_SIGNALS:

public Q_SLOTS:

};

}

#endif // STATE_HPP

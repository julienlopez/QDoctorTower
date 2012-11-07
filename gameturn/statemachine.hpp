#ifndef STATEMACHINE_HPP
#define STATEMACHINE_HPP

#include <QStateMachine>

class QFinalState;

namespace GameTurn {

class State;

class StateMachine : public QStateMachine
{
    Q_OBJECT
public:
    explicit StateMachine(QObject *parent = 0);

    void init();

    void add(State* s);
    void add(QFinalState* s);

    State* currentState();

private:
    quint8 m_cptState;
    State* m_currentState;
    State* m_lastStateAdded;

Q_SIGNALS:
    void newStateEntered();

private Q_SLOTS:
    void onStateEntered();

public Q_SLOTS:
    void next();

};

}

#endif // STATEMACHINE_HPP

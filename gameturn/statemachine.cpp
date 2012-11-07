#include "statemachine.hpp"
#include "state.hpp"

#include "creeps/rat.hpp"

#include <QFinalState>

GameTurn::StateMachine::StateMachine(QObject *parent) :
    QStateMachine(parent)
{
    m_currentState = 0;
}

void GameTurn::StateMachine::init()
{
    m_cptState = 1;
    m_lastStateAdded = 0;
    State* s1 = new State(200, 20, Rat::s_idType);
    State* s2 = new State(300, 30, Rat::s_idType);
    add(s1);
    add(s2);
    setInitialState(s1);

    add(new QFinalState); //final state to enable finished to be emitted by this machine
}

void GameTurn::StateMachine::add(State* s)
{
    s->setLevel(m_cptState++);
    connect(s, SIGNAL(entered()), this, SLOT(onStateEntered()));
    QStateMachine::addState(s);
    if(m_lastStateAdded) m_lastStateAdded->addTransition(m_lastStateAdded, SIGNAL(finished()), s);
    m_lastStateAdded = s;
}

void GameTurn::StateMachine::add(QFinalState* s)
{
    if(m_lastStateAdded) m_lastStateAdded->addTransition(m_lastStateAdded, SIGNAL(finished()), s);
    QStateMachine::addState(s);
    m_lastStateAdded = 0;
}

GameTurn::State* GameTurn::StateMachine::currentState()
{
    return m_currentState;
}

void GameTurn::StateMachine::onStateEntered()
{
     State* s = qobject_cast<State*>(sender());
     m_currentState = s;
     Q_EMIT newStateEntered();
}

void GameTurn::StateMachine::next()
{
    m_currentState->finish();
}

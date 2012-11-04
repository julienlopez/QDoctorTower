#include "joueur.h"

Joueur::Joueur(QObject* parent) : QObject(parent)
{
    m_gold = 0;
    m_nbEscaped = 0;
    m_nbKilled = 0;
}

quint32 Joueur::gold() const
{
    return m_gold;
}

QString Joueur::pseudo() const
{
    return m_pseudo;
}

void Joueur::addEscaped(quint32 nb)
{
    m_nbEscaped += nb;
    Q_EMIT nbEscapedChanged(m_nbEscaped);
}

void Joueur::addKilled(quint32 nb)
{
    m_nbKilled += nb;
    Q_EMIT nbKilledChanged(m_nbKilled);
}

void Joueur::addGold(quint32 qtt)
{
    m_gold += qtt;
    Q_EMIT goldChanged(m_gold);
}

void Joueur::retrieveGold(quint32 qtt) throw(std::invalid_argument)
{
    if(qtt > m_gold) throw std::invalid_argument((QString::number(qtt)+" > "+QString::number(m_gold)).toStdString());
}

void Joueur::setPseudo(QString pseudo)
{
    m_pseudo = pseudo;
    Q_EMIT pseudoChanged(m_pseudo);
}

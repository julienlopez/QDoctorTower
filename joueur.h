#ifndef JOUEUR_H
#define JOUEUR_H

#include <QObject>
#include <QString>

#include <stdexcept>

class Joueur : public QObject
{
    Q_OBJECT
public:
    Joueur(QObject* parent = 0);

    quint32 gold() const;
    QString pseudo() const;

    void addEscaped(quint32 nb = 1);
    void addKilled(quint32 nb = 1);

public slots:
    void addGold(quint32 qtt);
    void retrieveGold(quint32 qtt) throw(std::invalid_argument);
    void setPseudo(QString pseudo);

signals:
    void pseudoChanged(QString);
    void goldChanged(int);
    void nbEscapedChanged(int);
    void nbKilledChanged(int);

private:
    quint32 m_gold;
    QString m_pseudo;
    quint32 m_nbEscaped;
    quint32 m_nbKilled;
};

#endif // JOUEUR_H

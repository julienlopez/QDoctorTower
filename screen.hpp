#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <QWidget>

class Map;

class Screen : public QWidget
{
    Q_OBJECT
public:

    struct EngineMessage
    {
        EngineMessage(QString _titre, QString _message, quint8 _compteur);
        QString titre;
        QString message;
        quint8 compteur;
    };

    explicit Screen(Map* map, QWidget *parent = 0);
    
signals:
    
public slots:
    void onEngineMessage(QString, QString);
    void setTowerState(quint8 state);

protected:
    void paintEvent(QPaintEvent* evt);
    void mouseMoveEvent(QMouseEvent* evt);
    void mouseReleaseEvent(QMouseEvent* evt);

private:
    EngineMessage m_currentMessage;
    Map* m_map;
    quint8 m_currentTowerState;
    QPoint m_mousePos;
};

#endif // SCREEN_HPP

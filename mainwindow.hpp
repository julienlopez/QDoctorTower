#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Map;
class Screen;
class Joueur;
class Engine;

class QPushButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Map* m_map;
    Screen* m_screen;
    Joueur* m_player;
    Engine* m_engine;

    QPushButton* m_boutonDemarrer;

    void setUpPlayer();

private	Q_SLOTS:
    void onClickBoutonDemarrer();
    void onEngineDone();
};

#endif // MAINWINDOW_H

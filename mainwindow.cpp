#include "mainwindow.hpp"
#include "map.hpp"
#include "screen.hpp"
#include "joueur.h"
#include "engine.h"
#include "towerscreen.hpp"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLCDNumber>
#include <QInputDialog>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_map = Map::loadMap();

    m_player = new Joueur(this);

    m_screen = new Screen(m_map);

    TowerScreen* towerScreen = new TowerScreen;

    QWidget* w = new QWidget;
    QVBoxLayout* layout = new QVBoxLayout();
    QHBoxLayout* hl = new QHBoxLayout;
    m_engine = new Engine(m_player, m_map, this);
    connect(m_engine, SIGNAL(message(QString, QString)), m_screen, SLOT(onEngineMessage(QString, QString)));
    connect(m_engine, SIGNAL(updated()), m_screen, SLOT(update()));

    QLabel* l = new QLabel;
    connect(m_player, SIGNAL(pseudoChanged(QString)), l, SLOT(setText(QString)));
    hl->addWidget(new QLabel(tr("Pseudo: ")));
    hl->addWidget(l);

    QLCDNumber* lcd = new QLCDNumber(4);
    connect(m_player, SIGNAL(goldChanged(int)), lcd, SLOT(display(int)));
    hl->addWidget(new QLabel(tr("Or: ")));
    hl->addWidget(lcd);

    lcd = new QLCDNumber(4);
    connect(m_player, SIGNAL(nbKilledChanged(int)), lcd, SLOT(display(int)));
    hl->addWidget(new QLabel(tr("Killed: ")));
    hl->addWidget(lcd);

    lcd = new QLCDNumber(4);
    connect(m_player, SIGNAL(nbEscapedChanged(int)), lcd, SLOT(display(int)));
    hl->addWidget(new QLabel(tr("Escaped: ")));
    hl->addWidget(lcd);

    m_boutonDemarrer = new QPushButton("Démarrer");
    connect(m_boutonDemarrer, SIGNAL(clicked()), this, SLOT(onClickBoutonDemarrer()));
    hl->addWidget(m_boutonDemarrer);

    layout->addLayout(hl);
    hl = new QHBoxLayout;
    hl->addWidget(m_screen);
    hl->addWidget(towerScreen);
    layout->addLayout(hl);
    w->setLayout(layout);
    setCentralWidget(w);

    setUpPlayer();
}

MainWindow::~MainWindow()
{
    delete m_map;
}

void MainWindow::setUpPlayer()
{
    QString p;
    while(p.isEmpty()) p = QInputDialog::getText(this, tr("Choix du peudo"), tr("Choisissez votre pseudo"));
    m_player->setPseudo(p);
}

void MainWindow::onClickBoutonDemarrer()
{
    m_boutonDemarrer->setEnabled(false);
    m_engine->start();
}

void MainWindow::onEngineDone()
{
    m_boutonDemarrer->setEnabled(true);
}

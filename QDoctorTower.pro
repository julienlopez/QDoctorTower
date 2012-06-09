#-------------------------------------------------
#
# Project created by QtCreator 2012-06-02T13:59:57
#
#-------------------------------------------------

QT       += core gui

TARGET = QDoctorTower
TEMPLATE = app

INCLUDEPATH += .

SOURCES += main.cpp\
        mainwindow.cpp \
    tiles/tile.cpp \
    tiles/roadtile.cpp \
    tiles/watertile.cpp \
    tiles/grasstile.cpp \
    towers/tower.cpp \
    map.cpp \
    screen.cpp \
    tiles/tilefactory.cpp \
    towers/towerfactory.cpp \
    towers/generators/generator.cpp \
    towers/attackers/attacker.cpp \
    creeps/creep.cpp \
    joueur.cpp \
    engine.cpp \
    creeps/creepfactory.cpp \
    creeps/rat.cpp \
    utils/exception.cpp \
    towers/attackers/arrowtower.cpp \
    bullets/bullet.cpp \
    towerscreen.cpp \
    bullets/fleche.cpp \
    towerbutton.cpp \
    towers/attackers/canontower.cpp

HEADERS  += \
    tiles/tile.hpp \
    tiles/roadtile.hpp \
    utils/factory.hpp \
    utils/defaultfactoryerrorpolicy.hpp \
    utils/traits/parametertrait.hpp \
    utils/singleton.hpp \
    tiles/grasstile.hpp \
    tiles/watertile.hpp \
    mainwindow.hpp \
    towers/tower.hpp \
    utils/drawable.hpp \
    map.hpp \
    screen.hpp \
    tiles/tilefactory.hpp \
    towers/towerfactory.hpp \
    towers/generators/generator.hpp \
    towers/attackers/attacker.hpp \
    creeps/creep.h \
    joueur.h \
    engine.h \
    creeps/creepfactory.h \
    creeps/rat.hpp \
    utils/hascoords.hpp \
    utils/randomgenerator.hpp \
    utils/exception.hpp \
    towers/attackers/arrowtower.hpp \
    bullets/bullet.hpp \
    towerscreen.hpp \
    utils/updateable.hpp \
    bullets/fleche.hpp \
    utils/moving.hpp \
    towerbutton.hpp \
    towers/attackers/canontower.hpp

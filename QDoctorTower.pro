include(QDoctorTower.pri)

QT       += core gui
CONFIG += no_keywords

TARGET = QDoctorTower
TEMPLATE = app

INCLUDEPATH += .

CXXFLAGS += -Og

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
    engine/engine.cpp \
    creeps/creepfactory.cpp \
    creeps/rat.cpp \
    utils/exceptions/exception.cpp \
    towers/attackers/arrowtower.cpp \
    bullets/bullet.cpp \
    towerscreen.cpp \
    bullets/fleche.cpp \
    towerbutton.cpp \
    towers/attackers/canontower.cpp \
    engine/creephandler.cpp \
    engine/towerhandler.cpp \
    engine/bullethandler.cpp \
    utils/exceptions/notenoughgold.cpp \
    gameturn/statemachine.cpp \
    gameturn/state.cpp 

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
    creeps/creepfactory.h \
    creeps/rat.hpp \
    utils/hascoords.hpp \
    utils/randomgenerator.hpp \
    utils/exceptions/exception.hpp \
    towers/attackers/arrowtower.hpp \
    bullets/bullet.hpp \
    towerscreen.hpp \
    utils/updateable.hpp \
    bullets/fleche.hpp \
    utils/moving.hpp \
    towerbutton.hpp \
    towers/attackers/canontower.hpp \
    engine/engine.hpp \
    engine/creephandler.hpp \
    engine/towerhandler.hpp \
    engine/iengine.hpp \
    engine/bullethandler.hpp \
    utils/todelsender.hpp \
    utils/predicates.hpp \
    utils/exceptions/notenoughgold.hpp \
    gameturn/statemachine.hpp \
    gameturn/state.hpp 

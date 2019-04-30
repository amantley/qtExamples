QT += core
QT -= gui

TARGET = savegame
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

# install
target.path = $$[QT_INSTALL_EXAMPLES]/corelib/json/savegame
INSTALLS += target

SOURCES += main.cpp \
    animNode.cpp \
	character.cpp \
    game.cpp \
    level.cpp \
    edge.cpp \
    graphwidget.cpp \
    node.cpp

HEADERS += \
    animNode.h \
	character.h \
    game.h \
    level.h \
    edge.h \
    graphwidget.h \
    node.h

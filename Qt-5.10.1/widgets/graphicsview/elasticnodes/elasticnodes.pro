QT += widgets

HEADERS += \
        edge.h \
        node.h \
        graphwidget.h \
    animNode.h \
    game.h

SOURCES += \
        edge.cpp \
        main.cpp \
        node.cpp \
        graphwidget.cpp \
    animNode.cpp \
    game.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/graphicsview/elasticnodes
INSTALLS += target

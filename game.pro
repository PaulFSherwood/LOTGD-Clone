TEMPLATE = app
CONFIG += console
CONFIG += qt
QT      += xml

LIBS += -L/usr/local/lib -lSDL -lSDLmain -lSDL_image -lSDL_ttf

SOURCES += main.cpp \
    xp.cpp \
    forrest.cpp \
    xmlParse.cpp \
    display.cpp \
    fighttable.cpp \
    training.cpp \
    shop.cpp \
    bank.cpp \
    orge.cpp \
    warrior.cpp

HEADERS += \
    xp.h \
    variables.h \
    forrest.h \
    xmlParse.h \
    display.h \
    fighttable.h \
    training.h \
    includes.h \
    shop.h \
    bank.h \
    orge.h \
    warrior.h

OTHER_FILES += \
    img/background.png \
    img/hud.png


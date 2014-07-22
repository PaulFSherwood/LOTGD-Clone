TEMPLATE = app
CONFIG += console
CONFIG += qt
QT     += xml

LIBS += -L/usr/local/lib -lSDL -lSDLmain -lSDL_image -lSDL_ttf

SOURCES += main.cpp \
    uiGroup.cpp \
    training.cpp \
    shop.cpp \
    forrest.cpp \
    fighttable.cpp \
    display.cpp \
    bank.cpp \
    xp.cpp \
    xmlParse.cpp \
    creature.cpp \
    player.cpp \
    textData.cpp

HEADERS += \
    uiGroup.h \
    training.h \
    shop.h \
    includes.h \
    forrest.h \
    fighttable.h \
    display.h \
    bank.h \
    xp.h \
    xmlParse.h \
    creature.h \
    player.h \
    textData.h

OTHER_FILES += \
    arial.ttf \
    data/uiData.xml \
    data/myData.xml \
    img/xpRed.png \
    img/xpBlue.png \
    img/background.png \
    data/fightData.xml \
    img/Left_Menu.png


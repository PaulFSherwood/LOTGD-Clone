#ifndef FORREST_H
#define FORREST_H

#include <QObject>
#include <iostream>
#include "display.h"
#include "creature.h"
#include "player.h"
using namespace std;

class forrest : public QObject
{
    Q_OBJECT

public:
    forrest();

    void ForestLvl1(myplayer * myPlayer, mycreature * myCreature, uiGroup * uiDataValues, myTextData * TextData_Object);

public slots:
    void handleKeyEvent(int key);
};

#endif // FORREST_H

#ifndef FORREST_H
#define FORREST_H

#include <iostream>
#include "display.h"
#include "creature.h"
#include "player.h"
using namespace std;

class forrest
{
public:
    forrest();

    void ForestLvl1(myplayer * myPlayer, mycreature * myCreature, uiGroup * uiDataValues);
};

#endif // FORREST_H

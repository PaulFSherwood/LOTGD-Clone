#ifndef FORREST_H
#define FORREST_H

#include <iostream>
#include "display.h"
#include "orge.h"
#include "warrior.h"
using namespace std;

class forrest
{
public:
    forrest();

    void ForestLvl1(mywarrior * mySoilder, npc_orge * randomOrge, uiGroup * uiDataValues);
};

#endif // FORREST_H

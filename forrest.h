#ifndef FORREST_H
#define FORREST_H

#include <iostream>
#include "orge.h"
#include "warrior.h"
using namespace std;

class forrest
{
public:
    forrest();

    void ForestLvl1(mywarrior * mySoilder, npc_orge * randomOrge);
};

#endif // FORREST_H

#ifndef FIGHTTABLE_H
#define FIGHTTABLE_H

#include <iostream>
#include <cmath>
#include "orge.h"
#include "warrior.h"
using namespace std;

class fighttable
{
public:
    fighttable();
    void Fight_Table(mywarrior * mySoilder, npc_orge * randomOrge);

    int incommingDmg(int DmgPotential, int DmgMitigation);
};

#endif // FIGHTTABLE_H

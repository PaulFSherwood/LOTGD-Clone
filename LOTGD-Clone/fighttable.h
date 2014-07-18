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

    int getCreatureHp(mywarrior * warrior_Object, npc_orge * npc_Object);
    int getCreatureDef(mywarrior * warrior_Object, npc_orge * npc_Object);
    string getCreatureName(npc_orge * npc_Object);
    string getCreatureWeapon(npc_orge * npc_Object);
    int getCreatureAttack(mywarrior * warrior_Object, npc_orge * npc_Object);

    int incommingDmg(int DmgPotential, int DmgMitigation);
};

#endif // FIGHTTABLE_H

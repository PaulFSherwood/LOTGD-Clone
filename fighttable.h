#ifndef FIGHTTABLE_H
#define FIGHTTABLE_H

#include <iostream>
#include <cmath>
#include "includes.h"
using namespace std;

extern struct player warrior;
extern struct npc orge;

class fighttable
{
public:
    fighttable();
    void Fight_Table(player &warrior, npc &orge);
//
};

#endif // FIGHTTABLE_H

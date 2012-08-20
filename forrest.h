#ifndef FORREST_H
#define FORREST_H
#include <iostream>
#include "includes.h"
using namespace std;

extern player warrior;
extern npc orge;

class forrest
{
public:
    forrest();

    int ForestLvl1(player &warrior, npc &orge);
};

#endif // FORREST_H

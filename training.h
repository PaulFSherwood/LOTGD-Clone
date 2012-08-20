#ifndef TRAINING_H
#define TRAINING_H

#include <iostream>
#include "includes.h"
using namespace std;

extern struct player warrior;
extern struct npc orge;

class training
{
public:
    training();
    void Warrior_Training(player &warrior);
};

#endif // TRAINING_H

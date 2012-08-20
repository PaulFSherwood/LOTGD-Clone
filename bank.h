#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <stdio.h>
#include "includes.h"
using namespace std;

extern struct player warrior;
extern struct npc orge;

class bank
{
public:
    bank();

    void old_Bank(player &warrior);
};

#endif // BANK_H

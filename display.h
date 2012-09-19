#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include "orge.h"
#include "warrior.h"
using namespace std;

class display
{
public:
    display();

    void mainDisplay(mywarrior * warrior_Object);
    void forrestDisplay(mywarrior * warrior_Object);
    void fightDisplay(mywarrior * warrior_Object, npc_orge * npc_Object);
    void old_Bank(mywarrior * warrior_Object);

    void Weapon_Shop(string &systemMessage);
    void Armor_Shop(string &systemMessage);
};

#endif // DISPLAY_H

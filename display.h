#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include "includes.h"
using namespace std;

extern struct player warrior;
extern struct npc orge;

class display
{
public:
    display();

    void mainDisplay(player &warrior);
    void forrestDisplay(player &warrior);
    void fightDisplay(player &warrior, npc &orge);
    void old_Bank(player &warrior);

    void Shop_Entrance();
    void Weapon_Shop(string &systemMessage);
    void Armor_Shop(string &systemMessage);
};

#endif // DISPLAY_H

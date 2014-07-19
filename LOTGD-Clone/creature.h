#ifndef ORGE_H
#define ORGE_H

#include <iostream>
#include "player.h"
using namespace std;

class mycreature
{
public:
    mycreature();

    void SetCreatureHpC(int hp);
    void SetCreatureStrC(int str);
    void SetCreatureLvlC(int lvl);

    void SetCreatureAtkC(int atk);
    void SetCreatureDefC(int def);
    void SetCreatureDodgeC(int dod);
    void SetCreatureArmorValueC(int armorvalue);
    void SetCreatureNameC(string name);

    int GetCreatureHpC();
    int GetCreatureStrC();
    int GetCreatureLvlC();

    int GetCreatureAtkC();
    int GetCreatureDefC();
    int GetCreatureDodgeC();
    int GetCreatureArmorValueC();
    string GetCreatureNameC();
    void getNewCreature(myplayer * myPlayer, mycreature * myCreature);

    void PrintStats();

private:
    int CreatureHpC;
    int CreatureStrC;
    int CreatureLvlC;

    int CreatureAtkC;
    int CreatureDefC;
    int CreatureDodgeC;
    int CreatureArmorValueC;

    string CreatureNameC;
};

#endif // ORGE_H

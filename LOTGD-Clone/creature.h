#ifndef ORGE_H
#define ORGE_H

#include <iostream>
#include <vector>
#include "player.h"
using namespace std;

class mycreature
{
public:
    mycreature();

    void SetCreatureHpC(int hp);
    void SetCreatureStrC(int str);
    void SetCreatureLvlC(int lvl);
    void SetCreatureHitC(int hit);

    void SetCreatureAtkC(int atk);
    void SetCreatureDefC(int def);
    void SetCreatureDodgeC(int dod);
    void SetCreatureArmorValueC(int armorvalue);
    void SetCreatureNameC(string name);

    void SetFightVectorCounter(int data);
    string SetFightVectorData(string data, int index);

    int GetCreatureHpC();
    int GetCreatureStrC();
    int GetCreatureLvlC();
    int GetCreatureHitC();

    int GetCreatureAtkC();
    int GetCreatureDefC();
    int GetCreatureDodgeC();
    int GetCreatureArmorValueC();
    string GetCreatureNameC();

    int GetFightVectorCounter();
    string GetFightVectorData(int index);

    void GetNewCreature(myplayer * myPlayer, mycreature * myCreature);

    void PrintStats();

private:
    int CreatureHpC;
    int CreatureStrC;
    int CreatureLvlC;
    int CreatureHitC;

    int CreatureAtkC;
    int CreatureDefC;
    int CreatureDodgeC;
    int CreatureArmorValueC;

    int FightDataVectorCounter;
    vector<string> CreatureVectorData;

    string CreatureNameC;
};

#endif // ORGE_H

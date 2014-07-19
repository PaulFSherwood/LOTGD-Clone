#include <iostream>
#include "creature.h"
using namespace std;

mycreature::mycreature(){}

void mycreature::SetCreatureHpC(int hp) { CreatureHpC = hp; }
void mycreature::SetCreatureStrC(int str) { CreatureStrC = str; }
void mycreature::SetCreatureLvlC(int lvl) { CreatureLvlC = lvl; }
void mycreature::SetCreatureAtkC(int atk) { CreatureAtkC = atk; }
void mycreature::SetCreatureDefC(int def) { CreatureDefC = def; }
void mycreature::SetCreatureDodgeC(int dod) { CreatureDodgeC = dod; }
void mycreature::SetCreatureArmorValueC(int armorvalue) { CreatureArmorValueC = armorvalue; }
void mycreature::SetCreatureNameC(string name) { CreatureNameC = name; }

int mycreature::GetCreatureHpC() { return CreatureHpC; }
int mycreature::GetCreatureStrC() { return CreatureStrC; }
int mycreature::GetCreatureLvlC() { return CreatureLvlC; }
int mycreature::GetCreatureAtkC() { return CreatureAtkC; }
int mycreature::GetCreatureDefC() { return CreatureDefC; }
int mycreature::GetCreatureArmorValueC() { return CreatureArmorValueC; }
string mycreature::GetCreatureNameC() { return CreatureNameC; }
void mycreature::getNewCreature(myplayer * myPlayer, mycreature * myCreature)
{
    // going to assume that levels have associated stats
    myPlayer->GetPlayerLvlP();
    // creature Strength
    myCreature->SetCreatureStrC(myPlayer->GetPlayerLvlP() * 10);
    // creature Attack power
    myCreature->SetCreatureAtkC(myPlayer->GetPlayerLvlP() * 40);
    // just going to assume creature has 82% dodge chance
    myCreature->SetCreatureDodgeC(82);
}

void mycreature::PrintStats()
{
    cout << "HP: " <<  mycreature::GetCreatureHpC() << endl;
    cout << "Str: " <<  mycreature::GetCreatureStrC() << endl;
    cout << "Lvl: " <<  mycreature::GetCreatureLvlC() << endl;
    cout << "Atk: " <<  mycreature::GetCreatureAtkC() << endl;
    cout << "Def: " <<  mycreature::GetCreatureDefC() << endl;
    cout << "Name: " <<  mycreature::GetCreatureNameC() << endl;
}


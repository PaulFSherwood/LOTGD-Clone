#include <iostream>
#include "creature.h"
using namespace std;

mycreature::mycreature(){}

void mycreature::SetOHpC(int hp) { OHpC = hp; }
void mycreature::SetOStrC(int str) { OStrC = str; }
void mycreature::SetOLvlC(int lvl) { OLvlC = lvl; }
void mycreature::SetOAtkC(int atk) { OAtkC = atk; }
void mycreature::SetODefC(int def) { ODefC = def; }
void mycreature::SetOArmorValueC(int armorvalue) { OArmorValueC = armorvalue; }
void mycreature::SetONameC(string name) { ONameC = name; }

int mycreature::GetOHpC() { return OHpC; }
int mycreature::GetOStrC() { return OStrC; }
int mycreature::GetOLvlC() { return OLvlC; }
int mycreature::GetOAtkC() { return OAtkC; }
int mycreature::GetODefC() { return ODefC; }
int mycreature::GetOArmorValueC() { return OArmorValueC; }
string mycreature::GetONameC() { return ONameC; }
void mycreature::getNewCreature(myplayer * myPlayer, mycreature * myCreature)
{
    // going to assume that levels have associated stats
    myPlayer->GetPlayerLvlP();
}

void mycreature::PrintStats()
{
    cout << "HP: " <<  mycreature::GetOHpC() << endl;
    cout << "Str: " <<  mycreature::GetOStrC() << endl;
    cout << "Lvl: " <<  mycreature::GetOLvlC() << endl;
    cout << "Atk: " <<  mycreature::GetOAtkC() << endl;
    cout << "Def: " <<  mycreature::GetODefC() << endl;
    cout << "Name: " <<  mycreature::GetONameC() << endl;
}


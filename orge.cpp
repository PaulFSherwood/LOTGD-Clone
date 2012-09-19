#include <iostream>
#include "includes.h"
#include "orge.h"
using namespace std;

npc_orge::npc_orge(){}

void npc_orge::SetOHpC(int hp) { OHpC = hp; }
void npc_orge::SetOStrC(int str) { OStrC = str; }
void npc_orge::SetOLvlC(int lvl) { OLvlC = lvl; }
void npc_orge::SetOAtkC(int atk) { OAtkC = atk; }
void npc_orge::SetODefC(int def) { ODefC = def; }
void npc_orge::SetOArmorValueC(int armorvalue) { OArmorValueC = armorvalue; }
void npc_orge::SetONameC(string name) { ONameC = name; }

int npc_orge::GetOHpC() { return OHpC; }
int npc_orge::GetOStrC() { return OStrC; }
int npc_orge::GetOLvlC() { return OLvlC; }
int npc_orge::GetOAtkC() { return OAtkC; }
int npc_orge::GetODefC() { return ODefC; }
int npc_orge::GetOArmorValueC() { return OArmorValueC; }
string npc_orge::GetONameC() { return ONameC; }

void npc_orge::PrintStats()
{
    cout << "HP: " <<  npc_orge::GetOHpC() << endl;
    cout << "Str: " <<  npc_orge::GetOStrC() << endl;
    cout << "Lvl: " <<  npc_orge::GetOLvlC() << endl;
    cout << "Atk: " <<  npc_orge::GetOAtkC() << endl;
    cout << "Def: " <<  npc_orge::GetODefC() << endl;
    cout << "Name: " <<  npc_orge::GetONameC() << endl;
}


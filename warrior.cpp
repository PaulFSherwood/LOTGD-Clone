#include <iostream>
#include "includes.h"
#include "warrior.h"
using namespace std;

mywarrior::mywarrior(){}

void mywarrior::SetWHpP(int hp) { WHpP = hp; }
void mywarrior::SetWStrP(int str) { WStrP = str; }
void mywarrior::SetWLvlP(int lvl) { WLvlP = lvl; }
void mywarrior::SetWXptotalP(int xptotal) { WXptotalP = xptotal; }
void mywarrior::SetWMaxxpP(int maxxp) { WMaxxpP = maxxp; }
void mywarrior::SetWGoldP(int gold) { WGoldP = gold; }
void mywarrior::SetWSavingsP(int savings) { WSavingsP = savings; }
void mywarrior::SetWWeaponP(int wep) { WWeaponP = wep; }
void mywarrior::SetWArmorTypeP(int armortype ) { WArmorTypeP = armortype; }
void mywarrior::SetWArmorValueP(int armorvalue ) { WArmorValueP = armorvalue; }
void mywarrior::SetWAtkP(int atk) { WAtkP = atk; }
void mywarrior::SetWDefP(int def) { WDefP = def; }
void mywarrior::SetWRaceP(string race) { WRaceP = race; }
void mywarrior::SetWNameP(string name) { WNameP = name; }

int mywarrior::GetWHpP() { return WHpP; }
int mywarrior::GetWStrP() { return WStrP; }
int mywarrior::GetWLvlP() { return WLvlP; }
int mywarrior::GetWXptotalP() { return WXptotalP; }
int mywarrior::GetWMaxxpP() { return WMaxxpP; }
int mywarrior::GetWGoldP() { return WGoldP; }
int mywarrior::GetWSavingsP() { return WSavingsP; }
int mywarrior::GetWWeaponP() { return WWeaponP; }
int mywarrior::GetWArmorTypeP() { return WArmorTypeP; }
int mywarrior::GetWArmorValueP() { return WArmorValueP; }
int mywarrior::GetWAtkP() { return WAtkP; }
int mywarrior::GetWDefP() { return WDefP; }
string mywarrior::GetWRaceP() { return WRaceP; }
string mywarrior::GetWNameP() { return WNameP; }

void mywarrior::PrintStats()
{
    cout << "HP: " <<  mywarrior::GetWHpP() << endl;
    cout << "Str: " <<  mywarrior::GetWStrP() << endl;
    cout << "Lvl: " <<  mywarrior::GetWLvlP() << endl;
    cout << "XpTotal: " <<  mywarrior::GetWXptotalP() << endl;
    cout << "MaxXp: " <<  mywarrior::GetWMaxxpP() << endl;
    cout << "Gold: " <<  mywarrior::GetWGoldP() << endl;
    cout << "Savings: " <<  mywarrior::GetWSavingsP() << endl;
    cout << "Wepon: " <<  mywarrior::GetWWeaponP() << endl;
    cout << "Armor Type: " <<  mywarrior::GetWArmorTypeP() << endl;
    cout << "Armor Value: " <<  mywarrior::GetWArmorValueP() << endl;
    cout << "Atk: " <<  mywarrior::GetWAtkP() << endl;
    cout << "Def: " <<  mywarrior::GetWDefP() << endl;
    cout << "Race: " <<  mywarrior::GetWRaceP() << endl;
    cout << "Name: " <<  mywarrior::GetWNameP() << endl;
}


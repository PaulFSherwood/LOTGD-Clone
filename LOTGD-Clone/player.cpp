#include <iostream>
#include "player.h"
using namespace std;

myplayer::myplayer(){}

void myplayer::SetPlayerHpP(int hp) { WHpP = hp; }
void myplayer::SetPlayerStrP(int str) { WStrP = str; }
void myplayer::SetPlayerLvlP(int lvl) { WLvlP = lvl; }
void myplayer::SetPlayerXptotalP(int xptotal) { WXptotalP = xptotal; }
void myplayer::SetPlayerMaxxpP(int maxxp) { WMaxxpP = maxxp; }
void myplayer::SetPlayerGoldP(int gold) { WGoldP = gold; }
void myplayer::SetPlayerSavingsP(int savings) { WSavingsP = savings; }
void myplayer::SetPlayerWeaponP(int wep) { WWeaponP = wep; }
void myplayer::SetPlayerArmorTypeP(int armortype ) { WArmorTypeP = armortype; }
void myplayer::SetPlayerArmorValueP(int armorvalue ) { WArmorValueP = armorvalue; }
void myplayer::SetPlayerAtkP(int atk) { WAtkP = atk; }
void myplayer::SetPlayerDefP(int def) { WDefP = def; }
void myplayer::SetPlayerRaceP(string race) { WRaceP = race; }
void myplayer::SetPlayerNameP(string name) { WNameP = name; }

int myplayer::GetPlayerHpP() { return WHpP; }
int myplayer::GetPlayerStrP() { return WStrP; }
int myplayer::GetPlayerLvlP() { return WLvlP; }
int myplayer::GetPlayerXptotalP() { return WXptotalP; }
int myplayer::GetPlayerMaxxpP() { return WMaxxpP; }
int myplayer::GetPlayerGoldP() { return WGoldP; }
int myplayer::GetPlayerSavingsP() { return WSavingsP; }
int myplayer::GetPlayerWeaponP() { return WWeaponP; }
int myplayer::GetPlayerArmorTypeP() { return WArmorTypeP; }
int myplayer::GetPlayerArmorValueP() { return WArmorValueP; }
int myplayer::GetPlayerAtkP() { return WAtkP; }
int myplayer::GetPlayerDefP() { return WDefP; }
string myplayer::GetPlayerRaceP() { return WRaceP; }
string myplayer::GetPlayerNameP() { return WNameP; }

void myplayer::PrintStats()
{
    cout << "HP: " <<  myplayer::GetPlayerHpP() << endl;
    cout << "Str: " <<  myplayer::GetPlayerStrP() << endl;
    cout << "Lvl: " <<  myplayer::GetPlayerLvlP() << endl;
    cout << "XpTotal: " <<  myplayer::GetPlayerXptotalP() << endl;
    cout << "MaxXp: " <<  myplayer::GetPlayerMaxxpP() << endl;
    cout << "Gold: " <<  myplayer::GetPlayerGoldP() << endl;
    cout << "Savings: " <<  myplayer::GetPlayerSavingsP() << endl;
    cout << "Wepon: " <<  myplayer::GetPlayerWeaponP() << endl;
    cout << "Armor Type: " <<  myplayer::GetPlayerArmorTypeP() << endl;
    cout << "Armor Value: " <<  myplayer::GetPlayerArmorValueP() << endl;
    cout << "Atk: " <<  myplayer::GetPlayerAtkP() << endl;
    cout << "Def: " <<  myplayer::GetPlayerDefP() << endl;
    cout << "Race: " <<  myplayer::GetPlayerRaceP() << endl;
    cout << "Name: " <<  myplayer::GetPlayerNameP() << endl;
}


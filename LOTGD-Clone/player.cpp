#include <iostream>
#include "player.h"
using namespace std;

myplayer::myplayer(){}

void myplayer::SetPlayerHpCap(int hpCap) { PlayerHpCap = hpCap; }
void myplayer::SetPlayerHpCurrent(int hpCurrent) { PlayerHpCurrent = hpCurrent; }
void myplayer::SetPlayerLvlP(int lvl) { PlayerLvl = lvl; }

void myplayer::SetPlayerXpCurrent(int xpCurrent) { PlayerXpCurrent = xpCurrent; }
void myplayer::SetPlayerXpRequired(int xpRequired) { PlayerXpRequired = xpRequired; }

void myplayer::SetPlayerGoldP(int gold) { PlayerGold = gold; }
void myplayer::SetPlayerSavingsP(int savings) { PlayerSavings = savings; }
void myplayer::SetPlayerWeaponP(int weapon) { PlayerWeapon = weapon; }
void myplayer::SetPlayerArmorP(int armor) { PlayerArmor = armor; }

void myplayer::SetPlayerAtkP(int atk) { PlayerAtk = atk; }
void myplayer::SetPlayerDefP(int def) { PlayerDef = def; }
void myplayer::SetPlayerRaceP(string race) { PlayerRace = race; }
void myplayer::SetPlayerNameP(string name) { PlayerName = name; }
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
int myplayer::GetPlayerHpCap() { return PlayerHpCap; }
int myplayer::GetPlayerHpCurrent() { return PlayerHpCurrent; }
int myplayer::GetPlayerLvlP() { return PlayerLvl; }

int myplayer::GetPlayerXpCurrent() { return PlayerXpCurrent; }
int myplayer::GetPlayerXpRequired() { return PlayerXpRequired; }

int myplayer::GetPlayerGoldP() { return PlayerGold; }
int myplayer::GetPlayerSavingsP() { return PlayerSavings; }
int myplayer::GetPlayerWeaponP() { return PlayerWeapon; }
int myplayer::GetPlayerArmorP() { return PlayerArmor; }

int myplayer::GetPlayerAtkP() { return PlayerAtk; }
int myplayer::GetPlayerDefP() { return PlayerDef; }
string myplayer::GetPlayerRaceP() { return PlayerRace; }
string myplayer::GetPlayerNameP() { return PlayerName; }

void myplayer::PrintStats()
{
    cout << "HP: " <<  myplayer::GetPlayerHpCurrent() << endl;
    cout << "Lvl: " <<  myplayer::GetPlayerLvlP() << endl;
    cout << "XpTotal: " <<  myplayer::GetPlayerXpRequired() << endl;
    cout << "MaxXp: " <<  myplayer::GetPlayerXpCurrent() << endl;
    cout << "Gold: " <<  myplayer::GetPlayerGoldP() << endl;
    cout << "Savings: " <<  myplayer::GetPlayerSavingsP() << endl;
    cout << "Wepon: " <<  myplayer::GetPlayerWeaponP() << endl;
    cout << "Atk: " <<  myplayer::GetPlayerAtkP() << endl;
    cout << "Def: " <<  myplayer::GetPlayerDefP() << endl;
    cout << "Race: " <<  myplayer::GetPlayerRaceP() << endl;
    cout << "Name: " <<  myplayer::GetPlayerNameP() << endl;
}


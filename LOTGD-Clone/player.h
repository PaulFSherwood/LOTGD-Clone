#ifndef WARRIOR_H_
#define WARRIOR_H_

#include <iostream>
using namespace std;

class myplayer
{
public:
    myplayer();

    void SetPlayerHpCap(int hpCap);
    void SetPlayerHpCurrent(int hpCurrent);
    void SetPlayerLvlP(int lvl);

    void SetPlayerXpCurrent(int xptotal);
    void SetPlayerXpRequired(int maxxp);
    void SetPlayerGoldP(int gold);
    void SetPlayerSavingsP(int savings);
    void SetPlayerWeaponP(int wep);
    void SetPlayerArmorP(int armor);

    void SetPlayerAtkP(int atk);
    void SetPlayerDefP(int def);
    void SetPlayerRaceP(string race);
    void SetPlayerNameP(string name);
    //////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////
    int GetPlayerHpCap();
    int GetPlayerHpCurrent();
    int GetPlayerLvlP();

    int GetPlayerXpCurrent();
    int GetPlayerXpRequired();
    int GetPlayerGoldP();
    int GetPlayerSavingsP();
    int GetPlayerWeaponP();
    int GetPlayerArmorP();
    int GetPlayerAtkP();
    int GetPlayerDefP();
    string GetPlayerRaceP();
    string GetPlayerNameP();

    void PrintStats();

private:
    int PlayerHpCap;
    int PlayerHpCurrent;
    int PlayerLvl;

    int PlayerXpCurrent;
    int PlayerXpRequired;

    int PlayerGold;
    int PlayerSavings;

    int PlayerWeapon;
    int PlayerArmor;

    int PlayerAtk;
    int PlayerDef;

    string PlayerRace;
    string PlayerName;
};

#endif // WARRIOR_H

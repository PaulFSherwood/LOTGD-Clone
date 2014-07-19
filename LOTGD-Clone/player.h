#ifndef WARRIOR_H_
#define WARRIOR_H_

#include <iostream>
using namespace std;

class myplayer
{
public:
    myplayer();

    void SetPlayerHpP(int hp);
    void SetPlayerStrP(int str);
    void SetPlayerLvlP(int lvl);
    void SetPlayerXptotalP(int xptotal);
    void SetPlayerMaxxpP(int maxxp);
    void SetPlayerGoldP(int gold);
    void SetPlayerSavingsP(int savings);
    void SetPlayerWeaponP(int wep);
    void SetPlayerArmorTypeP(int armor);
    void SetPlayerArmorValueP(int armor);
    void SetPlayerAtkP(int atk);
    void SetPlayerDefP(int def);
    void SetPlayerRaceP(string race);
    void SetPlayerNameP(string name);

    int GetPlayerHpP();
    int GetPlayerStrP();
    int GetPlayerLvlP();
    int GetPlayerXptotalP();
    int GetPlayerMaxxpP();
    int GetPlayerGoldP();
    int GetPlayerSavingsP();
    int GetPlayerWeaponP();
    int GetPlayerArmorTypeP();
    int GetPlayerArmorValueP();
    int GetPlayerAtkP();
    int GetPlayerDefP();
    string GetPlayerRaceP();
    string GetPlayerNameP();

    void PrintStats();

private:
    int WHpP;
    int WStrP;
    int WLvlP;
    int WXptotalP;
    int WMaxxpP;
    int WGoldP;
    int WSavingsP;
    int WWeaponP;
    int WArmorTypeP;
    int WArmorValueP;
    int WAtkP;
    int WDefP;
    string WRaceP;
    string WNameP;
};

#endif // WARRIOR_H

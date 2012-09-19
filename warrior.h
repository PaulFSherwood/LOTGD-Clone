#ifndef WARRIOR_H_
#define WARRIOR_H_

#include <iostream>
#include "includes.h"
using namespace std;

class mywarrior
{
public:
    mywarrior();

    void SetWHpP(int hp);
    void SetWStrP(int str);
    void SetWLvlP(int lvl);
    void SetWXptotalP(int xptotal);
    void SetWMaxxpP(int maxxp);
    void SetWGoldP(int gold);
    void SetWSavingsP(int savings);
    void SetWWeaponP(int wep);
    void SetWArmorTypeP(int armor);
    void SetWArmorValueP(int armor);
    void SetWAtkP(int atk);
    void SetWDefP(int def);
    void SetWRaceP(string race);
    void SetWNameP(string name);

    int GetWHpP();
    int GetWStrP();
    int GetWLvlP();
    int GetWXptotalP();
    int GetWMaxxpP();
    int GetWGoldP();
    int GetWSavingsP();
    int GetWWeaponP();
    int GetWArmorTypeP();
    int GetWArmorValueP();
    int GetWAtkP();
    int GetWDefP();
    string GetWRaceP();
    string GetWNameP();

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

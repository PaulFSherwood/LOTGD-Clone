#ifndef ORGE_H
#define ORGE_H

#include <iostream>
using namespace std;

class npc_orge
{
public:
    npc_orge();

    void SetOHpC(int hp);
    void SetOStrC(int str);
    void SetOLvlC(int lvl);
    void SetOAtkC(int atk);
    void SetODefC(int def);
    void SetOArmorValueC(int armorvalue);
    void SetONameC(string name);

    int GetOHpC();
    int GetOStrC();
    int GetOLvlC();
    int GetOAtkC();
    int GetODefC();
    int GetOArmorValueC();
    string GetONameC();

    void PrintStats();

private:
    int OHpC;
    int OStrC;
    int OLvlC;

    int OAtkC;
    int ODefC;
    int OArmorValueC;

    string ONameC;
};

#endif // ORGE_H

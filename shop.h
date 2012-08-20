#ifndef WEAPON_SHOP_H
#define WEAPON_SHOP_H

#include <iostream>
#include <stdio.h>
#include "includes.h"
using namespace std;

extern struct player warrior;
extern struct npc orge;

class shop
{
public:
    shop();

    void Weapon_Shop(int &WstrP, int &currentWeapon, int &WGold);

    void Armor_Shop(int &WDef, int &currentArmor, int &WGold);

    void WeaponPriceCheck(int &WAtk, int &currentWeapon, int &WGold, int ItemPrice);

    void ArmorPriceCheck(int &WDef, int &currentArmor, int &WGold, int ItemPrice);

    string GetWeapon(int &currentWeapon);

    string GetArmor(int &currentArmor);

private:
    string systemMessage;
};

#endif // WEAPON_SHOP_H

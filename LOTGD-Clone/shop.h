#ifndef WEAPON_SHOP_H
#define WEAPON_SHOP_H

#include <iostream>
#include <stdio.h>
using namespace std;

class shop
{
public:
    shop();

    void Weapon_Shop(myplayer * myPlayer);

    void Armor_Shop(myplayer * myPlayer);

    void WeaponPriceCheck(myplayer * myPlayer, int ItemPrice);

    void ArmorPriceCheck(myplayer * myPlayer, int ItemPrice);

    string GetWeapon(int currentWeapon);

    string GetArmor(int currentArmor);

private:
    string systemMessage;
};

#endif // WEAPON_SHOP_H

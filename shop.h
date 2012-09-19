#ifndef WEAPON_SHOP_H
#define WEAPON_SHOP_H

#include <iostream>
#include <stdio.h>
using namespace std;

class shop
{
public:
    shop();

    void Weapon_Shop(mywarrior * mySoilder);

    void Armor_Shop(mywarrior * mySoilder);

    void WeaponPriceCheck(mywarrior * mySoilder, int ItemPrice);

    void ArmorPriceCheck(mywarrior * mySoilder, int ItemPrice);

    string GetWeapon(int currentWeapon);

    string GetArmor(int currentArmor);

private:
    string systemMessage;
};

#endif // WEAPON_SHOP_H

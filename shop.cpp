#include <iostream>
#include <stdio.h>
#include "display.h"
#include "shop.h"

// Define Prices
// with static const for syntax checking #define would not give
static const int Wooden_Stick = 300;
static const int Dull_Knife = 500;
static const int Long_Sword = 1000;
static const int Lazer_Pistol = 5000;
static const int Paper_Bag = 300;
static const int Worn_Jacket = 500;
static const int Chain_Mail = 1000;
static const int Force_Shield = 5000;
using namespace std;

// Initilize pointer class calls
display *getDisplay = new display();

shop::shop()
:systemMessage("\0")
{}

void shop::Weapon_Shop(int &WAtk, int &currentWeapon, int &WGold)
{
    // inside the shop
    bool inTheShop = true;

    while (inTheShop)
    {
        // display the shop
        getDisplay->Weapon_Shop(systemMessage);

        // select the weapon you want
        char e;
        cin >> e;
        switch(e)
        {
            case 'W': // Wooden Stick
            {
                WeaponPriceCheck(WAtk, currentWeapon, WGold, Wooden_Stick);
                break;
            }
            case 'D': // Dull Knife
            {
                WeaponPriceCheck(WAtk, currentWeapon, WGold, Dull_Knife);
                break;
            }
            case 'S': // Long Sword
            {
                WeaponPriceCheck(WAtk, currentWeapon, WGold, Long_Sword);
                break;
            }
            case 'L': // Lazer Pistol
            {
                WeaponPriceCheck(WAtk, currentWeapon, WGold, Lazer_Pistol);
                break;
            }
            default:
            {
                systemMessage = "\0";
                inTheShop = false;
                break;
            }
        }
    }
}

void shop::Armor_Shop(int &WDef, int &currentArmor, int &WGold)
{
    // inside the shop
    bool inTheShop = true;

    while (inTheShop)
    {
        // display the shop
        getDisplay->Armor_Shop(systemMessage);

        // select the armor you want
        char e;
        cin >> e;
        switch(e)
        {
            case 'P': // Paper Bag
            {
                ArmorPriceCheck(WDef, currentArmor, WGold, Paper_Bag);
                break;
            }
            case 'W': // Long Sword
            {
                ArmorPriceCheck(WDef, currentArmor, WGold, Worn_Jacket);
                break;
            }
            case 'C': // Chain Mail
            {
                ArmorPriceCheck(WDef, currentArmor, WGold, Chain_Mail);
                break;
            }
            case 'F': // Force Shield
            {
                ArmorPriceCheck(WDef, currentArmor, WGold, Force_Shield);
                break;
            }
            default:
            {
                systemMessage = "\0";
                inTheShop = false;
                break;
            }
        }
    }
}
// check to see if it can be purchased
void shop::WeaponPriceCheck(int &WAtk, int &currentWeapon, int &WGold, int ItemPrice)
{
    // check which item you want then see if you have enough money
    switch (ItemPrice)
    {
        case 300:
        {
            if (WGold >= ItemPrice)
            {
                WGold = WGold - ItemPrice;
                currentWeapon = 1;
                WAtk = 100;
                systemMessage = "You are now the proud owner of a Wooden Stick";

            } else {
                cout << "You dont have enough funds";
                cout << "WGold: " << WGold << " ItemPrice: " << ItemPrice << endl;
                break;
            }
            break;
        }
        case 500:
        {
            if (WGold >= ItemPrice)
            {
                WGold = WGold - ItemPrice;
                currentWeapon = 2;
                WAtk = 200;
                systemMessage = "You are now the proud owner of a Dull Knife";

            } else {
                cout << "You dont have enough funds";
                break;
            }
            break;
        }
        case 1000:
        {
            if (WGold >= ItemPrice)
            {
                WGold = WGold - ItemPrice;
                currentWeapon = 3;
                WAtk = 500;
                systemMessage = "You are now the proud owner of a Long Sword";

            } else {
                cout << "You dont have enough funds";
                break;
            }
            break;
        }
        case 5000:
        {
            if (WGold >= ItemPrice)
            {
                WGold = WGold - ItemPrice;
                currentWeapon = 4;
                WAtk = 1000;
                systemMessage = "You are now the proud owner of a Lazer Pistol";

            } else {
                cout << "You dont have enough funds";
                break;
            }
            break;
        }
        default:
        {
            break;
        }
    }
}

void shop::ArmorPriceCheck(int &WDef, int &currentArmor, int &WGold, int ItemPrice)
{
    switch (ItemPrice)
    {
        case 300:
        {
            if (WGold >= ItemPrice)
            {
                WGold = WGold - ItemPrice;
                currentArmor = 1;
                WDef = 100;
                systemMessage = "You are now the proud owner of a Paper Bag";

            } else {
                cout << "You dont have enough funds";
                break;
            }
            break;
        }
        case 500:
        {
            if (WGold >= ItemPrice)
            {
                WGold = WGold - ItemPrice;
                currentArmor = 2;
                WDef = 200;
                systemMessage = "You are now the proud owner of a Worn Jacket";

            } else {
                cout << "You dont have enough funds";
                break;
            }
            break;
        }
        case 1000:
        {
            if (WGold >= ItemPrice)
            {
                WGold = WGold - ItemPrice;
                currentArmor = 3;
                WDef = 500;
                systemMessage = "You are now the proud owner of a Chain Mail";

            } else {
                cout << "You dont have enough funds";
                break;
            }
            break;
        }
        case 5000:
        {
            if (WGold >= ItemPrice)
            {
                WGold = WGold - ItemPrice;
                currentArmor = 4;
                WDef = 1000;
                systemMessage = "You are now the proud owner of a Force Shield";

            } else {
                cout << "You dont have enough funds";
                break;
            }
            break;
        }
        default:
        {
            break;
        }
    }
}

// To display what weapon you have
string shop::GetWeapon(int &currentWeapon)
{
    switch(currentWeapon)
    {
        case 0:
        {
            return "none";
            break;
        }
        case 1:
        {
            return "Wooden Stick";
            break;
        }
        case 2:
        {
            return "Dull Knife";
            break;
        }
        case 3:
        {
            return "Long Sword";
            break;
        }
        case 4:
        {
            return "Lazer Pistol";
            break;
        }
        default:
        {
            return "\0";
            break;
        }
    }
}
string shop::GetArmor(int &currentArmor)
{
    switch(currentArmor)
    {
        case 0:
        {
            return "none";
            break;
        }
        case 1:
        {
            return "Paper Bag";
            break;
        }
        case 2:
        {
            return "Worn Jacket";
            break;
        }
        case 3:
        {
            return "Chain Mail";
            break;
        }
        case 4:
        {
            return "Force Shield";
            break;
        }
        default:
        {
            return "\0";
            break;
        }
    }
}

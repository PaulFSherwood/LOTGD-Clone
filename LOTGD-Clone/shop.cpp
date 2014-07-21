#include <iostream>
#include <stdio.h>
#include "display.h"
#include "shop.h"
#include "player.h"

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

void shop::Weapon_Shop(myplayer * myPlayer)
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
                WeaponPriceCheck(myPlayer, Wooden_Stick);
                break;
            }
            case 'D': // Dull Knife
            {
                WeaponPriceCheck(myPlayer, Dull_Knife);
                break;
            }
            case 'S': // Long Sword
            {
                WeaponPriceCheck(myPlayer, Long_Sword);
                break;
            }
            case 'L': // Lazer Pistol
            {
                WeaponPriceCheck(myPlayer, Lazer_Pistol);
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

void shop::Armor_Shop(myplayer * myPlayer)
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
                ArmorPriceCheck(myPlayer, Paper_Bag);
                break;
            }
            case 'W': // Long Sword
            {
                ArmorPriceCheck(myPlayer, Worn_Jacket);
                break;
            }
            case 'C': // Chain Mail
            {
                ArmorPriceCheck(myPlayer, Chain_Mail);
                break;
            }
            case 'F': // Force Shield
            {
                ArmorPriceCheck(myPlayer, Force_Shield);
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
void shop::WeaponPriceCheck(myplayer * myPlayer, int ItemPrice)
{
    int tempWGoldP = 0;

    // check which item you want then see if you have enough money
    switch (ItemPrice)
    {
        case 300:
        {
            if (myPlayer->GetPlayerGoldP() >= ItemPrice)
            {
                tempWGoldP = myPlayer->GetPlayerGoldP() - ItemPrice;
                myPlayer->SetPlayerGoldP(tempWGoldP);
                myPlayer->SetPlayerWeaponP(1);
                myPlayer->SetPlayerAtkP(100);
                systemMessage = "You are now the proud owner of a Wooden Stick";

            } else {
                cout << "You dont have enough funds";
                cout << "WGold: " << myPlayer->GetPlayerGoldP() << " ItemPrice: " << ItemPrice << endl;
                break;
            }
            break;
        }
        case 500:
        {
            if (myPlayer->GetPlayerGoldP() >= ItemPrice)
            {
                tempWGoldP = myPlayer->GetPlayerGoldP() - ItemPrice;
                myPlayer->SetPlayerGoldP(tempWGoldP);
                myPlayer->SetPlayerWeaponP(2);
                myPlayer->SetPlayerAtkP(200);
                systemMessage = "You are now the proud owner of a Dull Knife";

            } else {
                cout << "You dont have enough funds";
                break;
            }
            break;
        }
        case 1000:
        {
            if (myPlayer->GetPlayerGoldP() >= ItemPrice)
            {
                tempWGoldP = myPlayer->GetPlayerGoldP() - ItemPrice;
                myPlayer->SetPlayerGoldP(tempWGoldP);
                myPlayer->SetPlayerWeaponP(3);
                myPlayer->SetPlayerAtkP(500);
                systemMessage = "You are now the proud owner of a Long Sword";

            } else {
                cout << "You dont have enough funds";
                break;
            }
            break;
        }
        case 5000:
        {
            if (myPlayer->GetPlayerGoldP() >= ItemPrice)
            {
                tempWGoldP = myPlayer->GetPlayerGoldP() - ItemPrice;
                myPlayer->SetPlayerGoldP(tempWGoldP);
                myPlayer->SetPlayerWeaponP(4);
                myPlayer->SetPlayerAtkP(1000);
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

void shop::ArmorPriceCheck(myplayer * myPlayer, int ItemPrice)
{
    int tempWGoldP = 0;

    switch (ItemPrice)
    {
        case 300:
        {
            if (myPlayer->GetPlayerGoldP() >= ItemPrice)
            {
                tempWGoldP = myPlayer->GetPlayerGoldP() - ItemPrice;
                myPlayer->SetPlayerGoldP(tempWGoldP);
                myPlayer->SetPlayerDefP(100);
                systemMessage = "You are now the proud owner of a Paper Bag";

            } else {
                cout << "You dont have enough funds";
                break;
            }
            break;
        }
        case 500:
        {
            if (myPlayer->GetPlayerGoldP() >= ItemPrice)
            {
                tempWGoldP = myPlayer->GetPlayerGoldP() - ItemPrice;
                myPlayer->SetPlayerGoldP(tempWGoldP);
                myPlayer->SetPlayerDefP(200);
                systemMessage = "You are now the proud owner of a Worn Jacket";

            } else {
                cout << "You dont have enough funds";
                break;
            }
            break;
        }
        case 1000:
        {
            if (myPlayer->GetPlayerGoldP() >= ItemPrice)
            {
                tempWGoldP = myPlayer->GetPlayerGoldP() - ItemPrice;
                myPlayer->SetPlayerGoldP(tempWGoldP);
                myPlayer->SetPlayerDefP(500);
                systemMessage = "You are now the proud owner of a Chain Mail";

            } else {
                cout << "You dont have enough funds";
                break;
            }
            break;
        }
        case 5000:
        {
            if (myPlayer->GetPlayerGoldP() >= ItemPrice)
            {
                tempWGoldP = myPlayer->GetPlayerGoldP() - ItemPrice;
                myPlayer->SetPlayerGoldP(tempWGoldP);
                myPlayer->SetPlayerDefP(1000);
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
string shop::GetWeapon(int currentWeapon)
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
string shop::GetArmor(int currentArmor)
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

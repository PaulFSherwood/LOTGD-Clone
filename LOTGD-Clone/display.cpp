//============================================================================
// PFS:4/16/2023: Refactoring, removing SDL where possible to return to a console program
//============================================================================

#include <iostream>
#include <sstream>
#include <cstdlib>
#include "display.h"
#include "creature.h"
#include "player.h"
#include "textData.h"
#include "shop.h"
#include "uiGroup.h"
using namespace std;

display::display(){}

// Initialize pointer class calls
shop *Weapon = new shop();

// display functions
void display::vitalInfo(myplayer *myPlayer_Object, uiGroup *uiDataValues)
{
    // Vital Info Bar
    cout << "##Vital Info##" << endl;
    cout << "Name: " << myPlayer_Object->GetPlayerNameP() << endl;
    cout << "Level: " << myPlayer_Object->GetPlayerLvlP() << endl;
    cout << "Hitpoints: " << myPlayer_Object->GetPlayerHpCurrent() << endl;
    cout << "Turns: " << endl;
    cout << "Attack: " << myPlayer_Object->GetPlayerAtkP() << endl;
    cout << "Defense: " << myPlayer_Object->GetPlayerDefP() << endl;
    cout << "Race: " << myPlayer_Object->GetPlayerRaceP() << endl;
    cout << "Gold: " << myPlayer_Object->GetPlayerGoldP() << endl;
    cout << "Experience: " << myPlayer_Object->GetPlayerXpRequired() << "|" << myPlayer_Object->GetPlayerXpCurrent() << endl;
    cout << "Weapon: " << Weapon->GetWeapon(myPlayer_Object->GetPlayerWeaponP()) << endl;
}

void display::mainDisplay(myplayer * myPlayer_Object, uiGroup * uiDataValues)
{
    cout << "## In Town ##" << endl;
    vitalInfo(myPlayer_Object, uiDataValues);
}

void display::fightDisplay(myplayer * myPlayer_Object, uiGroup * uiDataValues , mycreature * creature_Object, myTextData * TextData_Object)
{
    cout << "## Fight Display ##" << endl;
    vitalInfo(myPlayer_Object, uiDataValues);
}

void display::forrestDisplay(myplayer * myPlayer_Object, uiGroup * uiDataValues)
{
    cout << "## Forrest ##" << endl;
    vitalInfo(myPlayer_Object, uiDataValues);
}

void display::old_Bank(myplayer * myPlayer_Object)
{
#ifdef WIN32
    system("cls");
#endif
#ifdef linux
    printf("\033[2J\033[1;1H");
#endif
    cout << "##GrrBank##" << "\t\t\t" << "##Vital Info##" << endl;
    cout << "You can deposit your money" << "\t" << "Name: " << myPlayer_Object->GetPlayerNameP() << endl;
    cout << "here for save keeping." << "\t\t" << "Level: " << myPlayer_Object->GetPlayerLvlP() << endl;
    cout << "\t\t\t\t" << "Hitpoints: " << myPlayer_Object->GetPlayerHpCurrent() << endl;
    cout << "Account Balance: " << myPlayer_Object->GetPlayerSavingsP() << "\t\t" << "Turns: " << endl;
    cout << "\t\t\t\t" << "Attack: " << myPlayer_Object->GetPlayerAtkP() << endl;
    cout << "\t\t\t\t" << "Defense: " << myPlayer_Object->GetPlayerDefP() << endl;
    cout << "\t\t\t\t" << "Race: " << myPlayer_Object->GetPlayerRaceP() << endl;
    cout << "\t\t\t\t" << "##Personal Info##" << endl;
    cout << "\t\t\t\t" << "Gold: " << myPlayer_Object->GetPlayerGoldP() << endl;
    cout << "\t\t\t\t" << "Gem: " << endl;
    cout << "\t\t\t\t" << "##Equipment##" << endl;
    cout << "(D)eposit" << "\t\t\t" << "Weapon: " << Weapon->GetWeapon(myPlayer_Object->GetPlayerWeaponP()) << endl;
    cout << "\t\t\t\t\t" << "Experience: " << myPlayer_Object->GetPlayerXpRequired() << "|" << myPlayer_Object->GetPlayerXpCurrent() << endl;
}
void display::Weapon_Shop(string &systemMessage)
{
#ifdef WIN32
    system("cls");
#endif
#ifdef linux
    printf("\033[2J\033[1;1H");
#endif
    cout << "##Welcome to the Weapon Shop##" << endl;
    cout << "Please have a look at our Weapons you can purchase" << endl;
    cout << "(W)ooden Stick" << endl;
    cout << "(D)ull Knife" << endl;
    cout << "Long (S)word" << endl;
    cout << "(L)azer Pistol" << endl;
    cout << "(E)xit the shop" << endl;
    cout << systemMessage << endl << endl;
}
void display::Armor_Shop(string &systemMessage)
{
#ifdef WIN32
    system("cls");
#endif
#ifdef linux
    printf("\033[2J\033[1;1H");
#endif
    cout << "##Welcome to the Weapon and Armor Shop##" << endl;
    cout << "Please have a look at our Armor you can purchase" << endl;
    cout << "(P)aper Bag" << endl;
    cout << "(W)orn Jacket" << endl;
    cout << "(C)hain Mail" << endl;
    cout << "(F)orce Shield" << endl;
    cout << "(E)xit the shop" << endl;
    cout << systemMessage << endl << endl;
}




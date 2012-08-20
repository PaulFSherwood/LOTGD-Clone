#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include "display.h"
#include "shop.h"
using namespace std;

extern player warrior;
extern npc orge;

display::display(){}

// Initilize pointer class calls
shop *Weapon = new shop();

// display functions
void display::mainDisplay(player &warrior)
{
    #ifdef WIN32
        system("cls");
    #endif
    #ifdef linux
        printf("\033[2J\033[1;1H");
    #endif
    cout << "##Village Gate##" << "\t\t" << "##Vital Info##" << endl;
    cout << "(F)orest" << "\t\t\t" << "Name: " << warrior.WNameP << endl;
    cout << "(Q)uit to the fields" << "\t\t" << "Level: " << warrior.WLvlP << endl;
    cout << "(W)arrior training" << "\t\t" << "Hitpoints: " << warrior.WHpP << endl;
    cout << "##Market Street##" << "\t\t" << "Turns: " << endl;
    cout << "(M)ightE's Weaponry" << "\t\t" << "Strenght: " << warrior.WStrP << endl;
    cout << "Pegasus (A)rmor" << "\t\t\t" << "Attack: " << warrior.WAtkP << endl;
    cout << "Ye Old (B)ank" << "\t\t\t" << "Defense: " << warrior.WDefP << endl;
    cout << "(H)eal your self\t\t" << "Race: " << warrior.WRaceP << endl;
    cout << "\t\t\t\t" << "##Personnel Info##" << endl;
    cout << "\t\t\t\t" << "Gold: " << warrior.WGoldP << endl;
    cout << "\t\t\t\t" << "Gem: " << endl;
    cout << "\t\t\t\t" << "##Equipment##" << endl;
    cout << "\t\t\t\t" << "Weapon: " << Weapon->GetWeapon(warrior.WWeaponP) << endl;
    cout << "\t\t\t\t" << "Armour: " << Weapon->GetArmor(warrior.WArmorP) << endl;
    cout << "\t\t\t\t" << "Experience: " << warrior.WXptotalP << "|" << warrior.WMaxxpP << endl;
}

void display::forrestDisplay(player &warrior)
{
    #ifdef WIN32
        system("cls");
    #endif
    #ifdef linux
        printf("\033[2J\033[1;1H");
    #endif
    cout << "##Forest##" << "\t\t\t" << "##Vital Info##" << endl;
    cout << "(C)hange Orges level" << "\t\t" << "Name: " << warrior.WNameP << endl;
    cout << "(L)ook for a fight" << "\t\t" << "Level: " << warrior.WLvlP << endl;
    cout << "(R)eturn to village" << "\t\t" << "Hitpoints: " << warrior.WHpP << endl;
    cout << "\t\t\t\t" << "Turns: " << endl;
    cout << "\t\t\t\t" << "Strength: " << warrior.WStrP << endl;
    cout << "\t\t\t\t" << "Attack: " << warrior.WAtkP << endl;
    cout << "\t\t\t\t" << "Defense: " << warrior.WDefP << endl;
    cout << "\t\t\t\t" << "Race: " << endl;
    cout << "\t\t\t\t" << "##Personnel Info##" << endl;
    cout << "\t\t\t\t" << "Gold: " << warrior.WGoldP << endl;
    cout << "\t\t\t\t" << "Gem: " << endl;
    cout << "\t\t\t\t" << "##Equipment##" << endl;
    cout << "\t\t\t\t" << "Weapon: " << Weapon->GetWeapon(warrior.WWeaponP) << endl;
    cout << "\t\t\t\t" << "Armour: " << Weapon->GetArmor(warrior.WArmorP) << endl;
    cout << "\t\t\t\t" << "Experience: " << warrior.WXptotalP << "|" << warrior.WMaxxpP << endl;
}

void display::fightDisplay(player &warrior, npc &orge)
{
    #ifdef WIN32
        system("cls");
    #endif
    #ifdef linux
        printf("\033[2J\033[1;1H");
    #endif
    cout << "##Fighting##" << "\t\t\t" << "##Vital Info##" << endl;
    cout << "Orger Info" << "\t\t\t" << "Name: " << warrior.WNameP << endl;
    if (orge.OHpC >= -1) { cout << "Hp: " << orge.OHpC << "\t\t\t\t" << "Level: " << warrior.WLvlP << endl; }
    else { cout << "Hp: " << orge.OHpC << "\t\t\t" << "Level: " << warrior.WLvlP << endl; }
    cout << "Str: " << orge.OStrC << "\t\t\t" << "Hitpoints: " << warrior.WHpP << endl;
    cout << "Lvl: " << orge.OLvlC << "\t\t\t\t" << "Turns: " << endl;
    cout << "\t\t\t\t" << "Strength: " << warrior.WStrP << endl;
    cout << "\t\t\t\t" << "Attack: " << warrior.WAtkP << endl;
    cout << "\t\t\t\t" << "Defense: " << warrior.WDefP << endl;
    cout << "\t\t\t\t" << "Race: " << endl;
    cout << "\t\t\t\t" << "##Personnel Info##" << endl;
    cout << "\t\t\t\t" << "Gold: " << warrior.WGoldP << endl;
    cout << "\t\t\t\t" << "Gem: " << endl;
    cout << "\t\t\t\t" << "##Equipment##" << endl;
    cout << "\t\t\t\t" << "Weapon: " << Weapon->GetWeapon(warrior.WWeaponP) << endl;
    cout << "\t\t\t\t" << "Armour: " << Weapon->GetArmor(warrior.WArmorP) << endl;
    cout << "\t\t\t\t" << "Experience: " << warrior.WXptotalP << "|" << warrior.WMaxxpP << endl;
}
void display::old_Bank(player &warrior)
{
    #ifdef WIN32
        system("cls");
    #endif
    #ifdef linux
        printf("\033[2J\033[1;1H");
    #endif
    cout << "##GrrBank##" << "\t\t\t" << "##Vital Info##" << endl;
    cout << "You can deposit your money" << "\t" << "Name: " << warrior.WNameP << endl;
    cout << "here for save keeping." << "\t\t" << "Level: " << warrior.WLvlP << endl;
    cout << "\t\t\t\t" << "Hitpoints: " << warrior.WHpP << endl;
    cout << "Account Balance: " << warrior.WSavingsP << "\t\t" << "Turns: " << endl;
    cout << "\t\t\t\t" << "Strength: " << warrior.WStrP << endl;
    cout << "\t\t\t\t" << "Attack: " << warrior.WAtkP << endl;
    cout << "\t\t\t\t" << "Defense: " << warrior.WDefP << endl;
    cout << "\t\t\t\t" << "Race: " << endl;
    cout << "\t\t\t\t" << "##Personnel Info##" << endl;
    cout << "\t\t\t\t" << "Gold: " << warrior.WGoldP << endl;
    cout << "\t\t\t\t" << "Gem: " << endl;
    cout << "\t\t\t\t" << "##Equipment##" << endl;
    cout << "(D)eposit" << "\t\t\t" << "Weapon: " << Weapon->GetWeapon(warrior.WWeaponP) << endl;
    cout << "(W)idthdraw" << "\t\t\t" << "Armour: " << Weapon->GetArmor(warrior.WArmorP) << endl;
    cout << "(E)xit Bank" << "\t\t\t" << "Experience: " << warrior.WXptotalP << "|" << warrior.WMaxxpP << endl;
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
    cout << "##Welcome to the Weapon and Armror Shop##" << endl;
    cout << "Please have a look at our  Armor you can purchase" << endl;
    cout << "(P)aper Bag" << endl;
    cout << "(W)orn Jacket" << endl;
    cout << "(C)hain Mail" << endl;
    cout << "(F)orce Shield" << endl;
    cout << "(E)xit the shop" << endl;
    cout << systemMessage << endl << endl;
}

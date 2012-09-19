#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include "display.h"
#include "orge.h"
#include "shop.h"
#include "warrior.h"
using namespace std;

display::display(){}

// Initilize pointer class calls
shop *Weapon = new shop();

// display functions
void display::mainDisplay(mywarrior * warrior_Object)
{
    #ifdef WIN32
        system("cls");
    #endif
    #ifdef linux
        printf("\033[2J\033[1;1H");
    #endif
    cout << "##Village Gate##" << "\t\t" << "##Vital Info##" << endl;
    cout << "(F)orest" << "\t\t\t" << "Name: " << warrior_Object->GetWNameP() << endl;
    cout << "(Q)uit to the fields" << "\t\t" << "Level: " << warrior_Object->GetWLvlP() << endl;
    cout << "(W)arrior training" << "\t\t" << "Hitpoints: " << warrior_Object->GetWHpP() << endl;
    cout << "##Market Street##" << "\t\t" << "Turns: " << endl;
    cout << "(M)ightE's Weaponry" << "\t\t" << "Strenght: " << warrior_Object->GetWStrP() << endl;
    cout << "Pegasus (A)rmor" << "\t\t\t" << "Attack: " << warrior_Object->GetWAtkP() << endl;
    cout << "Ye Old (B)ank" << "\t\t\t" << "Defense: " << warrior_Object->GetWDefP() << endl;
    cout << "(H)eal your self\t\t" << "Race: " << warrior_Object->GetWRaceP() << endl;
    cout << "\t\t\t\t" << "##Personnel Info##" << endl;
    cout << "\t\t\t\t" << "Gold: " << warrior_Object->GetWGoldP() << endl;
    cout << "\t\t\t\t" << "Gem: " << endl;
    cout << "\t\t\t\t" << "##Equipment##" << endl;
    cout << "\t\t\t\t" << "Weapon: " << Weapon->GetWeapon(warrior_Object->GetWWeaponP()) << endl;
    cout << "\t\t\t\t" << "Armour Type: " << Weapon->GetArmor(warrior_Object->GetWArmorTypeP()) << endl;
    cout << "\t\t\t\t" << "Armour Value: " << warrior_Object->GetWArmorValueP() << endl;
    cout << "\t\t\t\t" << "Experience: " << warrior_Object->GetWXptotalP() << "|" << warrior_Object->GetWMaxxpP() << endl;
}

void display::forrestDisplay(mywarrior * warrior_Object)
{
    #ifdef WIN32
        system("cls");
    #endif
    #ifdef linux
        printf("\033[2J\033[1;1H");
    #endif
    cout << "##Forest##" << "\t\t\t" << "##Vital Info##" << endl;
    cout << "(C)hange Orges level" << "\t\t" << "Name: " << warrior_Object->GetWNameP() << endl;
    cout << "(L)ook for a fight" << "\t\t" << "Level: " << warrior_Object->GetWLvlP() << endl;
    cout << "(R)eturn to village" << "\t\t" << "Hitpoints: " << warrior_Object->GetWHpP() << endl;
    cout << "\t\t\t\t" << "Turns: " << endl;
    cout << "\t\t\t\t" << "Strength: " << warrior_Object->GetWStrP() << endl;
    cout << "\t\t\t\t" << "Attack: " << warrior_Object->GetWAtkP() << endl;
    cout << "\t\t\t\t" << "Defense: " << warrior_Object->GetWDefP() << endl;
    cout << "\t\t\t\t" << "Race: " << warrior_Object->GetWRaceP() << endl;
    cout << "\t\t\t\t" << "##Personnel Info##" << endl;
    cout << "\t\t\t\t" << "Gold: " << warrior_Object->GetWGoldP() << endl;
    cout << "\t\t\t\t" << "Gem: " << endl;
    cout << "\t\t\t\t" << "##Equipment##" << endl;
    cout << "\t\t\t\t" << "Weapon: " << Weapon->GetWeapon(warrior_Object->GetWWeaponP()) << endl;
    cout << "\t\t\t\t" << "Armour Type: " << Weapon->GetArmor(warrior_Object->GetWArmorTypeP()) << endl;
    cout << "\t\t\t\t" << "Armour Value: " << warrior_Object->GetWArmorValueP() << endl;
    cout << "\t\t\t\t" << "Experience: " << warrior_Object->GetWXptotalP() << "|" << warrior_Object->GetWMaxxpP() << endl;
}

void display::fightDisplay(mywarrior * warrior_Object, npc_orge * npc_Object)
{
    #ifdef WIN32
        system("cls");
    #endif
    #ifdef linux
        printf("\033[2J\033[1;1H");
    #endif
    cout << "##Fighting##" << "\t\t\t" << "##Vital Info##" << endl;
    cout << "Orger Info" << "\t\t\t" << "Name: " << warrior_Object->GetWNameP() << endl;
    if (npc_Object->GetOHpC() >= -1) { cout << "Hp: " << npc_Object->GetOHpC() << "\t\t\t\t" << "Level: " << warrior_Object->GetWLvlP() << endl; }
    else { cout << "Hp: " << npc_Object->GetOHpC() << "\t\t\t\t" << "Level: " << warrior_Object->GetWLvlP() << endl; }
    cout << "Str: " << npc_Object->GetOStrC() << "\t\t\t" << "Hitpoints: " << warrior_Object->GetWHpP() << endl;
    cout << "Lvl: " << npc_Object->GetOLvlC() << "\t\t\t\t" << "Turns: " << endl;
    cout << "Atk:" << npc_Object->GetOAtkC() << "\t\t\t\t" << "Strength: " << warrior_Object->GetWStrP() << endl;
    cout << "Def:" << npc_Object->GetODefC() << "\t\t\t\t" << "Attack: " << warrior_Object->GetWAtkP() << endl;
    cout << "Armor Value:" << npc_Object->GetOArmorValueC() << "\t\t\t" << "Defense: " << warrior_Object->GetWDefP() << endl;
    cout << "\t\t\t\t" << "Race: " << warrior_Object->GetWRaceP() << endl;
    cout << "\t\t\t\t" << "##Personnel Info##" << endl;
    cout << "\t\t\t\t" << "Gold: " << warrior_Object->GetWGoldP() << endl;
    cout << "\t\t\t\t" << "Gem: " << endl;
    cout << "\t\t\t\t" << "##Equipment##" << endl;
    cout << "\t\t\t\t" << "Weapon: " << Weapon->GetWeapon(warrior_Object->GetWWeaponP()) << endl;
    cout << "\t\t\t\t" << "Armour Type: " << Weapon->GetArmor(warrior_Object->GetWArmorTypeP()) << endl;
    cout << "\t\t\t\t" << "Armour Value: " << warrior_Object->GetWArmorValueP() << endl;
    cout << "\t\t\t\t" << "Experience: " << warrior_Object->GetWXptotalP() << "|" << warrior_Object->GetWMaxxpP() << endl;
}
void display::old_Bank(mywarrior * warrior_Object)
{
    #ifdef WIN32
        system("cls");
    #endif
    #ifdef linux
        printf("\033[2J\033[1;1H");
    #endif
    cout << "##GrrBank##" << "\t\t\t" << "##Vital Info##" << endl;
    cout << "You can deposit your money" << "\t" << "Name: " << warrior_Object->GetWNameP() << endl;
    cout << "here for save keeping." << "\t\t" << "Level: " << warrior_Object->GetWLvlP() << endl;
    cout << "\t\t\t\t" << "Hitpoints: " << warrior_Object->GetWHpP() << endl;
    cout << "Account Balance: " << warrior_Object->GetWSavingsP() << "\t\t" << "Turns: " << endl;
    cout << "\t\t\t\t" << "Strength: " << warrior_Object->GetWStrP() << endl;
    cout << "\t\t\t\t" << "Attack: " << warrior_Object->GetWAtkP() << endl;
    cout << "\t\t\t\t" << "Defense: " << warrior_Object->GetWDefP() << endl;
    cout << "\t\t\t\t" << "Race: " << warrior_Object->GetWRaceP() << endl;
    cout << "\t\t\t\t" << "##Personnel Info##" << endl;
    cout << "\t\t\t\t" << "Gold: " << warrior_Object->GetWGoldP() << endl;
    cout << "\t\t\t\t" << "Gem: " << endl;
    cout << "\t\t\t\t" << "##Equipment##" << endl;
    cout << "(D)eposit" << "\t\t\t" << "Weapon: " << Weapon->GetWeapon(warrior_Object->GetWWeaponP()) << endl;
    cout << "(W)idthdraw" << "\t\t\t" << "Armour Type: " << Weapon->GetArmor(warrior_Object->GetWArmorTypeP()) << endl;
    cout << "(E)xit Bank" << "\t\t\t" << "Armour Value: " << warrior_Object->GetWArmorValueP() << endl;
    cout << "\t\t\t\t\t" << "Experience: " << warrior_Object->GetWXptotalP() << "|" << warrior_Object->GetWMaxxpP() << endl;
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

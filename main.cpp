//============================================================================
// Name        : game.cpp
// Author      : paul
// Version     :
// Lord Macaulay said this concerning Jeremiah: ???It is difficult to conceive
// any situation more painful than that of a great man, condemned to watch
// the lingering agony of an exhausted country, to tend it during the alternate
// fits of stupefaction and raving which precede its dissolution, and to see
// the symptoms of vitality disappear one by one, till nothing is left but
// COLDNESS, DARKNESS, and CORRUPTION"
//                         :
// Copyright   : no copyright
// Description : Trying to clone Legend of the Green dragon in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include "bank.h"
#include "display.h"
#include "fighttable.h"
#include "forrest.h"
#include "includes.h"
#include "shop.h"
#include "training.h"
#include "xmlParse.h"
#include "xp.h"
using namespace std;

extern struct player warrior;
extern struct npc orge;

int main()
{
    // Initilize pointer class calls
    display *getDisplay = new display();
    forrest *newForest = new forrest();
    shop *getShop = new shop();
    bank *getBank = new bank();
    training *getTraining = new training();
    xmlParse *importData = new xmlParse();

    // Import player and orge settings from a xml file
    importData->readXML(warrior, orge);

    // set game state to running
    bool running = true;

    // set a constant to reset HP
    const int ConstWHpP = warrior.WHpP;

    while (running)
    {
        // Show main display
        getDisplay->mainDisplay(warrior);

        char e;
        cin >> e;
        switch (e)
        {
            case 'F':   // Enter Forest
            {
                newForest->ForestLvl1(warrior, orge);
                break;
            }
            case 'Q':   // Quit to the fields
            {
                importData->writeXML(warrior, orge);

                running = false;
                break;
            }
            case 'W':   // Warrior Training
            {
                        // this should be used to level your character after you ahve enoguh exp.
                getTraining->Warrior_Training(warrior);
                break;
            }
            case 'M':   // MightE's Weaponry
            {
                        // this should be used to multiply your dmg
                getShop->Weapon_Shop(warrior.WAtkP, warrior.WWeaponP, warrior.WGoldP);

                break;
            }
            case 'A':   // Pegasus Armor
            {
                        // this should be used to alter reduction in dmg
                getShop->Armor_Shop(warrior.WDefP, warrior.WArmorP, warrior.WGoldP);
                break;
            }
            case 'B':   // ye old bank
            {
                getBank->old_Bank(warrior);
                break;
            }
            case 'H':   // easy heal bot
            {
                if (warrior.WLvlP == 1){
                    warrior.WHpP = ConstWHpP;
                }else{
                    warrior.WHpP = ConstWHpP + (warrior.WLvlP * 100);
                }
                cout << "With a wave of the wand your are not so much deader" << endl;
                cin.ignore().get();
                break;
            }
            default:
            {
                printf("i have detected an error and its you\n");
                break;
            }
        }
    }
    delete getDisplay;
    delete newForest;
    delete getShop;
    delete getBank;
    delete getTraining;
    delete importData;
    return 0;
}

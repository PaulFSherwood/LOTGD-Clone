//============================================================================
// Name        : game.cpp
// Author      : paul
// Version     :
// Lord Macaulay said this concerning Jeremiah: “It is difficult to conceive
// any situation more painful than that of a great man, condemned to watch
// the lingering agony of an exhausted country, to tend it during the alternate
// fits of stupefaction and raving which precede its dissolution, and to see
// the symptoms of vitality disappear one by one, till nothing is left but
// COLDNESS, DARKNESS, and CORRUPTION"
//			   :
// Copyright   : no copyright
// Description : Trying to clone Legend of the Green dragon in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include "bank.h"
#include "display.h"
#include "fighttable.h"
#include "forrest.h"
#include "orge.h"
#include "shop.h"
#include "training.h"
#include "uiGroup.h"
#include "warrior.h"
#include "xmlParse.h"
#include "xp.h"
using namespace std;



int main()
{
    // Initilize pointer class calls
    display *getDisplay = new display();
    forrest *newForest = new forrest();
    shop *getShop = new shop();
    bank *getBank = new bank();
    training *getTraining = new training();
    xmlParse *importData = new xmlParse();
    mywarrior *mySoilder = new mywarrior();
    npc_orge *randomOgre = new npc_orge();
    uiGroup *uiDataValues = new uiGroup();

    // Import player and orge settings from a xml file
    // importData->readXML(warrior, orge);

    // pull all info from the xml file and put it into the class objects
    importData->readXML_Class_Object(mySoilder);
    importData->readXML_Class_Object(randomOgre);
    importData->readXML_Class_Object(uiDataValues);

    // set game state to running
    bool running = true;

    // set a constant to reset HP
    const int ConstWHpP = mySoilder->GetWHpP();// warrior.WHpP;

    while (running)
    {
        // Show main display
        getDisplay->mainDisplay(mySoilder, uiDataValues);

        // sdl test //
        //if (SDL_PollEvent(&event))
        //{
        //    if (event.type == SDL_QUIT)
        //    {
        //        running = false;
        //    }
        //}
        // sdl test //
        char e;
        cin >> e;
        switch (e)
        {
            case 'F':   // Enter Forest
            {
                newForest->ForestLvl1(mySoilder, randomOgre);
                break;
            }
            case 'Q':	// Quit to the fields
            {
                // mySoilder->PrintStats(); // testing passing around information in classes
                // cout << "======================" << endl;
                // randomOgre->PrintStats(); // testing passing around information in classes
                importData->writeXML_Class_Object(mySoilder, randomOgre);

                running = false;
                break;
            }
            case 'W':	// Warrior Training
            {
                        // this should be used to level your character after you ahve enoguh exp.
                getTraining->Warrior_Training(mySoilder);
                break;
            }
            case 'M':	// MightE's Weaponry
            {
                        // this should be used to multiply your dmg
                getShop->Weapon_Shop(mySoilder);

                break;
            }
            case 'A':	// Pegasus Armor
            {
                        // this should be used to alter reduction in dmg
                getShop->Armor_Shop(mySoilder);
                break;
            }
            case 'B':	// ye old bank
            {
                getBank->old_Bank(mySoilder);
                break;
            }
            case 'H':	// easy heal bot
            {
            if (mySoilder->GetWLvlP() == 1){
                    // reset health to original
                    mySoilder->SetWHpP(ConstWHpP);
                }else{
                    // reset health based on level
                    mySoilder->SetWHpP(ConstWHpP + (mySoilder->GetWLvlP() * 100));
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
    // sdl test //
    getDisplay->clean_up();
    // sdl test //
    delete getDisplay;
    delete newForest;
    delete getShop;
    delete getBank;
    delete getTraining;
    delete importData;
    delete mySoilder;
    delete randomOgre;
    return 0;
}

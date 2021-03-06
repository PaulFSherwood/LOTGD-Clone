//============================================================================
// Name        : game.cpp
// Author      : Paul Sherwood
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
#include "creature.h"
#include "player.h"
#include "textData.h"
#include "shop.h"
#include "training.h"
#include "uiGroup.h"
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
    myTextData * TextData_Object = new myTextData();

    // all npc/orge blag should be myCreature
    myplayer *myPlayer = new myplayer();
    mycreature *myCreature = new mycreature();

    uiGroup *uiDataValues = new uiGroup();

    // The event structure
    SDL_Event event;

    // Import player and orge settings from a xml file
    // importData->readXML(warrior, orge);

    // pull all info from the xml file and put it into the class objects
    importData->readXML_Class_Object(myPlayer);
    importData->readXML_Class_Object(myCreature);
    importData->readXML_ui_Class_Object(uiDataValues);

    // Set TextData for Center Display
    TextData_Object->SetCenterTextX(188);
    TextData_Object->SetCenterTextY(22);

    // set game state to running
    bool running = true;

    // Show main display
    getDisplay->mainDisplay(myPlayer, uiDataValues);

    while (running)
    {
        while( SDL_PollEvent( &event ) )
        {
            /* look for key events */
            switch( event.key.keysym.sym )
            {
                case SDLK_f://'F':   // Enter Forest
                {
                    newForest->ForestLvl1(myPlayer, myCreature, uiDataValues, TextData_Object);
                    break;
                }
                case SDLK_q://'Q':	// Quit to the fields
                {
                    importData->writeXML_Class_Object(myPlayer, myCreature);

                    running = false;
                    break;
                }
                case SDLK_w://'W':	// Warrior Training
                {
                    // this should be used to level your character after you ahve enoguh exp.
                    getTraining->Warrior_Training(myPlayer);
                    break;
                }
                case SDLK_m://'M':	// MightE's Weaponry
                {
                    // this should be used to multiply your dmg
                    getShop->Weapon_Shop(myPlayer);

                    break;
                }
                case SDLK_a://'A':	// Pegasus Armor
                {
                    // this should be used to alter reduction in dmg
                    getShop->Armor_Shop(myPlayer);
                    break;
                }
                case SDLK_b://'B':	// ye old bank
                {
                    getBank->old_Bank(myPlayer);
                    break;
                }
                case SDLK_h://'H':	// easy heal bot
                {
                if (myPlayer->GetPlayerLvlP() == 1){
                        // reset health to original
                        myPlayer->SetPlayerHpCap(myPlayer->GetPlayerHpCurrent());
                    }else{
                        // reset health based on level
                    // this really should be 10%...30%...90%...bla bla bla
                        myPlayer->SetPlayerHpCap(myPlayer->GetPlayerHpCurrent());
                    }
                    // need to update this for the gui
                    cout << "With a wave of the wand your are not so much deader" << endl;
                    cin.ignore().get();
                    break;
                }
                default:
                {
                    // printf("i have detected an error and its you\n");
                    break;
                }
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
    delete myPlayer;
    delete myCreature;
    return 0;
}

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
// PFS:4/16/2023: Refactoring, removing SDL where possible to return to a console program
//============================================================================

// main.cpp
#include <iostream>
#include "bank.h"
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

#include <QCoreApplication>
#include "keyeventfilter.h"

using namespace std;

int main()
{
    // For QT applications to start
    QCoreApplication a(argc, argv);

    KeyEventFilter keyEventFilter;
    a.installEventFilter(&keyEventFilter);


    // Initialize pointer class calls
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

    // Import player and orge settings from an xml file
    importData->readXML_Class_Object(myPlayer);
    importData->readXML_Class_Object(myCreature);
    importData->readXML_ui_Class_Object(uiDataValues);

    // Set TextData for Center Display
    TextData_Object->SetCenterTextX(188);
    TextData_Object->SetCenterTextY(22);

    // set game state to running
    bool running = true;

    while (running)
    {
        char choice;
        cout << "Choose an option:\n"
             << "f: Enter Forest\n"
             << "q: Quit to the fields\n"
             << "w: Warrior Training\n"
             << "m: MightE's Weaponry\n"
             << "a: Pegasus Armor\n"
             << "b: ye old bank\n"
             << "h: easy heal bot\n";
        cin >> choice;
        cin.ignore(); // ignore any extra input

        switch (choice)
        {
            case 'f': // Enter Forest
            {
                newForest->ForestLvl1(myPlayer, myCreature, uiDataValues, TextData_Object);
                break;
            }
            case 'q': // Quit to the fields
            {
                importData->writeXML_Class_Object(myPlayer, myCreature);
                running = false;
                break;
            }
            case 'w': // Warrior Training
            {
                getTraining->Warrior_Training(myPlayer);
                break;
            }
            case 'm': // MightE's Weaponry
            {
                getShop->Weapon_Shop(myPlayer);
                break;
            }
            case 'a': // Pegasus Armor
            {
                getShop->Armor_Shop(myPlayer);
                break;
            }
            case 'b': // ye old bank
            {
                getBank->old_Bank(myPlayer);
                break;
            }
            case 'h': // easy heal bot
            {
                if (myPlayer->GetPlayerLvlP() == 1)
                {
                    myPlayer->SetPlayerHpCap(myPlayer->GetPlayerHpCurrent());
                }
                else
                {
                    myPlayer->SetPlayerHpCap(myPlayer->GetPlayerHpCurrent());
                }
                cout << "With a wave of the wand your are not so much deader" << endl;
                cin.ignore().get();
                break;
            }
            default:
            {
                break;
            }
        }
    }

    return a.exec();


    // Clean up
    delete newForest;
    delete getShop;
    delete getBank;
    delete getTraining;
    delete importData;
    delete myPlayer;
    delete myCreature;
    return 0;
}

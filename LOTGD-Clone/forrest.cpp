#include <iostream>
#include <stdio.h>
#include "forrest.h"
#include "display.h"
#include "creature.h"
#include "player.h"
#include "textData.h"
#include "fighttable.h"

#include "keyeventfilter.h"
#include <QObject>

using namespace std;

forrest::forrest(){}

void forrest::ForestLvl1(myplayer *myPlayer, mycreature *myCreature, uiGroup *uiDataValues, myTextData *TextData_Object, KeyEventFilter *keyEventFilter)
{
    // Initilize pointer class calls
    display *getDisplay = new display();
    fighttable *getFighttable = new fighttable();

    connect(keyEventFilter, &KeyEventFilter::keyPressed, this, &forrest::handleKeyEvent);

    bool inForrest = true;

    while (inForrest){
        // Display user stats
        getDisplay->forrestDisplay(myPlayer, uiDataValues);

            }
    delete getDisplay;
    delete getFighttable;
}

void forrest::handleKeyEvent(int key) {
    switch (key) {
    case Qt::Key_L:  // Look for a fight
        getFighttable->Fight_Table(myPlayer, myCreature, TextData_Object);
        cin.ignore().get();
        break;
    case Qt::Key_R:  // Return to world menu
        inForrest = false;
        break;

        // this is only for debug should be deleted.
    case Qt::Key_C:  // change Orge level
        cout << "Enter Orges new level" << endl;
        int templvl;
        cin >> templvl;
        // set cpu level
        myCreature->SetCreatureLvlC(templvl);
        // set cpu strength
        myCreature->SetCreatureStrC((myCreature->GetCreatureLvlC() * 5) + 100);
        break;
    case Qt::Key_X:  // add xp
        int tempxptotal;
        tempxptotal += 100 * myPlayer->GetPlayerLvlP();
        myPlayer->SetPlayerXpCurrent(tempxptotal);
        break;

    default:
        //printf("i have detected an error and its you\n");
        break;
    }
    //cout << endl;
}

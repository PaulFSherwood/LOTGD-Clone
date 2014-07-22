#include <iostream>
#include <stdio.h>
#include "forrest.h"
#include "display.h"
#include "creature.h"
#include "player.h"
#include "textData.h"
#include "fighttable.h"
using namespace std;

forrest::forrest(){}

void forrest::ForestLvl1(myplayer * myPlayer, mycreature * myCreature, uiGroup * uiDataValues, myTextData * TextData_Object)

{
    // Initilize pointer class calls
    display *getDisplay = new display();
    fighttable *getFighttable = new fighttable();
    // The event structure
    SDL_Event event;

    bool inForrest = true;

    while (inForrest){
        // Display user stats
        getDisplay->forrestDisplay(myPlayer, uiDataValues);

        while( SDL_PollEvent( &event ) )
        {
            /* look for key events */
            switch( event.key.keysym.sym )
            {
            case SDLK_l://'L':	// Look for a fight
                getFighttable->Fight_Table(myPlayer, myCreature, TextData_Object);
                cin.ignore().get();
                break;
            case SDLK_r://'R':	// Return to world menu
                inForrest = false;
                break;

            // this is only for debug should be deleted.
            case SDLK_c://'C':   // change Orge level
                cout << "Enter Orges new level" << endl;
                int templvl;
                cin >> templvl;
                // set cpu level
                myCreature->SetCreatureLvlC(templvl);
                // set cpu strength
                myCreature->SetCreatureStrC((myCreature->GetCreatureLvlC() * 5) + 100);
                break;
            case SDLK_x://'X': // add xp
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
    }
    delete getDisplay;
    delete getFighttable;
}

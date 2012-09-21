#include <iostream>
#include <stdio.h>
#include "forrest.h"
#include "display.h"
#include "orge.h"
#include "fighttable.h"
#include "warrior.h"
using namespace std;

forrest::forrest(){}

void forrest::ForestLvl1(mywarrior * mySoilder, npc_orge * randomOgre, uiGroup * uiDataValues)

{
    // Initilize pointer class calls
    display *getDisplay = new display();
    fighttable *getFighttable = new fighttable();

    bool inForrest = true;

    while (inForrest){
        // Display user stats
        getDisplay->forrestDisplay(mySoilder, uiDataValues);

        char e;
        cin >> e;
        switch (e){
        case 'L':	// Look for a fight
            getFighttable->Fight_Table(mySoilder, randomOgre);
            cin.ignore().get();
            break;
        case 'R':	// Return to world menu
            inForrest = false;
            break;
        case 'C':   // change Orge level
            cout << "Enter Orges new level" << endl;
            int templvl;
            cin >> templvl;
            // set cpu level
            randomOgre->SetOLvlC(templvl);
            // set cpu strength
            randomOgre->SetOStrC((randomOgre->GetOLvlC() * 5) + 100);
            break;
        case 'X': // add xp
            int tempxptotal;
            tempxptotal += 100 * mySoilder->GetWLvlP();
            mySoilder->SetWXptotalP(tempxptotal);
            break;
        default:
            printf("i have detected an error and its you\n");
            break;
        }
        cout << endl;
    }
    delete getDisplay;
    delete getFighttable;
}

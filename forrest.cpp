#include <iostream>
#include <stdio.h>
#include "forrest.h"
#include "display.h"
#include "fighttable.h"
using namespace std;

extern player warrior;
extern npc orge;

forrest::forrest(){}

int forrest::ForestLvl1(player &warrior, npc &orge)

{
    // Initilize pointer class calls
    display *getDisplay = new display();
    fighttable *getFighttable = new fighttable();

    bool inForrest = true;

    while (inForrest){
        getDisplay->forrestDisplay(warrior);

        char e;
        cin >> e;
        switch (e){
        case 'L':       // Look for a fight
            getFighttable->Fight_Table(warrior, orge);
            cin.ignore().get();
            break;
        case 'R':       // Return to world menu
            inForrest = false;
            break;
        case 'C':   // change Orge level
            cout << "Enter Orges new level" << endl;
            cin >> orge.OLvlC;
            warrior.WHpP = ((orge.OLvlC * 10) + 200); // const is changing this back to the original variable
            orge.OStrC = ((orge.OLvlC * 5) + 100);
        case 'X': // add xp
            warrior.WXptotalP += 100 * warrior.WLvlP;
            break;
        default:
            printf("i have detected an error and its you\n");
            break;
        }
        cout << endl;
    }
    return 0;
}

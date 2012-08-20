#include <iostream>
#include <stdio.h>
#include <cmath>
#include "display.h"
#include "fighttable.h"
#include "xp.h"
using namespace std;

extern player warrior;
extern npc orge;

fighttable::fighttable(){}

void fighttable::Fight_Table(player &warrior, npc &orge)
{
    // Initilize pointer class calls
    display *getDisplay = new display();
    xp *getNewXP = new xp(warrior.WXptotalP, warrior.WLvlP, orge.OLvlC);

    // reseting orges hp is there a better way???
    int const Const_OhpP_temp = orge.OHpC;
    // Show info
    getDisplay->fightDisplay(warrior, orge);
    cout << "get ready to rumble...or not\n";
    cout << "(R)un, (F)ight\n";

    char e;
    cin >> e;
    switch (e){
    case 'R':
        cout << "A RABBIT RUN AWAY!! RUN AWAY!!";
        break;
    case 'F':
        cout << "let the fight begin" << endl;
        // cout << "Player: " << WhpP << "\t" << "Ogre: " << OhpP << endl;
        getDisplay->fightDisplay(warrior, orge);

        while ((orge.OHpC >= 1) && (warrior.WHpP >= 1)) {
            cout << "how many times do you want to try to hit" << endl;
            int hit;
            cin >> hit;
            // while you can still hit and everyone has enough hp
            while ((hit >= 1) && (orge.OHpC >= 1) && (warrior.WHpP >= 1)){
                // alter health of both parties
                orge.OHpC = orge.OHpC - (warrior.WStrP + warrior.WAtkP);
                warrior.WHpP = (warrior.WHpP + warrior.WDefP) - orge.OStrC;
                // Show updated info
                getDisplay->fightDisplay(warrior, orge);

                // decrament the hit counter
                hit = hit - 1;
            }
            if ((orge.OHpC) <= 0)
            {
                // pass info to do xp calculation
                int tempXP = getNewXP->getxprecieved();
                warrior.WXptotalP = warrior.WXptotalP + tempXP;
                printf("%d XP recieved ", tempXP);

                // check to see if you can level
                getNewXP->canlvl(warrior.WXptotalP, warrior.WMaxxpP, warrior.WHpP, warrior.WStrP, warrior.WLvlP);
                warrior.WMaxxpP = getNewXP->getmaxxp(warrior.WLvlP);

                // Give some gold based on lvl difference
                warrior.WGoldP += 100 * warrior.WLvlP;

                // reset Orge hp back to values based on level
                orge.OHpC = Const_OhpP_temp;
                break;
            }
            // if the warrior dies make it hurt
            if ((warrior.WHpP) <= 0)
            {
                warrior.WGoldP = 0;
                if (warrior.WXptotalP > warrior.WMaxxpP)
                {
                    warrior.WXptotalP = warrior.WXptotalP - warrior.WMaxxpP;
                } else {
                    warrior.WXptotalP = 0;
                    warrior.WLvlP = 0;
                    warrior.WWeaponP = 0;
                    warrior.WArmorP = 0;
                }
            }
        }
        break;
    default:
        printf ("i have detected an error and its you\n");
        break;
    }
}

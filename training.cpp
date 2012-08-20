#include <stdio.h>
#include <cmath>
#include "training.h"
#include "xp.h"
using namespace std;

extern player warrior;
extern npc orge;

training::training(){}

void training::Warrior_Training(player &warrior)
{
    // Set up trainer
    int Thp = warrior.WHpP + (warrior.WHpP / 2);
    int Tstr = warrior.WLvlP * 90;
    int Tlvl = warrior.WLvlP + 5;

    // initilize pointer class calls
    xp *getNewXP = new xp(warrior.WXptotalP, warrior.WLvlP, Tlvl);

    cout << "Would you like to Fight the Master?\n";
    cout << "(F)ight\n";
    cout << "(R)eturn to City\n";

    char e;
    cin >> e;
    switch (e){
    case 'R':
        break;
    case 'F':
        cout << "The master wishes you luck." << endl;
        cout << "Player: " << warrior.WHpP << "\t" << "Master: " << Thp << endl;
        while ((Thp >= 1) && (warrior.WHpP >= 1)) {
            cout << "how many times do you want to try to hit" << endl;
            int hit;
            cin >> hit;
            while ((hit >= 1) && (Thp >= 1) && (warrior.WHpP >= 1)){
                cout << "hit\t" << "WstrP\t" << "WhpP\t" << "Tstr\t" << "Thp" << "\t\n";
                cout << hit << "\t" << warrior.WStrP << "\t" << warrior.WHpP << "\t" << warrior.WStrP << "\t" << warrior.WHpP << "\t\n\n";
                Thp = Thp - (warrior.WStrP + warrior.WAtkP);
                cout << "Master HP: " << Thp << endl;
                warrior.WHpP = (warrior.WHpP + warrior.WDefP) - Tstr;
                cout << "Player HP: " << warrior.WHpP << endl;
                hit = hit - 1;
            }
            if ((Thp) <= 0){
                // pass info to do xp calculation
                int tempXP = getNewXP->getxprecieved();
                warrior.WXptotalP = warrior.WXptotalP + tempXP;
                printf("%d XP recieved || Total XP: %d", tempXP, warrior.WXptotalP);

                getNewXP->canlvl(warrior.WXptotalP, warrior.WMaxxpP, warrior.WHpP, warrior.WStrP, warrior.WLvlP);
                warrior.WMaxxpP = getNewXP->getmaxxp(warrior.WLvlP);

                break;
            }
        }
        break;
    default:
        printf ("i have detected an error and its you\n");
        break;
    }
}

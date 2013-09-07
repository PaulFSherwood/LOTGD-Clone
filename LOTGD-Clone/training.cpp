#include <stdio.h>
#include <cmath>
#include "training.h"
#include "xp.h"
using namespace std;

training::training(){}

void training::Warrior_Training(mywarrior * warrior_Object)
{
    // Set up trainer
    int Thp = warrior_Object->GetWHpP() + (warrior_Object->GetWHpP() / 2);
    int Tstr = warrior_Object->GetWLvlP() * 90;
    int Tlvl = warrior_Object->GetWLvlP() + 5;

    // initilize pointer class calls
    xp *getNewXP = new xp(warrior_Object->GetWXptotalP(), warrior_Object->GetWLvlP(), Tlvl);

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
        cout << "Player: " << warrior_Object->GetWHpP() << "\t" << "Master: " << Thp << endl;
        while ((Thp >= 1) && (warrior_Object->GetWHpP() >= 1)) {
            cout << "how many times do you want to try to hit" << endl;
            int hit;
            cin >> hit;
            while ((hit >= 1) && (Thp >= 1) && (warrior_Object->GetWHpP() >= 1)){
                cout << "hit\t" << "WstrP\t" << "WhpP\t" << "Tstr\t" << "Thp" << "\t\n";
                cout << hit << "\t" << warrior_Object->GetWStrP() << "\t" << warrior_Object->GetWHpP() << "\t" << warrior_Object->GetWStrP() << "\t" << warrior_Object->GetWHpP() << "\t\n\n";
                // reduce hp based on players str and attack power
                Thp = Thp - (warrior_Object->GetWStrP() + warrior_Object->GetWAtkP());
                // reduce players hp based on hp + defence then subtract cpu strength
                warrior_Object->SetWHpP((warrior_Object->GetWHpP() + warrior_Object->GetWDefP()) - Tstr);
                // print out results
                cout << "Master HP: " << Thp << endl;
                cout << "Player HP: " << warrior_Object->GetWHpP() << endl;
                // change hit counter
                hit = hit - 1;
            }
            if ((Thp) <= 0){
                // pass info to do xp calculation
                int tempXP = getNewXP->getxprecieved();
                warrior_Object->SetWXptotalP(warrior_Object->GetWXptotalP() + tempXP);
                printf("%d XP recieved || Total XP: %d", tempXP, warrior_Object->GetWXptotalP());

                getNewXP->canlvl(warrior_Object);
                warrior_Object->SetWMaxxpP(getNewXP->getmaxxp(warrior_Object->GetWLvlP()));

                break;
            }
        }
        break;
    default:
        printf ("i have detected an error and its you\n");
        break;
    }
}

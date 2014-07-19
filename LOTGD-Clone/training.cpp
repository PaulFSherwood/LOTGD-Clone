#include <stdio.h>
#include <cmath>
#include "training.h"
#include "xp.h"
using namespace std;

training::training(){}

void training::Warrior_Training(myplayer * warrior_Object)
{
    // Set up trainer
    int Thp = warrior_Object->GetPlayerHpP() + (warrior_Object->GetPlayerHpP() / 2);
    int Tstr = warrior_Object->GetPlayerLvlP() * 90;
    int Tlvl = warrior_Object->GetPlayerLvlP() + 5;

    // initilize pointer class calls
    xp *getNewXP = new xp(warrior_Object->GetPlayerXptotalP(), warrior_Object->GetPlayerLvlP(), Tlvl);

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
        cout << "Player: " << warrior_Object->GetPlayerHpP() << "\t" << "Master: " << Thp << endl;
        while ((Thp >= 1) && (warrior_Object->GetPlayerHpP() >= 1)) {
            cout << "how many times do you want to try to hit" << endl;
            int hit;
            cin >> hit;
            while ((hit >= 1) && (Thp >= 1) && (warrior_Object->GetPlayerHpP() >= 1)){
                cout << "hit\t" << "WstrP\t" << "WhpP\t" << "Tstr\t" << "Thp" << "\t\n";
                cout << hit << "\t" << warrior_Object->GetPlayerStrP() << "\t" << warrior_Object->GetPlayerHpP() << "\t" << warrior_Object->GetPlayerStrP() << "\t" << warrior_Object->GetPlayerHpP() << "\t\n\n";
                // reduce hp based on players str and attack power
                Thp = Thp - (warrior_Object->GetPlayerStrP() + warrior_Object->GetPlayerAtkP());
                // reduce players hp based on hp + defence then subtract cpu strength
                warrior_Object->SetPlayerHpP((warrior_Object->GetPlayerHpP() + warrior_Object->GetPlayerDefP()) - Tstr);
                // print out results
                cout << "Master HP: " << Thp << endl;
                cout << "Player HP: " << warrior_Object->GetPlayerHpP() << endl;
                // change hit counter
                hit = hit - 1;
            }
            if ((Thp) <= 0){
                // pass info to do xp calculation
                int tempXP = getNewXP->getxprecieved();
                warrior_Object->SetPlayerXptotalP(warrior_Object->GetPlayerXptotalP() + tempXP);
                printf("%d XP recieved || Total XP: %d", tempXP, warrior_Object->GetPlayerXptotalP());

                getNewXP->canlvl(warrior_Object);
                warrior_Object->SetPlayerMaxxpP(getNewXP->getmaxxp(warrior_Object->GetPlayerLvlP()));

                break;
            }
        }
        break;
    default:
        printf ("i have detected an error and its you\n");
        break;
    }
}

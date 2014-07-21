#include <stdio.h>
#include <cmath>
#include "training.h"
#include "xp.h"
using namespace std;

training::training(){}

void training::Warrior_Training(myplayer * myPlayer_Object)
{
    // Set up trainer
    int Thp = myPlayer_Object->GetPlayerHpCurrent() + (myPlayer_Object->GetPlayerHpCurrent() / 2);
    int Tstr = myPlayer_Object->GetPlayerLvlP() * 90;
    int Tlvl = myPlayer_Object->GetPlayerLvlP() + 5;

    // initilize pointer class calls
    xp *getNewXP = new xp(myPlayer_Object->GetPlayerXpRequired(), myPlayer_Object->GetPlayerLvlP(), Tlvl);

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
        cout << "Player: " << myPlayer_Object->GetPlayerHpCurrent() << "\t" << "Master: " << Thp << endl;
        while ((Thp >= 1) && (myPlayer_Object->GetPlayerHpCurrent() >= 1)) {
            cout << "how many times do you want to try to hit" << endl;
            int hit;
            cin >> hit;
            while ((hit >= 1) && (Thp >= 1) && (myPlayer_Object->GetPlayerHpCurrent() >= 1)){
                cout << "hit\t" << "WstrP\t" << "WhpP\t" << "Tstr\t" << "Thp" << "\t\n";
                cout << hit << "\t" << myPlayer_Object->GetPlayerHpCurrent() << "\t" << myPlayer_Object->GetPlayerHpCurrent() << "\t\n\n";
                // reduce hp based on players str and attack power
                Thp = Thp - myPlayer_Object->GetPlayerAtkP();
                // reduce players hp based on hp + defence then subtract cpu strength
                myPlayer_Object->SetPlayerHpCurrent((myPlayer_Object->GetPlayerHpCurrent() + myPlayer_Object->GetPlayerDefP()) - Tstr);
                // print out results
                cout << "Master HP: " << Thp << endl;
                cout << "Player HP: " << myPlayer_Object->GetPlayerHpCurrent() << endl;
                // change hit counter
                hit = hit - 1;
            }
            if ((Thp) <= 0){
                // pass info to do xp calculation
                int tempXP = getNewXP->getxprecieved();
                myPlayer_Object->SetPlayerXpCurrent(myPlayer_Object->GetPlayerXpCurrent() + tempXP);
                printf("%d XP recieved || Total XP: %d", tempXP, myPlayer_Object->GetPlayerXpRequired());

                getNewXP->canlvl(myPlayer_Object);
                myPlayer_Object->SetPlayerXpCurrent(getNewXP->getmaxxp(myPlayer_Object->GetPlayerLvlP()));

                break;
            }
        }
        break;
    default:
        printf ("i have detected an error and its you\n");
        break;
    }
}

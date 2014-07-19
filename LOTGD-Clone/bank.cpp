#include <iostream>
#include <stdio.h>
#include "bank.h"
#include "display.h"
#include "player.h"
using namespace std;

bank::bank(){}

void bank::old_Bank(myplayer * myPlayer)
{

    // Initilize pointer class calls
    display *getDisplay = new display();

    // display the shop
    getDisplay->old_Bank(myPlayer);

    bool inBank = true;

    while (inBank)
    {
        // display the shop
        getDisplay->old_Bank(myPlayer);

        // select the weapon you want
        char e;
        int money;
        cin >> e;
        switch(e)
        {
            case 'D': // Deposit Money
            {
                cout << "Please enter the Deposit ammount" << endl;
                cin >> money;
                // remove amount from you and add it to the bank account
                myPlayer->SetPlayerGoldP(myPlayer->GetPlayerGoldP() - money);
                myPlayer->SetPlayerSavingsP(myPlayer->GetPlayerSavingsP() + money);
                // cout << "Your deposit of (" << money << ") was recorded" << endl;
                break;
            }
            case 'W': // Withdraw Money
            {
                cout << "Please enter the Withdraw ammount" << endl;
                cin >> money;
                // remove ammount from bank account and give it to you
                myPlayer->SetPlayerSavingsP(myPlayer->GetPlayerSavingsP() - money);
                myPlayer->SetPlayerGoldP(myPlayer->GetPlayerGoldP() + money);
                // cout << "Your withdraw of (" << money << ") was recorded" << endl;
                break;
            }
            default:
            {
                inBank = false;
                break;
            }
        }
    }
    delete getDisplay;
}

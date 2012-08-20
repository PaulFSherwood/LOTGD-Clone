#include <iostream>
#include <stdio.h>
#include "bank.h"
#include "display.h"
using namespace std;

extern player warrior;
extern npc orge;

bank::bank(){}

void bank::old_Bank(player &warrior)
{

    // Initilize pointer class calls
    display *getDisplay = new display();

    // display the shop
    getDisplay->old_Bank(warrior);

    bool inBank = true;

    while (inBank)
    {
        // display the shop
        getDisplay->old_Bank(warrior);

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
                warrior.WGoldP = warrior.WGoldP - money;
                warrior.WSavingsP = warrior.WSavingsP + money;
                // cout << "Your deposit of (" << money << ") was recorded" << endl;
                break;
            }
            case 'W': // Withdraw Money
            {
                cout << "Please enter the Withdraw ammount" << endl;
                cin >> money;
                warrior.WSavingsP = warrior.WSavingsP - money;
                warrior.WGoldP = warrior.WGoldP + money;
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
}

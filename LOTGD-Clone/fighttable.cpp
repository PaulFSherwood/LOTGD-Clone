#include <iostream>
#include <stdio.h>
#include <cmath>
#include "display.h"
#include "orge.h"
#include "fighttable.h"
#include "warrior.h"
#include "xp.h"
using namespace std;

fighttable::fighttable(){}

void fighttable::Fight_Table(mywarrior * mySoilder, npc_orge * randomOrge)
{
    // Initilize pointer class calls
    display *getDisplay = new display();
    xp *getNewXP = new xp(mySoilder->GetWXptotalP(), mySoilder->GetWLvlP(), randomOrge->GetOLvlC());

    // setting up player and npc stats for the fight
    int DmgPotential_Player = mySoilder->GetWStrP() + mySoilder->GetWAtkP();
    int DmgPotential_npc = randomOrge->GetOStrC() + randomOrge->GetOAtkC();

    int DmgMitigation_Player = mySoilder->GetWDefP() + mySoilder->GetWArmorValueP();
    int DmgMitigation_npc = randomOrge->GetODefC() + randomOrge->GetOArmorValueC();
    /*
    cout << "DmgPotential_Player: " << DmgPotential_Player << endl;
    cout << "DmgPotential_npc: " << DmgPotential_npc << endl;
    cout << "DmgMitigation_Player: " << DmgMitigation_Player << endl;
    cout << "DmgMitigation_npc: " << DmgMitigation_npc << endl;
    */
    // reseting orges hp is there a better way???
    int const Const_OhpP_temp = randomOrge->GetOHpC();
    // Show info
    getDisplay->fightDisplay(mySoilder, randomOrge);
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
        getDisplay->fightDisplay(mySoilder, randomOrge);

        while ((randomOrge->GetOHpC() >= 1) && (mySoilder->GetWHpP() >= 1)) {
            cout << "how many times do you want to try to hit" << endl;
            int hit;
            cin >> hit;
            // while you can still hit and everyone has enough hp
            while ((hit >= 1) && (randomOrge->GetOHpC() >= 1) && (mySoilder->GetWHpP() >= 1)){
                // alter health of both parties
                /*find how much dmg will be taken and subtract from original then set hp*/
                mySoilder->SetWHpP(mySoilder->GetWHpP() - incommingDmg(DmgPotential_npc, DmgMitigation_Player));
                /*find how much dmg will be taken and subtract from original then set hp*/
                randomOrge->SetOHpC(randomOrge->GetOHpC() -
                                   incommingDmg(DmgPotential_Player, DmgMitigation_npc));
                // update screen
                getDisplay->fightDisplay(mySoilder, randomOrge);

                // decrament the hit counter
                hit = hit - 1;
            }
            if ((randomOrge->GetOHpC()) <= 0)
            {
                // pass info to do xp calculation
                int tempXP = getNewXP->getxprecieved();
                mySoilder->SetWXptotalP(mySoilder->GetWXptotalP() + tempXP);
                printf("%d XP recieved ", tempXP);

                // check to see if you can level
                getNewXP->canlvl(mySoilder);
                mySoilder->SetWMaxxpP(getNewXP->getmaxxp(mySoilder->GetWLvlP()));

                // Give some gold based on lvl difference
                // some wierd reason i cant do this in one shot
                // mySoilder->SetWGoldP(mySoilder->GetWGoldP() += (100 * mySoilder->GetWLvlP()));
                int tempGold = mySoilder->GetWGoldP();
                tempGold += 100 * mySoilder->GetWLvlP();
                mySoilder->SetWGoldP(tempGold);

                // reset Orge hp back to values based on level
                randomOrge->SetOHpC(Const_OhpP_temp);
                break;
            }
            // if the warrior dies make it hurt
            if ((mySoilder->GetWHpP()) <= 0)
            {
                mySoilder->SetWGoldP(0);
                // set xp to zero
                if (mySoilder->GetWXptotalP() > mySoilder->GetWMaxxpP())
                {
                    mySoilder->SetWXptotalP(mySoilder->GetWXptotalP() - mySoilder->GetWMaxxpP());
                } else {
                    mySoilder->SetWXptotalP(0);
                    mySoilder->SetWLvlP(0);
                    mySoilder->SetWWeaponP(0);
                    mySoilder->SetWArmorTypeP(0);
                }
            }
        }
        break;
    default:
        printf ("i have detected an error and its you\n");
        break;
    }
    delete getDisplay;
    delete getNewXP;
}

int fighttable::incommingDmg(int DmgPotential, int DmgMitigation)
{
    if ((DmgPotential - DmgMitigation) <= 0)
    {
        return 10;
    } else {
        return DmgPotential - DmgMitigation;
    }
}

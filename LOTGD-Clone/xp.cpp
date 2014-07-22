#include <iostream>
#include <stdio.h>
#include <cmath>
#include "player.h"
#include "xp.h"
using namespace std;

xp::xp(int WxptotalP, int WlvlP,  int OlvlP)
:currentxp(WxptotalP),
 Wlvl(WlvlP),
 Olvl(OlvlP)
{}


int  xp::getxprecieved()
{

    int basexp = 0;
    // int xpmax = 0;
    int xprecieved = 0;

    // xp calculations
    basexp = (((Wlvl*5)+45)*(2));
    xpmax = ((10)*(pow(2, Wlvl)));
    xprecieved = (((Wlvl*5)+45)*(2+(Wlvl-Olvl)));

    // xp re-calc based on level difference
    if (Olvl >= Wlvl){
        // currentxp = currentxp + xprecieved;
        xprecieved = (basexp + (100*(Wlvl)));
    }
    else if (Olvl < Wlvl){
        xprecieved = (basexp - (10*(Wlvl)));
        // currentxp = currentxp + xprecieved;
    }
    return xprecieved;
}

int xp::getmaxxp(int playerLevel)
{
    if (playerLevel == 1){
        xpmax = playerLevel * 100;
    } else if (playerLevel == 2){
        xpmax = playerLevel * 200;
    } else if (playerLevel == 3 || playerLevel == 4){
        xpmax = playerLevel * 167;
    } else {
        xpmax = playerLevel * 200;
    }
    return xpmax;
}

void xp::canlvl(myplayer * myPlayer)
{
    // check current xp and see if you can level
    if (myPlayer->GetPlayerXpRequired() >= myPlayer->GetPlayerXpCurrent() && myPlayer->GetPlayerLvlP() != 15){
        // Increase your level
        int WlvlP = myPlayer->GetPlayerLvlP();
        WlvlP += 1;
        myPlayer->SetPlayerLvlP(WlvlP);

        // Increase the xp required
        myPlayer->SetPlayerXpRequired(getmaxxp(myPlayer->GetPlayerLvlP()));

        // Increase players Hitpoints
        myPlayer->SetPlayerHpCurrent(myPlayer->GetPlayerLvlP() * 10);

        // Increase players Attack
        myPlayer->SetPlayerAtkP(myPlayer->GetPlayerLvlP() + myPlayer->GetPlayerWeaponP());

        // Increase players Defence
        myPlayer->SetPlayerDefP(myPlayer->GetPlayerLvlP() + myPlayer->GetPlayerArmorP());
    }
    else {
        //return 0;
    }
    //return WlvlP;
}

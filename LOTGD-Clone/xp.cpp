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

int xp::getmaxxp(int WlvlP)
{
    int xpmax = 0;
    xpmax = ((100)*(pow(2, WlvlP)));

    return xpmax;
}

void xp::canlvl(myplayer * myPlayer)
{
    // check current xp and see if you can level
    if (myPlayer->GetPlayerXptotalP() >= myPlayer->GetPlayerMaxxpP()){
        int WlvlP = myPlayer->GetPlayerLvlP();
        WlvlP += 1;
        myPlayer->SetPlayerLvlP(WlvlP);
        double tempHP = 0;
        tempHP = ((myPlayer->GetPlayerHpP() * .1) + 10) + myPlayer->GetPlayerHpP();
        myPlayer->SetPlayerHpP(tempHP);
        myPlayer->SetPlayerStrP(myPlayer->GetPlayerStrP() + 5);
    }
    else {
        //return 0;
    }
    //return WlvlP;
}

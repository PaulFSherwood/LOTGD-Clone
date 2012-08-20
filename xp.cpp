#include <iostream>
#include <stdio.h>
#include <cmath>
#include "xp.h"
using namespace std;

xp::xp(int WxptotalP, int WlvlP,  int OlvlP)
:currentxp(WxptotalP),
 Wlvl(WlvlP),
 Olvl(OlvlP)
{}

// editing for git (test)
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

int xp::getmaxxp(int &WlvlP)
{
    int xpmax = 0;
    xpmax = ((100)*(pow(2, WlvlP)));

    return xpmax;
}

void xp::canlvl(int &currentxp, int &maxxp, int &WhpP, int &WstrP, int &WlvlP)
{
    // check current xp and see if you can level
    if (currentxp >= maxxp){
        WlvlP += 1;
        double tempHP = 0;
        tempHP = (WhpP * .1);
        WhpP += (tempHP + 10);
        WstrP += 5;
    }
    else {
        //return 0;
    }
    //return WlvlP;
}

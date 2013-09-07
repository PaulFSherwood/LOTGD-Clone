#include <iostream>
#include <stdio.h>
#include <cmath>
#include "warrior.h"
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

void xp::canlvl(mywarrior * mySoilder)
{
    // check current xp and see if you can level
    if (mySoilder->GetWXptotalP() >= mySoilder->GetWMaxxpP()){
        int WlvlP = mySoilder->GetWLvlP();
        WlvlP += 1;
        mySoilder->SetWLvlP(WlvlP);
        double tempHP = 0;
        tempHP = ((mySoilder->GetWHpP() * .1) + 10) + mySoilder->GetWHpP();
        mySoilder->SetWHpP(tempHP);
        mySoilder->SetWStrP(mySoilder->GetWStrP() + 5);
    }
    else {
        //return 0;
    }
    //return WlvlP;
}

#ifndef XP_H
#define XP_H

#include <iostream>
#include <cmath>
using namespace std;

class xp
{
public:
    xp(int WxptotalP, int WlvlP,  int OlvlP);
    int getxprecieved();
    int getmaxxp(int WlvlP);
    void canlvl(myplayer * myPlayer);
private:
    int currentxp;
    int Wlvl;
    int Olvl;
    int basexp;
    int xpmax;
    int xprecieved;
//
};

#endif // XP_H

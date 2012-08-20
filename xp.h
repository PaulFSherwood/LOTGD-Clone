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
    int getmaxxp(int &WlvlP);
    void canlvl(int &currentxp, int &maxxp, int &WhpP, int &WstrP, int &WlvlP);
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

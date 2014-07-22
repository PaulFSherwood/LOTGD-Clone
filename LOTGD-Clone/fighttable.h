#ifndef FIGHTTABLE_H
#define FIGHTTABLE_H

#include <iostream>
#include <cmath>
#include "creature.h"
#include "player.h"
#include "textData.h"
// sdl test //
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
using namespace std;

class fighttable
{
public:
    fighttable();
    void Fight_Table(myplayer * myPlayer, mycreature * myCreature, myTextData * TextData_Object);

    int getCreatureHp(myplayer * myPlayer_Object, mycreature * creature_Object);
    int getCreatureDef(myplayer * myPlayer_Object, mycreature * creature_Object);
    string getCreatureName(mycreature * creature_Object);
    string getCreatureWeapon(mycreature * creature_Object);
    int getCreatureAttack(myplayer * myPlayer_Object, mycreature * creature_Object);

    int incommingDmg(int DmgPotential, int DmgMitigation);
};

#endif // FIGHTTABLE_H

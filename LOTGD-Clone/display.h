//============================================================================
// PFS:4/16/2023: Refactoring, removing SDL where possible to return to a console program
//============================================================================

#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <string>
#include "creature.h"
#include "player.h"
#include "textData.h"
#include "shop.h"
#include "uiGroup.h"

class display {
public:
    display();

    void vitalInfo(myplayer *myPlayer_Object, uiGroup *uiDataValues);
    void mainDisplay(myplayer *myPlayer_Object, uiGroup *uiDataValues);
    void fightDisplay(myplayer *myPlayer_Object, uiGroup * uiDataValues, mycreature *creature_Object, myTextData *TextData_Object);
    void forrestDisplay(myplayer *myPlayer_Object, uiGroup *uiDataValues);
    void old_Bank(myplayer *myPlayer_Object);
    void Weapon_Shop(std::string &systemMessage);
    void Armor_Shop(std::string &systemMessage);
};

#endif // DISPLAY_H

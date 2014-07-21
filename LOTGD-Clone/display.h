#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include "creature.h"
#include "uiGroup.h"
#include "player.h"
// sdl test //
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
// sdl test //
using namespace std;

class display
{
public:
    display();

    void vitalInfo(myplayer * myPlayer_Object, uiGroup * uiDataValues);
    void mainDisplay(myplayer * myPlayer_Object, uiGroup * uiDataValues);
    void forrestDisplay(myplayer * myPlayer_Object, uiGroup * uiDataValues);
    void fightDisplay(myplayer * myPlayer_Object, mycreature * creature_Object);
    void old_Bank(myplayer * myPlayer_Object);

    void Weapon_Shop(string &systemMessage);
    void Armor_Shop(string &systemMessage);

    // surface loading
    bool init();
    bool load_files();
    void clean_up();
    SDL_Surface *load_image(string filename);
    void apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination);
    void superApplySurface(int number, int X, int Y, SDL_Surface* source, SDL_Surface* destination, SDL_Color textColor);
    void superApplySurface(string text, int X, int Y, SDL_Surface* source, SDL_Surface* destination, SDL_Color textColor);
    void showHpText(int numberOne, int numberTwo, int X, int Y, SDL_Surface* source, SDL_Surface* destination, SDL_Color textColorOne, SDL_Color textColorTwo);
    void showXPBar(myplayer * myPlayer_Object, int x, int y, SDL_Surface *blue, SDL_Surface *destination);
    void showHPBar(myplayer * myPlayer_Object, int x, int y, SDL_Surface *blue, SDL_Surface *destination);
    // sdl test //
};

#endif // DISPLAY_H

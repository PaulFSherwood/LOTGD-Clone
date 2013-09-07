#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include "orge.h"
#include "uiGroup.h"
#include "warrior.h"
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

    void mainDisplay(mywarrior * warrior_Object, uiGroup * uiDataValues);
    void forrestDisplay(mywarrior * warrior_Object, uiGroup * uiDataValues);
    void fightDisplay(mywarrior * warrior_Object, npc_orge * npc_Object);
    void old_Bank(mywarrior * warrior_Object);

    void Weapon_Shop(string &systemMessage);
    void Armor_Shop(string &systemMessage);

    // surface loading
    SDL_Surface *load_image(string filename);
    void apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination);
    void showXPBar(mywarrior * warrior_Object, int x, int y, SDL_Surface *red, SDL_Surface *blue, SDL_Surface *destination);
    bool init();
    bool load_files();
    void clean_up();
    void superApplySurface(int number, int X, int Y, SDL_Surface* source, SDL_Surface* destination);
    void superApplySurface(string text, int X, int Y, SDL_Surface* source, SDL_Surface* destination);
    // sdl test //
};

#endif // DISPLAY_H

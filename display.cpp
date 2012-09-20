#include <iostream>
#include <sstream>
#include "boost/lexical_cast.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <QtGui>
#include "display.h"
#include "orge.h"
#include "shop.h"
#include "warrior.h"
// sdl test //
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
// sdl test //
using namespace std;

display::display(){}

// Initilize pointer class calls
shop *Weapon = new shop();

// sdl test //
// screen atributes
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

// the surfaces
SDL_Surface *background = NULL;
SDL_Surface *hud = NULL;
SDL_Surface *screen = NULL;
SDL_Surface *message = NULL;

SDL_Event event;

//The font that's going to be used
TTF_Font *font = NULL;

//The color of the font
SDL_Color textColor = { 255, 255, 255 };



// display functions
void display::mainDisplay(mywarrior * warrior_Object)
{
    #ifdef WIN32
        system("cls");
    #endif
    #ifdef linux
        printf("\033[2J\033[1;1H");
    #endif
    cout << "##Village Gate##" << "\t\t" << "##Vital Info##" << endl;
    cout << "(F)orest" << "\t\t\t" << "Name: " << warrior_Object->GetWNameP() << endl;
    cout << "(Q)uit to the fields" << "\t\t" << "Level: " << warrior_Object->GetWLvlP() << endl;
    cout << "(W)arrior training" << "\t\t" << "Hitpoints: " << warrior_Object->GetWHpP() << endl;
    cout << "##Market Street##" << "\t\t" << "Turns: " << endl;
    cout << "(M)ightE's Weaponry" << "\t\t" << "Strenght: " << warrior_Object->GetWStrP() << endl;
    cout << "Pegasus (A)rmor" << "\t\t\t" << "Attack: " << warrior_Object->GetWAtkP() << endl;
    cout << "Ye Old (B)ank" << "\t\t\t" << "Defense: " << warrior_Object->GetWDefP() << endl;
    cout << "(H)eal your self\t\t" << "Race: " << warrior_Object->GetWRaceP() << endl;
    cout << "\t\t\t\t" << "##Personnel Info##" << endl;
    cout << "\t\t\t\t" << "Gold: " << warrior_Object->GetWGoldP() << endl;
    cout << "\t\t\t\t" << "Gem: " << endl;
    cout << "\t\t\t\t" << "##Equipment##" << endl;
    cout << "\t\t\t\t" << "Weapon: " << Weapon->GetWeapon(warrior_Object->GetWWeaponP()) << endl;
    cout << "\t\t\t\t" << "Armour Type: " << Weapon->GetArmor(warrior_Object->GetWArmorTypeP()) << endl;
    cout << "\t\t\t\t" << "Armour Value: " << warrior_Object->GetWArmorValueP() << endl;
    cout << "\t\t\t\t" << "Experience: " << warrior_Object->GetWXptotalP() << "|" << warrior_Object->GetWMaxxpP() << endl;

    // sdl test //
    // Initialize
    if (init() == false)
    {
        //return 1;
    }
    // Load the files
    if (load_files() == false)
    {
        cout << "load failed" << endl;
        //return 1;
    }

//    std::stringstream strm;
//    strm << warrior_Object->GetWXptotalP();
//    message = TTF_RenderText_Solid(font, strm.str().c_str(), textColor);



    // if there was an error in rendering the text
    if (message == NULL)
    {
        //return 1;
    }

    // apply the surfaces to the screen
    apply_surface(0, 0, background, screen);
    apply_surface(0, 0, hud, screen);
    // apply_surface(10, 400, message, screen);
    superApplySurface(warrior_Object->GetWXptotalP(), 10, 400, message, screen);

    // Update the screen
    if (SDL_Flip(screen) == -1)
    {
        //return 1;
    }
    // sdl test //

}

void display::forrestDisplay(mywarrior * warrior_Object)
{
    #ifdef WIN32
        system("cls");
    #endif
    #ifdef linux
        printf("\033[2J\033[1;1H");
    #endif
    cout << "##Forest##" << "\t\t\t" << "##Vital Info##" << endl;
    cout << "(C)hange Orges level" << "\t\t" << "Name: " << warrior_Object->GetWNameP() << endl;
    cout << "(L)ook for a fight" << "\t\t" << "Level: " << warrior_Object->GetWLvlP() << endl;
    cout << "(R)eturn to village" << "\t\t" << "Hitpoints: " << warrior_Object->GetWHpP() << endl;
    cout << "\t\t\t\t" << "Turns: " << endl;
    cout << "\t\t\t\t" << "Strength: " << warrior_Object->GetWStrP() << endl;
    cout << "\t\t\t\t" << "Attack: " << warrior_Object->GetWAtkP() << endl;
    cout << "\t\t\t\t" << "Defense: " << warrior_Object->GetWDefP() << endl;
    cout << "\t\t\t\t" << "Race: " << warrior_Object->GetWRaceP() << endl;
    cout << "\t\t\t\t" << "##Personnel Info##" << endl;
    cout << "\t\t\t\t" << "Gold: " << warrior_Object->GetWGoldP() << endl;
    cout << "\t\t\t\t" << "Gem: " << endl;
    cout << "\t\t\t\t" << "##Equipment##" << endl;
    cout << "\t\t\t\t" << "Weapon: " << Weapon->GetWeapon(warrior_Object->GetWWeaponP()) << endl;
    cout << "\t\t\t\t" << "Armour Type: " << Weapon->GetArmor(warrior_Object->GetWArmorTypeP()) << endl;
    cout << "\t\t\t\t" << "Armour Value: " << warrior_Object->GetWArmorValueP() << endl;
    cout << "\t\t\t\t" << "Experience: " << warrior_Object->GetWXptotalP() << "|" << warrior_Object->GetWMaxxpP() << endl;
}

void display::fightDisplay(mywarrior * warrior_Object, npc_orge * npc_Object)
{
    #ifdef WIN32
        system("cls");
    #endif
    #ifdef linux
        printf("\033[2J\033[1;1H");
    #endif
    cout << "##Fighting##" << "\t\t\t" << "##Vital Info##" << endl;
    cout << "Orger Info" << "\t\t\t" << "Name: " << warrior_Object->GetWNameP() << endl;
    if (npc_Object->GetOHpC() >= -1) { cout << "Hp: " << npc_Object->GetOHpC() << "\t\t\t\t" << "Level: " << warrior_Object->GetWLvlP() << endl; }
    else { cout << "Hp: " << npc_Object->GetOHpC() << "\t\t\t\t" << "Level: " << warrior_Object->GetWLvlP() << endl; }
    cout << "Str: " << npc_Object->GetOStrC() << "\t\t\t" << "Hitpoints: " << warrior_Object->GetWHpP() << endl;
    cout << "Lvl: " << npc_Object->GetOLvlC() << "\t\t\t\t" << "Turns: " << endl;
    cout << "Atk:" << npc_Object->GetOAtkC() << "\t\t\t\t" << "Strength: " << warrior_Object->GetWStrP() << endl;
    cout << "Def:" << npc_Object->GetODefC() << "\t\t\t\t" << "Attack: " << warrior_Object->GetWAtkP() << endl;
    cout << "Armor Value:" << npc_Object->GetOArmorValueC() << "\t\t\t" << "Defense: " << warrior_Object->GetWDefP() << endl;
    cout << "\t\t\t\t" << "Race: " << warrior_Object->GetWRaceP() << endl;
    cout << "\t\t\t\t" << "##Personnel Info##" << endl;
    cout << "\t\t\t\t" << "Gold: " << warrior_Object->GetWGoldP() << endl;
    cout << "\t\t\t\t" << "Gem: " << endl;
    cout << "\t\t\t\t" << "##Equipment##" << endl;
    cout << "\t\t\t\t" << "Weapon: " << Weapon->GetWeapon(warrior_Object->GetWWeaponP()) << endl;
    cout << "\t\t\t\t" << "Armour Type: " << Weapon->GetArmor(warrior_Object->GetWArmorTypeP()) << endl;
    cout << "\t\t\t\t" << "Armour Value: " << warrior_Object->GetWArmorValueP() << endl;
    cout << "\t\t\t\t" << "Experience: " << warrior_Object->GetWXptotalP() << "|" << warrior_Object->GetWMaxxpP() << endl;
}
void display::old_Bank(mywarrior * warrior_Object)
{
    #ifdef WIN32
        system("cls");
    #endif
    #ifdef linux
        printf("\033[2J\033[1;1H");
    #endif
    cout << "##GrrBank##" << "\t\t\t" << "##Vital Info##" << endl;
    cout << "You can deposit your money" << "\t" << "Name: " << warrior_Object->GetWNameP() << endl;
    cout << "here for save keeping." << "\t\t" << "Level: " << warrior_Object->GetWLvlP() << endl;
    cout << "\t\t\t\t" << "Hitpoints: " << warrior_Object->GetWHpP() << endl;
    cout << "Account Balance: " << warrior_Object->GetWSavingsP() << "\t\t" << "Turns: " << endl;
    cout << "\t\t\t\t" << "Strength: " << warrior_Object->GetWStrP() << endl;
    cout << "\t\t\t\t" << "Attack: " << warrior_Object->GetWAtkP() << endl;
    cout << "\t\t\t\t" << "Defense: " << warrior_Object->GetWDefP() << endl;
    cout << "\t\t\t\t" << "Race: " << warrior_Object->GetWRaceP() << endl;
    cout << "\t\t\t\t" << "##Personnel Info##" << endl;
    cout << "\t\t\t\t" << "Gold: " << warrior_Object->GetWGoldP() << endl;
    cout << "\t\t\t\t" << "Gem: " << endl;
    cout << "\t\t\t\t" << "##Equipment##" << endl;
    cout << "(D)eposit" << "\t\t\t" << "Weapon: " << Weapon->GetWeapon(warrior_Object->GetWWeaponP()) << endl;
    cout << "(W)idthdraw" << "\t\t\t" << "Armour Type: " << Weapon->GetArmor(warrior_Object->GetWArmorTypeP()) << endl;
    cout << "(E)xit Bank" << "\t\t\t" << "Armour Value: " << warrior_Object->GetWArmorValueP() << endl;
    cout << "\t\t\t\t\t" << "Experience: " << warrior_Object->GetWXptotalP() << "|" << warrior_Object->GetWMaxxpP() << endl;
}

void display::Weapon_Shop(string &systemMessage)
{
    #ifdef WIN32
        system("cls");
    #endif
    #ifdef linux
        printf("\033[2J\033[1;1H");
    #endif
    cout << "##Welcome to the Weapon Shop##" << endl;
    cout << "Please have a look at our Weapons you can purchase" << endl;
    cout << "(W)ooden Stick" << endl;
    cout << "(D)ull Knife" << endl;
    cout << "Long (S)word" << endl;
    cout << "(L)azer Pistol" << endl;
    cout << "(E)xit the shop" << endl;
    cout << systemMessage << endl << endl;
}
void display::Armor_Shop(string &systemMessage)
{
    #ifdef WIN32
        system("cls");
    #endif
    #ifdef linux
        printf("\033[2J\033[1;1H");
    #endif
    cout << "##Welcome to the Weapon and Armror Shop##" << endl;
    cout << "Please have a look at our  Armor you can purchase" << endl;
    cout << "(P)aper Bag" << endl;
    cout << "(W)orn Jacket" << endl;
    cout << "(C)hain Mail" << endl;
    cout << "(F)orce Shield" << endl;
    cout << "(E)xit the shop" << endl;
    cout << systemMessage << endl << endl;
}

// sdl test //

SDL_Surface *display::load_image(string filename)
{
    // the image that's loaded
    SDL_Surface *loadedImage = NULL;

    // the optimized image that will be used
    SDL_Surface *optimizedImage = NULL;

    // load the image
    loadedImage = IMG_Load(filename.c_str());

    // if the image loaded
    if (loadedImage != NULL)
    {
        // creat an optimized image
        optimizedImage = SDL_DisplayFormat(loadedImage);

        // free the old image
        SDL_FreeSurface(loadedImage);

        // if the image was optimized just fine
        if (optimizedImage != NULL)
        {
            // map the color key
            Uint32 colorkey = SDL_MapRGB(optimizedImage->format, 0 , 0xFF, 0xFF);

            // set all the pixels to color r 0, g 0xFF, g 0xFF to be transparent
            SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, colorkey);
        }
    }
    // return the optimized image
    return optimizedImage;
}

void display::apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination)
{
    // temp rectangle to hold the offsets
    SDL_Rect offset;

    // Get the offsets
    offset.x = x;
    offset.y = y;

    // blit the surface
    SDL_BlitSurface(source, NULL, destination, &offset);
}

bool display::init()
{
    // init all SDL_subsystems
    if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        return false;
    }

    // set up the screen
    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);

    // If there was an error in setting up the screen
    if(screen == NULL)
    {
        return false;
    }

    // Initialize SDL_ttf
    if (TTF_Init() == -1)
    {
        return false;
    }

    // set the winow caption
    SDL_WM_SetCaption("SDL HUD TEST", NULL);

    // If everthing initialized fine
    return true;
}

bool display::load_files()
{
    // Load the background image
    background = load_image("img/background.png");

    // if the background didn't load
    if (background == NULL)
    {
        cout << "background load failed" << endl;
        return false;
    }

    // load the stick figure
    hud = load_image("img/hud.png");

    // if the hud figure didn't load
    if (hud == NULL)
    {
        cout << "hud load failed" << endl;
        return false;
    }

    // Open the font
    font = TTF_OpenFont("arial.ttf", 28);

    // if there was an error in loading the font
    if (font == NULL)
    {
        cout << "font load failed" << endl;
        return false;
    }

    return true;
}

void display::clean_up()
{
    // Free the surfaces
    SDL_FreeSurface(background);
    SDL_FreeSurface(hud);
    SDL_FreeSurface(message);

    // quit sdl_ttf
    TTF_Quit();

    // Quit SDL
    SDL_Quit();
}

void display::superApplySurface(int number, int X, int Y, SDL_Surface* source, SDL_Surface* destination)
{
    // convert int to char* for use in surface
    std::stringstream strm;
    strm << number;

    source = TTF_RenderText_Solid(font, strm.str().c_str(), textColor);

    if (source == NULL)
    {
        cout << "source not loaded" << endl;
    }
    // apply the surface to the screen
    apply_surface(X, Y, source, destination);

}

// sdl test //

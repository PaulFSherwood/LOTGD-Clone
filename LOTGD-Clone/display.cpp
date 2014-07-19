#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <QtGui>
#include "display.h"
#include "creature.h"
#include "player.h"
#include "shop.h"
#include "uiGroup.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
using namespace std;

display::display(){}

// Initilize pointer class calls
shop *Weapon = new shop();
// uiGroup *uiData = new uiGroup();

// screen atributes
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

// the surfaces
SDL_Surface *background = NULL;
SDL_Surface *hud = NULL;
SDL_Surface *screen = NULL;
SDL_Surface *message = NULL;
SDL_Surface *xpRedBar = NULL;
SDL_Surface *xpBlueBar = NULL;
SDL_Surface *name_tag_left = NULL;
SDL_Surface *name_value_right = NULL;
SDL_Surface *level_tag_left = NULL;
SDL_Surface *level_value_right = NULL;
SDL_Surface *hp_tag_left = NULL;
SDL_Surface *hp_value_right = NULL;
SDL_Surface *race_tag_left = NULL;
SDL_Surface *race_value_right = NULL;
SDL_Surface *str_tag_left = NULL;
SDL_Surface *str_value_right = NULL;
SDL_Surface *atk_tag_left = NULL;
SDL_Surface *atk_value_right = NULL;
SDL_Surface *def_tag_left = NULL;
SDL_Surface *def_value_right = NULL;
SDL_Surface *armv_tag_left = NULL;
SDL_Surface *armv_value_right = NULL;
SDL_Surface *gold_tag_left = NULL;
SDL_Surface *gold_value_right = NULL;
SDL_Surface *wep_tag_left = NULL;
SDL_Surface *wep_value_right = NULL;
SDL_Surface *arm_tag_left = NULL;
SDL_Surface *arm_value_right = NULL;
SDL_Surface *exp_tag_left = NULL;
SDL_Surface *exp_value_right = NULL;

//The font that's going to be used
TTF_Font *font = NULL;

// display functions
void display::mainDisplay(myplayer * warrior_Object, uiGroup * uiDataValues)
{
    // #ifdef WIN32
    //     system("cls");
    // #endif
    // #ifdef linux
    //     printf("\033[2J\033[1;1H");
    // #endif
    // cout << "##Village Gate##" << "\t\t" << "##Vital Info##" << endl;
    // cout << "(F)orest" << "\t\t\t" << "Name: " << warrior_Object->GetPlayerNameP() << endl;
    // cout << "(Q)uit to the fields" << "\t\t" << "Level: " << warrior_Object->GetPlayerLvlP() << endl;
    // cout << "(W)arrior training" << "\t\t" << "Hitpoints: " << warrior_Object->GetPlayerHpP() << endl;
    // cout << "##Market Street##" << "\t\t" << "Turns: " << endl;
    // cout << "(M)ightE's Weaponry" << "\t\t" << "Strenght: " << warrior_Object->GetPlayerStrP() << endl;
    // cout << "Pegasus (A)rmor" << "\t\t\t" << "Attack: " << warrior_Object->GetPlayerAtkP() << endl;
    // cout << "Ye Old (B)ank" << "\t\t\t" << "Defense: " << warrior_Object->GetPlayerDefP() << endl;
    // cout << "(H)eal your self\t\t" << "Race: " << warrior_Object->GetPlayerRaceP() << endl;
    // cout << "\t\t\t\t" << "##Personnel Info##" << endl;
    // cout << "\t\t\t\t" << "Gold: " << warrior_Object->GetPlayerGoldP() << endl;
    // cout << "\t\t\t\t" << "Gem: " << endl;
    // cout << "\t\t\t\t" << "##Equipment##" << endl;
    // cout << "\t\t\t\t" << "Weapon: " << Weapon->GetPlayereapon(warrior_Object->GetPlayerWeaponP()) << endl;
    // cout << "\t\t\t\t" << "Armour Type: " << Weapon->GetArmor(warrior_Object->GetPlayerArmorTypeP()) << endl;
    // cout << "\t\t\t\t" << "Armour Value: " << warrior_Object->GetPlayerArmorValueP() << endl;
    // cout << "\t\t\t\t" << "Experience: " << warrior_Object->GetPlayerXptotalP() << "|" << warrior_Object->GetPlayerMaxxpP() << endl;

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

    // apply the surfaces to the screen
    apply_surface(0, 0, background, screen);
    apply_surface(0, 0, hud, screen);
    // set the caption
    SDL_WM_SetCaption("In Town", NULL);

    // Left
    // Print name
    superApplySurface(uiDataValues->Getname_tag_left_text(), uiDataValues->Getname_tag_left_x(), uiDataValues->Getname_tag_left_y(), name_tag_left, screen);
    superApplySurface(warrior_Object->GetPlayerNameP(), uiDataValues->Getname_value_right_x(), uiDataValues->Getname_value_right_y(), name_value_right, screen);
    // Print Level
    superApplySurface(uiDataValues->Getlevel_tag_left_text(), uiDataValues->Getlevel_tag_left_x(), uiDataValues->Getlevel_tag_left_y(), level_tag_left, screen);
    superApplySurface(warrior_Object->GetPlayerLvlP(), uiDataValues->Getlevel_value_right_x(), uiDataValues->Getlevel_value_right_y(), level_value_right, screen);
    // Print HP
    superApplySurface(uiDataValues->Gethp_tag_left_text(), uiDataValues->Gethp_tag_left_x(), uiDataValues->Gethp_tag_left_y(), hp_tag_left, screen);
    superApplySurface(warrior_Object->GetPlayerHpP(), uiDataValues->Gethp_value_right_x(), uiDataValues->Gethp_value_right_y(), hp_value_right, screen);
    // Print Race
    superApplySurface(uiDataValues->Getrace_tag_left_text(), uiDataValues->Getrace_tag_left_x(), uiDataValues->Getrace_tag_left_y(), race_tag_left, screen);
    superApplySurface(warrior_Object->GetPlayerRaceP(), uiDataValues->Getrace_value_right_x(), uiDataValues->Getrace_value_right_y(), race_value_right, screen);

    // Middle
    // Print STR
    superApplySurface(uiDataValues->Getstr_tag_left_text(), uiDataValues->Getstr_tag_left_x(), uiDataValues->Getstr_tag_left_y(), str_tag_left, screen);
    superApplySurface(warrior_Object->GetPlayerStrP(), uiDataValues->Getstr_value_right_x(), uiDataValues->Getstr_value_right_y(), str_value_right, screen);
    // Print ATK
    superApplySurface(uiDataValues->Getatk_tag_left_text(), uiDataValues->Getatk_tag_left_x(), uiDataValues->Getatk_tag_left_y(), atk_tag_left, screen);
    superApplySurface(warrior_Object->GetPlayerAtkP(), uiDataValues->Getatk_value_right_x(), uiDataValues->Getatk_value_right_y(), atk_value_right, screen);
    // Print DEF
    superApplySurface(uiDataValues->Getdef_tag_left_text(), uiDataValues->Getdef_tag_left_x(), uiDataValues->Getdef_tag_left_y(), def_tag_left, screen);
    superApplySurface(warrior_Object->GetPlayerDefP(), uiDataValues->Getdef_value_right_x(), uiDataValues->Getdef_value_right_y(), def_value_right, screen);
    // Print Armor Value
    superApplySurface(uiDataValues->Getarmv_tag_left_text(), uiDataValues->Getarmv_tag_left_x(), uiDataValues->Getarmv_tag_left_y(), armv_tag_left, screen);
    superApplySurface(warrior_Object->GetPlayerArmorValueP(), uiDataValues->Getarmv_value_right_x(), uiDataValues->Getarmv_value_right_y(), armv_value_right, screen);

    // Right
    // Print Gold
    superApplySurface(uiDataValues->Getgold_tag_left_text(), uiDataValues->Getgold_tag_left_x(), uiDataValues->Getgold_tag_left_y(), gold_tag_left, screen);
    superApplySurface(warrior_Object->GetPlayerGoldP(), uiDataValues->Getgold_value_right_x(), uiDataValues->Getgold_value_right_y(), gold_value_right, screen);
    // Print Weapon
    superApplySurface(uiDataValues->Getwep_tag_left_text(), uiDataValues->Getwep_tag_left_x(), uiDataValues->Getwep_tag_left_y(), wep_tag_left, screen);
    superApplySurface(warrior_Object->GetPlayerWeaponP(), uiDataValues->Getwep_value_right_x(), uiDataValues->Getwep_value_right_y(), wep_value_right, screen);
    // Print Armor Type
    superApplySurface(uiDataValues->Getarm_tag_left_text(), uiDataValues->Getarm_tag_left_x(), uiDataValues->Getarm_tag_left_y(), arm_tag_left, screen);
    superApplySurface(warrior_Object->GetPlayerArmorTypeP(), uiDataValues->Getarm_value_right_x(), uiDataValues->Getarm_value_right_y(), arm_value_right, screen);
    // Print Experience
    superApplySurface(uiDataValues->Getexp_tag_left_text(), uiDataValues->Getexp_tag_left_x(), uiDataValues->Getexp_tag_left_y(), exp_tag_left, screen);
    // superApplySurface(warrior_Object->GetPlayerXptotalP(), uiDataValues->Getexp_value_right_x(), uiDataValues->Getexp_value_right_y(), exp_value_right, screen);

    showXPBar(warrior_Object, uiDataValues->Getexp_value_right_x(), uiDataValues->Getexp_value_right_y(), xpRedBar, xpBlueBar, screen);

    // Update the screen
    if (SDL_Flip(screen) == -1)
    {
        //return 1;
    }
}

void display::forrestDisplay(myplayer * warrior_Object, uiGroup * uiDataValues)
{
    // #ifdef WIN32
    //     system("cls");
    // #endif
    // #ifdef linux
    //     printf("\033[2J\033[1;1H");
    // #endif
    // cout << "##Forest##" << "\t\t\t" << "##Vital Info##" << endl;
    // cout << "(C)hange Orges level" << "\t\t" << "Name: " << warrior_Object->GetPlayerNameP() << endl;
    // cout << "(L)ook for a fight" << "\t\t" << "Level: " << warrior_Object->GetPlayerLvlP() << endl;
    // cout << "(R)eturn to village" << "\t\t" << "Hitpoints: " << warrior_Object->GetPlayerHpP() << endl;
    // cout << "\t\t\t\t" << "Turns: " << endl;
    // cout << "\t\t\t\t" << "Strength: " << warrior_Object->GetPlayerStrP() << endl;
    // cout << "\t\t\t\t" << "Attack: " << warrior_Object->GetPlayerAtkP() << endl;
    // cout << "\t\t\t\t" << "Defense: " << warrior_Object->GetPlayerDefP() << endl;
    // cout << "\t\t\t\t" << "Race: " << warrior_Object->GetPlayerRaceP() << endl;
    // cout << "\t\t\t\t" << "##Personnel Info##" << endl;
    // cout << "\t\t\t\t" << "Gold: " << warrior_Object->GetPlayerGoldP() << endl;
    // cout << "\t\t\t\t" << "Gem: " << endl;
    // cout << "\t\t\t\t" << "##Equipment##" << endl;
    // cout << "\t\t\t\t" << "Weapon: " << Weapon->GetPlayereapon(warrior_Object->GetPlayerWeaponP()) << endl;
    // cout << "\t\t\t\t" << "Armour Type: " << Weapon->GetArmor(warrior_Object->GetPlayerArmorTypeP()) << endl;
    // cout << "\t\t\t\t" << "Armour Value: " << warrior_Object->GetPlayerArmorValueP() << endl;
    // cout << "\t\t\t\t" << "Experience: " << warrior_Object->GetPlayerXptotalP() << "|" << warrior_Object->GetPlayerMaxxpP() << endl;

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

    // apply the surfaces to the screen
    apply_surface(0, 0, background, screen);
    apply_surface(0, 0, hud, screen);
    // set the caption
    SDL_WM_SetCaption("Forrest", NULL);

    // Left
    // Print name
    superApplySurface(uiDataValues->Getname_tag_left_text(), uiDataValues->Getname_tag_left_x(), uiDataValues->Getname_tag_left_y(), name_tag_left, screen);
    superApplySurface(warrior_Object->GetPlayerNameP(), uiDataValues->Getname_value_right_x(), uiDataValues->Getname_value_right_y(), name_value_right, screen);
    // Print Level
    superApplySurface(uiDataValues->Getlevel_tag_left_text(), uiDataValues->Getlevel_tag_left_x(), uiDataValues->Getlevel_tag_left_y(), level_tag_left, screen);
    superApplySurface(warrior_Object->GetPlayerLvlP(), uiDataValues->Getlevel_value_right_x(), uiDataValues->Getlevel_value_right_y(), level_value_right, screen);
    // Print HP
    superApplySurface(uiDataValues->Gethp_tag_left_text(), uiDataValues->Gethp_tag_left_x(), uiDataValues->Gethp_tag_left_y(), hp_tag_left, screen);
    superApplySurface(warrior_Object->GetPlayerHpP(), uiDataValues->Gethp_value_right_x(), uiDataValues->Gethp_value_right_y(), hp_value_right, screen);
    // Print Race
    superApplySurface(uiDataValues->Getrace_tag_left_text(), uiDataValues->Getrace_tag_left_x(), uiDataValues->Getrace_tag_left_y(), race_tag_left, screen);
    superApplySurface(warrior_Object->GetPlayerRaceP(), uiDataValues->Getrace_value_right_x(), uiDataValues->Getrace_value_right_y(), race_value_right, screen);

    // Middle
    // Print STR
    superApplySurface(uiDataValues->Getstr_tag_left_text(), uiDataValues->Getstr_tag_left_x(), uiDataValues->Getstr_tag_left_y(), str_tag_left, screen);
    superApplySurface(warrior_Object->GetPlayerStrP(), uiDataValues->Getstr_value_right_x(), uiDataValues->Getstr_value_right_y(), str_value_right, screen);
    // Print ATK
    superApplySurface(uiDataValues->Getatk_tag_left_text(), uiDataValues->Getatk_tag_left_x(), uiDataValues->Getatk_tag_left_y(), atk_tag_left, screen);
    superApplySurface(warrior_Object->GetPlayerAtkP(), uiDataValues->Getatk_value_right_x(), uiDataValues->Getatk_value_right_y(), atk_value_right, screen);
    // Print DEF
    superApplySurface(uiDataValues->Getdef_tag_left_text(), uiDataValues->Getdef_tag_left_x(), uiDataValues->Getdef_tag_left_y(), def_tag_left, screen);
    superApplySurface(warrior_Object->GetPlayerDefP(), uiDataValues->Getdef_value_right_x(), uiDataValues->Getdef_value_right_y(), def_value_right, screen);
    // Print Armor Value
    superApplySurface(uiDataValues->Getarmv_tag_left_text(), uiDataValues->Getarmv_tag_left_x(), uiDataValues->Getarmv_tag_left_y(), armv_tag_left, screen);
    superApplySurface(warrior_Object->GetPlayerArmorValueP(), uiDataValues->Getarmv_value_right_x(), uiDataValues->Getarmv_value_right_y(), armv_value_right, screen);

    // Right
    // Print Gold
    superApplySurface(uiDataValues->Getgold_tag_left_text(), uiDataValues->Getgold_tag_left_x(), uiDataValues->Getgold_tag_left_y(), gold_tag_left, screen);
    superApplySurface(warrior_Object->GetPlayerGoldP(), uiDataValues->Getgold_value_right_x(), uiDataValues->Getgold_value_right_y(), gold_value_right, screen);
    // Print Weapon
    superApplySurface(uiDataValues->Getwep_tag_left_text(), uiDataValues->Getwep_tag_left_x(), uiDataValues->Getwep_tag_left_y(), wep_tag_left, screen);
    superApplySurface(warrior_Object->GetPlayerWeaponP(), uiDataValues->Getwep_value_right_x(), uiDataValues->Getwep_value_right_y(), wep_value_right, screen);
    // Print Armor Type
    superApplySurface(uiDataValues->Getarm_tag_left_text(), uiDataValues->Getarm_tag_left_x(), uiDataValues->Getarm_tag_left_y(), arm_tag_left, screen);
    superApplySurface(warrior_Object->GetPlayerArmorTypeP(), uiDataValues->Getarm_value_right_x(), uiDataValues->Getarm_value_right_y(), arm_value_right, screen);
    // Print Experience
    superApplySurface(uiDataValues->Getexp_tag_left_text(), uiDataValues->Getexp_tag_left_x(), uiDataValues->Getexp_tag_left_y(), exp_tag_left, screen);
    superApplySurface(warrior_Object->GetPlayerXptotalP(), uiDataValues->Getexp_value_right_x(), uiDataValues->Getexp_value_right_y(), exp_value_right, screen);

    // Update the screen
    if (SDL_Flip(screen) == -1)
    {
        //return 1;
    }
}

void display::fightDisplay(myplayer * warrior_Object, mycreature * creature_Object)
{
    #ifdef WIN32
        system("cls");
    #endif
    #ifdef linux
        printf("\033[2J\033[1;1H");
    #endif
    cout << "##Fighting##" << "\t\t\t" << "##Vital Info##" << endl;
    cout << "Orger Info" << "\t\t\t" << "Name: " << warrior_Object->GetPlayerNameP() << endl;
    if (creature_Object->GetCreatureHpC() >= -1) { cout << "Hp: " << creature_Object->GetCreatureHpC() << "\t\t\t\t" << "Level: " << warrior_Object->GetPlayerLvlP() << endl; }
    else { cout << "Hp: " << creature_Object->GetCreatureHpC() << "\t\t\t\t" << "Level: " << warrior_Object->GetPlayerLvlP() << endl; }
    cout << "Str: " << creature_Object->GetCreatureStrC() << "\t\t\t" << "Hitpoints: " << warrior_Object->GetPlayerHpP() << endl;
    cout << "Lvl: " << creature_Object->GetCreatureLvlC() << "\t\t\t\t" << "Turns: " << endl;
    cout << "Atk:" << creature_Object->GetCreatureAtkC() << "\t\t\t\t" << "Strength: " << warrior_Object->GetPlayerStrP() << endl;
    cout << "Def:" << creature_Object->GetCreatureDefC() << "\t\t\t\t" << "Attack: " << warrior_Object->GetPlayerAtkP() << endl;
    cout << "Armor Value:" << creature_Object->GetCreatureArmorValueC() << "\t\t\t" << "Defense: " << warrior_Object->GetPlayerDefP() << endl;
    cout << "\t\t\t\t" << "Race: " << warrior_Object->GetPlayerRaceP() << endl;
    cout << "\t\t\t\t" << "##Personnel Info##" << endl;
    cout << "\t\t\t\t" << "Gold: " << warrior_Object->GetPlayerGoldP() << endl;
    cout << "\t\t\t\t" << "Gem: " << endl;
    cout << "\t\t\t\t" << "##Equipment##" << endl;
    cout << "\t\t\t\t" << "Weapon: " << Weapon->GetWeapon(warrior_Object->GetPlayerWeaponP()) << endl;
    cout << "\t\t\t\t" << "Armour Type: " << Weapon->GetArmor(warrior_Object->GetPlayerArmorTypeP()) << endl;
    cout << "\t\t\t\t" << "Armour Value: " << warrior_Object->GetPlayerArmorValueP() << endl;
    cout << "\t\t\t\t" << "Experience: " << warrior_Object->GetPlayerXptotalP() << "|" << warrior_Object->GetPlayerMaxxpP() << endl;
}
void display::old_Bank(myplayer * warrior_Object)
{
    #ifdef WIN32
        system("cls");
    #endif
    #ifdef linux
        printf("\033[2J\033[1;1H");
    #endif
    cout << "##GrrBank##" << "\t\t\t" << "##Vital Info##" << endl;
    cout << "You can deposit your money" << "\t" << "Name: " << warrior_Object->GetPlayerNameP() << endl;
    cout << "here for save keeping." << "\t\t" << "Level: " << warrior_Object->GetPlayerLvlP() << endl;
    cout << "\t\t\t\t" << "Hitpoints: " << warrior_Object->GetPlayerHpP() << endl;
    cout << "Account Balance: " << warrior_Object->GetPlayerSavingsP() << "\t\t" << "Turns: " << endl;
    cout << "\t\t\t\t" << "Strength: " << warrior_Object->GetPlayerStrP() << endl;
    cout << "\t\t\t\t" << "Attack: " << warrior_Object->GetPlayerAtkP() << endl;
    cout << "\t\t\t\t" << "Defense: " << warrior_Object->GetPlayerDefP() << endl;
    cout << "\t\t\t\t" << "Race: " << warrior_Object->GetPlayerRaceP() << endl;
    cout << "\t\t\t\t" << "##Personnel Info##" << endl;
    cout << "\t\t\t\t" << "Gold: " << warrior_Object->GetPlayerGoldP() << endl;
    cout << "\t\t\t\t" << "Gem: " << endl;
    cout << "\t\t\t\t" << "##Equipment##" << endl;
    cout << "(D)eposit" << "\t\t\t" << "Weapon: " << Weapon->GetWeapon(warrior_Object->GetPlayerWeaponP()) << endl;
    cout << "(W)idthdraw" << "\t\t\t" << "Armour Type: " << Weapon->GetArmor(warrior_Object->GetPlayerArmorTypeP()) << endl;
    cout << "(E)xit Bank" << "\t\t\t" << "Armour Value: " << warrior_Object->GetPlayerArmorValueP() << endl;
    cout << "\t\t\t\t\t" << "Experience: " << warrior_Object->GetPlayerXptotalP() << "|" << warrior_Object->GetPlayerMaxxpP() << endl;
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

void display::showXPBar(myplayer * warrior_Object, int x, int y, SDL_Surface *red, SDL_Surface *blue, SDL_Surface *destination)
{
    // print the bar
    apply_surface(x, y, red, destination);

    // find the percentage
    int currentPercentage = 0;
    currentPercentage = (warrior_Object->GetPlayerXptotalP() * 100) / warrior_Object->GetPlayerMaxxpP();

    // print the current xp percentage
    while (currentPercentage > 1)
    {
        // print one line of blue for each percent
        apply_surface(x, y, blue, destination);
        x = x + 1;
        currentPercentage = currentPercentage - 1;
    }
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

    // Load the xpRed image
    xpRedBar = load_image("img/xpRed.png");

    // if the xpRed didn't load
    if (xpRedBar == NULL)
    {
        cout << "xpRedBar load failed" << endl;
        return false;
    }

    // Load the xpBlueBar image
    xpBlueBar = load_image("img/xpBlue.png");

    // if the xpBlueBar didn't load
    if (xpBlueBar == NULL)
    {
        cout << "xpBlueBar load failed" << endl;
        return false;
    }

    // Open the font
    font = TTF_OpenFont("arial.ttf", 12);

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
    SDL_FreeSurface(screen);
    SDL_FreeSurface(xpRedBar);
    SDL_FreeSurface(xpBlueBar);
    SDL_FreeSurface(name_tag_left);
    SDL_FreeSurface(name_value_right);
    SDL_FreeSurface(level_tag_left);
    SDL_FreeSurface(level_value_right);
    SDL_FreeSurface(hp_tag_left);
    SDL_FreeSurface(hp_value_right);
    SDL_FreeSurface(race_tag_left);
    SDL_FreeSurface(race_value_right);
    SDL_FreeSurface(str_tag_left);
    SDL_FreeSurface(str_value_right);
    SDL_FreeSurface(atk_tag_left);
    SDL_FreeSurface(atk_value_right);
    SDL_FreeSurface(def_tag_left);
    SDL_FreeSurface(def_value_right);
    SDL_FreeSurface(armv_tag_left);
    SDL_FreeSurface(armv_value_right);
    SDL_FreeSurface(gold_tag_left);
    SDL_FreeSurface(gold_value_right);
    SDL_FreeSurface(wep_tag_left);
    SDL_FreeSurface(wep_value_right);
    SDL_FreeSurface(arm_tag_left);
    SDL_FreeSurface(arm_value_right);
    SDL_FreeSurface(exp_tag_left);
    SDL_FreeSurface(exp_value_right);

    // Quit sdl_ttf
    TTF_Quit();

    // Quit SDL
    SDL_Quit();
}

void display::superApplySurface(string text, int X, int Y, SDL_Surface* source, SDL_Surface* destination)
{
    //The color of the font
    SDL_Color textColor = { 255, 255, 255 };

    // convert int to char* for use in surface
    std::stringstream strm;
    strm << text;

    source = TTF_RenderText_Solid(font, strm.str().c_str(), textColor);

    if (source == NULL)
    {
        cout << "source string: " << text << " not loaded" << endl;
    }
    // apply the surface to the screen
    apply_surface(X, Y, source, destination);

}

void display::superApplySurface(int number, int X, int Y, SDL_Surface* source, SDL_Surface* destination)
{
    //The color of the font
    SDL_Color textColor = { 255, 255, 255 };

    // convert int to char* for use in surface
    std::stringstream strm;
    strm << number;

    source = TTF_RenderText_Solid(font, strm.str().c_str(), textColor);

    if (source == NULL)
    {
        cout << "source int: " << number << " not loaded" << endl;
    }
    // apply the surface to the screen
    apply_surface(X, Y, source, destination);

}

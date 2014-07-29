#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <QtGui>
#include "display.h"
#include "creature.h"
#include "player.h"
#include "textData.h"
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

// Available Colors
SDL_Color yellow = { 214, 238, 0, 255 };
SDL_Color red = { 238, 0, 0, 255 };
SDL_Color purple = { 230, 6, 157, 255 };
SDL_Color white = { 255, 255, 255, 255 };

// the surfaces
SDL_Surface *background = NULL;
SDL_Surface *left_menu = NULL;
// SDL_Surface *hud = NULL;
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
void display::vitalInfo(myplayer *myPlayer_Object, uiGroup *uiDataValues)
{
    shop *checkStuff = new shop();
    // Vital Info Bar
    // Print name
    superApplySurface(uiDataValues->Getname_tag_left_text(), uiDataValues->Getname_tag_left_x(), uiDataValues->Getname_tag_left_y(), name_tag_left, screen, white);
    superApplySurface(myPlayer_Object->GetPlayerNameP(), uiDataValues->Getname_value_right_x(), uiDataValues->Getname_value_right_y(), name_value_right, screen, yellow);
    // Print Level
    superApplySurface(uiDataValues->Getlevel_tag_left_text(), uiDataValues->Getlevel_tag_left_x(), uiDataValues->Getlevel_tag_left_y(), level_tag_left, screen, white);
    superApplySurface(myPlayer_Object->GetPlayerLvlP(), uiDataValues->Getlevel_value_right_x(), uiDataValues->Getlevel_value_right_y(), level_value_right, screen, yellow);
    // Print Hitpoints
    superApplySurface(uiDataValues->Gethp_tag_left_text(), uiDataValues->Gethp_tag_left_x(), uiDataValues->Gethp_tag_left_y(), hp_tag_left, screen, white);
    showHpText(myPlayer_Object->GetPlayerHpCurrent(), myPlayer_Object->GetPlayerHpCap(), uiDataValues->Gethp_value_right_x(), uiDataValues->Gethp_value_right_y(), screen, yellow, white);
    // Show HP Bar
    showHPBar(myPlayer_Object, uiDataValues->Gethp_bar_right_x(), uiDataValues->Gethp_bar_right_y(), xpBlueBar, screen);
    // Turns

    // Print ATK
    superApplySurface(uiDataValues->Getatk_tag_left_text(), uiDataValues->Getatk_tag_left_x(), uiDataValues->Getatk_tag_left_y(), atk_tag_left, screen, white);
    superApplySurface(myPlayer_Object->GetPlayerAtkP(), uiDataValues->Getatk_value_right_x(), uiDataValues->Getatk_value_right_y(), atk_value_right, screen, yellow);
    // Print DEF
    superApplySurface(uiDataValues->Getdef_tag_left_text(), uiDataValues->Getdef_tag_left_x(), uiDataValues->Getdef_tag_left_y(), def_tag_left, screen, white);
    superApplySurface(myPlayer_Object->GetPlayerDefP(), uiDataValues->Getdef_value_right_x(), uiDataValues->Getdef_value_right_y(), def_value_right, screen, yellow);
    // Spirits

    // Print Race
    superApplySurface(uiDataValues->Getrace_tag_left_text(), uiDataValues->Getrace_tag_left_x(), uiDataValues->Getrace_tag_left_y(), race_tag_left, screen, white);
    superApplySurface(myPlayer_Object->GetPlayerRaceP(), uiDataValues->Getrace_value_right_x(), uiDataValues->Getrace_value_right_y(), race_value_right, screen, yellow);
    //-----------------------------------------------------//
    // Print Gold
    superApplySurface(uiDataValues->Getgold_tag_left_text(), uiDataValues->Getgold_tag_left_x(), uiDataValues->Getgold_tag_left_y(), gold_tag_left, screen, white);
    superApplySurface(myPlayer_Object->GetPlayerGoldP(), uiDataValues->Getgold_value_right_x(), uiDataValues->Getgold_value_right_y(), gold_value_right, screen, yellow);
    // Print Experience
    superApplySurface(uiDataValues->Getexp_tag_left_text(), uiDataValues->Getexp_tag_left_x(), uiDataValues->Getexp_tag_left_y(), exp_tag_left, screen, white);
    showXPBar(myPlayer_Object, uiDataValues->Getexp_value_right_x(), uiDataValues->Getexp_value_right_y(), xpBlueBar, screen);
    //-----------------------------------------------------//
    // Print Weapon
    superApplySurface(uiDataValues->Getwep_tag_left_text(), uiDataValues->Getwep_tag_left_x(), uiDataValues->Getwep_tag_left_y(), wep_tag_left, screen, white);
    superApplySurface(myPlayer_Object->GetPlayerWeaponP(), uiDataValues->Getwep_value_right_x(), uiDataValues->Getwep_value_right_y(), wep_value_right, screen, yellow);
    superApplySurface(checkStuff->GetWeapon(myPlayer_Object->GetPlayerWeaponP()), (uiDataValues->Getwep_value_right_x() + 10), uiDataValues->Getwep_value_right_y(), wep_value_right, screen, yellow);
    // Print Armor
    superApplySurface(uiDataValues->Getarm_tag_left_text(), uiDataValues->Getarm_tag_left_x(), uiDataValues->Getarm_tag_left_y(), arm_tag_left, screen, white);
    superApplySurface(myPlayer_Object->GetPlayerArmorP(), uiDataValues->Getarm_value_right_x(), uiDataValues->Getarm_value_right_y(), arm_value_right, screen, yellow);
    superApplySurface(checkStuff->GetArmor(myPlayer_Object->GetPlayerArmorP()), (uiDataValues->Getarm_value_right_x() + 10), uiDataValues->Getarm_value_right_y(), arm_value_right, screen, yellow);

}
void display::mainDisplay(myplayer * myPlayer_Object, uiGroup * uiDataValues)
{
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
    // apply_surface(0, 0, hud, screen);
    // set the caption
    SDL_WM_SetCaption("In Town", NULL);
    // Vital Info Bar
    vitalInfo(myPlayer_Object, uiDataValues);
    // Update the screen
    if (SDL_Flip(screen) == -1)
    {
        //return 1;
    }
}
//void display::fightDisplay(myplayer * myPlayer_Object, mycreature * creature_Object, myTextData textInfo)
void display::fightDisplay(myplayer * myPlayer_Object, mycreature * creature_Object, myTextData * TextData_Object)
{
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
    // Set up the Menu_Display
    if (left_menu == NULL){
        cout << "left menu is null" << endl;
    }
    // refresh surfaces "Should this be here"
    apply_surface(0, 0, background, screen);
    apply_surface(0, 0, left_menu, background);

    // Need the text overlay for the left_menu dont have it right now.

    // set up and show center display



    // set start text to the next line
    TextData_Object->SetCenterTextY(TextData_Object->GetCenterTextY() + 12);

    // Update the screen
    if (SDL_Flip(background) == -1)
    {
        //return 1;
    }
}
void display::forrestDisplay(myplayer * myPlayer_Object, uiGroup * uiDataValues)
{
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
    apply_surface(0, 0, left_menu, background);
    // apply_surface(0, 0, hud, screen);
    // set the caption
    SDL_WM_SetCaption("Forrest", NULL);

    // Forrest Menu
    superApplySurface("Forrest", 20, 5, left_menu, screen, white);
    superApplySurface("(L)ook for a fight", 5, 25, left_menu, screen, yellow);
    superApplySurface("(R)eturn to the world", 5, 45, left_menu, screen, yellow);
    superApplySurface("(C)hange npc level", 5, 65, left_menu, screen, yellow);
    superApplySurface("(X)p add", 5, 85, left_menu, screen, yellow);

    // Vital Info Bar
    vitalInfo(myPlayer_Object, uiDataValues);

    // Update the screen
    if (SDL_Flip(screen) == -1)
    {
        //return 1;
    }
}
void display::old_Bank(myplayer * myPlayer_Object)
{
    #ifdef WIN32
        system("cls");
    #endif
    #ifdef linux
        printf("\033[2J\033[1;1H");
    #endif
    cout << "##GrrBank##" << "\t\t\t" << "##Vital Info##" << endl;
    cout << "You can deposit your money" << "\t" << "Name: " << myPlayer_Object->GetPlayerNameP() << endl;
    cout << "here for save keeping." << "\t\t" << "Level: " << myPlayer_Object->GetPlayerLvlP() << endl;
    cout << "\t\t\t\t" << "Hitpoints: " << myPlayer_Object->GetPlayerHpCurrent() << endl;
    cout << "Account Balance: " << myPlayer_Object->GetPlayerSavingsP() << "\t\t" << "Turns: " << endl;
    cout << "\t\t\t\t" << "Attack: " << myPlayer_Object->GetPlayerAtkP() << endl;
    cout << "\t\t\t\t" << "Defense: " << myPlayer_Object->GetPlayerDefP() << endl;
    cout << "\t\t\t\t" << "Race: " << myPlayer_Object->GetPlayerRaceP() << endl;
    cout << "\t\t\t\t" << "##Personnel Info##" << endl;
    cout << "\t\t\t\t" << "Gold: " << myPlayer_Object->GetPlayerGoldP() << endl;
    cout << "\t\t\t\t" << "Gem: " << endl;
    cout << "\t\t\t\t" << "##Equipment##" << endl;
    cout << "(D)eposit" << "\t\t\t" << "Weapon: " << Weapon->GetWeapon(myPlayer_Object->GetPlayerWeaponP()) << endl;
    cout << "\t\t\t\t\t" << "Experience: " << myPlayer_Object->GetPlayerXpRequired() << "|" << myPlayer_Object->GetPlayerXpCurrent() << endl;
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
    if (background == NULL) {
        background = load_image("img/background.png");
    }

    // if the background didn't load
    if (background == NULL)
    {
        cout << "background load failed" << endl;
        return false;
    }
    // Load the left_menu image
    if (left_menu == NULL) {
        left_menu = load_image("img/Left_Menu.png");
    }

    // if the background didn't load
    if (left_menu == NULL)
    {
        cout << "background load failed" << endl;
        return false;
    }
    // Load the xpRed image
    if (xpRedBar == NULL){
        xpRedBar = load_image("img/xpRed.png");
    }

    // if the xpRed didn't load
    if (xpRedBar == NULL)
    {
        cout << "xpRedBar load failed" << endl;
        return false;
    }

    // Load the xpBlueBar image
    if (xpBlueBar == NULL) {
        xpBlueBar = load_image("img/xpBlue.png");
    }

    // if the xpBlueBar didn't load
    if (xpBlueBar == NULL)
    {
        cout << "xpBlueBar load failed" << endl;
        return false;
    }

    // Open the font
    if (font == NULL) {
        font = TTF_OpenFont("arial.ttf", 12);
    }

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
    SDL_FreeSurface(left_menu);
    // SDL_FreeSurface(hud);
    SDL_FreeSurface(screen);
    SDL_FreeSurface(message);
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
void display::superApplySurface(string text, int X, int Y, SDL_Surface* source, SDL_Surface* destination, SDL_Color textColor)
{
    TTF_SetFontStyle(font, TTF_STYLE_BOLD);

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
void display::superApplySurface(int number, int X, int Y, SDL_Surface* source, SDL_Surface* destination, SDL_Color textColor)
{
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
void display::showHpText(int numberOne, int numberTwo, int X, int Y, SDL_Surface* destination, SDL_Color textColorOne, SDL_Color textColorTwo)
{
    SDL_Surface* sourceOne = NULL;
    SDL_Surface* sourceText = NULL;
    SDL_Surface* sourceTwo = NULL;

    // convert in to char* for use in surface
    std::stringstream strOne;
    strOne << numberOne;
    //
    std::stringstream strTwo;
    strTwo << numberTwo;

    // std::string sourceText = numberOne + "/" + numberTwo;

    sourceOne = TTF_RenderText_Solid(font, strOne.str().c_str(), textColorOne);
    sourceText = TTF_RenderText_Solid(font, "/", textColorTwo);
    sourceTwo = TTF_RenderText_Solid(font, strTwo.str().c_str(), textColorTwo);

    if (sourceOne == NULL)
    {
        cout << "source int: " << sourceText << "failed to load" << endl;
    }
    // apply the surface to the screen
    apply_surface(X, Y, sourceOne, destination);
    apply_surface((X + sourceOne->w + 2), Y, sourceText, destination);
    apply_surface((X + sourceOne->w + sourceText->w + 2), Y, sourceTwo, destination);

}
void display::showXPBar(myplayer * myPlayer_Object, int x, int y, SDL_Surface *blue, SDL_Surface *destination)
{
    // find the percentage
    int currentPercentage = 0;
    currentPercentage = (myPlayer_Object->GetPlayerXpCurrent() * 69) / myPlayer_Object->GetPlayerXpRequired();
    // print the current xp percentage
    while (currentPercentage > 1)
    {
        // print one line of blue for each percent
        apply_surface(x, y, blue, destination);
        x = x + 1;
        currentPercentage = currentPercentage - 1;
    }
}
void display::showHPBar(myplayer * myPlayer_Object, int x, int y, SDL_Surface *blue, SDL_Surface *destination)
{
    // find the percentage
    int currentPercentage = 0;
    currentPercentage = (myPlayer_Object->GetPlayerHpCurrent() * 69) / myPlayer_Object->GetPlayerHpCap();

    // print the current hp percentage
    while (currentPercentage > 1)
    {
        // print one line of blue for each percent
        apply_surface(x, y, blue, destination);
        x = x + 1;
        currentPercentage = currentPercentage - 1;
    }
}

//============================================================================
// Name        : game.cpp
// Author      : paul
// Version     :
// Lord Macaulay said this concerning Jeremiah: “It is difficult to conceive
// any situation more painful than that of a great man, condemned to watch
// the lingering agony of an exhausted country, to tend it during the alternate
// fits of stupefaction and raving which precede its dissolution, and to see
// the symptoms of vitality disappear one by one, till nothing is left but
// COLDNESS, DARKNESS, and CORRUPTION"
//			   :
// Copyright   : no copyright
// Description : Trying to clone Legend of the Green dragon in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include "bank.h"
#include "display.h"
#include "fighttable.h"
#include "forrest.h"
#include "orge.h"
#include "shop.h"
#include "training.h"
#include "warrior.h"
#include "xmlParse.h"
#include "xp.h"
// sdl test //
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
// sdl test //
using namespace std;

// sdl test //
// screen atributes
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

// the surfaces
SDL_Surface *background = NULL;
SDL_Surface *hud = NULL;
SDL_Surface *screen = NULL;

SDL_Event event;

// surface loading
SDL_Surface *load_image(string filename)
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

void apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination);

bool init();

bool load_files();

void clean_up();




// sdl test //

int main()
{
    // Initilize pointer class calls
    display *getDisplay = new display();
    forrest *newForest = new forrest();
    shop *getShop = new shop();
    bank *getBank = new bank();
    training *getTraining = new training();
    xmlParse *importData = new xmlParse();
    // class test for a new warrior
    mywarrior *mySoilder = new mywarrior();
    npc_orge *randomOgre = new npc_orge();


    // sdl test //
    // Initialize
    if (init() == false)
    {
        return 1;
    }
    // Load the files
    if (load_files() == false)
    {
        return 1;
    }

    // apply the surfaces to the screen
    apply_surface(0, 0, background, screen);
    apply_surface(240, 190, hud, screen);

    // Update the screen
    if (SDL_Flip(screen) == -1)
    {
        return 1;
    }
    // sdl test //

    // Import player and orge settings from a xml file
    // importData->readXML(warrior, orge);

    // pull all info from the xml file and put it into the class object
    importData->readXML_Class_Object(mySoilder);
    importData->readXML_Class_Object(randomOgre);

    // set game state to running
    bool running = true;

    // set a constant to reset HP
    const int ConstWHpP = mySoilder->GetWHpP();// warrior.WHpP;

    while (running)
    {
        // Show main display
        getDisplay->mainDisplay(mySoilder);

        // sdl test //
        if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
        }
        // sdl test //
        char e;
        cin >> e;
        switch (e)
        {
            case 'F':   // Enter Forest
            {
                newForest->ForestLvl1(mySoilder, randomOgre);
                break;
            }
            case 'Q':	// Quit to the fields
            {
                // mySoilder->PrintStats(); // testing passing around information in classes
                // cout << "======================" << endl;
                // randomOgre->PrintStats(); // testing passing around information in classes
                importData->writeXML_Class_Object(mySoilder, randomOgre);

                running = false;
                break;
            }
            case 'W':	// Warrior Training
            {
                        // this should be used to level your character after you ahve enoguh exp.
                getTraining->Warrior_Training(mySoilder);
                break;
            }
            case 'M':	// MightE's Weaponry
            {
                        // this should be used to multiply your dmg
                getShop->Weapon_Shop(mySoilder);

                break;
            }
            case 'A':	// Pegasus Armor
            {
                        // this should be used to alter reduction in dmg
                getShop->Armor_Shop(mySoilder);
                break;
            }
            case 'B':	// ye old bank
            {
                getBank->old_Bank(mySoilder);
                break;
            }
            case 'H':	// easy heal bot
            {
            if (mySoilder->GetWLvlP() == 1){
                    // reset health to original
                    mySoilder->SetWHpP(ConstWHpP);
                }else{
                    // reset health based on level
                    mySoilder->SetWHpP(ConstWHpP + (mySoilder->GetWLvlP() * 100));
                }
                cout << "With a wave of the wand your are not so much deader" << endl;
                cin.ignore().get();
                break;
            }
            default:
            {
                printf("i have detected an error and its you\n");
                break;
            }
        }
    }
    // sdl test //
    clean_up();
    // sdl test //
    delete getDisplay;
    delete newForest;
    delete getShop;
    delete getBank;
    delete getTraining;
    delete importData;
    delete mySoilder;
    delete randomOgre;
    return 0;
}
// sdl test //

void apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination)
{
    // temp rectangle to hold the offsets
    SDL_Rect offset;

    // Get the offsets
    offset.x = x;
    offset.y = y;

    // blit the surface
    SDL_BlitSurface(source, NULL, destination, &offset);
}

bool init()
{
    // init all SDL_subsystems
    if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        return 1;
    }

    // set up the screen
    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);

    // If there was an error in setting up the screen
    if(screen == NULL)
    {
        return 1;
    }

    // set the winow caption
    SDL_WM_SetCaption("SDL HUD TEST", NULL);

    // If everthing initializedfine
    return true;
}

bool load_files()
{
    // Load the background image
    background = load_image("background.png");

    // if the background didn't load
    if (background == NULL)
    {
        return false;
    }

    // load the stick figure
    hud = load_image("hud.png");

    // if the stick figure didn't load
    if (hud == NULL)
    {
        return false;
    }
    return true;
}

void clean_up()
{
    // Free the surfaces
    SDL_FreeSurface(background);
    SDL_FreeSurface(hud);

    // Quit SDL
    SDL_Quit();
}

// sdl test //

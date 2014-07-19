#include <iostream>
#include <stdio.h>
#include <cmath>
#include "display.h"
#include "creature.h"
#include "player.h"
#include "fighttable.h"
#include "xp.h"
using namespace std;

fighttable::fighttable(){}

void fighttable::Fight_Table(myplayer * myPlayer, mycreature * myCreature)
{
    // Initilize pointer class calls
    display *getDisplay = new display();

    xp *getNewXP = new xp(myPlayer->GetPlayerXptotalP(), myPlayer->GetPlayerLvlP(), myCreature->GetCreatureLvlC());

    // setting up player and npc stats for the fight
    int DmgPotential_Player = myPlayer->GetPlayerStrP() + myPlayer->GetPlayerAtkP();
    int DmgPotential_npc = myCreature->GetCreatureStrC() + myCreature->GetCreatureAtkC();

    int DmgMitigation_Player = myPlayer->GetPlayerDefP() + myPlayer->GetPlayerArmorValueP();
    int DmgMitigation_npc = myCreature->GetCreatureDefC() + myCreature->GetCreatureArmorValueC();
    /*
    cout << "DmgPotential_Player: " << DmgPotential_Player << endl;
    cout << "DmgPotential_npc: " << DmgPotential_npc << endl;
    cout << "DmgMitigation_Player: " << DmgMitigation_Player << endl;
    cout << "DmgMitigation_npc: " << DmgMitigation_npc << endl;
    */
    // reseting orges hp is there a better way???
    int const Const_OhpP_temp = myCreature->GetCreatureHpC();


    //THIS SHOULD BE A CALLED FUNCTION THE CREATION OF STATS SHOULD BE IN THE CREATURE CLASS


    // Set up monster should be only 1 level above player
    // if needed reset monster hp

    // getCreatureStats(based on player) {

    // getCreatureHp(based on players base stats){
    //      creatureHp = some math % of players base Hp }
    int creatureHp = getCreatureHp(myPlayer, myCreature);

    // getCreatureDef(based on players base stats){
    //      creatureDef = some math % of players base def }
    int creatureDef = getCreatureDef(myPlayer, myCreature);

    // getCreatureName(){
    //      creatureName = some random name from a list in an xml file }
    string creatureName = getCreatureName(myCreature);

    // getCreatureWeapon(){
    //      could use this to add some special % chance to do extra dmg
    //      creatureWeapon = some random weapon from a list in an xml file
    string creatureWeapon = getCreatureWeapon(myCreature);

    // getCreatureAttack(based on players base stats){
    //      not sure if i should take into account creatures weapon
    //      creatureAttack = some math % of players base attack
    int creatureAttack = getCreatureAttack(myPlayer, myCreature);


    // Show info
    getDisplay->fightDisplay(myPlayer, myCreature);
    cout << "get ready to rumble...or not\n";
    cout << "(R)un, (F)ight\n";

    char e;
    cin >> e;
    switch (e){
    case 'R':
        cout << "A RABBIT RUN AWAY!! RUN AWAY!!";
        break;
    case 'F':
        cout << "let the fight begin" << endl;
        // cout << "Player: " << WhpP << "\t" << "Ogre: " << OhpP << endl;
        getDisplay->fightDisplay(myPlayer, myCreature);

        while ((myCreature->GetCreatureHpC() >= 1) && (myPlayer->GetPlayerHpP() >= 1)) {
            cout << "how many times do you want to try to hit" << endl;
            int hit;
            cin >> hit;
            // while you can still hit and everyone has enough hp
            while ((hit >= 1) && (myCreature->GetCreatureHpC() >= 1) && (myPlayer->GetPlayerHpP() >= 1)){
                // alter health of both parties
                /*find how much dmg will be taken and subtract from original then set hp*/
                myPlayer->SetPlayerHpP(myPlayer->GetPlayerHpP() - incommingDmg(DmgPotential_npc, DmgMitigation_Player));
                /*find how much dmg will be taken and subtract from original then set hp*/
                myCreature->SetCreatureHpC(myCreature->GetCreatureHpC() -
                                   incommingDmg(DmgPotential_Player, DmgMitigation_npc));
                // update screen
                getDisplay->fightDisplay(myPlayer, myCreature);

                // decrement the hit counter
                hit = hit - 1;
            }
            if ((myCreature->GetCreatureHpC()) <= 0)
            {
                // pass info to do xp calculation
                int tempXP = getNewXP->getxprecieved();
                myPlayer->SetPlayerXptotalP(myPlayer->GetPlayerXptotalP() + tempXP);
                printf("%d XP recieved ", tempXP);

                // check to see if you can level
                getNewXP->canlvl(myPlayer);
                myPlayer->SetPlayerMaxxpP(getNewXP->getmaxxp(myPlayer->GetPlayerLvlP()));

                // Give some gold based on lvl difference
                // some wierd reason i cant do this in one shot
                // myPlayer->SetPlayerGoldP(myPlayer->GetPlayerGoldP() += (100 * myPlayer->GetPlayerLvlP()));
                int tempGold = myPlayer->GetPlayerGoldP();
                tempGold += 100 * myPlayer->GetPlayerLvlP();
                myPlayer->SetPlayerGoldP(tempGold);

                // reset Orge hp back to values based on level
                myCreature->SetCreatureHpC(Const_OhpP_temp);
                break;
            }
            // if the warrior dies make it hurt
            if ((myPlayer->GetPlayerHpP()) <= 0)
            {
                myPlayer->SetPlayerGoldP(0);
                // set xp to zero
                if (myPlayer->GetPlayerXptotalP() > myPlayer->GetPlayerMaxxpP())
                {
                    myPlayer->SetPlayerXptotalP(myPlayer->GetPlayerXptotalP() - myPlayer->GetPlayerMaxxpP());
                } else {
                    myPlayer->SetPlayerXptotalP(0);
                    myPlayer->SetPlayerLvlP(0);
                    myPlayer->SetPlayerWeaponP(0);
                    myPlayer->SetPlayerArmorTypeP(0);
                }
            }
        }
        break;
    default:
        printf ("i have detected an error and its you\n");
        break;
    }
    delete getDisplay;
    delete getNewXP;
}

int fighttable::incommingDmg(int DmgPotential, int DmgMitigation)
{
    if ((DmgPotential - DmgMitigation) <= 0)
    {
        return 10;
    } else {
        return DmgPotential - DmgMitigation;
    }
}

int fighttable::getCreatureHp(myplayer *warrior_Object, mycreature *creature_Object)
{
    // temp fix for this playerHp problem.
    // playerHp will always be chaning so to base the npcHp off of the playerHp would be odd
    // going to set npcHp to a % or something of the players level.
    // this can be changed latter
    int playerLvl = warrior_Object->GetPlayerLvlP();
    int creatureHp = (playerLvl * 100);
    return creatureHp;
}
int fighttable::getCreatureDef(myplayer *warrior_Object, mycreature *creature_Object)
{
    // solving issue with temp solution till i get something better.
    // baseing stats off of level
    int playerLvl = warrior_Object->GetPlayerLvlP();
    int creatureDef = (playerLvl * 10);

    return creatureDef;
}
string fighttable::getCreatureName(mycreature *creature_Object)
{
    // need a xml list of creature names to work with

}
string fighttable::getCreatureWeapon(mycreature *creature_Object)
{
    // need an xml list of creature weapons to work with

}
int fighttable::getCreatureAttack(myplayer *warrior_Object, mycreature *creature_Object)
{
    int playerLvl = warrior_Object->GetPlayerLvlP();
    int creatureAttack = (playerLvl * 10);

    return creatureAttack;
}

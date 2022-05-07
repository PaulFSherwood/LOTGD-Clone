#include <iostream>
#include "creature.h"
#include "xmlParse.h"  // should this just be done in main?
using namespace std;

mycreature::mycreature(){}

void mycreature::SetCreatureHpC(int hp) { CreatureHpC = hp; }
void mycreature::SetCreatureStrC(int str) { CreatureStrC = str; }
void mycreature::SetCreatureLvlC(int lvl) { CreatureLvlC = lvl; }
void mycreature::SetCreatureHitC(int hit) { CreatureHitC = hit; }

void mycreature::SetCreatureAtkC(int atk) { CreatureAtkC = atk; }
void mycreature::SetCreatureDefC(int def) { CreatureDefC = def; }
void mycreature::SetCreatureDodgeC(int dod) { CreatureDodgeC = dod; }
void mycreature::SetCreatureArmorValueC(int armorvalue) { CreatureArmorValueC = armorvalue; }
void mycreature::SetCreatureNameC(string name) { CreatureNameC = name; }

void mycreature::SetFightVectorCounter(int data) { FightDataVectorCounter = data; }
string mycreature::SetFightVectorData(string data, int index) {  return CreatureVectorData[index] = data; }

int mycreature::GetCreatureHpC() { return CreatureHpC; }
int mycreature::GetCreatureStrC() { return CreatureStrC; }
int mycreature::GetCreatureLvlC() { return CreatureLvlC; }
int mycreature::GetCreatureHitC() { return CreatureHitC; }

int mycreature::GetCreatureAtkC() { return CreatureAtkC; }
int mycreature::GetCreatureDefC() { return CreatureDefC; }
int mycreature::GetCreatureArmorValueC() { return CreatureArmorValueC; }
string mycreature::GetCreatureNameC() { return CreatureNameC; }

int mycreature::GetFightVectorCounter() { return FightDataVectorCounter; }
string mycreature::GetFightVectorData(int index) { return CreatureVectorData[index]; }

void mycreature::GetNewCreature(myplayer * myPlayer, mycreature * myCreature)
{
    xmlParse *importData = new xmlParse();

    // going to assume that levels have associated stats
    myPlayer->GetPlayerLvlP();
    // creature Strength
    myCreature->SetCreatureStrC(myPlayer->GetPlayerLvlP() * 10);
    // creature Attack power
    myCreature->SetCreatureAtkC(myPlayer->GetPlayerLvlP() * 40);
    // no math just setting hit to an arbitrary value
    myCreature->SetCreatureHitC(83);
    // just going to assume creature has 13% dodge chance
    myCreature->SetCreatureDodgeC(13);
    // creatures dont have armor????
    myCreature->SetCreatureArmorValueC(0);
    // pull in a funny name / weapons / and deaths for the creature... still waiting on that list
    importData->readXML_Fight_Data(myCreature);
}

void mycreature::PrintStats()
{
    cout << "HP: " <<  mycreature::GetCreatureHpC() << endl;
    cout << "Str: " <<  mycreature::GetCreatureStrC() << endl;
    cout << "Lvl: " <<  mycreature::GetCreatureLvlC() << endl;
    cout << "Atk: " <<  mycreature::GetCreatureAtkC() << endl;
    cout << "Def: " <<  mycreature::GetCreatureDefC() << endl;
    cout << "Name: " <<  mycreature::GetCreatureNameC() << endl;
}


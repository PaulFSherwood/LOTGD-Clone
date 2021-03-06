#ifndef XMLPARSE_H
#define XMLPARSE_H

#include <iostream>
#include <QtXml>
#include "uiGroup.h"
using namespace std;

class xmlParse
{
public:

void writeXML_Class_Object(myplayer * myPlayer_Object, mycreature * creature_Object);

void readXML_Class_Object(myplayer * myPlayer_Object);

void readXML_Class_Object(mycreature * creature_Object);

void readXML_ui_Class_Object(uiGroup * uiObject);

void readXML_Fight_Data(mycreature * myCreature);

};

#endif // XMLPARSE_H

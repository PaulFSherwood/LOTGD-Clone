#ifndef XMLPARSE_H
#define XMLPARSE_H

#include <iostream>
#include <QtXml>
#include "uiGroup.h"
using namespace std;

class xmlParse
{
public:

void writeXML_Class_Object(myplayer * warrior_Object, mycreature * creature_Object);

void readXML_Class_Object(myplayer * warrior_Object);

void readXML_Class_Object(mycreature * creature_Object);

void readXML_ui_Class_Object(uiGroup * uiObject);

};

#endif // XMLPARSE_H

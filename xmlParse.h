#ifndef XMLPARSE_H
#define XMLPARSE_H

#include <iostream>
#include "uiGroup.h"
using namespace std;

class xmlParse
{
public:

void writeXML_Class_Object(mywarrior * warrior_Object, npc_orge * npc_Object);

void readXML_Class_Object(mywarrior * warrior_Object);

void readXML_Class_Object(npc_orge * npc_Object);

void readXML_ui_Class_Object(uiGroup * uiObject);

};

#endif // XMLPARSE_H

#ifndef XMLPARSE_H
#define XMLPARSE_H

#include <iostream>
#include "includes.h"
using namespace std;

extern struct player warrior;
extern struct npc orge;

class xmlParse
{
public:

void readXML(struct player &warrior, struct npc &orge);

void writeXML(struct player &warrior, struct npc &orge);

};

#endif // XMLPARSE_H

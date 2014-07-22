#include <iostream>
#include "textData.h"
using namespace std;

myTextData::myTextData(){}

void myTextData::SetCenterTextX(int x) { CenterTextX = x; }
void myTextData::SetCenterTextY( int y) { CenterTextY = y; }
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
int myTextData::GetCenterTextX() { return CenterTextX; }
int myTextData::GetCenterTextY() { return CenterTextY; }

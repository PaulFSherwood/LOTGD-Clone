#ifndef TEXTDATA_H
#define TEXTDATA_H

#include <iostream>
using namespace std;

class myTextData
{
public:
    myTextData();

    void SetCenterTextX(int x);
    void SetCenterTextY( int y);
    //////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////
    int GetCenterTextX();
    int GetCenterTextY();

private:
    int CenterTextX;
    int CenterTextY;
};

#endif // TEXTDATA_H_

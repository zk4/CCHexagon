#include "Hexagones.h"
#include <algorithm>
using namespace std;
#include <math.h>


void Hexagones::draw()
{
    for (auto& hexagon : hexagones)
    {
        hexagon.draw (length, zeroPoint, bPoint_top);
    }
}


Hexagones::Hexagones (int length_,   CCPoint zeroPoint_ /*= CCPointZero*/, bool bPoint_top_/*=true */):
    length (length_),

    zeroPoint (zeroPoint_),
    bPoint_top (bPoint_top_)
{



}

int Hexagones::Contains (CCPoint& pos)
{

    Hexagon h = Hexagon::getHexagon (length,zeroPoint,pos);

    for (int i=0; i <hexagones.size()  ; ++i)
    {
        if (hexagones[i] == h)
            return i;
    }
    return -1;
}


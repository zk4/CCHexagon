#include "HexCoordinate.h"
#include "BeeHive.h"
#include <algorithm>
#include <math.h>
using namespace std;

void HexCoordinate::draw()
{
    for (auto& hexagon : hexagones)
    {
        CCPoint center = Hex2CCP (hexagon);
        hexagon.Draw (length, center );
    }
}


HexCoordinate::HexCoordinate (float length_, CCPoint zeroPoint_ /*= CCPointZero*/,CCAffineTransform  m_) :
    length (length_),
    zeroPoint (zeroPoint_),
    matrix (m_)
{}

cocos2d::CCPoint HexCoordinate::Hex2CCP (Hexagon  h) const
{
    h *= length;
    return CCPointApplyAffineTransform (ccp (h.q, h.r), matrix) + zeroPoint;
}

Hexagon HexCoordinate::CCP2Hex (CCPoint  p) const
{
    CCPoint pp = CCPointApplyAffineTransform (ccpSub (p, zeroPoint) / length, CCAffineTransformInvert (matrix));
    return Hexagon (pp.x, pp.y);
}



void HexCoordinate::MakeSolidHex (int radius, const Hexagon& center, ccColor4F color)
{
    BeeHive::MakeSolidHex (radius, center, hexagones, color);
}

void HexCoordinate::MakeRingHex (int radius, const Hexagon& center, ccColor4F color)
{
    BeeHive::MakeRingHex (radius, center, hexagones, color);
}

void HexCoordinate::MakeRingHexes (int inner, int outter, const Hexagon& center, ccColor4F color)
{
    BeeHive::MakeRingHexes (inner, outter, center, hexagones, color);
}



void HexCoordinate::MakeCross (int radius, const Hexagon& center, ccColor4F color)
{
    BeeHive::MakeCross (radius, center, hexagones, color);
}

void HexCoordinate::InterSect (const vector<Hexagon>& src)
{
    BeeHive::InterSect (hexagones, src);
}

bool HexCoordinate::Find (const Hexagon& target) const
{
    return   BeeHive::Find (hexagones, target);
}



void HexCoordinate::MakeLine (const Hexagon& start, const Hexagon& end, ccColor4F color /*= ccc4f(1, 1, 1, 1)*/)
{
    BeeHive::MakeLine (start, end, hexagones, color);
}

void HexCoordinate::MakeRect (int width, int height, const Hexagon& lb, ccColor4F color /*= ccc4f (1, 1, 1, 1)*/)
{
    BeeHive::MakeRect (width, height, lb, hexagones, color);
}

void HexCoordinate::setMatrix (CCAffineTransform& m)
{
    matrix=m;
}


void HexCoordinate::CopyCoordinate (HexCoordinate& c)
{
    c.length=length;
    c.zeroPoint=zeroPoint;
    c.matrix=matrix;
}

void HexCoordinate::MakeRect2 (int width, int height, const Hexagon& lb, ccColor4F color /*= ccc4f (1, 1, 1, 1)*/)
{
    BeeHive::MakeRect2 (width, height, lb, hexagones, color);
}





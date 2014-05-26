#include "HexCoordinate.h"
#include <algorithm>
#include <math.h>
using namespace std;

void HexCoordinate::draw()
{
    for (auto& hexagon : hexagones)
    {
        CCPoint center = Hex2CCP (hexagon);
        hexagon.Draw (length, center + zeroPoint);
    }
}


HexCoordinate::HexCoordinate (float length_, CCPoint zeroPoint_ /*= CCPointZero*/) :
    length (length_),
    zeroPoint (zeroPoint_)
{}


static CCAffineTransform hexMatrix = { sqrt (3.0f), 0, sqrt (3.0f) / 2.0f, -1.5f };
static CCAffineTransform revert_hexMatrix = CCAffineTransformInvert (hexMatrix);
cocos2d::CCPoint HexCoordinate::Hex2CCP (Hexagon  h) const
{
    h *= length;
    return CCPointApplyAffineTransform (ccp (h.q, h.r), hexMatrix);
}

Hexagon HexCoordinate::CCP2Hex (CCPoint  p)
{
    CCPoint pp = CCPointApplyAffineTransform (ccpSub (p, zeroPoint) / length, revert_hexMatrix);
    return Hexagon (pp.x, pp.y);

}

bool HexCoordinate::Contains (Hexagon& hex) const
{
    for (auto & a : hexagones)
    {
        if (a == hex)
            return true;
    }
    return false;
}

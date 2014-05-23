#include "Hexagon.h"
Hexagon Hexagon::directions[Hexagon::eDirection::COUNT] =
{
    { 0, 0 }, { 1, 0 }, { 1, 1 }, { 0, 1 },
    { -1, 0 }, { -1, -1 }, { 0, -1 }
};


int Hexagon::distance (Hexagon& h)
{
    return max (max (abs (x - h.x), abs (y - h.y)), abs (z - h.z));
}

Hexagon::Hexagon (int x_ /*= 0*/, int y_ /*= 0 */, ccColor4F color_ /*= ccc4f(1, 1, 1, 1)*/) :x (x_), y (y_), color (color_)
{
    z = x - y;
}

Hexagon::Hexagon (const Hexagon& h)
{
    *this = h;
}

Hexagon::eDirection Hexagon::Towards (const Hexagon& h) const
{
    bool bX = false, bY = false, bZ = false;
    Hexagon dir = *this - h;
    int aX = abs (dir.x);
    int aY = abs (dir.y);
    int aZ = abs (dir.z);
    if (aX > abs (dir.y))
    {
        if (aY > aZ)
        {
            if (dir.x)
                dir.x /= aX;
            if (dir.y)
                dir.y /= aY;
            dir.z = 0;
        }
        else
        {
            if (dir.x)
                dir.x /= aX;
            if (dir.z)
                dir.z /= aZ;
            dir.y = 0;

        }
    }
    else
    {
        if (aX > aZ)
        {
            if (dir.x)
                dir.x /= aX;
            if (dir.y)
                dir.y /= aY;
            dir.z = 0;
        }
        else
        {
            if (dir.y)
                dir.y /= aY;
            if (dir.z)
                dir.z /= aZ;
            dir.x = 0;

        }
    }
    for (int i = 0; i < eDirection::COUNT; ++i)
    {
        if (dir == directions[i])
            return eDirection (i);
    }

}

Hexagon& Hexagon::Move (eDirection dir, int times)
{
    *this += (directions[dir] * times);
    return *this;
}


void Hexagon::draw (int length, CCPoint zeroPoint, bool bPoint_top/* = true*/)
{

    for (int i = 0; i < 6; ++i)
    {
        float start_radian = M_PI / 3 * i + (bPoint_top ? M_PI / 6 : 0);
        float end_radian = start_radian + M_PI / 3;

        CCPoint center = getPixelLocation (length, zeroPoint, bPoint_top);

        ccDrawColor4F (color.r, color.g, color.b, color.a);
        ccDrawLine (
            ccpAdd (ccp (cos (start_radian)*length, sin (start_radian)*length), center),
            ccpAdd (ccp (cos (end_radian)*length, sin (end_radian)*length), center)

        );
    }
}




cocos2d::CCPoint Hexagon::getPixelLocation (int length, CCPoint zeroPoint, bool bPoint_top)
{
    CCPoint center;
    float step = length* 1.5f;
    center.y = step *  y + zeroPoint.y;
    //speed it up
    static float C = cos (M_PI / 3);
    static float T = tan (2 * M_PI / 3);


    center.x = (step *y - step *x / C) / T + zeroPoint.x;
    return center;
}

Hexagon Hexagon::getHexagon (int length, CCPoint zeroPoint, CCPoint center)
{
    //speed it up
    static float C = cos (M_PI / 3);
    static float T = tan (2 * M_PI / 3);


    float step = length* 1.5f;
    float y = (center.y - zeroPoint.y) / step;
    float x = (((center.x - zeroPoint.x)*T - step* y)* (-C)) / step;
    return Hexagon (x, y);
}


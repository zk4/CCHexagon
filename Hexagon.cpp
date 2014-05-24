#include "Hexagon.h"
Hexagon Hexagon::directions[Hexagon::eDirection::COUNT] =
{
    { 0, 0 }, { 1, 0 }, { 1, 1 }, { 0, 1 },
    { -1, 0 }, { -1, -1 }, { 0, -1 }
};


int Hexagon::distance (Hexagon& h)
{
    return max (max (abs (q - h.q), abs (r - h.r)), abs (y() - h.y()));
}

Hexagon::Hexagon (int x_ /*= 0*/, int y_ /*= 0 */, ccColor4F color_ /*= ccc4f(1, 1, 1, 1)*/) :q (x_), r (y_), color (color_)
{
   
}

Hexagon::Hexagon (const Hexagon& h)
{
    *this = h;
}

Hexagon::eDirection Hexagon::Towards (const Hexagon& h) const
{
    bool bX = false, bY = false, bZ = false;
    Hexagon dir = *this - h;
    int aX = abs (dir.q);
    int aY = abs (dir.r);
    int aZ = abs (dir.y());
    if (aX > abs (dir.r))
    {
        if (aY > aZ)
        {
            if (dir.q)
                dir.q /= aX;
            if (dir.r)
                dir.r /= aY;
            
        }
        else
        {
            if (dir.q)
                dir.q /= aX;
            
            dir.r = 0;

        }
    }
    else
    {
        if (aX > aZ)
        {
            if (dir.q)
                dir.q /= aX;
            if (dir.r)
                dir.r /= aY;
            
        }
        else
        {
            if (dir.r)
                dir.r /= aY;
            
            dir.q = 0;

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
    center.y = step *  r + zeroPoint.y;
    //speed it up
    static float C = cos (M_PI / 3);
    static float T = tan (2 * M_PI / 3);


    center.x = (step *r - step *q / C) / T + zeroPoint.x;
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


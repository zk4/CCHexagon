#pragma  once
//  Created by ZK on 2014/5/23.

#include <algorithm>
#include <vector>
#include <iostream>

#include "cocos2d.h"
using namespace cocos2d;

using namespace std;
#define ZeroHexagon  Hexagon()
class  Hexagon
{
public:

    int x;
    int y;
    int z;
    ccColor4F color;

    enum eDirection
    {
        C,
        R,
        RT,
        LT,
        L,
        LB,
        RB,
        COUNT
    };
    static  Hexagon directions[eDirection::COUNT];


    Hexagon (const Hexagon& h);
    Hexagon (int x_ = 0, int y_ = 0,ccColor4F color = ccc4f (1, 1, 1, 1));
    void draw (int length, CCPoint zeroPoint , bool bPoint_top=true);
    int distance (Hexagon& h);
    Hexagon::eDirection Towards (const Hexagon& h)const ;
    Hexagon& Move (Hexagon::eDirection dir, int times=1);
    inline Hexagon operator- (const Hexagon& r) const
    {
        Hexagon p;
        p.x = x - r.x;
        p.y = y - r.y;
        p.z = z - r.z;
        return p;
    }

    inline Hexagon operator+ (const Hexagon& r) const
    {
        Hexagon p;
        p.x  =x+ r.x;
        p.y =y+ r.y;
        p.z =z+ r.z;
        return p;
    }
    inline Hexagon& operator+= (const Hexagon& r)
    {

        x += r.x;
        y += r.y;
        z += r.z;
        return *this;
    }
    inline Hexagon& operator-= (const Hexagon& r)
    {

        x -= r.x;
        y -= r.y;
        z -= r.z;
        return *this;
    }
    inline Hexagon& operator= (const Hexagon& r)
    {

        x = r.x;
        y = r.y;
        z = r.z;
        color=r.color;
        return *this;
    }
    inline Hexagon operator* (float r) const
    {

        Hexagon p;
        p.x = x * r;
        p.y = y * r;
        p.z = z * r;
        return p;
    }

    inline Hexagon operator/ (float r) const
    {
        Hexagon p;
        p.x = x / r;
        p.y = y / r;
        p.z = z / r;
        return p;
    }

    inline bool operator != (const Hexagon& a) const
    {
        return a.x != this->x || a.y != this->y || a.z != this->z;
    }

    inline bool operator == (const Hexagon& a) const
    {
        return a.x == this->x && a.y == this->y && a.z == this->z;
    }


    //for Set
    inline bool operator < (const Hexagon& a) const
    {
        return (a.x + a.y) < (this->x + this->y);

    }
    inline bool operator > (const Hexagon& a) const
    {
        return (a.x + a.y) > (this->x + this->y);

    }

    CCPoint getPixelLocation (int length, CCPoint zeroPoint, bool bPoint_top);
    static Hexagon getHexagon (int length, CCPoint zeroPoint, CCPoint center);
};

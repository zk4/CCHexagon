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

    float q;  //x in cub coordinate
    float r;  //z in cub coordinate

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
    static  Hexagon s_directions[eDirection::COUNT];



    Hexagon (const Hexagon& h);
    Hexagon (float x_ = 0, float y_ = 0, ccColor4F color = ccc4f (1, 1, 1, 1));
    inline float		y()const
    {
        return -q - r;
    };
    void				Draw (int length, CCPoint center);
    float				Distance (const Hexagon& h) const;
    Hexagon::eDirection Towards (const Hexagon& h)const ;
    Hexagon				Round() const;
    void				Integerilze();
    void				Normalize();
    Hexagon&			Move (Hexagon::eDirection dir, int times=1);

    inline int					ix() const
    {
        return std::round (q);
    };
    inline int					iz() const
    {
        return std::round (r);
    };
    inline int					iy() const
    {
        return std::round (-q - r);
    };
    inline Hexagon operator- (const Hexagon& h) const
    {
        Hexagon p;
        p.q = q - h.q;
        p.r = r - h.r;

        return p;
    }

    inline Hexagon operator+ (const Hexagon& h) const
    {
        Hexagon p;
        p.q  =q+ h.q;
        p.r =r+ h.r;

        return p;
    }
    inline Hexagon& operator+= (const Hexagon& h)
    {

        q += h.q;
        r += h.r;

        return *this;
    }
    inline Hexagon& operator/= (const float scale)
    {
        assert (scale != 0);
        if (scale!=0)
        {
            q /= scale;
            r /= scale;
        }

        return *this;
    }
    inline Hexagon& operator*= (const float scale)
    {

        q *= scale;
        r *= scale;

        return *this;
    }
    inline Hexagon& operator-= (const Hexagon& h)
    {

        q -= h.q;
        r -= h.r;

        return *this;
    }
    inline Hexagon& operator= (const Hexagon& h)
    {

        q = h.q;
        r = h.r;

        color=h.color;
        return *this;
    }
    inline Hexagon operator* (float f) const
    {

        Hexagon p;
        p.q = q * f;
        p.r = r * f;

        return p;
    }

    inline Hexagon operator/ (float f) const
    {
        assert (f != 0);
        Hexagon p;

        if (f!=0)
        {
            p.q = q / f;
            p.r = r / f;
        }

        return p;
    }

    inline bool operator != (const Hexagon& a) const
    {
        return ! (*this == a);
    }

    inline bool operator == (const Hexagon& a) const
    {
        return (abs (a.q- this->q)<0.001f) && (abs (a.r - this->r)<0.001f) ;
    }

};

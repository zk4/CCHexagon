#pragma  once
//  Created by ZK on 2014/5/23.

#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
#include <float.h>

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
    Hexagon (float q_ = 0, float r_ = 0, ccColor4F color = ccc4f (1, 1, 1, 1));
    inline float		y()const
    {
        return -q - r;
    };
    void				Draw (int length, CCPoint center);
    float				Distance (const Hexagon& h) const;
    Hexagon::eDirection Towards (const Hexagon& h)const ;
    Hexagon				Mirror (const Hexagon& mirror_hex)const;
    Hexagon				Round() const;
    void				Integerilze();
    void				Normalize();
    Hexagon&			Move (Hexagon::eDirection dir, int times=1);
    Hexagon&			Color (const ccColor4F& color);
    inline int					ix() const
    {
        return round (q);
    };
    inline int					iz() const
    {
        return round (r);
    };
    inline int					iy() const
    {
        return round (-q - r);
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
        return (abs (a.q - this->q)<FLT_EPSILON) && (abs (a.r - this->r)<FLT_EPSILON);
    }

    inline bool operator < (const Hexagon& a) const
    {
        return this< &a;
    }

    inline bool operator >  (const Hexagon& a) const
    {
        return this > &a;
    }
};

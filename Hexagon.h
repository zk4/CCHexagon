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
    void				Integerlize();
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
    inline Hexagon operator- (const Hexagon& h_) const
    {
        Hexagon p;
        p.q = q - h_.q;
        p.r = r - h_.r;

        return p;
    }

    inline Hexagon operator+ (const Hexagon& h_) const
    {
        Hexagon p;
        p.q  =q+ h_.q;
        p.r =r+ h_.r;

        return p;
    }
    inline Hexagon& operator+= (const Hexagon& h_)
    {

        q += h_.q;
        r += h_.r;

        return *this;
    }
    inline Hexagon& operator/= (const float f_)
    {
        assert (f_ != 0);
        if (f_!=0)
        {
            q /= f_;
            r /= f_;
        }

        return *this;
    }
    inline Hexagon& operator*= (const float f_)
    {

        q *= f_;
        r *= f_;

        return *this;
    }
    inline Hexagon& operator-= (const Hexagon& h_)
    {

        q -= h_.q;
        r -= h_.r;

        return *this;
    }
    inline Hexagon& operator= (const Hexagon& h_)
    {

        q = h_.q;
        r = h_.r;

        color=h_.color;
        return *this;
    }
    inline Hexagon operator* (float f_) const
    {

        Hexagon p;
        p.q = q * f_;
        p.r = r * f_;

        return p;
    }

    inline Hexagon operator/ (float f_) const
    {
        assert (f_ != 0);
        Hexagon p;

        if (f_!=0)
        {
            p.q = q / f_;
            p.r = r / f_;
        }

        return p;
    }

    inline bool operator != (const Hexagon& h_) const
    {
        return ! (*this == h_);
    }

    inline bool operator == (const Hexagon& h_) const
    {
        return (abs (h_.q - this->q)<FLT_EPSILON) && (abs (h_.r - this->r)<FLT_EPSILON);
    }

    inline bool operator < (const Hexagon& h_) const
    {
        return this->q < h_.q || ((this->q == h_.q)  && this->r < h_.r);
    }


};

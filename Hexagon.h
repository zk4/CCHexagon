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
    static  Hexagon directions[eDirection::COUNT];
	void interilze();
	float y()const { return -q - r; };
	
    Hexagon (const Hexagon& h);
	Hexagon(float x_ = 0, float y_ = 0, ccColor4F color = ccc4f(1, 1, 1, 1));
    
	void draw(int length, CCPoint center);
	float distance(Hexagon& h);
    Hexagon::eDirection Towards (const Hexagon& h)const ;
	Hexagon round();
    Hexagon& Move (Hexagon::eDirection dir, int times=1);

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
        Hexagon p;
        p.q = q / f;
        p.r = r / f;
       
        return p;
    }

    inline bool operator != (const Hexagon& a) const
    {
        return a.q != this->q || a.r != this->r || a.y() != this->y();
    }

    inline bool operator == (const Hexagon& a) const
    {
        return a.q == this->q && a.r == this->r ;
    }
 
   /* CCPoint getPixelLocation (int length, CCPoint zeroPoint );
    static Hexagon getHexagon (int length, CCPoint zeroPoint, CCPoint center);
	*/
};

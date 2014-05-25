#pragma  once
//  Created by ZK on 2014/5/23.

#include "Hexagon.h"
#include "cocos2d.h"
#include <vector>
using namespace std;

struct HexCoordinate
{
	cocos2d::CCPoint zeroPoint;
	float length;
    vector<Hexagon>  hexagones;

	HexCoordinate(float length_=20, cocos2d::CCPoint zeroPoint_ = CCPointZero);
    void draw();
	cocos2d::CCPoint hex2ccp(  Hexagon  h) const;
	Hexagon ccpToHex(  cocos2d::CCPoint  p);

};



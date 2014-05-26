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
    HexCoordinate (float length_=20, cocos2d::CCPoint zeroPoint_ = CCPointZero);

    void				draw	      ();
    cocos2d::CCPoint	Hex2CCP       (Hexagon  h) const;
    Hexagon				CCP2Hex       (cocos2d::CCPoint  p);
    bool                Find          (const Hexagon& target)const;

    //make factory
    void                MakeRect      (int width, int height, const Hexagon& lb, ccColor4F color  = ccc4f (1, 1, 1, 1) );
    void                MakeLine      (const Hexagon& start, const Hexagon& end, ccColor4F color = ccc4f (1, 1, 1, 1));
    void                InterSect     (const vector<Hexagon>& src);
    void                MakeCross	  (int radius, const Hexagon& center, ccColor4F color = ccc4f (1, 1, 1, 1));
    void                MakeRingHexes (int inner, int outter, const Hexagon& center, ccColor4F color = ccc4f (1, 1, 1, 1));
    void                MakeRingHex   (int radius, const Hexagon& center, ccColor4F color = ccc4f (1, 1, 1, 1));
    void                MakeSolidHex  (int radius, const Hexagon& center, ccColor4F color = ccc4f (1, 1, 1, 1));
};



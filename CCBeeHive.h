#pragma  once
//  Created by ZK on 2014/5/23.


#include "cocos2d.h"
#include "HexCoordinate.h"
using namespace cocos2d;
struct CCBeeHive
{

    static void   MakeHexagons (int radius, const Hexagon& center, vector<Hexagon>& hexagons, ccColor4F color = ccc4f (1, 1, 1, 1));
    static void   MakeRing (int radius, const Hexagon& center, vector<Hexagon>& ring, ccColor4F color = ccc4f (1, 1, 1, 1));
    static void   MakeRings (int inner, int outter, const Hexagon& center, vector<Hexagon>& rings, ccColor4F color = ccc4f (1, 1, 1, 1));
    static void   MakeCross (int radius, const Hexagon& center, vector<Hexagon>& cross, ccColor4F color = ccc4f (1, 1, 1, 1));
	static void   MakeLine (Hexagon& start, Hexagon& end, vector<Hexagon>& line, ccColor4F color = ccc4f(1, 1, 1, 1));
    static void   MakeIntersectRange (int r, const Hexagon& center, vector<Hexagon>& des, vector<Hexagon>& range, ccColor4F color = ccc4f (1, 1, 1, 1));
    static void   InterSect (vector<Hexagon>& des, vector<Hexagon>& src, vector<Hexagon>& out, ccColor4F color = ccc4f (1, 1, 1, 1));
    static bool	  Find (const vector<Hexagon>& src, const Hexagon& target);

};

#pragma  once
//  Created by ZK on 2014/5/23.

#include "Hexagon.h"
#include "cocos2d.h"
#include <vector>
using namespace std;
using namespace cocos2d;
struct Hexagones
{
    CCPoint zeroPoint;
    int length;
    bool bPoint_top;

    vector<Hexagon>  hexagones;
    void draw();
    Hexagones (int length_,  CCPoint zeroPoint_ = CCPointZero,bool bPoint_top=true );

    int Contains (CCPoint& pos);


};

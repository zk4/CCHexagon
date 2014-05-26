#include "HelloWorldScene.h"
#include "Hexagon.h"
#include "BeeHive.h"

USING_NS_CC;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();

    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild (layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if (!CCLayer::init())
    {
        return false;
    }
    CCSize s = CCDirector::sharedDirector()->getWinSize();

    field.zeroPoint = ccp (s.width / 2, s.height / 2);
    line.zeroPoint = ccp (s.width / 2, s.height / 2);
    HexCoordinate h;
    BeeHive::MakeRingHex (1, ZeroHexagon, h.hexagones, ccc4f (0, 1, 1, 1));
    //test direction
    for (auto&a :h.hexagones )
    {
        CCLOG ("0,0 ->%f,%f direction is %d\n",a.q,a.r, ZeroHexagon.Towards (a));
    }



    field.MakeLine (Hexagon (-15, 10), Hexagon (8, -15), ccc4f (1, 0, 0, 1));
    field.MakeCross (3, Hexagon (10, 10),   ccc4f (1, 1, 0, 1));
    field.MakeSolidHex (3, Hexagon (-10, 10),   ccc4f (1, 0, 1, 1));
    field.MakeRingHex (3, Hexagon (-10, -10),   ccc4f (0, 1, 1, 1));
    field.MakeRingHexes (3, 4, Hexagon (10, -10),   ccc4f (0, 0, 1, 1));
    field.MakeRect (10, 5, Hexagon (24, -10),   ccc4f (1, 0, 0.5, 1));
    //behind

    field.MakeRect2 (11, 7, Hexagon (5, -10), ccc4f (1, 0, 0.5, 1));
    // HexCoordinate for_intersect;
    // for_intersect.MakeRect (11, 7, Hexagon (5, -10), ccc4f (1, 0, 0.5, 1));
    /*field.InterSect (for_intersect.hexagones);
    field.hexagones.push_back (Hexagon (15, 15, ccc4f (0.5, 1, 0, 1)));*/

    setTouchMode (kCCTouchesOneByOne);
    return true;
}



void HelloWorld::draw()
{
    CCLayer::draw();

    field.draw();
    line.draw();

}

HelloWorld::HelloWorld() :field (10), line (10)
{

}

void HelloWorld::ccTouchMoved (CCTouch *pTouch, CCEvent *pEvent)
{
    line.hexagones.erase (line.hexagones.begin() + 1, line.hexagones.end());


    Hexagon h = field.CCP2Hex (this->convertTouchToNodeSpace (pTouch));

    h.Integerilze();
    line.MakeLine (line.hexagones[0], h, ccc4f (1, 0.5, 0.5, 1));

}



bool HelloWorld::ccTouchBegan (CCTouch *pTouch, CCEvent *pEvent)
{
    Hexagon h = line.CCP2Hex (this->convertTouchToNodeSpace (pTouch));
    h.color = ccc4f (1, 0, 1, 1);
    h.Integerilze();
    line.hexagones.push_back (h);

    return true;
}

void HelloWorld::onEnter()
{
    CCLayer::onEnter();
    setTouchEnabled (true);
}

void HelloWorld::ccTouchEnded (CCTouch *pTouch, CCEvent *pEvent)
{
    line.hexagones.clear();
}

void HelloWorld::ccTouchCancelled (CCTouch *pTouch, CCEvent *pEvent)
{
    line.hexagones.clear();
}





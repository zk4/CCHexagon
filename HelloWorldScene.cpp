#include "HelloWorldScene.h"
#include "Hexagon.h"
#include "CCBeeHive.h"

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

	HexCoordinate h;
	CCBeeHive::MakeRing(1, ZeroHexagon, h.hexagones, ccc4f(0, 1, 1, 1));
	//test direction
	for (auto&a :h.hexagones )
	{
		CCLOG("0,0 ->%f,%f direction is %d\n",a.q,a.r, ZeroHexagon.Towards(a));
	}
	


	CCBeeHive::MakeLine(Hexagon(-15, 10), Hexagon( 15,-15), field.hexagones,ccc4f(1,0,0,1));
	CCBeeHive::MakeCross(3, Hexagon(10, 10), field.hexagones, ccc4f(1, 1, 0, 1));
	CCBeeHive::MakeHexagons(3, Hexagon(-10, 10), field.hexagones, ccc4f(1, 0, 1, 1));
	CCBeeHive::MakeRing(3, Hexagon(-10, -10), field.hexagones, ccc4f(0, 1, 1, 1));
	CCBeeHive::MakeRings(3, 4, Hexagon(10, -10), field.hexagones, ccc4f(0, 0, 1, 1));

	//behind 
	field.hexagones.push_back(Hexagon(15, 15, ccc4f(0.5, 1, 0, 1)));

    setTouchMode (kCCTouchesOneByOne);
    return true;
}
 


void HelloWorld::draw()
{
    CCLayer::draw();
 
    field.draw();
   
}

HelloWorld::HelloWorld() :field(10) 
{

}

void HelloWorld::ccTouchMoved (CCTouch *pTouch, CCEvent *pEvent)
{
   
	//touch_field.hexagones.clear();
	Hexagon h = field.ccpToHex(this->convertTouchToNodeSpace(pTouch));
	h.color = ccc4f(1, 0, 1, 1);
	h.Integerilze();
	field.hexagones.push_back(h);
}



bool HelloWorld::ccTouchBegan (CCTouch *pTouch, CCEvent *pEvent)
{
	//touch_field.hexagones.clear();
	Hexagon h = field.ccpToHex(this->convertTouchToNodeSpace(pTouch));
	h.color = ccc4f(1, 0, 1, 1);
	h.Integerilze();
	field.hexagones.push_back(h);
 
    return true;
}

void HelloWorld::onEnter()
{
    CCLayer::onEnter();
    setTouchEnabled (true);
}

void HelloWorld::ccTouchEnded (CCTouch *pTouch, CCEvent *pEvent)
{
  
}

void HelloWorld::ccTouchCancelled (CCTouch *pTouch, CCEvent *pEvent)
{

}





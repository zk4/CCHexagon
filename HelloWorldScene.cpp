#include "HelloWorldScene.h"

#include "Hexagon.h"

#include "CCBeeHive.h"

USING_NS_CC;
class BP :public Hexagon
{
public:
    inline BP& operator= (const BP& r)
    {
        q = r.q;
        return *this;
    }
    int q;

};
CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();

    // 'layer' is an autorelease object
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
    HexCoordinate fields1 (5);
    fields.zeroPoint = ccp (s.width / 2, s.height / 2);
    
	CCBeeHive::MakeLine(Hexagon(-5, 0), Hexagon( 0,5), fields.hexagones);
	 
	 // fields.hexagones.push_back({ -4, 0 });
	  //fields.hexagones.push_back({ -3, 0 });
	 // fields.hexagones.push_back({ -2, 0 });
	 // fields.hexagones.push_back({ -1, 0 });
	// fields.hexagones.push_back({ 0,  -1, ccc4f(1, 0, 0, 1) });
	// fields.hexagones.push_back({ 0,  1, ccc4f(1, 1, 0, 1) });
	//fields.hexagones.push_back({ 5, -5 });
	//fields.hexagones.push_back({ 5, 0 });
	//fields.hexagones.push_back({ 0, 5 });
	//fields.hexagones.push_back({ -5, 5 });
	//fields.hexagones.push_back({ -5, 0 });
	//for (auto & a : Hexagon::directions)
	//{
	//	fields.hexagones.push_back(a);
	//}
	
	
	/*CCBeeHive::MakeRing(1, ZeroHexagon, fields.hexagones);
	 for (auto & a :fields.hexagones)
	 {
		 CCLOG("pointe is x:%d,y:%d\n", a.x, a.y);
		 CCLOG("0 --> point is %d\n", ZeroHexagon.Towards(a));
	 }*/
	 
    // CCBeeHive::MakeIntersectRange (3, ZeroHexagon.Move (Hexagon::L), fields1.hexagones, fields.hexagones);
    setTouchMode (kCCTouchesOneByOne);
    return true;
}

CCPoint Hexagon2CCP (Hexagon& h)
{
    return ccp (0, 0);
}



void HelloWorld::draw()
{
    CCLayer::draw();
 
    fields.draw();
   
}

HelloWorld::HelloWorld() :fields(20) 
{

}

void HelloWorld::ccTouchMoved (CCTouch *pTouch, CCEvent *pEvent)
{
   
	//touch_field.hexagones.clear();
	Hexagon h = fields.PixToHex(this->convertTouchToNodeSpace(pTouch));
	h.color = ccc4f(1, 0, 1, 1);
	h.interilze();
	fields.hexagones.push_back(h);
}



bool HelloWorld::ccTouchBegan (CCTouch *pTouch, CCEvent *pEvent)
{
	//touch_field.hexagones.clear();
	Hexagon h = fields.PixToHex(this->convertTouchToNodeSpace(pTouch));
	h.color = ccc4f(1, 0, 1, 1);
	h.interilze();
	fields.hexagones.push_back(h);
	/*  int idx = fields.Contains (this->convertTouchToNodeSpace (pTouch));
	  if (idx != -1)
	  {

	  touch_field.hexagones.push_back (fields.hexagones[idx]);
	  touch_field.hexagones[0].color = ccc4f (1, 0, 1, 1);

	  }*/
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





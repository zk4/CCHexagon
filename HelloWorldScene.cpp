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
    Hexagones fields1 (5);
    fields.zeroPoint = ccp (s.width / 2, s.height / 2);
    touch_field.zeroPoint = ccp (s.width / 2, s.height / 2);
    CCBeeHive::MakeRings (3,5, ZeroHexagon, fields.hexagones);
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
    touch_field.draw();
}

HelloWorld::HelloWorld() :fields (20), touch_field (20)
{

}

void HelloWorld::ccTouchMoved (CCTouch *pTouch, CCEvent *pEvent)
{
    touch_field.hexagones.clear();
    int idx = fields.Contains (this->convertTouchToNodeSpace (pTouch));
    if (idx != -1)
    {

        touch_field.hexagones.push_back (fields.hexagones[idx]);
        touch_field.hexagones[0].color = ccc4f (0, 1, 0, 1);

    }


}



bool HelloWorld::ccTouchBegan (CCTouch *pTouch, CCEvent *pEvent)
{

    int idx = fields.Contains (this->convertTouchToNodeSpace (pTouch));
    if (idx != -1)
    {

        touch_field.hexagones.push_back (fields.hexagones[idx]);
        touch_field.hexagones[0].color = ccc4f (1, 0, 1, 1);

    }
    return true;
}

void HelloWorld::onEnter()
{

    CCLayer::onEnter();
    setTouchEnabled (true);
}

void HelloWorld::ccTouchEnded (CCTouch *pTouch, CCEvent *pEvent)
{
    touch_field.hexagones.clear();
}

void HelloWorld::ccTouchCancelled (CCTouch *pTouch, CCEvent *pEvent)
{
    touch_field.hexagones.clear();
}





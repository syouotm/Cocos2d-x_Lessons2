#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto *label = LabelTTF::create("Syou", "courier", 30);
    label->setPosition(visibleSize/2);
    addChild(label);
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [label](Touch *t ,Event *e){
        if (label->getBoundingBox().containsPoint(t->getLocation())) {
//            label->runAction(MoveBy::create(1, Vec2(-50,-50))->reverse());
//            label->runAction(Spawn::create(MoveBy::create(1, Point(100,100)),RotateBy::create(1, 360), NULL));
//            label->runAction(Sequence::create(MoveBy::create(1, Point(100,100)),RotateBy::create(1, 360),NULL));
            label->runAction(Sequence::create(MoveBy::create(1, Point(100,100)),RotateBy::create(1, 360),CallFunc::create([](){
                MessageBox("Action Complete", "Complete");
            }),NULL));
        }
        return false;
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, label);
//    label->runAction(RepeatForever::create(RotateBy::create(1, 180)));
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

//
//  ImageScene.cpp
//  L01StartScene
//
//  Created by 张翔 on 15/8/28.
//
//

#include "ImageScene.h"

Scene* ImageScene::createScene(){
    Scene* scene  = Scene::create();
    ImageScene* layer= ImageScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool ImageScene::init(){
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Sprite *s  = Sprite::create("HelloWorld.png");
    
    s->setAnchorPoint(Vec2(0.5,0.5));
    s->setPosition(visibleSize/2);
    addChild(s);
    return true;
}
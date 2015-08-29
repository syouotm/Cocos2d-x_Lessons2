//
//  ImageScene.h
//  L01StartScene
//
//  Created by 张翔 on 15/8/28.
//
//

#ifndef __L01StartScene__ImageScene__
#define __L01StartScene__ImageScene__

#include <stdio.h>
#include <cocos2d.h>

USING_NS_CC;

class ImageScene:public Layer{
public:
    static Scene* createScene();
    
    virtual bool init();
    
    CREATE_FUNC(ImageScene);
};

#endif /* defined(__L01StartScene__ImageScene__) */

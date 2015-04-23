#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::CCLayer
{
public:

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::CCObject* pSender);
    
    // implement the "static create()" method manually
    
    void menuBannerCallback(cocos2d::CCObject* pSender);
    
    void menuRequestInterstitialCallback(cocos2d::CCObject* pSender);
    
    void menuShowInterstitialCallback(cocos2d::CCObject* pSender);
    
    void menuInitInterstitalCallback(cocos2d::CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__

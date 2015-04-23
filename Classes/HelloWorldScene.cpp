#include "HelloWorldScene.h"
#include "DomobAd.h"

USING_NS_CC;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

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
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    CCLabelTTF* pLabel = CCLabelTTF::create("DomobAdSample", "Arial", 30);
    
    // position the label on the center of the screen
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
    
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    CCMenuItemLabel  * bannerLable=CCMenuItemLabel::create(CCLabelTTF::create("show banner", "Helvetica", 40),this, menu_selector(HelloWorld::menuBannerCallback));
    bannerLable->setPosition(ccp(winSize.width -200, winSize.height -80));
    
    
    CCMenuItemLabel  * closebanner=CCMenuItemLabel::create(CCLabelTTF::create("close banner", "Helvetica", 40),this, menu_selector(HelloWorld::menuRequestInterstitialCallback));
    closebanner->setPosition(ccp(winSize.width -200, winSize.height -150));
    
    
    CCMenuItemLabel  * showInterstitial=CCMenuItemLabel::create(CCLabelTTF::create("initInterstitial", "Helvetica", 40),this, menu_selector(HelloWorld::menuInitInterstitalCallback));
    showInterstitial->setPosition(ccp(winSize.width -250, winSize.height -270));
    
    CCMenuItemLabel  * closeInterstital=CCMenuItemLabel::create(CCLabelTTF::create("showInterstital", "Helvetica", 40),this, menu_selector(HelloWorld::menuShowInterstitialCallback));
    closeInterstital->setPosition(ccp(winSize.width -250, winSize.height -330));
    
    CCMenu * pMenu1 = CCMenu::create(bannerLable,closebanner,showInterstitial,closeInterstital,NULL);
    
    pMenu1->setPosition(ccp(100, 20));
    this->addChild(pMenu1, 1);
    
    return true;
}

void HelloWorld::menuBannerCallback(cocos2d::CCObject* pSender){
    DomobAd::showBanner();
}
void HelloWorld::menuRequestInterstitialCallback(cocos2d::CCObject* pSender){
    DomobAd::hideBanner();
}
void HelloWorld::menuShowInterstitialCallback(cocos2d::CCObject* pSender){
    DomobAd::showInterstitial();
}
void HelloWorld::menuInitInterstitalCallback(cocos2d::CCObject* pSender){
    DomobAd::initInterstitial();
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}

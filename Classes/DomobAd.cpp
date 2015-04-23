#include "DomobAd.h"
DomobAd::DomobAd(){}
DomobAd::~DomobAd(){}
void DomobAd::showBanner()
 {
	#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) 
	 JniMethodInfo showBanner;
	bool isHave = JniHelper::getStaticMethodInfo(showBanner,"cn/domob/ads/sample/DomobCocos2dSample","showBannerStatic","()V");
	   if (!isHave) {
	 CCLog("jni:showBannerStatic false");
	}else{
	
	showBanner.env->CallStaticVoidMethod(showBanner.classID, showBanner.methodID);
	}
	  #endif
}
 void DomobAd::hideBanner()
{
 	#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) 
	 JniMethodInfo hideBanner;
	bool isHave = JniHelper::getStaticMethodInfo(hideBanner,"cn/domob/ads/sample/DomobCocos2dSample","hideBannerStatic","()V");
	 if (!isHave) {
	 CCLog("jni:hideBannerStatic false");
	}else{
	CCLog("jni:hideBannerStatic true");
	
	hideBanner.env->CallStaticVoidMethod(hideBanner.classID, hideBanner.methodID);
	 }
	  #endif
}

void DomobAd::showInterstitial()
{
 	#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) 
	 JniMethodInfo showInterstitial;
	bool isHave = JniHelper::getStaticMethodInfo(showInterstitial,"cn/domob/ads/sample/DomobCocos2dSample","showInterstitialStatic","()V");
	 if (!isHave) {
	 CCLog("jni:showInterstitial false");
	}else{
	CCLog("jni:showInterstitial true");
	
	showInterstitial.env->CallStaticVoidMethod(showInterstitial.classID, showInterstitial.methodID);
	 }
	  #endif
}

void DomobAd::initInterstitial()
{
 	#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) 
	 JniMethodInfo initInterstitial;
	bool isHave = JniHelper::getStaticMethodInfo(initInterstitial,"cn/domob/ads/sample/DomobCocos2dSample","initInterstitialStatic","()V");
	 if (!isHave) {
	 CCLog("jni:initInterstitial false");
	}else{
	CCLog("jni:initInterstitial true");
	
	initInterstitial.env->CallStaticVoidMethod(initInterstitial.classID, initInterstitial.methodID);
	 }
	  #endif
}
	  
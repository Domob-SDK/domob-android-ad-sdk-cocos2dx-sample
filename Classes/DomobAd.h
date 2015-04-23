#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include <jni.h>
#include "platform/android/jni/JniHelper.h"
#include <android/log.h>
#include "cocos2d.h"
#endif
  using namespace cocos2d;
class DomobAd
{
	public:
	DomobAd();
	virtual ~DomobAd();
	static void showBanner();
	static void hideBanner();
	static void showInterstitial();
	static void initInterstitial();
 };
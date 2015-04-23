/****************************************************************************
Copyright (c) 2010-2011 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
 ****************************************************************************/
package cn.domob.ads.sample;

import org.cocos2dx.lib.Cocos2dxActivity;
import org.cocos2dx.lib.Cocos2dxGLSurfaceView;

import cn.domob.android.ads.AdEventListener;
import cn.domob.android.ads.AdView;
import cn.domob.android.ads.InterstitialAd;
import cn.domob.android.ads.InterstitialAdListener;
import cn.domob.android.ads.AdManager.ErrorCode;

import android.annotation.SuppressLint;
import android.content.Context;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.view.View;
import android.widget.RelativeLayout;
import android.widget.Toast;

@SuppressLint("HandlerLeak")
public class DomobCocos2dSample extends Cocos2dxActivity {

	public static final String PUBLISHER_ID = "56OJyM1ouMGoaSnvCK";
	public static final String InlinePPID = "16TLwebvAchksY6iO_8oSb-i";
	public static final String InterstitialPPID = "16TLwebvAchksY6iOa7F4DXs";

	private static Handler handler;
	private static RelativeLayout bannerLayout;
	private AdView adView;
	private InterstitialAd mInterstitialAd;

	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		bannerLayout = new RelativeLayout(this);
		RelativeLayout.LayoutParams parentLayputParams = new RelativeLayout.LayoutParams(
				RelativeLayout.LayoutParams.MATCH_PARENT, RelativeLayout.LayoutParams.MATCH_PARENT);
		this.addContentView(bannerLayout, parentLayputParams);

		handler = new Handler() {
			@Override
			public void handleMessage(Message msg) {
				switch (msg.what) {
				case 0:// showBanner
					if (bannerLayout.getChildCount() == 0) {
						adView = new AdView(DomobCocos2dSample.this, PUBLISHER_ID, InlinePPID);
						// set banner size
						adView.setAdSize(AdView.INLINE_SIZE_320X50);
						adView.setKeyword("game");
						adView.setUserGender("male");
						adView.setUserBirthdayStr("2000-08-08");
						adView.setUserPostcode("123456");
						adView.setAdEventListener(new AdEventListener() {
							@Override
							public void onAdOverlayPresented(AdView adView) {
								Log.i("DomobSDKCocos2d-xDemo", "overlayPresented");
							}

							@Override
							public void onAdOverlayDismissed(AdView adView) {
								Log.i("DomobSDKCocos2d-xDemo", "Overrided be dismissed");
							}

							@Override
							public void onAdClicked(AdView adView) {
								Log.i("DomobSDKCocos2d-xDemo", "onDomobAdClicked");
							}

							@Override
							public void onLeaveApplication(AdView adView) {
								Log.i("DomobSDKCocos2d-xDemo", "onDomobLeaveApplication");
							}

							@Override
							public Context onAdRequiresCurrentContext() {
								return null;
							}

							@Override
							public void onAdFailed(AdView adView, ErrorCode errorCode) {
								Log.i("DomobSDKCocos2d-xDemo", "onDomobAdFailed");
							}

							@Override
							public void onEventAdReturned(AdView adView) {
								Log.i("DomobSDKCocos2d-xDemo", "onDomobAdReturned");
							}
						});
						RelativeLayout.LayoutParams layoutParams = new RelativeLayout.LayoutParams(
								RelativeLayout.LayoutParams.WRAP_CONTENT, RelativeLayout.LayoutParams.WRAP_CONTENT);
						layoutParams.addRule(RelativeLayout.ALIGN_PARENT_BOTTOM, RelativeLayout.TRUE);
						layoutParams.addRule(RelativeLayout.CENTER_HORIZONTAL, RelativeLayout.TRUE);
						bannerLayout.addView(adView, layoutParams);
					} else {
						if (adView != null) {
							adView.setVisibility(View.VISIBLE);
							adView.requestRefreshAd();
						}
					}
					break;
				case 1:
					if (adView != null) {
						adView.setVisibility(View.GONE);
					}
					break;
				case 2:
					if (mInterstitialAd != null) {
						return;
					}
					mInterstitialAd = new InterstitialAd(DomobCocos2dSample.this, PUBLISHER_ID, InterstitialPPID);

					mInterstitialAd.setInterstitialAdListener(new InterstitialAdListener() {
						@Override
						public void onInterstitialAdReady() {
							Log.i("DomobSDKCocos2d-xDemo", "onAdReady");
							Toast.makeText(getApplicationContext(), "InterstitialAd init complete", Toast.LENGTH_SHORT)
									.show();
						}

						@Override
						public void onLandingPageOpen() {
							Log.i("DomobSDKCocos2d-xDemo", "onLandingPageOpen");
						}

						@Override
						public void onLandingPageClose() {
							Log.i("DomobSDKCocos2d-xDemo", "onLandingPageClose");
						}

						@Override
						public void onInterstitialAdPresent() {
							Log.i("DomobSDKCocos2d-xDemo", "onInterstitialAdPresent");
						}

						@Override
						public void onInterstitialAdDismiss() {
							// Request new ad when the previous interstitial ad
							// was closed.
							mInterstitialAd.loadInterstitialAd();
							Log.i("DomobSDKCocos2d-xDemo", "onInterstitialAdDismiss");
						}

						@Override
						public void onInterstitialAdFailed(ErrorCode errorCode) {
							Log.i("DomobSDKCocos2d-xDemo", "onInterstitialAdFailed");
						}

						@Override
						public void onInterstitialAdLeaveApplication() {
							Log.i("DomobSDKCocos2d-xDemo", "onInterstitialAdLeaveApplication");

						}

						@Override
						public void onInterstitialAdClicked(InterstitialAd interstitialAd) {
							Log.i("DomobSDKCocos2d-xDemo", "onInterstitialAdClicked");
						}
					});
					mInterstitialAd.loadInterstitialAd();
					break;
				case 3:
					if (mInterstitialAd != null) {
						if (mInterstitialAd.isInterstitialAdReady()) {
							mInterstitialAd.showInterstitialAd(DomobCocos2dSample.this);
						} else {
							Log.i("DomobSDKCocos2d-xDemo", "Interstitial Ad is not ready");
							mInterstitialAd.loadInterstitialAd();
						}
					} else {
						Log.i("DomobSDKCocos2d-xDemo", "Interstitial Ad is not init");
					}
					break;
				default:
					break;
				}
			}
		};
	}

	public Cocos2dxGLSurfaceView onCreateView() {
		Cocos2dxGLSurfaceView glSurfaceView = new Cocos2dxGLSurfaceView(this);
		// DomobCocos2dSample should create stencil buffer
		glSurfaceView.setEGLConfigChooser(5, 6, 5, 0, 16, 8);

		return glSurfaceView;
	}

	public static void showBannerStatic() {
		handler.sendEmptyMessage(0);
	}

	public static void hideBannerStatic() {
		handler.sendEmptyMessage(1);
	}

	public static void initInterstitialStatic() {
		handler.sendEmptyMessage(2);
	}

	public static void showInterstitialStatic() {
		handler.sendEmptyMessage(3);
	}

	static {
		System.loadLibrary("cocos2dcpp");
	}
}

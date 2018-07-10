//
//  OXMAdType.h
//  OpenXSDKCore
//
//  Created by Anton Morozov on 1/30/18.
//  Copyright © 2018 OpenX. All rights reserved.
//

#import <UIKit/UIKit.h>

#pragma mark - OXMAdTypeAction

typedef NSString * _Nonnull const OXMAdTypeAction NS_STRING_ENUM  NS_SWIFT_NAME(AdTypeValues);
static OXMAdTypeAction OXMAdTypeActionInterstitial NS_SWIFT_NAME(interstitial) = @"Interstitial";
static OXMAdTypeAction OXMAdTypeActionInterstitialVideo NS_SWIFT_NAME(interstitialVideo) = @"InterstitialVideo";
static OXMAdTypeAction OXMAdTypeActionBanner NS_SWIFT_NAME(banner) = @"Banner";
static OXMAdTypeAction OXMAdTypeActionMraid NS_SWIFT_NAME(mraid) = @"MRAID";
static OXMAdTypeAction OXMAdTypeActionVideo NS_SWIFT_NAME(video) = @"Video";
static OXMAdTypeAction OXMAdTypeActionNative NS_SWIFT_NAME(native) = @"Native";


#pragma mark - OXMAdType

NS_SWIFT_NAME(AdType)
@interface OXMAdType : NSObject

@property (nonatomic, assign, nonnull) OXMAdTypeAction action;
@property (nonatomic, assign) CGSize size;

- (nonnull NSString *)actionDescription;
+ (CGSize)initialSize;
+ (nullable OXMAdType *)fromString:(nonnull NSString *)str w:(NSInteger)w h:(NSInteger)h;

@end

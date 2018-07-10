//
//  OXMInterstitialController.h
//  OpenXSDKCore
//
//  Created by Scott McCoy on 2/22/18.
//  Copyright © 2018 OpenX. All rights reserved.
//

#import <Foundation/Foundation.h>
@import UIKit;

//Protocols
#import "OXMAdInterface.h"
#import "OXMAdViewManagerDelegate.h"
#import "OXMInterstitialControllerDelegate.h"
#import "OXMModalManagerDelegate.h"

@class OXMInterstitialDisplayProperties;
@class OXMLocationManager;
@class OXMModalManager;

@interface OXMInterstitialController : NSObject <OXMAdInterface, OXMAdViewManagerDelegate>

@property (weak, nullable) id <OXMInterstitialControllerDelegate> delegate;

@property (nonatomic, strong, nonnull) OXMAdViewManager *adViewManager;
@property (nonatomic, strong, nonnull) OXMLocationManager *locationManager;

//Interstitial-Specific:
@property (nonatomic, nullable) NSString* vastURL;
@property (nonatomic) BOOL forceMediatedInterstitial;
@property (nonatomic) BOOL isRewarded;
@property (nonatomic, strong, nonnull) OXMInterstitialDisplayProperties* interstitialDisplayProperties;

- (nonnull instancetype) initWithOXMServerConnection:(OXMServerConnection*)oxmServerConnection modalManager:(OXMModalManager*)modalManager oxmSDKConfiguration:(OXMSDKConfiguration*)oxmSDKConfiguration NS_DESIGNATED_INITIALIZER
NS_SWIFT_NAME(init(connection:modalManager:config:));

@end

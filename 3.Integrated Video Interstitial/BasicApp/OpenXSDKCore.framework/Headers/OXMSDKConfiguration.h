//
//  OXMSDKConfiguration.h
//  OpenXSDKCore
//
//  Created by Yuriy Velichko on 2/2/18.
//  Copyright © 2018 OpenX. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OXMLogLevel.h"

@interface OXMSDKConfiguration : NSObject

@property (class, readonly, nonnull) OXMSDKConfiguration *singleton;

//If set, controls the initial value of domain for all newly created OXMInterstitialControllers and OXMBannerViews. Useful if the same domain is in use throughout your app.
@property (nonatomic, copy, nullable) NSString *defaultDomain;

//If set, controls the initial value of adUnitID for all newly created OXMInterstitialControllers and OXMBannerViews. Useful if the same domain is in use throughout your app.
@property (nonatomic, copy, nullable) NSString *defaultAdUnitId;

//Controls the initial value of autoRefreshDelay for all newly created OXMInterstitialControllers and OXMBannerViews. Default is 60 seconds.
@property (nonatomic, assign) NSTimeInterval defaultAutoRefreshDelay;

//Controls how long each creative has to load before it is considered a failure.
@property (nonatomic, assign) NSTimeInterval creativeFactoryTimeout;

//If preRenderContent flag is set, controls how long the creative has to completely pre-render before it is considered a failure.
//Useful for video interstitials.
@property (nonatomic, assign) NSTimeInterval creativeFactoryTimeoutPreRenderContent;

//Controls whether to use OpenX's in-app browser or the Safari App for displaying ad clickthrough content.
@property (nonatomic, assign) BOOL useInternalClickthroughBrowser;

//If true, the SDK sends "af=3,5", indicating support for MRAID
@property (nonatomic, assign) BOOL sendMRAIDSupportParams;

//Controls the verbosity of OpenXSDKCore's internal logger. Options are (from most to least noisy) .info, .warn, .error and .none. Defaults to .info.
@property (nonatomic, assign) OXMLogLevel logLevel;

//If set to true, the output of OpenXSDKCore's internal logger is written to a text file. This can be helpful for debugging. Defaults to false.
@property (nonatomic, assign) BOOL debugLogFileEnabled;

//If true, the SDK will use https instead of http. Defaults to false.
@property (nonatomic, assign) BOOL secureRequestsEnabled;

//If true, the SDK will periodically try to listen for location updates in order to request location-based ads.
@property (nonatomic, assign) BOOL locationUpdatesEnabled;

//This function must be called in applicationDidFinishLaunchingWithOptions
//Intitializes location manager, gets the user agent and initializes OXMLog
+ (void)initializeSDK;

@end

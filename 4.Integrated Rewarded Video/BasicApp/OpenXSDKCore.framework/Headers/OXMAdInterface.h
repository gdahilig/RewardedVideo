//
//  OXMAdInterface.h
//  OpenXSDKCore
//
//  Created by Scott McCoy on 2/12/18.
//  Copyright © 2018 OpenX. All rights reserved.
//

#import "OXMAdConfigurationConstants.h"
@class OXMAdViewManager;
@class OXMUserParameters;
@class OXMAbstractCreative;
@class OXMModalManager;

#import "OXMInterstitialControllerDelegate.h"
@class OXMServerConnection;
@class OXMSDKConfiguration;

//This protocol is implemented by OXMInterstitialController and OXMBannerView.
//It would be preferable for it to be a superclass but OXMBannerView must inherit from UIView
//And ObjC does not support multiple inheritance.

@protocol OXMAdInterface
    @property (nonatomic, nullable) NSString *domain;
    @property (nonatomic, nullable) NSString *adUnitId;
    @property (nonatomic) OXMAdUnitIdentifierType adUnitIdentifierType;
    @property (nonatomic) NSTimeInterval connectionTimeoutInSeconds;
    @property (nonatomic, nonnull) OXMUserParameters* userParameters;
    @property (nonatomic) BOOL autoDisplayOnLoad;
    @property (nonatomic) BOOL autoDetectLocation __attribute__((deprecated("Please use OXMSDKConfiguration locationUpdatesEnabled:")));
    @property (nonatomic, nullable) NSString *flexAdSize;

    @property (nonatomic, nullable, readonly) NSString *revenueForNextCreative;
    @property (nonatomic, nullable) OXMAbstractCreative *currentCreative;

    @property (nonatomic, nonnull, readonly) OXMAdViewManager *adViewManager;

    - (nonnull instancetype) init;
    - (nonnull instancetype) initWithOXMServerConnection:(OXMServerConnection*)oxmServerConnection modalManager:(OXMModalManager*)modalManager oxmSDKConfiguration:(OXMSDKConfiguration*)oxmSDKConfiguration
    NS_SWIFT_NAME(init(connection:modalManager:config:));

    -(void) load;
    -(void) show;
@end

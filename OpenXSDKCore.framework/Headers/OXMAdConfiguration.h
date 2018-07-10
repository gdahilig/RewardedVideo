//
//  OXMAdConfiguration.h
//  OpenXSDKCore
//
//  Created by Yuriy Velichko on 2/2/18.
//  Copyright © 2018 OpenX. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "OXMUserParameters.h"
#import "OXMAdConfigurationConstants.h"

#pragma mark - OXMAdConfiguration

// AdConfiguration contains all the data needed to load an ad.
NS_SWIFT_NAME(AdConfiguration)
@interface OXMAdConfiguration : NSObject

#pragma mark Request

@property (nonatomic, assign) OXMAdUnitIdentifierType oxmAdUnitIdentifierType;
@property (nonatomic, assign) NSTimeInterval connectionTimeoutInSeconds;
@property (nonatomic, copy, nullable) NSString *flexAdSize;
@property (nonatomic, copy, nullable) NSString *auid;
@property (nonatomic, copy, nullable) NSString *domain;
@property (nonatomic, copy, nullable) NSString *vastURL;
@property (nonatomic, strong, nonnull) OXMUserParameters *userParameters;

#pragma mark Interstitial

/**
 Whether or not this ad configuration is intended to represent an intersitial ad.

 Setting this to @c YES will disable auto refresh.
 */
@property (nonatomic, assign) BOOL isInterstitial;
@property (nonatomic, assign) BOOL isRewarded;
@property (nonatomic, assign) BOOL forceMediatedInterstitial;

#pragma mark Auto Refresh

/**
 Delay (in seconds) for which to wait before performing an auto refresh.

 Note that this value is clamped between @c OXMAutoRefresh.AUTO_REFRESH_DELAY_MIN
 and @c OXMAutoRefresh.AUTO_REFRESH_DELAY_MAX.

 Also note that this will return @c nil if @c isInterstitial is set to @c YES.
 */
@property (nonatomic, copy, nullable) NSNumber *autoRefreshDelay;
@property (nonatomic, copy, nullable) NSNumber *autoRefreshMax;
@property (nonatomic, assign) NSUInteger numRefreshes;

- (nonnull instancetype)init;

@end

//
//  OXMMediatedAd.h
//  OpenXSDKCore
//
//  Created by Anton Morozov on 1/29/18.
//  Copyright © 2018 OpenX. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OXMTrackingEventDict.h"
#import "OXMAdCreativeProtocol.h"
#import "OXMAdType.h"

#pragma mark - OXMMediatedAdCreative

NS_SWIFT_NAME(MediatedAdCreative)
@interface OXMMediatedAdCreative : NSObject <OXMAdCreativeProtocol>

@property (nonatomic, copy, nullable) NSString *adCreativeMedia;
@property (nonatomic, copy, nullable) NSString *adCreativeMime;
@property (nonatomic, copy, nullable) NSString *adCreativeWidth;
@property (nonatomic, copy, nullable) NSString *adCreativeHeight;
@property (nonatomic, strong, nullable) NSArray<OXMTrackingRecord *> *adCreativeTracking; //TODO: This may be unnecessary if we go with ACJ instead of ARJ
@property (nonatomic, strong, nullable) OXMTrackingEventDict * adTemplateTracking;
@property (nonatomic, copy, nullable) NSString *adCreativeRevenue;
@property (nonatomic, strong, nullable) NSDictionary<NSString *, NSString *> *mediatedSDKparams;

- (nonnull instancetype) init NS_UNAVAILABLE;

- (nonnull instancetype)initWithAdCreativeMedia:(nonnull NSString *)adCreativeMedia
                                 adCreativeMime:(nonnull NSString *)adCreativeMime
                                adCreativeWidth:(nonnull NSString *)adCreativeWidth
                               adCreativeHeight:(nonnull NSString *)adCreativeHeight
                             adCreativeTracking:(nonnull NSArray<OXMTrackingRecord *> *)adCreativeTracking
                             adTemplateTracking:(nonnull OXMTrackingEventDict *)adTemplateTracking
                              adCreativeRevenue:(nullable NSString *)adCreativeRevenue
                              mediatedSDKparams:(nonnull NSDictionary<NSString *, NSString *> *)mediatedSDKparams NS_DESIGNATED_INITIALIZER;

@end


#pragma mark - OXMMediatedAd

NS_SWIFT_NAME(MediatedAd)
@interface OXMMediatedAd : NSObject

@property (nonatomic, strong, nullable) OXMAdType *adType;
@property (nonatomic, strong, nullable) NSArray <OXMMediatedAdCreative *> *mediatedAdCreatives;
@property (nonatomic, copy, nullable) NSString *adUnitID;
@property (nonatomic, copy, nullable) NSString *adMedium;
@property (nonatomic, copy, nullable) NSString *adTrackingTemplateURL;
@property (nonatomic, strong, nullable) OXMAdDetails *adDetails;
@property (nonatomic, assign) NSTimeInterval autoRefreshDelay;
@property (nonatomic, assign) NSUInteger autoRefreshMax;

- (nonnull instancetype)init NS_UNAVAILABLE;
- (nonnull instancetype)initWithAdType:(nonnull OXMAdType *)adType
                   mediatedAdCreatives:(nonnull NSArray <OXMMediatedAdCreative *> *)mediatedAdCreatives
                              adUnitID:(nonnull NSString *)adUnitID
                              adMedium:(nonnull NSString *)adMedium
                 adTrackingTemplateURL:(nonnull NSString *)adTrackingTemplateURL
                             adDetails:(nonnull OXMAdDetails *)adDetails
                      autoRefreshDelay:(NSTimeInterval)autoRefreshDelay
                        autoRefreshMax:(NSUInteger)autoRefreshMax NS_DESIGNATED_INITIALIZER;

@end

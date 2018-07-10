//
//  OXMMediatedAdResult.h
//  OpenXSDKCore
//
//  Created by Gene Dahilig on 4/17/18.
//  Copyright © 2018 OpenX. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OXMMediatedAd.h"
#import "OXMMediatedAdChain.h"

@interface OXMMediatedAdResult : NSObject
@property (nonatomic, strong, nullable) NSArray<OXMMediatedAd *> *ads;
@property (nonatomic, strong, nullable) OXMMediatedAdChain *chainSDKData;
@property (nonatomic, copy, nullable) NSNumber *autoRefreshDelay;
@property (nonatomic, copy, nullable) NSNumber *autoRefreshMax;

- (nonnull instancetype)init NS_UNAVAILABLE;
- (nonnull instancetype)initWithInitialAds:(nonnull NSArray<OXMMediatedAd *> *)initialAds
                              initialChain:(nonnull OXMMediatedAdChain *)initialChain
                          autoRefreshDelay:(nullable NSNumber *)autoRefreshDelay
                            autoRefreshMax:(nullable NSNumber *)autoRefreshMax NS_DESIGNATED_INITIALIZER;
@end

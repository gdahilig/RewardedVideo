//
//  OXMAdCreativeProtocol.h
//  OpenXSDKCore
//
//  Created by Anton Morozov on 1/30/18.
//  Copyright © 2018 OpenX. All rights reserved.
//

#import <Foundation/Foundation.h>

@class OXMTrackingRecord;

NS_SWIFT_NAME(AdCreative)
@protocol OXMAdCreativeProtocol

@property (nonatomic, copy, nonnull) NSString *adCreativeMedia;
@property (nonatomic, copy, nonnull) NSString *adCreativeMime;
@property (nonatomic, copy, nonnull) NSString *adCreativeWidth;
@property (nonatomic, copy, nonnull) NSString *adCreativeHeight;
@property (nonatomic, strong, nonnull) NSArray<OXMTrackingRecord *> *adCreativeTracking;
@property (nonatomic, strong, nonnull) NSDictionary<NSString *, NSString *> *mediatedSDKparams;

@end

//
//  OXMTrackingEventDict.h
//  OpenXSDKCore
//
//  Created by Anton Morozov on 1/29/18.
//  Copyright © 2018 OpenX. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OXMACJBasicTracking.h"

NS_SWIFT_NAME(TrackingEventDict)
@interface OXMTrackingEventDict : NSObject

#pragma mark - Object subscripting
- (nullable NSArray<OXMACJBasicTracking *> *)objectForKeyedSubscript:(nonnull OXMTrackingEventType)key;
- (void)setObject:(nonnull NSArray<OXMACJBasicTracking *> *)obj forKeyedSubscript:(nonnull OXMTrackingEventType)key;
- (nonnull NSDictionary<OXMTrackingEventType, NSArray<OXMACJBasicTracking *> *> *)dictionary;

@end

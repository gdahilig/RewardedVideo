//
//  OXMACJBasicTracking.h
//  OpenXSDKCore
//
//  Created by Anton Morozov on 1/26/18.
//  Copyright © 2018 OpenX. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OXMServerConnection.h"

@class OXMServerConnection;

#pragma mark - OXMTrackingEventType

typedef NSString * OXMTrackingEventType NS_STRING_ENUM  NS_SWIFT_NAME(TrackingEventType);
static OXMTrackingEventType _Nonnull const OXMTrackingEventTypeClick       NS_SWIFT_NAME(Click) = @"rc";
static OXMTrackingEventType _Nonnull const OXMTrackingEventTypeImpression  NS_SWIFT_NAME(Impression) = @"ri";
static OXMTrackingEventType _Nonnull const OXMTrackingEventTypeDefault     NS_SWIFT_NAME(Default) = @"rdf";
static OXMTrackingEventType _Nonnull const OXMTrackingEventTypeRequest     NS_SWIFT_NAME(Request) = @"rr";


#pragma mark - OXMACJBasicTracking

@class OXMAdDetails;

NS_SWIFT_NAME(ACJBasicTracking)
@interface OXMACJBasicTracking : NSObject

@property (nonatomic, strong, nullable) NSString *trackingURL;
@property (nonatomic, strong, nullable) NSString *trackingMedium;
@property (nonatomic, strong, nullable) OXMAdDetails *adDetails;
@property (nonatomic, assign, nullable) OXMTrackingEventType trackingEventType;

@property (class, readonly, nonnull) NSArray <NSString *> * allCases;

- (nonnull instancetype)init NS_UNAVAILABLE;
- (nonnull instancetype)initWithUrl:(nonnull NSString *)url
                             medium:(nonnull NSString *)medium
                          adDetails:(nonnull OXMAdDetails *)adDetails
                          eventType:(nonnull OXMTrackingEventType)eventType NS_DESIGNATED_INITIALIZER;

- (void)trackWithConnection:(nonnull OXMServerConnection *)connection args:(nonnull NSDictionary <NSString *, NSString *> *)args;
- (nonnull NSString *)formatTrackingURL;

@end

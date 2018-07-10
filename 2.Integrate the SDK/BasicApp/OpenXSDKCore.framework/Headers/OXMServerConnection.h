//
//  OXMServerConnection.h
//  OpenXSDKCore
//
//  Copyright © 2018 OpenX. All rights reserved.
//

#import <Foundation/Foundation.h>

@class OXMUserAgentService;
@class OXMServerResponse;

typedef void (^ OXMServerResponseCallback)(OXMServerResponse *_Nonnull);

@interface OXMServerConnection : NSObject

@property (class, nonatomic, strong, readonly, nonnull) NSString *userAgentHeaderKey;
@property (class, nonatomic, strong, readonly, nonnull) NSString *contentTypeKey;
@property (class, nonatomic, strong, readonly, nonnull) NSString *contentTypeVal;
@property (nonatomic, strong, nonnull) NSMutableArray<NSURLProtocol *> *protocolClasses;

+ (nonnull instancetype)singleton;
- (nonnull instancetype)init:(nonnull OXMUserAgentService *)userAgentService NS_SWIFT_NAME(init(userAgentService:));
- (void)fireAndForget:(nonnull NSString *) resourceURL;
- (void)head:(nonnull NSString *)resourceURL timeout:(NSTimeInterval)timeout callback:(nonnull OXMServerResponseCallback)callback;
- (void)get:(nonnull NSString *)resourceURL timeout:(NSTimeInterval)timeout callback:(nonnull OXMServerResponseCallback)callback;
- (void)post:(nonnull NSString *)resourceURL data:(nonnull NSData *)data timeout:(NSTimeInterval)timeout callback:(nonnull OXMServerResponseCallback)callback;

- (void)download:(nonnull NSString *)resourceURL callback:(nonnull OXMServerResponseCallback)callback;

@end

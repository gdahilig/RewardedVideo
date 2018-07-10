//
//  OXMError.h
//  OpenXSDKCore
//
//  Created by Yuriy Velichko on 1/24/18.
//  Copyright © 2018 OpenX. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString * const _Nonnull OXMErrorDomain;

typedef NS_ENUM(NSInteger, OXMErrorCode) {
    OXMErrorCodeGeneral = 700
};

//MARK: OXMErrorType
typedef NSString * _Nonnull const OXMErrorType NS_STRING_ENUM  NS_SWIFT_NAME(OxmErrorType);
static OXMErrorType OXMErrorTypeInvalidRequest  NS_SWIFT_NAME(InvalidRequest) = @"Invalid request";
static OXMErrorType OXMErrorTypeInternalError   NS_SWIFT_NAME(InternalError) = @"SDK internal error";
static OXMErrorType OXMErrorTypeInitError       NS_SWIFT_NAME(InitError) = @"Initialization error";
static OXMErrorType OXMErrorTypeServerError     NS_SWIFT_NAME(ServerError) = @"Server error";

@interface OXMError : NSError
@property (nonatomic, copy, nullable) NSString* message;

+ (nonnull OXMError *)errorWithDescription:(nonnull NSString *)description NS_SWIFT_NAME(error(description:));
- (nonnull instancetype)init: (nonnull NSString*)message NS_SWIFT_NAME(init(message:));

@end

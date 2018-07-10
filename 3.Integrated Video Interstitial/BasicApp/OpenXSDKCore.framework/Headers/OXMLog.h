//
//  OXMLog.h
//  OpenXSDKCore
//
//  Created by Yuriy Velichko on 1/22/18.
//  Copyright © 2018 OpenX. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OXMLogLevel.h"

@interface OXMLog : NSObject

@property (nonatomic, assign) OXMLogLevel logLevel;
@property (nonatomic, assign) BOOL logToFile;

@property (class, readonly) OXMLog * _Nonnull singleton;

+ (void)logObjC:(nonnull NSString *)message
       logLevel:(OXMLogLevel)logLevel
           file:(nullable const char *)file
           line:(unsigned int)line
       function:(nullable const char *)function;

+ (void)info:(nonnull NSString *)message;
+ (void)warn:(nonnull NSString *)message;
+ (void)error:(nonnull NSString *)message;
+ (void)always:(nonnull NSString *)message;
+ (void)whereAmI;

+ (void)info:(nonnull NSString *)message file:(nullable NSString *)file line:(unsigned int)line function:(nullable NSString *)function;
+ (void)warn:(nonnull NSString *)message file:(nullable NSString *)file line:(unsigned int)line function:(nullable NSString *)function;
+ (void)error:(nonnull NSString *)message file:(nullable NSString *)file line:(unsigned int)line function:(nullable NSString *)function;
+ (void)always:(nonnull NSString *)message file:(nullable NSString *)file line:(unsigned int)line function:(nullable NSString *)function;
+ (void)whereAmI:(nullable NSString *)file line:(unsigned int)line function:(nullable NSString *)function;

@end

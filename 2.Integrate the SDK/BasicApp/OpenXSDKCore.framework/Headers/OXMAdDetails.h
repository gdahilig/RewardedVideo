//
//  OXMAdDetails.h
//  OpenXSDKCore
//
//  Created by Yuriy Velichko on 2/26/18.
//  Copyright © 2018 OpenX. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface OXMAdDetails : NSObject

@property (nonatomic, copy, nullable) NSString *rawResponse;
@property (nonatomic, copy, nullable) NSString *transactionId;

- (nonnull instancetype)init NS_UNAVAILABLE;
- (nonnull instancetype)initWithRawResponse:(NSString *)rawResponse
                              transactionId:(NSString *)transactionId NS_DESIGNATED_INITIALIZER;

@end

//
//  OXMChainInfo.h
//  OpenXSDKCore
//
//  Created by Gene Dahilig on 2/12/18.
//  Copyright © 2018 OpenX. All rights reserved.
//

#import <Foundation/Foundation.h>

@class OXMAdConfiguration;
@class OXMMediatedAdResult;

@interface OXMChainInfo : NSObject

@property (nonatomic, copy, nullable) NSNumber *autoRefreshDelay;
@property (nonatomic, copy, nullable) NSNumber *autoRefreshMax;
@property (nonatomic, copy, nullable) NSString *rawResponse;

- (nonnull instancetype)initWithAdConfiguration:(nonnull OXMAdConfiguration *)adConfiguration
                               mediatedAdResult:(nonnull OXMMediatedAdResult *)mediatedAdResult;

@end

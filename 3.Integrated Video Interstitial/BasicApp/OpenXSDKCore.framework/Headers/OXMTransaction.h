//
//  OXMTransaction.h
//  OpenXSDKCore
//
//  Created by Gene Dahilig on 4/15/18.
//  Copyright © 2018 OpenX. All rights reserved.
//

#import <Foundation/Foundation.h>
@protocol OXMTransactionDelegate;

@class OXMServerConnection;
@class OXMModalManager;
@class OXMAdConfiguration;
@class OXMCreativeModel;
@class OXMAbstractCreative;
@class OXMAdDetails;
@class OXMChainInfo;

@interface OXMTransaction : NSObject

@property (nonatomic, strong, nonnull) OXMChainInfo *chainInfo;
@property (nonatomic, strong, nonnull) NSMutableArray<OXMAbstractCreative*> *creatives;
@property (nonatomic, strong, nonnull) NSArray<OXMCreativeModel *> *creativeModels;

@property (weak, atomic, nullable) id<OXMTransactionDelegate> delegate;

- (nonnull instancetype)init NS_UNAVAILABLE;
- (nonnull instancetype)initWithServerConnection:(nonnull OXMServerConnection *)connection
                                    modalManager:(nonnull OXMModalManager*)modalManager
                                 adConfiguration:(nonnull OXMAdConfiguration*)adConfiguration
                                          models:(nonnull NSArray<OXMCreativeModel *> *)creativeModels
                                       chainInfo:(nonnull OXMChainInfo*)chainInfo NS_DESIGNATED_INITIALIZER;

- (void)startCreativeMakers;
- (nullable OXMAdDetails *)getAdDetails;
- (nullable OXMAbstractCreative *)getFirstCreative;
- (nullable OXMAbstractCreative *)getCreativeAfter:(nonnull OXMAbstractCreative *)creative;
- (nullable NSString*)revenueForCreativeAfter:(nonnull OXMAbstractCreative *)creative;
@end

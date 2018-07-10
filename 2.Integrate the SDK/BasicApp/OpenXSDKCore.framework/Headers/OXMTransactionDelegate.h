//
//  OXMTransactionDelegate.h
//  OpenXSDKCore
//
//  Created by Gene Dahilig on 4/20/18.
//  Copyright © 2018 OpenX. All rights reserved.
//

@class OXMTransaction;
@class OXMAbstractCreative;
@class OXMChainInfo;

@protocol OXMTransactionDelegate
- (void)transactionReadyForDisplay:(nonnull OXMTransaction *)transaction;
- (void)transactionFailedToLoad:(nonnull OXMTransaction *)transaction error:(nonnull NSError *)error;
@end

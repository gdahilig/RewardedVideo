//
//  OXMAdLoadManagerDelegate.h
//  OpenXSDKCore
//
//  Created by Gene Dahilig on 2/5/18.
//  Copyright © 2018 OpenX. All rights reserved.
//

@class OXMAd;
@class OXMTransaction;

NS_SWIFT_NAME(OXMAdLoadManagerDelegate)
@protocol OXMAdLoadManagerDelegate

- (void) transactionReadyForDisplay: (nonnull OXMTransaction *) transaction;

- (void) failedToLoadTransaction: (nonnull OXMTransaction *) transaction error:(nonnull NSError *) error;
- (void) failedToLoadAd: (nonnull NSError *) error  NS_SWIFT_NAME(failedToLoadAd(_:));
@end

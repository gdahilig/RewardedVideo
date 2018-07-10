//
//  OXMCreativeViewDelegate.h
//  OpenXSDKCore
//
//  Created by Gene Dahilig on 2/15/18.
//  Copyright © 2018 OpenX. All rights reserved.
//

@class OXMAbstractCreative;

@protocol OXMCreativeViewDelegate
- (void)creativeDidComplete:(nonnull OXMAbstractCreative *)creative;
- (void)creativeDidDisplay:(nonnull OXMAbstractCreative *)creative;
- (void)creativeWasClicked:(nonnull OXMAbstractCreative *)creative;
- (void)creativeClickthroughDidClose:(nonnull OXMAbstractCreative *)creative;
- (void)creativeInterstitialDidClose:(nonnull OXMAbstractCreative *)creative;
- (void)creativeInterstitialDidLeaveApp:(nonnull OXMAbstractCreative *)creative;

// MRAID Only
- (void)creativeReadyToReimplant:(nonnull OXMAbstractCreative *)creative NS_SWIFT_NAME(creativeReadyToReimplant(_:));
- (void)creativeMraidDidCollapse:(nonnull OXMAbstractCreative *)creative;
- (void)creativeMraidDidExpand:(nonnull OXMAbstractCreative *)creative;
@end



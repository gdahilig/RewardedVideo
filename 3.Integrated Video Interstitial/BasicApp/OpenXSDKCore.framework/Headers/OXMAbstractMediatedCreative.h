//
//  OXMAbstractMediatedCreative.h
//  OpenXSDKCore
//
//  Created by Anton Morozov on 2/19/18.
//  Copyright © 2018 OpenX. All rights reserved.
//

#import "OXMAbstractCreative.h"

@interface OXMAbstractMediatedCreative : OXMAbstractCreative

@property (nonatomic, readonly, weak, nullable) UIViewController *viewControllerForView;

// Note, we're assuming here that a resolved mediated ad is also displayable. If that changes, this function will need to as well
- (void)setResolutionWasResolvedSuccessfully:(BOOL)resolved;
- (void)deployInterstitialFromRoot:(nonnull UIViewController*)rootViewController    NS_SWIFT_NAME(deployInterstitialFromRoot(_:));
- (void)creativeInterstitialDidClose;
- (void)creativeClickthroughDidClose;
- (void)creativeWasClicked;
@end

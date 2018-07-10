//
//  OXMBannerViewDelegate.h
//  OpenXSDKCore
//
//  Created by Scott McCoy on 2/12/18.
//  Copyright © 2018 OpenX. All rights reserved.
//

@class OXMBannerView;
@class OXMAdDetails;


@protocol OXMBannerViewDelegate

/// Must be implemented
- (UIViewController*)viewControllerForModalPresentation;

/// Called every time an ad had loaded and is ready for display
- (void)adDidLoad:(nonnull OXMBannerView*) oxmBannerView adDetails:(nonnull OXMAdDetails *)adDetails NS_SWIFT_NAME(adDidLoad(oxmBannerView:adDetails:));

/// Called whenever the load process fails to produce a viable ad
- (void)adDidFailToLoad:(nonnull OXMBannerView*) oxmBannerView error:(NSError * _Nonnull)error NS_SWIFT_NAME(adDidFailToLoad(oxmBannerView:error:));

/// Called after an ad has rendered to the device's screen
- (void)adDidDisplay:(nonnull OXMBannerView*) oxmBannerView NS_SWIFT_NAME(adDidDisplay(oxmBannerView:));

/// Called once an ad has finished displaying all of it's creatives
- (void)adDidComplete:(nonnull OXMBannerView*) oxmBannerView NS_SWIFT_NAME(adDidComplete(oxmBannerView:));

/// Called when the user clicks on an ad and a clickthrough is about to occur
- (void)adWasClicked:(nonnull OXMBannerView*) oxmBannerView NS_SWIFT_NAME(adWasClicked(oxmBannerView:));

/// Called when the user closes a clickthrough
- (void)adClickthroughDidClose:(nonnull OXMBannerView*) oxmBannerView NS_SWIFT_NAME(adClickthroughDidClose(oxmBannerView:));

/// Called when an ad causes the sdk to leave the app
- (void)adDidLeaveApplication:(nonnull OXMBannerView*) oxmBannerView NS_SWIFT_NAME(adDidLeaveApplication(oxmBannerView:));

/// Called when an mraid ad expands
- (void)adDidExpand:(nonnull OXMBannerView*) oxmBannerView NS_SWIFT_NAME(adDidExpand(oxmBannerView:));

/// Called when an mraid ad collapses
- (void)adDidCollapse:(nonnull OXMBannerView*) oxmBannerView NS_SWIFT_NAME(adDidCollapse(oxmBannerView:));
@end

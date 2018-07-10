//
//  OXMInterstitialControllerDelegate.h
//  OpenXSDKCore
//
//  Created by Scott McCoy on 2/22/18.
//  Copyright © 2018 OpenX. All rights reserved.
//

@class OXMInterstitialController;
@class OXMAdDetails;


@protocol OXMInterstitialControllerDelegate

/// Must be implemented
- (UIViewController*)viewControllerForModalPresentation;

/// Called every time an ad had loaded and is ready for display
- (void)adDidLoad:(nonnull OXMInterstitialController*) interstitialController adDetails:(nonnull OXMAdDetails *)adDetails
NS_SWIFT_NAME(adDidLoad(interstitialController:adDetails:));

/// Called whenever the load process fails to produce a viable ad
- (void)adDidFailToLoad:(nonnull OXMInterstitialController*) interstitialController error:(NSError * _Nonnull)error
NS_SWIFT_NAME(adDidFailToLoad(interstitialController:error:));

/// Called after an ad has rendered to the device's screen
- (void)adDidDisplay:(nonnull OXMInterstitialController*) interstitialController
NS_SWIFT_NAME(adDidDisplay(interstitialController:));

/// Called once an ad has finished displaying all of it's creatives
- (void)adDidComplete:(nonnull OXMInterstitialController*) interstitialController
NS_SWIFT_NAME(adDidComplete(interstitialController:));

/// Called when the user clicks on an ad and a clickthrough is about to occur
- (void)adWasClicked:(nonnull OXMInterstitialController*) interstitialController
NS_SWIFT_NAME(adWasClicked(interstitialController:));

/// Called when a user has closed an interstitial
- (void)adInterstitialDidClose:(nonnull OXMInterstitialController*) interstitialController
NS_SWIFT_NAME(adInterstitialDidClose(interstitialController:));

/// Called when the user closes a clickthrough
- (void)adClickthroughDidClose:(nonnull OXMInterstitialController*) interstitialController
NS_SWIFT_NAME(adClickthroughDidClose(interstitialController:));

/// Called when an ad causes the sdk to leave the app
- (void)adDidLeaveApplication:(nonnull OXMInterstitialController*) interstitialController
NS_SWIFT_NAME(adDidLeaveApplication(interstitialController:));

@end

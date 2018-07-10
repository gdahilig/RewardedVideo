//
//  OXMAdViewManagerDelegate.h
//  OpenXSDKCore
//
//  Created by Gene Dahilig on 2/14/18.
//  Copyright © 2018 OpenX. All rights reserved.
//

#import <Foundation/Foundation.h>

@class OXMAdDetails;
@class OXMAbstractCreative;
@class UIViewController;
@class OXMInterstitialDisplayProperties;

// This protocol defines the communication from the OXMAdViewManager to the OXMAdView
NS_SWIFT_NAME(OXMAdViewManagerDelegate)
@protocol OXMAdViewManagerDelegate

@required
- (nonnull UIViewController*) adViewManagerViewControllerForModalPresentation;

- (void) adLoaded: (nonnull OXMAdDetails*)oxmAdDetails
            NS_SWIFT_NAME(adLoaded(_:));
- (void) failedToLoad: (nonnull NSError*)error
            NS_SWIFT_NAME(failedToLoad(_:));
- (void) removeCreativeFromDisplay
            NS_SWIFT_NAME(removeCreativeFromDisplay());
- (void) adDidComplete
            NS_SWIFT_NAME(adDidComplete());
- (void) adDidDisplay
            NS_SWIFT_NAME(adDidDisplay());

- (void) creativeWasClicked: (nonnull OXMAbstractCreative *) creative
            NS_SWIFT_NAME(creativeWasClicked(_:));
- (void) creativeInterstitialDidClose: (nonnull OXMAbstractCreative *) creative
            NS_SWIFT_NAME(creativeInterstitialDidClose(_:));
- (void) creativeInterstitialDidLeaveApp: (nonnull OXMAbstractCreative *) creative
            NS_SWIFT_NAME(creativeInterstitialDidLeaveApp(_:));
- (void) creativeClickthroughDidClose: (nonnull OXMAbstractCreative *) creative
            NS_SWIFT_NAME(creativeClickthroughDidClose(_:));

// TODO: this is for reimplanting. Do it this way?
- (void) replaceWithCreative: (nonnull OXMAbstractCreative*) creative
            NS_SWIFT_NAME(replaceWithCreative(_:));

// MRAID events
- (void) creativeMraidDidCollapse: (nonnull OXMAbstractCreative *) creative
            NS_SWIFT_NAME(creativeMraidDidCollapse(_:));
- (void) creativeMraidDidExpand: (nonnull OXMAbstractCreative *) creative
            NS_SWIFT_NAME(creativeMraidDidExpand(_:));

@optional
//Only used by OXMBannerView
- (void) creativeReadyForImmediateDisplay:(nonnull OXMAbstractCreative*) creative
NS_SWIFT_NAME(creativeReadyForImmediateDisplay(_:));

//Only used by OXMInterstitialController
-(OXMInterstitialDisplayProperties*) interstitialDisplayProperties;


// Properties
@property (nonatomic, readonly) BOOL isCurrentlyDisplayingACreative;

@end

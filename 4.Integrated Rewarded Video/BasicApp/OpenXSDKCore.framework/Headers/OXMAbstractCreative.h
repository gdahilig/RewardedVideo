//
//  OXMAbstractCreative.h
//  OpenXSDKCore
//
//  Copyright © 2018 OpenX. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "OXMModalManagerDelegate.h"
#import "OXMCreativeViewDelegate.h"
@class OXMAbstractCreative;
@class OXMCreativeModel;
@class OXMInterstitialDisplayProperties;
@class OXMModalManager;

@protocol OXMCreativeResolutionDelegate
- (void)creativeReady:(nonnull OXMAbstractCreative *)creative;
- (void)creativeFailed:(nonnull NSError *)error;
@end


/**
 *  `OXMAbstractCreative`'s purpose is a bundling of a model and a view. It acts as an adapter between
 *  the view and the SDK, it's essentially the C in MVC.
 *
 *  All `Creatives` must conform to this protocol. Each creative has-a model which contains the
 *  creative info, and must implement a few methods for handling display of the creative.
 */
@interface OXMAbstractCreative : NSObject <OXMModalManagerDelegate>

@property (nonatomic, strong, nullable) OXMCreativeModel *oxmCreativeModel;
@property (nonatomic, strong, nullable) UIView *view;
@property (nonatomic, assign) BOOL clickthroughVisible;
@property (nonatomic, strong, readonly) OXMModalManager* modalManager;
@property (nonatomic, strong, nonnull) dispatch_queue_t dispatchQueue;
@property BOOL resolved;

// Indicates whether creative is opened with user action (expanded, clickthrough showed ...) or not
// Note that subclasses provide specific implementation.
@property (nonatomic, readonly)BOOL isOpened;

// The time that that the ad is displayed (i.e. before its refreshed).
// Note that subclasses provide specific implementation.
@property (nonatomic, readonly)NSNumber *displayInterval;

@property (nonatomic, weak, nullable) id<OXMCreativeResolutionDelegate> creativeResolutionDelegate;
@property (nonatomic, weak, nullable) id<OXMCreativeViewDelegate> creativeViewDelegate;
@property (nonatomic, weak) UIViewController* viewControllerForPresentingModals;

- (nonnull instancetype)init NS_UNAVAILABLE;
- (nonnull instancetype)initWithCreativeModel:(nonnull OXMCreativeModel *)oxmCreativeModel modalManager:(OXMModalManager*)modalManager NS_SWIFT_NAME(init(oxmCreativeModel:modalManager:)) NS_DESIGNATED_INITIALIZER;

- (void)setupView;
- (void)displayWithRootViewController:(nonnull UIViewController*)viewController;
- (void)showAsInterstitialFromRootViewController:(nonnull UIViewController*)viewController displayProperties:(OXMInterstitialDisplayProperties*)displayProperties;
- (BOOL)handleClickthrough:(nonnull NSURL*)url;

//Resolution
- (void)resolveSuccessfully;
- (void)failResolution:(nonnull NSError *)error;

@end

//
//  OXMAdViewManager.h
//  OpenXSDKCore
//
//  Created by Gene Dahilig on 2/14/18.
//  Copyright © 2018 OpenX. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OXMAdViewManagerDelegate.h"
#import "OXMAbstractCreative.h"
#import "OXMCreativeViewDelegate.h"
#import "OXMAdLoadManagerDelegate.h"

@class OXMAdLoadManager;
@class OXMAdLoadManagerDelegate;
@class OXMServerConnection;
@class OXMAdViewManagerDelegate;
@class OXMInterstitialDisplayProperties;


@interface OXMAdViewManager : NSObject <OXMCreativeViewDelegate, OXMAdLoadManagerDelegate>
@property (strong, nonnull) OXMAdLoadManager* adLoadManager;
@property (weak, nullable) id<OXMAdViewManagerDelegate> adViewManagerDelegate;
@property (assign) BOOL autoDisplayOnLoad;

- (nonnull instancetype) init NS_UNAVAILABLE;
- (nonnull instancetype) initWithServerConnection: (nonnull OXMServerConnection *) connection adLoadManager: (OXMAdLoadManager *) adLoadManager;

- (nullable NSString*) revenueForNextCreative;

- (void) show;

@end

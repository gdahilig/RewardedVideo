//
//  OXMBannerView.h
//  OpenXSDKCore
//
//  Created by Scott McCoy on 2/12/18.
//  Copyright © 2018 OpenX. All rights reserved.
//

#import <Foundation/Foundation.h>
@import UIKit;

//Protocols
#import "OXMAdInterface.h"
#import "OXMAdViewManagerDelegate.h"
#import "OXMBannerViewDelegate.h"
#import "OXMModalManagerDelegate.h"

@class OXMLocationManager;

@interface OXMBannerView : UIView <OXMAdInterface, OXMAdViewManagerDelegate>

@property (weak, nullable) id <OXMBannerViewDelegate> delegate;
@property (nonatomic, nonnull) OXMAdViewManager *adViewManager;
@property (nonatomic, strong, nonnull) OXMLocationManager *locationManager;

//Banner-Specific properties
@property (nonatomic) NSTimeInterval autoRefreshDelay;
@property (nonatomic) NSUInteger autoRefreshMax;
@property (nonatomic, readonly) NSUInteger numRefreshes;

@end

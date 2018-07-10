//
//  OXMCreativeModel.h
//  OpenXSDKCore
//
//  Created by Anton Morozov on 2/12/18.
//  Copyright © 2018 OpenX. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OXMTrackingEvent.h"
#import "OXMMediatedAd.h"

// OXMCreativeModel is visible to the publisher, and defines:
// --- duration indicates the time the creative will display for
// -------- A negative value indicates that this field has not been set
// -------- A value of 0 indicates an indefinite time
// -------- A postitive value indicates that this creative will be displayed for that many seconds
// --- width is the width of the creative, in pixels
// --- height is the height of the creative, in pixels
// --- creativeData is a String:String dictionary that contains all of the data needed to display the creative in a capable view
// -------- Example: An HTML creative would include key "html" with the html code for that creative as the value. A video creative would have a key "videourl" that would point to the asset to be played
// --- trackEvent functions take an enum or string, and cause the tracking URLs associated with those events to be fired
// --- forceMediatedInterstitial is used to tell mediated creatives if they should load in mediated mode
// --- baseURL is an optional base URL to use when loading in an OXMWebView
// @objc and public because it will be used by publishers to display an ad in their own view

@class OXMAdConfiguration;
@class OXMServerConnection;

@interface OXMCreativeModel : NSObject


// internal data
@property (nonatomic, copy, nullable) NSString *name;
@property (nonatomic, strong, nullable) OXMAdConfiguration *adConfiguration;
@property (nonatomic, copy, nullable) NSNumber *displayDurationInSeconds;
@property (nonatomic, assign) NSInteger width;
@property (nonatomic, assign) NSInteger height;
@property (nonatomic, assign) BOOL forceMediatedInterstitial;
@property (nonatomic, copy, nullable) NSString *html;
@property (nonatomic, copy, nullable) NSString *videoFileURL;
@property (nonatomic, copy, nullable) NSString *revenue;

@property (nonatomic, strong, nonnull) NSDictionary<NSString *, NSArray<NSString *> *> *trackingURLs;
@property (nonatomic, strong, nullable) OXMServerConnection *oxmServerConnection;

@property (nonatomic, copy, nullable) NSString *adTrackingTemplateURL;
@property (nonatomic, strong, nullable) OXMAdDetails *adDetails;
@property (nonatomic, strong, nullable) NSDictionary<NSString *, NSString *> *mediatedSDKparams;
@property (nonatomic, copy, nullable) NSString *clickThroughURL;
@property (nonatomic, assign) BOOL isCompanionAd;
@property (atomic, assign) bool hasCompanionAd;

/// Base URL used when loading in an OXMWebView
@property (nonatomic, strong, nullable) NSURL *baseURL;

- (nonnull instancetype)initWithOxmServerConnection:(nonnull OXMServerConnection *)oxmServerConnection
                                    adConfiguration:(nonnull OXMAdConfiguration *)adConfiguration;

- (void)trackEvent:(OXMTrackingEvent)event;

@end

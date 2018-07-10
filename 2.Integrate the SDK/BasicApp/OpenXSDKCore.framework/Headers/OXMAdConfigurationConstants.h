//
//  OXMAdConfigurationConstants.h
//  OpenXSDKCore
//
//  Created by Yuriy Velichko on 2/2/18.
//  Copyright © 2018 OpenX. All rights reserved.
//
#import <Foundation/Foundation.h>

#pragma mark - OXMAdUnitIdentifierType

#pragma warning - restore to OXMAdConfiguration
// AdUnitIdentifierType is an enum that determines the type of an AdIndentifier Object
typedef NS_ENUM(NSInteger, OXMAdUnitIdentifierType) {
    OXMAdUnitIdentifierTypeAuid,            //Ad Unit ID
    OXMAdUnitIdentifierTypeVast,            //Video
};

#pragma mark - OXMFlexAdSize

@interface OXMFlexAdSize : NSObject

@property (class, readonly, nonnull) NSString *Banner_320x50                           NS_SWIFT_NAME(Banner_320x50);
@property (class, readonly, nonnull) NSString *Banner_300x250                          NS_SWIFT_NAME(Banner_300x250);
@property (class, readonly, nonnull) NSString *Banner_320x50_300x250                   NS_SWIFT_NAME(Banner_320x50_300x250);
@property (class, readonly, nonnull) NSString *Interstitial_320x480                    NS_SWIFT_NAME(Interstitial_320x480);
@property (class, readonly, nonnull) NSString *Interstitial_300x250                    NS_SWIFT_NAME(Interstitial_300x250);
@property (class, readonly, nonnull) NSString *Interstitial_480x320                    NS_SWIFT_NAME(Interstitial_480x320);
@property (class, readonly, nonnull) NSString *Interstitial_768x1024                   NS_SWIFT_NAME(Interstitial_768x1024);
@property (class, readonly, nonnull) NSString *Interstitial_1024x768                   NS_SWIFT_NAME(Interstitial_1024x768);
@property (class, readonly, nonnull) NSString *Interstitial_320x480_300x250            NS_SWIFT_NAME(Interstitial_320x480_300x250);
@property (class, readonly, nonnull) NSString *Interstitial_480x320_300x250            NS_SWIFT_NAME(Interstitial_480x320_300x250);
@property (class, readonly, nonnull) NSString *Interstitial_768x1024_320x480_300x250   NS_SWIFT_NAME(Interstitial_768x1024_320x480_300x250);
@property (class, readonly, nonnull) NSString *Interstitial_1024x768_480x320_300x250   NS_SWIFT_NAME(Interstitial_1024x768_480x320_300x250);

@end



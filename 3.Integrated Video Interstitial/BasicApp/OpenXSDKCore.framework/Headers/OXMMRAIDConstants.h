//
//  OXMMRAIDConstants.h
//  OpenXSDKCore
//
//  Created by Anton Morozov on 1/24/18.
//  Copyright © 2018 OpenX. All rights reserved.
//

#import <Foundation/Foundation.h>

//MARK: MRAID Actions
typedef NSString * _Nonnull const OXMMRAIDAction NS_STRING_ENUM;
static OXMMRAIDAction OXMMRAIDActionOpen                            NS_SWIFT_NAME(Open) = @"open";
static OXMMRAIDAction OXMMRAIDActionExpand                          NS_SWIFT_NAME(Expand) = @"expand";
static OXMMRAIDAction OXMMRAIDActionResize                          NS_SWIFT_NAME(Resize) = @"resize";
static OXMMRAIDAction OXMMRAIDActionClose                           NS_SWIFT_NAME(Close) = @"close";
static OXMMRAIDAction OXMMRAIDActionStorePicture                    NS_SWIFT_NAME(StorePicture) = @"storepicture";
static OXMMRAIDAction OXMMRAIDActionCreateCalendarEvent             NS_SWIFT_NAME(CreateCalendarEvent) = @"createCalendarevent";
static OXMMRAIDAction OXMMRAIDActionPlayVideo                       NS_SWIFT_NAME(PlayVideo) = @"playVideo";
static OXMMRAIDAction OXMMRAIDActionLog                             NS_SWIFT_NAME(Log) = @"log";
static OXMMRAIDAction OXMMRAIDActionOnOrientationPropertiesChanged  NS_SWIFT_NAME(OnOrientationPropertiesChanged) = @"onOrientationPropertiesChanged";

// mraid enums and structs
typedef NSString * _Nonnull const OXMMRAIDPlacementType             NS_STRING_ENUM;
static OXMMRAIDPlacementType OXMMRAIDPlacementTypeInline            NS_SWIFT_NAME(Inline) = @"inline";
static OXMMRAIDPlacementType OXMMRAIDPlacementTypeInterstitial      NS_SWIFT_NAME(Interstitial) = @"interstitial";

typedef NSString * _Nonnull const OXMMRAIDFeature NS_STRING_ENUM;
static OXMMRAIDFeature OXMMRAIDFeatureSMS           = @"sms";
static OXMMRAIDFeature OXMMRAIDFeaturePhone         = @"tel";
static OXMMRAIDFeature OXMMRAIDFeatureCalendar      = @"calendar";
static OXMMRAIDFeature OXMMRAIDFeatureSavePicture   = @"storePicture";
static OXMMRAIDFeature OXMMRAIDFeatureInlineVideo   = @"inlineVideo";

//MARK: MRAID Parse Keys
@interface OXMMRAIDParseKeys : NSObject

@property (class, readonly, nonnull) NSString *X                   NS_SWIFT_NAME(X);
@property (class, readonly, nonnull) NSString *Y                   NS_SWIFT_NAME(Y);
@property (class, readonly, nonnull) NSString *WIDTH               NS_SWIFT_NAME(WIDTH);
@property (class, readonly, nonnull) NSString *HEIGHT              NS_SWIFT_NAME(HEIGHT);
@property (class, readonly, nonnull) NSString *X_OFFSET            NS_SWIFT_NAME(X_OFFSET);
@property (class, readonly, nonnull) NSString *Y_OFFSET            NS_SWIFT_NAME(Y_OFFSET);

@property (class, readonly, nonnull) NSString *ALLOW_OFFSCREEN     NS_SWIFT_NAME(ALLOW_OFFSCREEN);
@property (class, readonly, nonnull) NSString *CUSTOM_CLOSE_POS    NS_SWIFT_NAME(CUSTOM_CLOSE_POS);
@property (class, readonly, nonnull) NSString *USE_CUSTOM_CLOSE    NS_SWIFT_NAME(USE_CUSTOM_CLOSE);

@property (class, readonly, nonnull) NSString *FORCE_ORIENTATION   NS_SWIFT_NAME(FORCE_ORIENTATION);

@end


//MARK: MRAID Values
@interface OXMMRAIDValues : NSObject

@property (class, readonly, nonnull) NSString *LANDSCAPE           NS_SWIFT_NAME(LANDSCAPE);
@property (class, readonly, nonnull) NSString *PORTRAIT            NS_SWIFT_NAME(PORTRAIT);

@end


// MRAID Close Button Positions
@interface OXMMRAIDCloseButtonPosition : NSObject

@property (class, readonly, nonnull) NSString *BOTTOM_CENTER       NS_SWIFT_NAME(BOTTOM_CENTER);
@property (class, readonly, nonnull) NSString *BOTTOM_LEFT         NS_SWIFT_NAME(BOTTOM_LEFT);
@property (class, readonly, nonnull) NSString *BOTTOM_RIGHT        NS_SWIFT_NAME(BOTTOM_RIGHT);
@property (class, readonly, nonnull) NSString *CENTER              NS_SWIFT_NAME(CENTER);
@property (class, readonly, nonnull) NSString *TOP_CENTER          NS_SWIFT_NAME(TOP_CENTER);
@property (class, readonly, nonnull) NSString *TOP_LEFT            NS_SWIFT_NAME(TOP_LEFT);
@property (class, readonly, nonnull) NSString *TOP_RIGHT           NS_SWIFT_NAME(TOP_RIGHT);

@end


// MRAID Close Button Size
@interface OXMMRAIDCloseButtonSize : NSObject

@property (class, readonly) float WIDTH                             NS_SWIFT_NAME(WIDTH);
@property (class, readonly) float HEIGHT                            NS_SWIFT_NAME(HEIGHT);

@end

NS_SWIFT_NAME(MRAIDExpandProperties)
@interface OXMMRAIDExpandProperties : NSObject

@property (nonatomic, assign) NSInteger width;
@property (nonatomic, assign) NSInteger height;
@property (nonatomic, assign) BOOL useCustomClose;

- (nonnull instancetype)initWithWidth:(NSInteger)width height:(NSInteger)height useCustomClose:(BOOL)useCustomClose;

@end

NS_SWIFT_NAME(MRAIDResizeProperties)
@interface OXMMRAIDResizeProperties : NSObject

@property (nonatomic, assign) NSInteger width;
@property (nonatomic, assign) NSInteger height;
@property (nonatomic, copy, nullable) NSString *customClosePosition;
@property (nonatomic, assign) NSInteger offsetX;
@property (nonatomic, assign) NSInteger offsetY;
@property (nonatomic, assign) BOOL allowOffscreen;

- (nonnull instancetype)initWithWidth:(NSInteger)width
                               height:(NSInteger)height
                  customClosePosition:(nullable NSString *)customClosePosition
                              offsetX:(NSInteger)offsetX
                              offsetY:(NSInteger)offsetY
                       allowOffscreen:(BOOL)allowOffscreen;

@end

//MARK: OXMMRAIDConstants
@interface OXMMRAIDConstants : NSObject

@property (class, readonly, nonnull) NSString *mraidURLScheme;
@property (class, readonly, nonnull) NSArray <NSString *> *allCases;

@end

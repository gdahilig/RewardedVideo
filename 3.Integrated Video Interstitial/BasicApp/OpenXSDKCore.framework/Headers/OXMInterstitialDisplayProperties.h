//
//  OXMInterstitialDisplayProperties.h
//  OpenXSDKCore
//
//  Created by Anton Morozov on 2/21/18.
//  Copyright © 2018 OpenX. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, OXMInterstitalClosePosition) {
    OXMInterstitalClosePositionTopLeft      NS_SWIFT_NAME(topLeft),
    OXMInterstitalClosePositionTopCenter    NS_SWIFT_NAME(topCenter),
    OXMInterstitalClosePositionTopRight     NS_SWIFT_NAME(topRight),
    OXMInterstitalClosePositionCenter       NS_SWIFT_NAME(center),
    OXMInterstitalClosePositionBottomLeft   NS_SWIFT_NAME(bottomLeft),
    OXMInterstitalClosePositionBottomCenter NS_SWIFT_NAME(bottomCenter),
    OXMInterstitalClosePositionBottomRight  NS_SWIFT_NAME(bottomRight),
    OXMInterstitalClosePositionCustom       NS_SWIFT_NAME(custom)
};

@interface OXMInterstitialDisplayProperties : NSObject <NSCopying>

@property (nonatomic, assign) OXMInterstitalClosePosition closePosition;
@property (nonatomic, strong, nullable) UIImage *closeButtonImage;
@property (nonatomic, assign) CGRect customClosePosition;
@property (nonatomic, assign) NSTimeInterval closeDelay;
@property (nonatomic, assign) CGRect contentFrame;
@property (nonatomic, strong, nonnull) UIColor *contentViewColor;

@end

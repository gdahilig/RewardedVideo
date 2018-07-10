//
//  OXMWebViewDelegate.h
//  OpenXSDKCore
//
//  Created by Yuriy Velichko on 2/16/18.
//  Copyright © 2018 OpenX. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol OXMWebViewDelegate <NSObject>

- (void)webViewReadyToDisplay;
- (void)webViewFailedToLoadWithError:(nonnull NSError *)error
    NS_SWIFT_NAME(webViewFailedToLoad(_:));
- (void)webViewReceivedClickthroughLink:(nonnull NSURL *)url
    NS_SWIFT_NAME(webViewReceivedExternalLink(_:));
- (void)webViewReceivedMRAIDLink:(nonnull NSURL *)url
    NS_SWIFT_NAME(webViewReceivedMRAIDLink(_:));
- (void)webViewShouldClose;

@end


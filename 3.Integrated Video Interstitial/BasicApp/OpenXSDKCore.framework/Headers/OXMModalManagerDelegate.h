//
//  OXMModalManagerDelegate.h
//  OpenXSDKCore
//
//  Copyright © 2018 OpenX. All rights reserved.
//

@class OXMModalState;

@protocol OXMModalManagerDelegate
- (void)modalManagerDidFinishPop:(OXMModalState*)state;
- (void)modalManagerDidLeaveApp:(OXMModalState*)state;
@end


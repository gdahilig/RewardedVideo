//
//  OXMTrackingEvent.h
//  OpenXSDKCore
//
//  Created by Anton Morozov on 2/12/18.
//  Copyright © 2018 OpenX. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, OXMTrackingEvent) {
    OXMTrackingEventRequest = 0,
    OXMTrackingEventImpression,
    OXMTrackingEventClick,
    OXMTrackingEventOverlayClick,
    OXMTrackingEventCompanionClick, // split these or no?
    
    OXMTrackingEventPlay,
    OXMTrackingEventPause,
    OXMTrackingEventResume,
    OXMTrackingEventRewind,
    OXMTrackingEventSkip,
    
    OXMTrackingEventCreativeView,
    OXMTrackingEventStart,
    OXMTrackingEventFirstQuartile,
    OXMTrackingEventMidpoint,
    OXMTrackingEventThirdQuartile,
    OXMTrackingEventComplete,
    
    OXMTrackingEventMute,
    OXMTrackingEventUnmute,
    
    OXMTrackingEventFullscreen,
    OXMTrackingEventExitFullscreen,
    OXMTrackingEventExpand,
    OXMTrackingEventCollapse,
    
    OXMTrackingEventCloseLinear,
    OXMTrackingEventCloseOverlay,
    
    OXMTrackingEventAcceptInvitation,
    
    OXMTrackingEventError
};


@interface OXMTrackingEventDescription : NSObject

+ (nonnull NSString *)getDescription:(OXMTrackingEvent)event;

@end

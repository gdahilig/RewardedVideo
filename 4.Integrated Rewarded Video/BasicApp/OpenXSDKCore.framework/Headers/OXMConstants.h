//
//  OXMConstants.h
//  OpenXSDKCore
//
//  Created by Yuriy Velichko on 1/19/18.
//  Copyright © 2018 OpenX. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OXMMRAIDConstants.h"

typedef NSDictionary<NSString *, id> OXMJsonDictionary  NS_SWIFT_NAME(JsonDictionary);
typedef NSMutableDictionary<NSString *, id> OXMMutableJsonDictionary;

typedef NSDictionary<NSString *, NSString *> OXMStringDictionary;
typedef NSMutableDictionary<NSString *, NSString *> OXMMutableStringDictionary;

static NSString * const _Nonnull OXM_TRANSACTION_STATE_KEY      = @"ts";
static NSString * const _Nonnull OXM_TRACKING_URL_TEMPLATE      = @"record_tmpl";
static NSString * const _Nonnull OXM_ORIGINAL_ADUNIT_KEY        = @"OriginalAdUnitID";
static NSString * const _Nonnull OXM_MEDIATION_URL              = @"mediation_url";


typedef NS_ENUM(NSInteger, OXMLocationSourceValues) {
    OXMLocationSourceValuesGPS NS_SWIFT_NAME(GPS) = 1,                              //From Location Service
    OXMLocationSourceValuesIPAddress NS_SWIFT_NAME(IPAddress) = 2,                  //Unused by SDK
    OXMLocationSourceValuesUserRegistration NS_SWIFT_NAME(UserRegistration) = 3     //Supplied by Publisher
};


//MARK: MRAID
typedef NSString * const _Nonnull OXMMRAIDState NS_STRING_ENUM  NS_SWIFT_NAME(MRAIDState);
static OXMMRAIDState OXMMRAIDStateNotEnabled NS_SWIFT_NAME(NotEnabled) = @"not_enabled";
static OXMMRAIDState OXMMRAIDStateDefault NS_SWIFT_NAME(Default) = @"default";
static OXMMRAIDState OXMMRAIDStateExpanded NS_SWIFT_NAME(Expanded) = @"expanded";
static OXMMRAIDState OXMMRAIDStateHidden NS_SWIFT_NAME(Hidden) = @"hidden";
static OXMMRAIDState OXMMRAIDStateLoading NS_SWIFT_NAME(Loading) = @"loading";
static OXMMRAIDState OXMMRAIDStateResized NS_SWIFT_NAME(Resized) = @"resized";


//MARK: Tracking Supression Detection Strings
typedef NSString * const _Nonnull OXMTrackingPattern NS_STRING_ENUM  NS_SWIFT_NAME(TrackingPattern);
static OXMTrackingPattern OXMTrackingPatternRI NS_SWIFT_NAME(RI) = @"/ma/1.0/ri";
static OXMTrackingPattern OXMTrackingPatternRC NS_SWIFT_NAME(RC) = @"/ma/1.0/rc";
static OXMTrackingPattern OXMTrackingPatternRDF NS_SWIFT_NAME(RDF) = @"/ma/1.0/rdf";
static OXMTrackingPattern OXMTrackingPatternRR NS_SWIFT_NAME(RR) = @"/ma/1.0/rr";
static OXMTrackingPattern OXMTrackingPatternBO NS_SWIFT_NAME(BO) = @"/ma/1.0/bo";


//MARK: Query String Parameters
typedef NSString * const _Nonnull OXMParameterKeys NS_STRING_ENUM   NS_SWIFT_NAME(ParameterKeys);
static OXMParameterKeys OXMParameterKeysAUID NS_SWIFT_NAME(AUID) = @"auid";
static OXMParameterKeys OXMParameterKeysAGE NS_SWIFT_NAME(AGE) = @"age";
static OXMParameterKeys OXMParameterKeysAPP_STORE_URL NS_SWIFT_NAME(APP_STORE_URL) = @"url";
static OXMParameterKeys OXMParameterKeysCARRIER NS_SWIFT_NAME(CARRIER) = @"crr";
static OXMParameterKeys OXMParameterKeysDESIGNATED_MARKET_AREA NS_SWIFT_NAME(DESIGNATED_MARKET_AREA) = @"dma";
static OXMParameterKeys OXMParameterKeysETHNICITY NS_SWIFT_NAME(ETHNICITY) = @"eth";
static OXMParameterKeys OXMParameterKeysGENDER NS_SWIFT_NAME(GENDER) = @"gen";
static OXMParameterKeys OXMParameterKeysINCOME NS_SWIFT_NAME(INCOME) = @"inc";
static OXMParameterKeys OXMParameterKeysIP_ADDRESS NS_SWIFT_NAME(IP_ADDRESS) = @"ip";
static OXMParameterKeys OXMParameterKeysMARITIAL_STATUS NS_SWIFT_NAME(MARITIAL_STATUS) = @"mar";
static OXMParameterKeys OXMParameterKeysNETWORK_TYPE NS_SWIFT_NAME(NETWORK_TYPE) = @"net";
static OXMParameterKeys OXMParameterKeysOPEN_RTB NS_SWIFT_NAME(OPEN_RTB) = @"openrtb";
static OXMParameterKeys OXMParameterKeysUSER_ID NS_SWIFT_NAME(USER_ID) = @"xid";
static OXMParameterKeys OXMParameterKeysPUB_PROVIDED_PREFIX NS_SWIFT_NAME(PUB_PROVIDED_PREFIX) = @"c.";


//MARK: OXMLocationParamKeys
NS_SWIFT_NAME(LocationParamKeys)
@interface OXMLocationParamKeys : NSObject

@property (class, readonly, nonnull) NSString *Latitude                          NS_SWIFT_NAME(Latitude);
@property (class, readonly, nonnull) NSString *Longitude                         NS_SWIFT_NAME(Longitude);
@property (class, readonly, nonnull) NSString *Country                           NS_SWIFT_NAME(Country);
@property (class, readonly, nonnull) NSString *City                              NS_SWIFT_NAME(City);
@property (class, readonly, nonnull) NSString *State                             NS_SWIFT_NAME(State);
@property (class, readonly, nonnull) NSString *Zip                               NS_SWIFT_NAME(Zip);
@property (class, readonly, nonnull) NSString *LocationSource                    NS_SWIFT_NAME(LocationSource);

@end


//MARK: JSON Parse Keys
//TODO: Change Name
NS_SWIFT_NAME(ParseKey)
@interface OXMParseKey : NSObject

@property (class, readonly, nonnull) NSString *ADUNIT                            NS_SWIFT_NAME(ADUNIT);
@property (class, readonly, nonnull) NSString *HEIGHT                            NS_SWIFT_NAME(HEIGHT);
@property (class, readonly, nonnull) NSString *WIDTH                             NS_SWIFT_NAME(WIDTH);
@property (class, readonly, nonnull) NSString *HTML                              NS_SWIFT_NAME(HTML);
@property (class, readonly, nonnull) NSString *IMAGE                             NS_SWIFT_NAME(IMAGE);
@property (class, readonly, nonnull) NSString *MEDIATION_URL                     NS_SWIFT_NAME(MEDIATION_URL);
@property (class, readonly, nonnull) NSString *NETWORK_UID                       NS_SWIFT_NAME(NETWORK_UID);
@property (class, readonly, nonnull) NSString *REVENUE                           NS_SWIFT_NAME(REVENUE);
@property (class, readonly, nonnull) NSString *SSM_TYPE                          NS_SWIFT_NAME(SSM_TYPE);

@end


//MARK: OXMAutoRefresh
@interface OXMAutoRefresh : NSObject

@property (class, readonly) NSTimeInterval AUTO_REFRESH_DELAY_DEFAULT   NS_SWIFT_NAME(AUTO_REFRESH_DELAY_DEFAULT);
@property (class, readonly) NSTimeInterval AUTO_REFRESH_DELAY_MIN       NS_SWIFT_NAME(AUTO_REFRESH_DELAY_MIN);
@property (class, readonly) NSTimeInterval AUTO_REFRESH_DELAY_MAX       NS_SWIFT_NAME(AUTO_REFRESH_DELAY_MAX);

@end


//MARK: Other Time Intervals
@interface OXMTimeInterval : NSObject

@property (class, readonly) NSTimeInterval VAST_LOADER_TIMEOUT          NS_SWIFT_NAME(VAST_LOADER_TIMEOUT);
@property (class, readonly) NSTimeInterval AD_CLICKED_ALLOWED_INTERVAL  NS_SWIFT_NAME(AD_CLICKED_ALLOWED_INTERVAL);
@property (class, readonly) NSTimeInterval CONNECTION_TIMEOUT_DEFAULT   NS_SWIFT_NAME(CONNECTION_TIMEOUT_DEFAULT);
@property (class, readonly) NSTimeInterval CLOSE_DELAY_MIN              NS_SWIFT_NAME(CLOSE_DELAY_MIN);
@property (class, readonly) NSTimeInterval CLOSE_DELAY_MAX              NS_SWIFT_NAME(CLOSE_DELAY_MAX);
@property (class, readonly) NSTimeInterval FIRE_AND_FORGET_TIMEOUT      NS_SWIFT_NAME(FIRE_AND_FORGET_TIMEOUT);

@end


//TODO: Move to Video
@interface OXMTimeScale : NSObject

@property (class, readonly) NSInteger VIDEO_TIMESCALE                   NS_SWIFT_NAME(VIDEO_TIMESCALE);

@end


//MARK: OXMGeoLocationConstants
NS_SWIFT_NAME(GeoLocationConstants)
@interface OXMGeoLocationConstants : NSObject

@property (class, readonly) double DISTANCE_FILTER                      NS_SWIFT_NAME(DISTANCE_FILTER);

@end


//MARK: OXMConstants
@interface OXMConstants : NSObject

@property (class, readonly, nonnull) NSArray <NSString *> *supportedVideoMimeTypes           NS_SWIFT_NAME(supportedVideoMimeTypes);
@property (class, readonly, nonnull) NSArray <NSString *> *urlSchemesForAppStoreAndITunes    NS_SWIFT_NAME(urlSchemesForAppStoreAndITunes);
@property (class, readonly, nonnull) NSArray <NSString *> *urlSchemesNotSupportedOnSimulator NS_SWIFT_NAME(urlSchemesNotSupportedOnSimulator);
@property (class, readonly, nonnull) NSArray <NSString *> *urlSchemesNotSupportedOnClickthroughBrowser NS_SWIFT_NAME(urlSchemesNotSupportedOnClickthroughBrowser);

@end


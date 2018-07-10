//
//  OXMUserParameters.h
//  OpenXSDKCore
//
//  Created by Yuriy Velichko on 1/31/18.
//  Copyright © 2018 OpenX. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "OXMORTBBidRequest.h"

typedef NS_ENUM(NSInteger, OXMGender) {
    OXMGenderUnknown,
    OXMGenderMale,
    OXMGenderFemale,
    OXMGenderOther
};

typedef NS_ENUM(NSInteger, OXMMaritalStatus) {
    OXMMaritalStatusUnknown,
    OXMMaritalStatusSingle,
    OXMMaritalStatusMarried,
    OXMMaritalStatusDivorced
};

typedef NS_ENUM(NSInteger, OXMEthnicity) {
    OXMEthnicityAfrican_American = 0,
    OXMEthnicityAsian,
    OXMEthnicityHispanic,
    OXMEthnicityWhite,
    OXMEthnicityOther,
    OXMEthnicityUnknown
};

typedef NS_ENUM(NSInteger, OXMNetworkType) {
    OXMNetworkTypeOffline,
    OXMNetworkTypeWifi,
    OXMNetworkTypeCell,
    OXMNetworkTypeUnknown
};

typedef NS_ENUM(NSInteger, OXMLocationSource) {
    OXMLocationSourceGPS                = 1,
    OXMLocationSourceIPAddress          = 2,
    OXMLocationSourceUserRegistration   = 3,
};

@interface OXMUserParameters : NSObject

@property (nonatomic, strong, nonnull) OXMORTBBidRequest *oxmORTBBidRequest;

#pragma mark - User Information

/** Indicates the end-user's age, in years. */
@property (nonatomic, assign) NSInteger userAge;

/** Indicates the end-user's gender. */
@property (nonatomic, assign) OXMGender userGender;

/** Indicates the end-user's marital status. */
@property (nonatomic, assign) OXMMaritalStatus userMaritalStatus;

/** Indicates the end-user's ethnicity. */
@property (nonatomic, assign) OXMEthnicity userEthnicity;

/** Indicates the end-user's annual household income, in US Dollars (no commas (,) or periods (.)). */
@property (nonatomic, assign) NSInteger userAnnualIncomeInUS;

/** Indicates the customer-provided user ID, if different from the Device ID. */
@property (nonatomic, copy, nullable) NSString *userID;

#pragma mark - Application Information

/** Indicates the store URL for the mobile application. */
@property (nonatomic, copy, nullable) NSString *appStoreMarketURL;

#pragma mark - Location and connection information

/** For US locations, indicates the end-user's Designated Market Area. For example: dma=803. */
@property (nonatomic, copy, nullable) NSString *DMA
    NS_SWIFT_NAME(DMA);

#pragma mark - Network

/** The IP address of the carrier gateway. If this is not present, then OpenX retrieves it from the request header. */
@property (nonatomic, copy, nullable) NSString *IP
    NS_SWIFT_NAME(IP);

/** Mobile carrier - Defined by the Mobile Country Code (MCC) and Mobile Network Code (MNC), using the format: <MCC>-<MNC>. For example: crr=310-410. */
@property (nonatomic, copy, nullable) NSString *carrier;

/** Indicates the end-user's network connection type. For a wireless network, use net=wifi. */
@property (nonatomic, assign) OXMNetworkType networkType;

- (nonnull instancetype)init;

- (void)resetUserAge;
- (void)resetUserAnnualIncomeInUS;

/** This method allows to add new OpenX param by name and set needed value.
 If some ad call parameter doesn't exist in this SDK, you can always set it manually using this method.
 */
- (void)addParam:(nonnull NSString *)value withName:(nonnull NSString *)name;

/** Custom user parameters, a dictionary of name-value parameter pairs, where each param name will be prepended with ‘c.’.
 So for example parameter with name ‘xxx’ will be turned into ‘c.xxx’ when request will be sent.
 */
- (void)setCustomParams:(nullable NSDictionary<NSString *, NSString *> *)params;

/** A convenient method to add custom params one by one, here name will also be auto-prepended with ‘c.’.
 Make sure to provide the plain name of the param, like ‘xxx’.
 */
- (void)addCustomParam:(nonnull NSString *)value withName:(nonnull NSString *)name;

@end

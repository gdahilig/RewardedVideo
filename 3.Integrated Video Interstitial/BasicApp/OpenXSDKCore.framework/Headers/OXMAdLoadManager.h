//
//  OXMAdLoadManager.h
//  OpenXSDKCore
//
//  Created by Gene Dahilig on 1/24/18.
//  Copyright © 2018 OpenX. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OXMAdConfiguration.h"
#import "OXMAdLoadManagerDelegate.h"
#import "OXMAdRequesterAbstract.h"
#import "OXMTransaction.h"
#import "OXMTransactionDelegate.h"
#import "OXMAdRequestDelegate.h"
#import "OXMCreativeModelCollectionMakerAbstract.h"

@import UIKit;


@class OXMServerConnection;
@class OXMModalManager;


// OXMAdLoadManager's role is to coordinating the ad request, creating the creative model creation and the creating the creative.
NS_SWIFT_NAME(OXMAdLoadManager)
@interface OXMAdLoadManager : NSObject <OXMTransactionDelegate, OXMAdRequestDelegate>

@property (strong, nullable) OXMServerConnection * connection;
@property (weak, nullable) id<OXMAdLoadManagerDelegate> adLoadManagerDelegate;
@property (strong, nonnull) OXMAdConfiguration * adConfiguration;
@property (strong, atomic, nonnull) OXMAdRequesterAbstract* adRequester;
@property (strong, atomic, nonnull) OXMCreativeModelCollectionMakerAbstract* creativeModelCollectionMaker;
@property (strong, atomic, nullable) NSMutableArray<OXMCreativeModel*> *creativeModels;
@property (strong, nonatomic, nullable) OXMTransaction *currentTransaction;

- (nonnull instancetype)init NS_UNAVAILABLE;
- (nonnull instancetype)init:(nonnull OXMServerConnection *)connection modalManager:(OXMModalManager*) modalManager NS_DESIGNATED_INITIALIZER;

- (void) load;
- (void) creativeModelCollectionMakerFailed: (nonnull NSError*) error;

@end

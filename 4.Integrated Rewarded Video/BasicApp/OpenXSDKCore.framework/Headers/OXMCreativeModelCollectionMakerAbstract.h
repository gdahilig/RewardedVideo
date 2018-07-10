//
//  OXMCreativeModelCollectionMaker.h
//  OpenXSDKCore
//
//  Created by Gene Dahilig on 4/15/18.
//  Copyright © 2018 OpenX. All rights reserved.
//

#import <Foundation/Foundation.h>


@class OXMCreativeModel;
@class OXMAdConfiguration;
@class OXMServerConnection;
@class OXMMediatedAdResult;
@class OXMAdRequestResponseAbstract;
@class OXMChainInfo;

typedef void(^OXMCreativeModelMakerSuccessCallback)(NSArray<OXMCreativeModel *> * _Nonnull,  OXMChainInfo * _Nullable);
typedef void(^OXMCreativeModelMakerFailureCallback)(NSError * _Nonnull);

@interface OXMCreativeModelCollectionMakerAbstract : NSObject

@property (strong, nonnull)OXMAdConfiguration *adConfiguration;
@property (strong, nonnull)OXMServerConnection *serverConnection;

- (nonnull instancetype)init NS_UNAVAILABLE;
- (nonnull instancetype)initWithOxmServerConnection:(nonnull OXMServerConnection *)oxmServer
                                    adConfiguration:(nonnull OXMAdConfiguration *)adConfiguration;

- (void)makeModels:(nonnull OXMAdRequestResponseAbstract *)mediatedAd
   successCallback:(nonnull OXMCreativeModelMakerSuccessCallback)successCallback
   failureCallback:(nonnull OXMCreativeModelMakerFailureCallback)failureCallback;


@end

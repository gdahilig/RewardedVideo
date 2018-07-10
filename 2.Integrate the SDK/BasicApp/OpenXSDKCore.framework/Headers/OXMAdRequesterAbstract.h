//
//  OXMAdRequest.h
//  OpenXSDKCore
//
//  Created by Gene Dahilig on 4/15/18.
//  Copyright © 2018 OpenX. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OXMServerConnection.h"
#import "OXMAdConfiguration.h"

typedef void(^OXMAdRequestCallback)(OXMServerResponse * _Nullable serverResponse, NSError * _Nullable);

@protocol OXMAdRequestDelegate;

@interface OXMAdRequesterAbstract : NSObject

@property (nonatomic, strong, nonnull) OXMAdConfiguration * adConfiguration;
@property (nonatomic, strong, nonnull) OXMServerConnection* serverConnection;
@property (nonatomic, weak, nullable) id<OXMAdRequestDelegate> adRequestDelegate;

- (nonnull instancetype) initWithOxmServerConnection: (nonnull OXMServerConnection*) serverConnection
                                     adConfiguration: (nonnull OXMAdConfiguration* ) adConfiguration;
- (void) load;
@end

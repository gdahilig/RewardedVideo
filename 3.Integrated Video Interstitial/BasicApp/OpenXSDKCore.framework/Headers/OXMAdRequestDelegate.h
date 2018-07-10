//
//  OXMAdRequestDelegate.h
//  OpenXSDKCore
//
//  Created by Gene Dahilig on 4/17/18.
//  Copyright © 2018 OpenX. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OXMAdRequestResponseAbstract.h"

@protocol OXMAdRequestDelegate

- (void) requestCompletedSuccess: (nonnull OXMAdRequestResponseAbstract *) adRequestResponse;
- (void) requestCompletedFailure: (nonnull NSError *) error;

@end


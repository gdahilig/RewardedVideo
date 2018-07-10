//
//  OXMAdRequestResponseVast.h
//  OpenXSDKCore
//
//  Created by Gene Dahilig on 5/2/18.
//  Copyright © 2018 OpenX. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "OXMAdRequestResponseAbstract.h"

@class OXMVastAbstractAd;

@interface OXMAdRequestResponseVast : OXMAdRequestResponseAbstract
@property (strong, atomic, nullable) NSArray<OXMVastAbstractAd *> *ads;
@end

//
//  OXMAdRequestResponseAcj.h
//  OpenXSDKCore
//
//  Created by Gene Dahilig on 5/2/18.
//  Copyright © 2018 OpenX. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "OXMAdRequestResponseAbstract.h"

@class OXMMediatedAdResult;

@interface OXMAdRequestResponseAcj : OXMAdRequestResponseAbstract
@property (strong, atomic, nullable) OXMMediatedAdResult *mediatedAdResult;
@end

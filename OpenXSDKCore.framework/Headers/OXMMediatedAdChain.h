//
//  OXMMediatedAdChain.h
//  OpenXSDKCore
//
//  Created by Anton Morozov on 2/2/18.
//  Copyright © 2018 OpenX. All rights reserved.
//

#import <Foundation/Foundation.h>

@class OXMMediatedAdChainElement;

#pragma mark - OXMMediatedAdChain

NS_SWIFT_NAME(MediatedAdChain)
@interface OXMMediatedAdChain : NSObject

@property (nonatomic, strong, nullable) NSArray<OXMMediatedAdChainElement *> *adChain;

- (nonnull instancetype)init NS_UNAVAILABLE;
- (nonnull instancetype)initWithElements:(nonnull NSArray<OXMMediatedAdChainElement *> *)elements auid:(nonnull NSString *)auid NS_DESIGNATED_INITIALIZER;

@end


#pragma mark - OXMMediatedAdChainElement

@interface OXMMediatedAdChainElement : NSObject

@property (nonatomic, strong, nullable) NSDictionary<NSString *, NSString *> *parameters;
@property (nonatomic, copy, nullable) NSString *name;
@property (nonatomic, copy, nullable) NSString *trackingURL;
@property (nonatomic, copy, nullable) NSString *state;

- (nonnull instancetype)init NS_UNAVAILABLE;
- (nonnull instancetype)initWithName:(nonnull NSString *)name parameters:(nonnull NSDictionary<NSString *, NSString *> *)parameters NS_DESIGNATED_INITIALIZER; 

@end

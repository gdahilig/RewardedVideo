//OpenXSDK Umbrella Header

#import <UIKit/UIKit.h>

//! Project version number for OpenXSDKCore.
FOUNDATION_EXPORT double OpenXSDKCoreVersionNumber;

//! Project version string for OpenXSDKCore.
FOUNDATION_EXPORT const unsigned char OpenXSDKCoreVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <OpenXSDKCore/PublicHeader.h>
//Objective-c interface to OXMLog
#import "OXMLog.h"

#define OXMLogWhereAmI() [OXMLog logObjC:@"" logLevel:OXMLogLevelInfo file:__FILE__ line:__LINE__ function:__PRETTY_FUNCTION__]
#define OXMLogInfo( s, ... ) [OXMLog logObjC:[NSString stringWithFormat:(s), ##__VA_ARGS__] logLevel:OXMLogLevelInfo file:__FILE__ line:__LINE__ function:__PRETTY_FUNCTION__]
#define OXMLogWarn( s, ... ) [OXMLog logObjC:[NSString stringWithFormat:(s), ##__VA_ARGS__] logLevel:OXMLogLevelWarn file:__FILE__ line:__LINE__ function:__PRETTY_FUNCTION__]
#define OXMLogError( s, ... ) [OXMLog logObjC:[NSString stringWithFormat:(s), ##__VA_ARGS__] logLevel:OXMLogLevelError file:__FILE__ line:__LINE__ function:__PRETTY_FUNCTION__]

#define OXMParameterCheck(condition)                \
    if (!condition) {                               \
        OXMLogError(@"Invalid input parameters");   \
    }                                               \

//
//  OXMORTBBidRequest.h
//  OpenXSDKCore
//
//  Created by Yuriy Velichko on 1/25/18.
//  Copyright © 2018 OpenX. All rights reserved.
//

#import <Foundation/Foundation.h>

//This file holds the structure for an ORTB 2.5 Bid Request Object
//https://www.iab.com/wp-content/uploads/2016/03/OpenRTB-API-Specification-Version-2-5-FINAL.pdf


@class OXMORTBApp;
@class OXMORTBBanner;
@class OXMORTBDeal;
@class OXMORTBDevice;
@class OXMORTBGeo;
@class OXMORTBImp;
@class OXMORTBPmp;
@class OXMORTBRegs;
@class OXMORTBUser;
@class OXMORTBVideo;

@interface OXMORTBAbstract : NSObject <NSCopying>

+ (nullable instancetype)fromJsonString:(nonnull NSString *)jsonString error:(NSError* _Nullable __autoreleasing * _Nullable)error
    NS_SWIFT_NAME(from(jsonString:));

- (nullable NSString *)toJsonStringWithError:(NSError* _Nullable __autoreleasing * _Nullable)error;

@end

#pragma mark - 3.2.1: BidRequest

//The top-level bid request object contains a globally unique bid request or auction ID. This id att;ribute is
//    required as is at least one impression object (Section 3.2.4). Other attributes in this top-level object
//establish rules and restrictions that apply to all impressions being offered.
//There are also several subordinate objects that provide detailed data to potential buyers. Among these
//are the Site and App objects, which describe the type of published media in which the impression(s)
//appear. These objects are highly recommended, but only one applies to a given bid request depending
//on whether the media is browser-based web content or a non-browser application, respectively.
@interface OXMORTBBidRequest : OXMORTBAbstract
    
//Unique ID of the bid request, provided by the exchange.
//Note: id is not supported

//Array of Imp objects (Section 3.2.4) representing the impressions offered. At least 1 Imp object is required.
@property (nonatomic, copy, nonnull) NSArray<OXMORTBImp *> *imp;

//Note: Site object not supported.
//Details via a Site object (Section 3.2.13) about the publisher’s website. Only applicable and recommended for websites.

//Details via an App object (Section 3.2.14) about the publisher’s
//app (i.e., non-browser applications). Only applicable and
//recommended for apps
@property (nonatomic, copy, nonnull) OXMORTBApp *app;

//Details via a Device object (Section 3.2.18) about the user’s
//device to which the impression will be delivered.
@property (nonatomic, copy, nonnull) OXMORTBDevice *device;

//Details via a User object (Section 3.2.20) about the human
//user of the device; the advertising audience.
@property (nonatomic, copy, nonnull) OXMORTBUser *user;

//Integer. Indicator of test mode in which auctions are not billable,
//where 0 = live mode, 1 = test mode.
@property (nonatomic, copy, nonnull) NSNumber *test;

//Auction type, where 1 = First Price, 2 = Second Price Plus.
//Exchange-specific auction types can be defined using values
//greater than 500.
//Note: at is not supported

//Maximum time in milliseconds the exchange allows for bids to
//be received including Internet latency to avoid timeout. This
//value supersedes any a priori guidance from the exchange
@property (nonatomic, copy, nullable) NSNumber *tmax;
@property (nonatomic, copy, nullable) NSNumber *intTmax;

//White list of buyer seats (e.g., advertisers, agencies) allowed
//to bid on this impression. IDs of seats and knowledge of the
//buyer’s customers to which they refer must be coordinated
//between bidders and the exchange a priori. At most, only one
//of wseat and bseat should be used in the same request.
//Omission of both implies no seat restrictions
//Note: wseat is not supported

//Block list of buyer seats (e.g., advertisers, agencies) restricted
//from bidding on this impression. IDs of seats and knowledge
//of the buyer’s customers to which they refer must be
//coordinated between bidders and the exchange a priori. At
//most, only one of wseat and bseat should be used in the
//same request. Omission of both implies no seat restrictions.
//Note: bseat is not supported

//Flag to indicate if Exchange can verify that the impressions
//offered represent all of the impressions available in context
//(e.g., all on the web page, all video spots such as pre/mid/post
//roll) to support road-blocking. 0 = no or unknown, 1 = yes, the
//impressions offered represent all that are available.
//Note: allimps is not supported

//Array of allowed currencies for bids on this bid request using
//ISO-4217 alpha codes. Recommended only if the exchange
//accepts multiple currencies.
//Note: cur is not supported

//White list of languages for creatives using ISO-639-1-alpha-2.
//Omission implies no specific restrictions, but buyers would be
//advised to consider language attribute in the Device and/or
//Content objects if available.
//Note: wlang is not supported

//Blocked advertiser categories using the IAB content
//categories. Refer to List 5.1.
//Note: bcat is not supported

//Block list of advertisers by their domains (e.g., “ford.com”).
//Note: badv is not supported

//Block list of applications by their platform-specific exchangeindependent
//application identifiers. On Android, these should
//be bundle or package names (e.g., com.foo.mygame). On iOS,
//these are numeric IDs
//Note: bapp is not supported

//A Source object (Section 3.2.2) that provides data about the
//inventory source and which entity makes the final decision
//Note: Source is not supported

//A Regs object (Section 3.2.3) that specifies any industry, legal,
//or governmental regulations in force for this request.
@property (nonatomic, copy, nonnull) OXMORTBRegs *regs;

//Placeholder for exchange-specific extensions to OpenRTB.
//Note: ext object not supported.

- (nonnull instancetype)init;

@end

#pragma mark - 3.2.2: Source

//This object describes the nature and behavior of the entity that is the source of the bid request
//upstream from the exchange. The primary purpose of this object is to define post-auction or upstream
//decisioning when the exchange itself does not control the final decision. A common example of this is
//header bidding, but it can also apply to upstream server entities such as another RTB exchange, a
//mediation platform, or an ad server combines direct campaigns with 3rd party demand in decisioning.
//Note: Source is not supported.

#pragma mark - 3.2.3: Regs

//This object contains any legal, governmental, or industry regulations that apply to the request. The
//coppa flag signals whether or not the request falls under the United States Federal Trade Commission’s
//regulations for the United States Children’s Online Privacy Protection Act (“COPPA”).
@interface OXMORTBRegs : OXMORTBAbstract
    
//Int. Flag indicating if this request is subject to the COPPA regulations established by the USA FTC, where 0 = no, 1 = yes
@property (nonatomic, copy, nullable) NSNumber *coppa;

/// Placeholder for exchange-specific extensions to OpenRTB.
@property (nonatomic, strong, nullable) NSMutableDictionary<NSString *, id> *ext;

@end

#pragma mark - 3.2.4: Imp

//This object describes an ad placement or impression being auctioned. A single bid request can include
//multiple Imp objects, a use case for which might be an exchange that supports selling all ad positions on
//a given page. Each Imp object has a required ID so that bids can reference them individually.
//The presence of Banner (Section 3.2.6), Video (Section 3.2.7), and/or Native (Section 3.2.9) objects
//subordinate to the Imp object indicates the type of impression being offered. The publisher can choose
//one such type which is the typical case or mix them at their discretion. However, any given bid for the
//    impression must conform to one of the offered types.
@interface OXMORTBImp : OXMORTBAbstract
    
//A unique identifier for this impression within the context of the bid request (typically, starts with 1 and increments.
//Note: id is not supported.

//An array of Metric object (Section 3.2.5).
//Note: metric is not supported.

//A Banner object (Section 3.2.6); required if this impression is offered as a banner ad opportunity.
@property (nonatomic, copy, nullable) OXMORTBBanner * banner;

//A Video object (Section 3.2.7); required if this impression is offered as a video ad opportunity.
@property (nonatomic, copy, nullable) OXMORTBVideo *video;

//Note: audio object not supported
//An Audio object (Section 3.2.8); required if this impression is offered as an audio ad opportunity.

//Note: Native object not supported
//A Native object (Section 3.2.9); required if this impression is offered as a native ad opportunity.

//A Pmp object (Section 3.2.11) containing any private marketplace deals in effect for this impression.
@property (nonatomic, copy, nonnull) OXMORTBPmp * pmp;

//Name of ad mediation partner, SDK technology, or player
//responsible for rendering ad (typically video or mobile). Used
//by some ad servers to customize ad code by partner.
//Recommended for video and/or apps.
@property (nonatomic, copy, nonnull) NSString *displaymanager;

//Version of ad mediation partner, SDK technology, or player
//responsible for rendering ad (typically video or mobile). Used
//by some ad servers to customize ad code by partner.
//Recommended for video and/or apps.
@property (nonatomic, copy, nullable) NSString *displaymanagerver;

//1 = the ad is interstitial or full screen, 0 = not interstitial
@property (nonatomic, copy, nonnull) NSNumber *instl;

//Identifier for specific ad placement or ad tag that was used to
//initiate the auction. This can be useful for debugging of any
//issues, or for optimization by the buyer.
@property (nonatomic, copy, nullable) NSString *tagid;

//Minimum bid for this impression expressed in CPM.
//Note: bidfloor is not supported.

//Currency specified using ISO-4217 alpha codes. This may be
//different from bid currency returned by bidder if this is
//allowed by the exchange.
//Note: bidfloorcur is not supported.

//Indicates the type of browser opened upon clicking the
//creative in an app, where 0 = embedded, 1 = native. Note that
//the Safari View Controller in iOS 9.x devices is considered a
//native browser for purposes of this attribute.
//TODO: clarify with Product if this should be informed by OpenXSDKConfiguration.useInternalClickthroughBrowser
@property (nonatomic, copy, nonnull) NSNumber *clickbrowser;

//Flag to indicate if the impression requires secure HTTPS URL
//creative assets and markup, where 0 = non-secure, 1 = secure.
//If omitted, the secure state is unknown, but non-secure HTTP
//support can be assumed.
@property (nonatomic, copy, nonnull) NSNumber *secure;

//Array of exchange-specific names of supported iframe busters.
//Note: iframebuster is not supported.

//Advisory as to the number of seconds that may elapse
//between the auction and the actual impression.
//Note: exp is not supported.

//Note: ext is not supported.
//Placeholder for exchange-specific extensions to OpenRTB.

- (nonnull instancetype)init;

@end

#pragma mark - 3.2.5: Metric

//This object is associated with an impression as an array of metrics. These metrics can offer insight into
//the impression to assist with decisioning such as average recent viewability, click-through rate, etc. Each
//metric is identified by its type, reports the value of the metric, and optionally identifies the source or
//vendor measuring the value.
//Note: Metric not supported.

#pragma mark - 3.2.6: Banner

//This object represents the most general type of impression. Although the term “banner” may have very
//specific meaning in other contexts, here it can be many things including a simple static image, an
//expandable ad unit, or even in-banner video (refer to the Video object in Section 3.2.7 for the more
//generalized and full featured video ad units). An array of Banner objects can also appear within the
//Video to describe optional companion ads defined in the VAST specification.
//The presence of a Banner as a subordinate of the Imp object indicates that this impression is offered as
//a banner type impression. At the publisher’s discretion, that same impression may also be offered as
//video, audio, and/or native by also including as Imp subordinates objects of those types. However, any
//given bid for the impression must conform to one of the offered types.
@interface OXMORTBBanner : OXMORTBAbstract
    
//Array of format objects (Section 3.2.10) representing the
//banner sizes permitted. If none are specified, then use of the
//h and w attributes is highly recommended.
//Note: format is not supported.

//Exact width in device independent pixels (DIPS);
//recommended if no format objects are specified.
//Note: w is not supported.

//Exact height in device independent pixels (DIPS);
//recommended if no format objects are specified
//Note: h is not supported.

//NOTE: Deprecated in favor of the format array.
//Maximum width in device independent pixels (DIPS).
//Note: wmax is not supported.

//NOTE: Deprecated in favor of the format array.
//Maximum height in device independent pixels (DIPS).
//Note: hmax is not supported.

//NOTE: Deprecated in favor of the format array.
//Minimum width in device independent pixels (DIPS).
//Note: wmin is not supported.

//NOTE: Deprecated in favor of the format array.
//Minimum height in device independent pixels (DIPS).
//Note: hmin is not supported.

//Blocked banner ad types. Refer to List 5.2.
//Note: btype is not supported.

//Blocked creative attributes. Refer to List 5.3.
//Note: battr is not supported.

//Ad position on screen. Refer to List 5.4:
//The following table specifies the position of the ad as a relative measure of visibility or prominence. This
//OpenRTB table has values derived from the Inventory Quality Guidelines (IQG). Practitioners should
//keep in sync with updates to the IQG values as published on IAB.com. Values “4” - “7” apply to apps per
//the mobile addendum to IQG version 2.1.
//Value Description
//0 Unknown
//1 Above the Fold
//2 DEPRECATED - May or may not be initially visible depending on screen size/resolution.
//3 Below the Fold
//4 Header
//5 Footer
//6 Sidebar
//7 Full Screen
@property (nonatomic, copy, nullable) NSNumber *pos;
@property (nonatomic, copy, nullable) NSNumber *intPos;

//Content MIME types supported. Popular MIME types may include “application/x-shockwave-flash”, “image/jpg”, and “image/gif"
//Note: mimes is not supported.

//Integer. Indicates if the banner is in the top frame as opposed to an iframe, where 0 = no, 1 = yes
//Note: topframe is not supported.

//Directions in which the banner may expand. See table 5.5:
//5.5 Expandable Direction
//The following table lists the directions in which an expandable ad may expand, given the positioning of
//the ad unit on the page and constraints imposed by the content.
//Value Description
//1 Left
//2 Right
//3 Up
//4 Down
//5 Full Screen
//Note: expdir is not supported.

//List of supported API frameworks for this impression. If an API is not explicitly listed, it is assumed not to be supported
//1) VPAID 1.0
//2) VPAID 2.0
//3) MRAID-1
//4) ORMMA
//5) MRAID-2
//6) MRAID-3
//Note: OpenXSDKCore supports MRAID 1 and MRAID 2
//Also note that since this is not settable by pub, we can use [Int] instead of NSNumber
@property (nonatomic, copy, nonnull) NSArray<NSNumber *> *api;

//Unique identifier for this banner object. Recommended when Banner objects are used with a Video object to represent an array of companion ads. Values usually start at 1 and increase with each object; should be unique within an impression
//Note: id is not supported.

//Relevant only for Banner objects used with a Video object
//(Section 3.2.7) in an array of companion ads. Indicates the
//companion banner rendering mode relative to the associated
//video, where 0 = concurrent, 1 = end-card.
//Note: vcm is not supported.

//Placeholder for exchange-specific extensions to OpenRTB.
//Note: ext is not supported.

- (nonnull instancetype)init;

@end

#pragma mark - 3.2.7: Video

//This object represents an in-stream video impression. Many of the fields are non-essential for minimally viable transactions, but are included to offer fine control when needed. Video in OpenRTB generally assumes compliance with the VAST standard. As such, the notion of companion ads is supported by optionally including an array of Banner objects that define these companion ads.
@interface OXMORTBVideo : OXMORTBAbstract
    
//Content MIME types supported (e.g., “video/x-ms-wmv”, “video/mp4”).
@property (nonatomic, copy, nonnull) NSArray<NSString *> *mimes;

//Int. Minimum video ad duration in seconds.
@property (nonatomic, copy, nullable) NSNumber *minduration;
@property (nonatomic, copy, nullable) NSNumber *intMinduration;

//Int. Maximum video ad duration in seconds.
@property (nonatomic, copy, nullable) NSNumber *maxduration;
@property (nonatomic, copy, nullable) NSNumber *intMaxduration;

//Int. Array of supported video bid response protocols. At least one supported protocol must be specified in either the protocol or protocols attribute. See table 5.8:
//1) VAST 1.0
//2) VAST 2.0
//3) VAST 3.0
//4) VAST 1.0 Wrapper
//5) VAST 2.0 Wrapper
//6) VAST 3.0 Wrapper
//7) VAST 4.0
//8) VAST 4.0 Wrapper
//9) DAAST 1.0
//10) DAAST 1.0 Wrapper
//Note: since this is not settable by the pub, it can be an Int array instead of NSNumber.
@property (nonatomic, copy, nonnull) NSArray<NSNumber *> *protocols;

//NOTE: Deprecated in favor of protocols.
//Supported video protocol. Refer to List 5.8. At least one
//supported protocol must be specified in either the protocol
//or protocols attribute.
//protocol is not supported

//Int. Width of the video player in device independent pixels (DIPS).
@property (nonatomic, copy, nullable) NSNumber *w;
@property (nonatomic, copy, nullable) NSNumber *intW;

//Int. Height of the video player in device independent pixels (DIPS).
@property (nonatomic, copy, nullable) NSNumber *h;
@property (nonatomic, copy, nullable) NSNumber *intH;

//Int. Indicates the start delay in seconds for pre-roll, mid-roll, or
//post-roll ad placements. Refer to List 5.12 for additional
//generic values.
@property (nonatomic, copy, nullable) NSNumber *startdelay;
@property (nonatomic, copy, nullable) NSNumber *intStartdelay;

//Placement type for the impression. Refer to list 5.9:
//1) In-Stream: Played before, during or after the streaming video content that the consumer has requested (e.g., Pre-roll, Mid-roll, Post-roll).
//2) In-Banner: Exists within a web banner that leverages the banner space to deliver a video experience as opposed to another static or rich media format. The format relies on the existence of display ad inventory on the page for its delivery.
//3) In-Article: Loads and plays dynamically between paragraphs of editorial content; existing as a standalone branded message.
//4) In-Feed: Found in content, social, or product feeds.
//5) Interstitial/Slider/Floating: Covers the entire or a portion of screen area, but is always on screen while displayed (i.e. cannot be scrolled out of view). Note that a full-screen interstitial (e.g., in mobile) can be distinguished from a floating/slider unit by the imp.instl field.
//Note: OpenXSDKCore supports only Interstitial right now
@property (nonatomic, copy, nonnull) NSNumber *placement;

//Int. Indicates if the impression must be linear, nonlinear, etc. If none specified, assume all are allowed.
//See table 5.7:
//Value Description
//1 Linear / In-Stream
//2 Non-Linear / Overlay
@property (nonatomic, copy, nullable) NSNumber *linearity;
@property (nonatomic, copy, nullable) NSNumber *intLinearity;

//Indicates if the player will allow the video to be skipped,
//where 0 = no, 1 = yes.
//If a bidder sends markup/creative that is itself skippable, the
//Bid object should include the attr array with an element of
//16 indicating skippable video. Refer to List 5.3
//Note: Skip is not supported

//Videos of total duration greater than this number of seconds
//can be skippable; only applicable if the ad is skippable.
//Note: Skipmin is not supported

//Number of seconds a video must play before skipping is
//enabled; only applicable if the ad is skippable.
//Note: Skipafter is not supported

//If multiple ad impressions are offered in the same bid request, the sequence number will allow for the coordinated delivery of multiple creatives
//Note: Sequence is not supported

//Integer. Blocked creative attributes. Refer to list 5.3:
//Note: battr is not supported

//Int. Maximum extended video ad duration if extension is allowed. If blank or 0, extension is not allowed. If -1, extension is allowed, and there is no time limit imposed. If greater than 0, then the value represents the number of seconds of extended play supported beyond the maxduration value
//Note: Maxextended is not supported

//Int. Minimum bit rate in Kbps. Exchange may set this dynamically or universally across their set of publishers
@property (nonatomic, copy, nullable) NSNumber *minbitrate;
@property (nonatomic, copy, nullable) NSNumber *intMinbitrate;

//Int. Maximum bit rate in Kbps. Exchange may set this dynamically åor universally across their set of publishers
@property (nonatomic, copy, nullable) NSNumber *maxbitrate;
@property (nonatomic, copy, nullable) NSNumber *intMaxbitrate;

//Indicates if letter-boxing of 4:3 content into a 16:9 window is allowed, where 0 = no, 1 = yes.
//Note: boxingallowed is not supported

//Int. Allowed playback methods. If none specified, assume all are allowed. Refer to table 5.9:
//5.9 Video Playback Methods
//The following table lists the various video playback methods.
//Value Description
//1 Auto-Play Sound On
//2 Auto-Play Sound Off
//3 Click-to-Play
//4 Mouse-Over
@property (nonatomic, copy, nonnull) NSArray<NSNumber *> *playbackmethod;

//The event that causes playback to end. Refer to List 5.11:
//1) On Video Completion or when Terminated by User
//2) On Leaving Viewport or when Terminated by User
//3) On Leaving Viewport Continues as a Floating/Slider Unit until Video Completion or when Terminated by User
//Note: OpenXSDKCore supports #2
@property (nonatomic, copy, nonnull) NSNumber *playbackend;

//Int. Supported delivery methods (e.g., streaming, progressive). If none specified, assume all are supported.
//See table 5.15:
//1) Streaming
//2) Progressive
//3) Download
//Note: OpenXSDKCore supports Streaming and Download.
//Note: Since this is not settable by the pub we can use [Int] instead of [NSNumber].
@property (nonatomic, copy, nullable) NSArray<NSNumber *> *delivery;

//Ad position on screen
//Refer to table 5.4:
//0) Unknown
//1) Above the Fold
//2) DEPRECATED - May or may not be initially visible depending on screen size/resolution.
//3) Below the Fold
//4) Header
//5) Footer
//6) Sidebar
//7) Full Screen
//Note: OpenXSDKCore supports Full Screen Only
@property (nonatomic, copy, nonnull) NSNumber *pos;

//Note: companionad is not supported.
//Array of Banner objects if companion ads are available

//Int. List of supported API frameworks for this impression. If an API is not explicitly listed, it is assumed not to be supported
//Value Description
//1 VPAID 1.0
//2 VPAID 2.0
//3 MRAID-1
//4 ORMMA
//5 MRAID-2
//Note: OpenXSDKCore doesn't yet support Companion ads, so no apis are supported.
@property (nonatomic, copy, nullable) NSArray<NSNumber *> *api;

//Int. Supported VAST companion ad types. Recommended if companion Banner objects are included via the companionad array.
//Refer to 5.12:
//1 Static Resource
//2 HTML Resource
//3 iframe Resource
//Note: companiontype is not supported.

//Placeholder for exchange-specific extensions to OpenRTB.
//Note: ext is not supported.
    
- (nonnull instancetype)init;

@end

#pragma mark - 3.2.8: Audio

//This object represents an audio type impression. Many of the fields are non-essential for minimally
//    viable transactions, but are included to offer fine control when needed. Audio in OpenRTB generally
//assumes compliance with the DAAST standard. As such, the notion of companion ads is supported by
//optionally including an array of Banner objects (refer to the Banner object in Section 3.2.6) that define
//these companion ads.
//The presence of a Audio as a subordinate of the Imp object indicates that this impression is offered as
//an audio type impression. At the publisher’s discretion, that same impression may also be offered as
//banner, video, and/or native by also including as Imp subordinates objects of those types. However, any
//given bid for the impression must conform to one of the offered types
//Note: Audio is not supported.

#pragma mark - 3.2.9: Native

//This object represents a native type impression. Native ad units are intended to blend seamlessly into the surrounding content (e.g., a sponsored Twitter or Facebook post). As such, the response must be well-structured to afford the publisher fine-grained control over rendering.
//The Native Subcommittee has developed a companion specification to OpenRTB called the Native Ad Specification. It defines the request parameters and response markup structure of native ad units. This object provides the means of transporting request parameters as an opaque string so that the specific parameters can evolve separately under the auspices of the Native Ad Specification. Similarly, the ad markup served will be structured according to that specification.
//Note: Native is not supported.

#pragma mark - 3.2.10: Format

//This object represents an allowed size (i.e., height and width combination) or Flex Ad parameters for a
//    banner impression. These are typically used in an array where multiple sizes are permitted. It is
//recommended that either the w/h pair or the wratio/hratio/wmin set (i.e., for Flex Ads) be specified.
//Note: Format is not supported.

#pragma mark - 3.2.11: Pmp

//This object is the private marketplace container for direct deals between buyers and sellers that may
//pertain to this impression. The actual deals are represented as a collection of Deal objects. Refer to
//Section 7.3 for more details.
@interface OXMORTBPmp : OXMORTBAbstract
    
//Int. Indicator of auction eligibility to seats named in the Direct Deals object, where 0 = all bids are accepted, 1 = bids are restricted to the deals specified and the terms thereof
@property (nonatomic, copy, nullable) NSNumber *private_auction;
@property (nonatomic, copy, nullable) NSNumber *intPrivate_auction;

//Array of Deal (Section 3.2.18) objects that convey the specific deals applicable to this impression
@property (nonatomic, copy, nonnull) NSArray<OXMORTBDeal *> *deals;

//Placeholder for exchange-specific extensions to OpenRTB.
//Note: ext is not supported.

- (nonnull instancetype)init;

@end

#pragma mark - 3.2.12: Deal

//This object constitutes a specific deal that was struck a priori between a buyer and a seller. Its presence
//with the Pmp collection indicates that this impression is available under the terms of that deal. Refer to
//Section 7.3 for more details.
@interface OXMORTBDeal : OXMORTBAbstract
    
//A unique identifier for the direct deal
//REQUIRED
@property (nonatomic, copy, nullable) NSString *id;

//Minimum bid for this impression expressed in CPM
//Defaults to 0
@property (nonatomic, copy, nonnull) NSNumber *bidfloor;

//Currency specified using ISO-4217 alpha codes. This may be different from bid currency returned by bidder if this is allowed by the exchange
//Defaults to USD
@property (nonatomic, copy, nonnull) NSString *bidfloorcur;

//Int. Optional override of the overall auction type of the bid request, where 1 = First Price, 2 = Second Price Plus, 3 = the value passed in bidfloor is the agreed upon deal price. Additional auction types can be defined by the exchange
@property (nonatomic, copy, nullable) NSNumber *at;
@property (nonatomic, copy, nullable) NSNumber *intAt;

//Whitelist of buyer seats allowed to bid on this deal. Seat IDs must be communicated between bidders and the exchange a priori. Omission implies no seat restrictions
@property (nonatomic, copy, nonnull) NSArray<NSString *> *wseat;

//Array of advertiser domains (e.g., advertiser.com) allowed to bid on this deal. Omission implies no advertiser restrictions
@property (nonatomic, copy, nonnull) NSArray<NSString *> *wadomain;

//Placeholder for exchange-specific extensions to OpenRTB.
//Note: ext is not supported.

- (nonnull instancetype)init;

@end

#pragma mark - 3.2.14: Site

//This object should be included if the ad supported content is a website as opposed to a non-browser
//application. A bid request must not contain both a Site and an App object. At a minimum, it is useful
//to provide a site ID or page URL, but this is not strictly required.
//Note: Site not supported.

#pragma mark - 3.2.14: App

//This object should be included if the ad supported content is a non-browser application (typically in
//mobile) as opposed to a website. A bid request must not contain both an App and a Site object. At a
//minimum, it is useful to provide an App ID or bundle, but this is not strictly required.
@interface OXMORTBApp : OXMORTBAbstract
    
//Exchange specific id, recommended
@property (nonatomic, copy, nullable) NSString *id;

//App name
@property (nonatomic, copy, nullable) NSString *name;

//App bundle or package name
@property (nonatomic, copy, nullable) NSString *bundle;

//Domain name of the app
@property (nonatomic, copy, nullable) NSString *domain;

//App store url for an installed app
@property (nonatomic, copy, nullable) NSString *storeurl;

//Array of IAB content categories of the app
@property (nonatomic, copy, nonnull) NSArray<NSString *> *cat;

//Array of IAB content categories of the current section of the app
@property (nonatomic, copy, nonnull) NSArray<NSString *> *sectioncat;

//Array of IAB content categories of the current page or view of the app
@property (nonatomic, copy, nonnull) NSArray<NSString *> *pagecat;

//Application version
@property (nonatomic, copy, nullable) NSString *ver;

//Int. Indicates if the site has a privacy policy where 0 = no and 1 = yes
@property (nonatomic, copy, nullable) NSNumber *privacypolicy;
@property (nonatomic, copy, nullable) NSNumber *intPrivacypolicy;

//Int. Paid status; 0 = app is free, 1 = app is paid
@property (nonatomic, copy, nullable) NSNumber *paid;
@property (nonatomic, copy, nullable) NSNumber *intPaid;

//Note: Publisher object not supported
//Details about the publisher of the site

//Note: Content object not supported
//Details about the content of the site

//Comma seperated list of keywords about the site
@property (nonatomic, copy, nullable) NSString *keywords;

//Placeholder for exchange-specific extensions to OpenRTB.
//Note: ext is not supported.

- (nonnull instancetype )init;

@end

#pragma mark - 3.2.15: Publisher

//This object describes the publisher of the media in which the ad will be displayed. The publisher is
//typically the seller in an OpenRTB transaction.
//Note: Publisher not supported.

#pragma mark - 3.2.16: Content

//This object describes the content in which the impression will appear, which may be syndicated or nonsyndicated
//content. This object may be useful when syndicated content contains impressions and does
//not necessarily match the publisher’s general content. The exchange might or might not have
//knowledge of the page where the content is running, as a result of the syndication method. For
//example might be a video impression embedded in an iframe on an unknown web property or device.
//Note: Content not supported.

#pragma mark - 3.2.17: Producer

//This object defines the producer of the content in which the ad will be shown. This is particularly useful
//when the content is syndicated and may be distributed through different publishers and thus when the
//producer and publisher are not necessarily the same entity.
//Note: Producer not supported.

#pragma mark - 3.2.18: Device

//This object provides information pertaining to the device through which the user is interacting. Device
//information includes its hardware, platform, location, and carrier data. The device can refer to a mobile
//handset, a desktop computer, set top box, or other digital device.
@interface OXMORTBDevice : OXMORTBAbstract
    
//Browsers user agent string
//Note: ua not supported

//Location of the device, assumed to be the user's location
@property (nonatomic, copy, nonnull) OXMORTBGeo *geo;

//Do Not Track flag, set in the header by the browser: 0 = unrestricted, 1 = do no track
//Note: dnt not supported

//Limit Ad Tracking flag: 0 = unrestricted, 1 = tracking must be limited per commercial guidelines
@property (nonatomic, copy, nullable) NSNumber *lmt;
@property (nonatomic, copy, nullable) NSNumber *intLmt;

//IPv4 address closest to the device
//Note: ip not supported

//IPv6 address closest to the device
//Note: ipv6 not supported

//Int. General type of the device. See 5.17:
//Value Description Notes
//1 Mobile/Tablet Version 2.0
//2 Personal Computer Version 2.0
//3 Connected TV Version 2.0
//4 Phone New for Version 2.2
//5 Tablet New for Version 2.2
//6 Connected Device New for Version 2.2
//7 Set Top Box New for Version 2.2
@property (nonatomic, copy, nullable) NSNumber *devicetype;
@property (nonatomic, copy, nullable) NSNumber *intDevicetype;

//Device Make
@property (nonatomic, copy, nullable) NSString *make;

//Device Model
@property (nonatomic, copy, nullable) NSString *model;

//Device operating system
@property (nonatomic, copy, nullable) NSString *os;

//Device operating system version
@property (nonatomic, copy, nullable) NSString *osv;

//Hardware version of the device
@property (nonatomic, copy, nullable) NSString *hwv;

//Physical height of the screen in pixels
@property (nonatomic, copy, nullable) NSNumber *h;
@property (nonatomic, copy, nullable) NSNumber *intH;

//Physical width of the screen in pixels
@property (nonatomic, copy, nullable) NSNumber *w;
@property (nonatomic, copy, nullable) NSNumber *intW;

//Screen size as pixels per linear inch
@property (nonatomic, copy, nullable) NSNumber *ppi;
@property (nonatomic, copy, nullable) NSNumber *intPpi;

//Ratio of physical pixels to device independent pixels
@property (nonatomic, copy, nullable) NSNumber *pxratio;
@property (nonatomic, copy, nullable) NSNumber *floatPxratio;

//Support for javascript: 0 = no, 1 = yes
@property (nonatomic, copy, nullable) NSNumber *js;
@property (nonatomic, copy, nullable) NSNumber *intJs;

//Indicates if the geolocation API will be available to JavaScript
//code running in the banner, where 0 = no, 1 = yes.
@property (nonatomic, copy, nullable) NSNumber *geofetch;
@property (nonatomic, copy, nullable) NSNumber *intGeofetch;

//Version of flash supported by the browser
@property (nonatomic, copy, nullable) NSString *flashver;

//Browser language using ISO-639-1-alpha-2
@property (nonatomic, copy, nullable) NSString *language;

//Carrier or ISP
@property (nonatomic, copy, nullable) NSString *carrier;

//Mobile carrier as the concatenated MCC-MNC code (e.g.,
//“310-005” identifies Verizon Wireless CDMA in the USA).
//Refer to https://en.wikipedia.org/wiki/Mobile_country_code
//for further examples. Note that the dash between the MCC
//and MNC parts is required to remove parsing ambiguity.
@property (nonatomic, copy, nullable) NSString *mccmnc;

//Network connection type. See table 5.18:
//0 Unknown
//1 Ethernet
//2 WIFI
//3 Cellular Network – Unknown Generation
//4 Cellular Network – 2G
//5 Cellular Network – 3G
//6 Cellular Network – 4G
@property (nonatomic, copy, nullable) NSNumber *connectiontype;
@property (nonatomic, copy, nullable) NSNumber *intConnectiontype;

//ID sanctioned for adverstiser use
@property (nonatomic, copy, nullable) NSString *ifa;

//Hardware device ID, hashed via SHA1
@property (nonatomic, copy, nullable) NSString *didsha1;

//Hardware device ID, hashed via MD5
@property (nonatomic, copy, nullable) NSString *didmd5;

//Platform device ID, hashed via SHA1
@property (nonatomic, copy, nullable) NSString *dpidsha1;

//Platform device ID, hashed via MD5
@property (nonatomic, copy, nullable) NSString *dpidmd5;

//MAC of the device hashed via SHA1
@property (nonatomic, copy, nullable) NSString *macsha1;

//MAC of the device hashed via MD5
@property (nonatomic, copy, nullable) NSString *macmd5;

//Placeholder for exchange-specific extensions to OpenRTB.
//Note: ext is not supported.

- (nonnull instancetype )init;

@end

#pragma mark - 3.2.19: Geo

//This object encapsulates various methods for specifying a geographic location. When subordinate to a
//Device object, it indicates the location of the device which can also be interpreted as the user’s current
//location. When subordinate to a User object, it indicates the location of the user’s home base (i.e., not
//necessarily their current location).
//The lat/lon attributes should only be passed if they conform to the accuracy depicted in the type
//attribute. For example, the centroid of a geographic region such as postal code should not be passed.
@interface OXMORTBGeo : OXMORTBAbstract

//Double. Longitude from -90.0 to 90.0 where negative is south
@property (nonatomic, copy, nullable) NSNumber *lat;
@property (nonatomic, copy, nullable) NSNumber *doubleLat;

//Double. Latitude from -180.0 to 180.0 where negative is west
@property (nonatomic, copy, nullable) NSNumber *lon;
@property (nonatomic, copy, nullable) NSNumber *doubleLon;

//Int. Source of the location data. See table 5.20 for details:
//1 GPS/Location Services
//2 IP Address
//3 User provided (e.g., registration data)
@property (nonatomic, copy, nullable) NSNumber *type;
@property (nonatomic, copy, nullable) NSNumber *intType;

//Integer. Estimated location accuracy in meters; recommended when
//lat/lon are specified and derived from a device’s location
//services (i.e., type = 1). Note that this is the accuracy as
//reported from the device. Consult OS specific documentation
//(e.g., Android, iOS) for exact interpretation.
@property (nonatomic, copy, nullable) NSNumber *accuracy;
@property (nonatomic, copy, nullable) NSNumber *intAccuracy;

//Number of seconds since this geolocation fix was established.
//Note that devices may cache location data across multiple
//fetches. Ideally, this value should be from the time the actual
//fix was taken.
@property (nonatomic, copy, nullable) NSNumber *lastfix;
@property (nonatomic, copy, nullable) NSNumber *intLastfix;

//Service or provider used to determine geolocation from IP
//address if applicable (i.e., type = 2). Refer to List 5.23.
//ipservice is not supported

//Country code using ISO-3166-1-alpha-3
@property (nonatomic, copy, nullable) NSString *country;

//Region code using ISO-3166-2; 2-letter state code if USA
@property (nonatomic, copy, nullable) NSString *region;

//Region of a country using FIPS 10-4 notation. While OpenRTB supports this attribute, it has been withdrawn by NIST in 2008
@property (nonatomic, copy, nullable) NSString *regionfips104;

//Google metro code; similar to but not exactly Nielsen DMAs
//https://developers.google.com/adwords/api/docs/appendix/geotargeting?csw=1
@property (nonatomic, copy, nullable) NSString *metro;

//City using United Nations Code for Trade & Transport Locations
@property (nonatomic, copy, nullable) NSString *city;

//Zip or postal code
@property (nonatomic, copy, nullable) NSString *zip;

//Int. Local time as the number +/- of minutes from UTC
@property (nonatomic, copy, nullable) NSNumber *utcoffset;
@property (nonatomic, copy, nullable) NSNumber *intUtcoffset;


@end

#pragma mark - 3.2.20: User

//This object contains information known or derived about the human user of the device (i.e., the
//    audience for advertising). The user id is an exchange artifact and may be subject to rotation or other
//privacy policies. However, this user ID must be stable long enough to serve reasonably as the basis for
//    frequency capping and retargeting.
@interface OXMORTBUser : OXMORTBAbstract

//Exchange-specific ID for the user. At least one of id or buyerid is recommended
//id not supported

//Buyer-specific ID for the user as mapped by the exchange for the buyer. At least one of buyerid or id is recommended.
//buyeruid not supported

//Year of birth as a 4-digit integer
@property (nonatomic, copy, nullable) NSNumber *yob;
@property (nonatomic, copy, nullable) NSNumber *intYob;

//Gender, where “M” = male, “F” = female, “O” = known to be other (i.e., omitted is unknown)
@property (nonatomic, copy, nullable) NSString *gender;

//Comma separated list of keywords, interests, or intent
@property (nonatomic, copy, nullable) NSString *keywords;

//Optional feature to pass bidder data that was set in the exchange’s cookie. The string must be in base85 cookie safe characters and be in any format. Proper JSON encoding must be used to include “escaped” quotation marks
//customdata not supported

//Location of the user’s home base defined by a Geo object. This is not necessarily their current location
@property (nonatomic, copy, nonnull) OXMORTBGeo *geo;

//Note: Data object not supported.
//Additional user data. Each Data object represents a different data source

/// Placeholder for exchange-specific extensions to OpenRTB.
@property (nonatomic, strong, nullable) NSMutableDictionary<NSString *, id> *ext;

- (nonnull instancetype )init;

@end

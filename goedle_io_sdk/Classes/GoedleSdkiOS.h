//
//  GoedleSdkiOS.h
//  GoedleSdkiOS
//
//  Created by Marc Müller on 16.10.15.
//  Copyright © 2015 Marc Müller. All rights reserved.
//


#import <Foundation/Foundation.h>
@import UIKit;

@interface GoedleSdkiOS : NSObject<NSURLConnectionDelegate>
{
    NSMutableData *_responseData;
    
}
///--------------------------------------
/// @name Connecting to Goedle
///--------------------------------------

@property(nonatomic, strong) UIWindow *window;
@property(nonatomic, readonly, strong) NSString *registrationKey;
@property(nonatomic, readonly, strong) NSString *messageKey;
@property(nonatomic, readonly, strong) NSString *gcmSenderID;
@property(nonatomic, readonly, strong) NSDictionary *registrationOptions;

/*!
 @abstract Sets the appId and apiKey of your application to authentificate and identify the app at the goedle.io backend.
 @param appId Unique app identifier from goedle.io
 @param apiKey The apiKey of your goedle.io application.
 */
+ (void)initGoedle:(NSString *)plistPath;

+ (void)initGoedle:(NSString *)appKey :(NSString *)apiKey;

+ (void)checkStandardDefaults;

+(void)setUserId:(NSString *)userId;

/*!
 @abstract Sets the gcmSenderId from google of your application, for gcm messaging
 @param gcmSenderId Sender is the identifier for the gcm servcie, it is used to register
 */
- (void)setMessaging:(NSString *)gcmSenderId;

/*!
 @abstract The current appId id that was used to configure goedle.io sdk.
 */
- (NSString *)getAppId;

/*!
 @abstract The current apiKey that was used to configure goedle.io sdk.
 */
- (NSString *)getApiKey;


/*!
 @abstract The current gcmSenderId that was used to configure goedle.io sdk.
 */
- (NSString *)getGcmSenderId;

/*!
 @abstract Send POST request to goedle.io Backend.
 */
+ (void)trackLaunch:(NSString * )event;

+ (void)trackACK:(NSDictionary * )userInfo;

+ (void)track:(NSString * )event;

+ (void)track:(NSString * )event :(NSString * )event_id;

+ (void)track:(NSString * )event :(NSString * )event_id :(NSString * )event_value;

+ (void)trackGeo:(NSString * )event :(NSString * )geoHash;

+ (void)trackGeo:(NSString * )event :(NSString * )event_id :(NSString * )geoHash;

+ (void)buildTrackData:(NSString * )event :(NSString * )event_id :(NSString * )geoHash :(NSString * )event_value;

+ (void)jumpToTarget:(NSString * )target;

+ (void)sendMessage:(NSData *) ga;

+ (bool)buildUserId;

+(void)sendToken:(NSString *)deviceToken;

+(void)sendAPNSToken:(NSData *)deviceToken;

+(BOOL) checkAppVersionInNSUserDefaults;

+ (void)makeToastBox:(NSDictionary * )aps;
/*!
 @abstract hash String with sha1
 @param str content of the payload it should be hashed with the content (values GoedleAtom) and the apiKey to use it as ane authentification on the server
 */
+ (NSString *)shaOne:(NSString *)str ;

+ (NSString *)identifierForAdvertising;

+ (NSString *)buildTrackRequest:(NSString * )event;

@end

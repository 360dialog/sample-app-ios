//
//  This file is part of Dialog 360 SDK.
//  See the file LICENSE.txt for copying permission.
//

#import <Foundation/Foundation.h>

#import "D360LogLevel.h"
#import "D360Compatibility.h"

@class D360Options;
@class D360PushService;
@class D360UserService;
@class D360EventService;
@class D360URLService;
@class D360Channel;
@class D360InAppService;
@class D360Identifiers;
@class D360DataService;
@class D360InboxService;

/**
 * The `D360` manages the 360 Dialog services. the `startWithOptions:` should be
 * called from within your application delegate's `application:didFinishLaunchingWithOptions:` method
 * to initialize the shared instance.
 *
 * To access the different services, use the class accessors
 */
@interface D360 : NSObject


NS_ASSUME_NONNULL_BEGIN

#pragma mark - Starting the SDK

/**
 *  Starts the D360 SDK. You need to call this method before being able to use any of the SDK features. The simpliest way to start the
 *  SDK is by providing only the API key:
 *
 *  ```objc
 * D360Options *options = [D360Options optionsWithAppId:@"12345" apiKey:@"aaa-bbbb-cccc-dddd"];
 *  [D360 startWithOptions:options];
 *  ```
 *
 *  @param options A `D360Options` object containing information such as `apiKey`
 *
 *  @see `D360Options`
 */
+ (void)startWithOptions:(D360Options *)options NS_SWIFT_NAME(start(withOptions:));

#pragma mark - Accessing Services

/**
 * Returns the shared `D360PushService` instance used for handeling push notifications
 *
 * @return The shared `D360PushService` instance
 * @see `D360PushService`
 */
+ (D360PushService *)push;

/**
* Use this method to access the `D360EventService` object for handling events
*
* @return The shared `D360EventService` instance
* @see `D360EventService`
*/
+ (D360EventService *)events;

/**
* Use this method to access the `D360URLService` object for handling anything related to deeplinks or links
*
* @return The shared `D360URLService` instance
* @see `D360URLService`
*/
+ (D360URLService *)urls;

/**
* Use this method to access the `D360DataService` object for handling anything related to custom data callbacks
*
* @return The shared `D360DataService` instance
* @see `D360DataService`
*/
+ (D360DataService *)data;

/**
 * Returns the shared `D360UserService` instance used for handling users
 *
 * @return The shared `D360UserService` instance
 * @see `D360UserService`
 */
+ (D360UserService *)users;


/**
 * Returns the shared `D360InAppService` instance used for handling in-app messages
 *
 * @return The shared `D360InAppService` instance
 * @see `D360InAppService`
 */
+ (D360InAppService *)inApp;

/**
 * Method used for accessing internal SDK identifiers.
 *
 * @return The instance of the identifiers
 */
+ (D360Identifiers *)ids;

/**
 * Method used for accessing the Inbox Service
 *
 * @return The instance of the Inbox service
 */
+ (D360InboxService *)inbox;

#pragma mark - Miscellaneous

/**
 * This method can be used to set options on a given communication channel. Currently only opt-in or out for
 * the push channel is supported.
 *
 * To opt out from push notifications, you would use
 *
    ```objc
    D360Channel *push = [D360Channel pushChannel];
    push.optIn = NO;

    [D360 updateChannel:push];
    ```
 *
 * @param channel The channel settings you want to update.
 * @see `D360Channel`
 * @warning Note that the options are not persisted locally so it is up to the application to track the current channel state
 */
+ (void)updateChannel:(D360Channel*)channel;

/**
 *  Sets the log level
 *
 *  @param logLevel The level of logging you want to see. By default the log level is set to D360LogLevelInfo
 *
 *  @see `D360LogLevel`
 */
+ (void)setLogLevel:(D360LogLevel)logLevel;

/**
 *  The D360 shared instance
 */
+ (instancetype)instance;

/**
 * Gets the SDK version
 */
+ (NSString *)kitVersion;


@end

NS_ASSUME_NONNULL_END

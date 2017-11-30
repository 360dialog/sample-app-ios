//
//  This file is part of Dialog 360 SDK.
//  See the file LICENSE.txt for copying permission.
//

#import <Foundation/Foundation.h>
#import "D360Compatibility.h"
#import "D360LogLevel.h"

@protocol D360Network;

@class D360EventsOptions;
@class D360InboxOptions;

NS_ASSUME_NONNULL_BEGIN

/**
 * The `D360Options` class is the entry point for configuring the SDK option.
 * All the options must be set before calling `D360 startWithOptions` otherwise they have no effect
 */
@interface D360Options : NSObject


#pragma mark - SDK Start
/**
 * The Application ID found in your dashboard
 *
 *  @note The API key must not be empty or nil in which case a `NSInternalInconsistencyException` will be thrown. The leading and trailing spaces are automatically trimmed.
 *
 */
@property (nonatomic, readonly) NSString *appID;

/**
 *  The API secret key found in your dashboard
 *
 *  @note The API key must not be empty or nil in which case a `NSInternalInconsistencyException` will be thrown. The leading and trailing spaces are automatically trimmed.
 *
 */
@property (nonatomic, readonly) NSString *apiKey;

#pragma mark - User Session

/**
 * The time interval in seconds for a user session to timeout when the app is in the background or not running.
 * If the app is in the background for a shorter interval than this value, the session will be reused.
 * The value must be an integer bigger than 0.
 */
@property (nonatomic, assign) NSTimeInterval sessionBackgroundTimeout;

#pragma mark - Remote Notification

/**
 * This property is used to remove the application's badge count and to clear the notification center when the application starts. Default is `NO`
 *
 * @note When the property is set to `YES`, the application icon badge count and the notification center will be cleared regardless of the notification origin.
 * If you use other push services or local push notification, you shoud probably not enable this setting and handle the badge count removal by yourself.
 *
 */
@property (nonatomic, assign) BOOL clearNotificationsAtStart;

/**
 * This property is used to remove the application's badge count and to clear the notification center when the user taps on a 360dialog notification. Default is `NO`
 *
 * @note When the property is set to `YES`, the application icon badge count and the notification center will be cleared regardless of the notification origin.
 * If you use other push services or local push notification, you shoud probably not enable this setting and handle the badge count removal by yourself.
 *
 */
@property (nonatomic, assign) BOOL clearNotificationsOnTap;

#pragma mark - Events


/**
 * Object holding the settings related to events.
 */
@property (nonatomic, strong, readonly) D360EventsOptions *eventsOptions;

/**
 * This property determines how often in seconds are the queued events send to the backend.
 *
 * @warning A value equal to `0.0` will disable the event sending and you should call manually the `D360EventService` `flush` method
 *
 * @warning Deprecated: Please Use the `eventOptions.eventsFlushInterval` instead
 */
@property (nonatomic, assign) NSTimeInterval eventsFlushInterval __deprecated_msg("Use the eventOptions.eventsFlushInterval instead");

#pragma mark - Inbox

/// The inbox options
@property (nonatomic, strong, readonly) D360InboxOptions *inboxOptions;

#pragma mark - Miscellaneous


/**
 * When you integrate the 360dialog SDK for the first time, it will consider all installations as new. If you can detect that a user actually updated
 * your application, you can call this method . In this case, the first SDK start on a given device will not be considered as a new installation
 * by the campaign management system.
 */
-(void) markInstallationAsUpdated;

/**
 *  Sets the log level
 *
 *  @param logLevel The level of logging you want to see. By default the log level is set to D360LogLevelInfo
 *
 *  @see `D360LogLevel`
 */
- (void)setLogLevel:(D360LogLevel)logLevel;


/**
 * This method is not available
 *
 * @note Use `initWithAppId:apiKey:` to create a new instance
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 * This method is not available
 *
 * @note Use `initWithAppId:apiKey:` to create a new instance
 */
- (instancetype)new NS_UNAVAILABLE;

/**
 * @param appId The application id found in the dashbooard.
 * @param apiKey The API secret key found in the dashboard.
 * @return The option object that you can use to start the SDK with.
 */
- (instancetype)initWithAppId:(NSString *)appId apiKey:(NSString *)apiKey NS_DESIGNATED_INITIALIZER;

/**
 * Factory method for instanciating the options.
 *
 * @param appId The application id found in the dashbooard.
 * @param apiKey The API secret key found in the dashboard.
 *
 * @return The option object that you can use to start the SDK with.
 */
+ (instancetype)optionsWithAppId:(NSString *)appId apiKey:(NSString *)apiKey;


@end

NS_ASSUME_NONNULL_END

//
//  This file is part of 360 Dialog SDK.
//  See the file LICENSE.txt for copying permission.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class D360Channel;

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 100000
@import UserNotifications;
#else
typedef NS_ENUM(NSUInteger, UNNotificationPresentationOptions);
#endif

@class UNUserNotificationCenter;
@class UNNotification;
@class UNNotificationResponse;

NS_ASSUME_NONNULL_BEGIN

/**
 * The `D360PushService` is the entry point for handling everything related to remote notifications.
 *
 * @note You cannot instantiate this object. Instead, use`[D360 push]` to obtain a shared instance.
 */
@interface D360PushService : NSObject


#pragma mark - Remote Notifications

/**
 *  This method sends the Apple's remote notification device token to 360 Dialog servers
 *
 *  @param deviceToken The token received in the `application:didRegisterForRemoteNotificationsWithDeviceToken:` delegate
 */
- (void)registerDeviceToken:(NSData *)deviceToken;

/**
 * This method sends the user categories  that you registered on your app once the user allows notifications.
 * It will allow you to use those categories from the 360 Dialog Dashboard.
 *
 * This method should be placed in the `UIApplicationDelegate` `didRegisterUserNotificationSettings` method
 * @param categories A set of `UIUserNotificationCategory` or `UNNotificationCategory` you registered for.
 */
- (void)registerNotificationCategories:(nullable NSSet *)categories;

/**
 * This method forwards the received push notification to the 360 Dialog. The SDK takes care of calling the
 * completion handler if this is actually a 360 Dialog notification.
 *
 * @param userInfo An NSDictionary passed in from the `didReceiveRemoteNotification:fetchCompletionHandler:` call
 * @param completionHandler A block passed in from the `didReceiveRemoteNotification:fetchCompletionHandler:` call
 * @return  `YES` if the notification is a 360dialog payload. In this case the completionHandler is called by the SDK
 *          and the application must not call it again
 *
 *          `NO` if this is not a 360dialog in which case it is up to the application to call the completion handler
 */
- (BOOL)handleNotification:(NSDictionary *)userInfo
    fetchCompletionHandler:(nullable void (^)(UIBackgroundFetchResult result))completionHandler;


/**
 * Use this method to forward the received in the `[UserNotificationDelegate userNotificationCenter:willPresentNotification:withCompletionHandler:]` to our SDK.
 *
 * @param center The app's current notification center passed in in the UNNotificationDelegate call.
 * @param notification The notification  received in the the UNNotificationDelegate call.
 * @param completionHandler The completion handler passed in the the UNNotificationDelegate call.
 * @return `YES` if the d360 SDK handled the push `NO` otherwise
 *
 * @note When this method returns `NO`, it means that the push was from another push provider that 360dialog and it's up to you to call the completion block.
 */
-(BOOL)handleNotificationCenter:(UNUserNotificationCenter *)center willPresentNotification:(UNNotification *)notification withCompletionHandler:(void (^)(UNNotificationPresentationOptions options))completionHandler NS_AVAILABLE_IOS(10_0);

/**
 * Use this method to forward the received in the `[UserNotificationDelegate userNotificationCenter:didReceiveNotificationResponse:withCompletionHandler]` to our SDK.
 *
 * @param center The app's current notification center passed in in the UNNotificationDelegate call.
 * @param response The notification response received in the the UNNotificationDelegate call.
 * @param completionHandler The completion handler passed in the the UNNotificationDelegate call.
 * @return `YES` if the d360 SDK handled the push `NO` otherwise
 *
 * @note When this method returns `NO`, it means that the push was from another push provider that 360dialog and it's up to you to call the completion block.
 */
-(BOOL)handleNotificationCenter:(UNUserNotificationCenter *)center didReceiveNotificationResponse:(UNNotificationResponse *)response withCompletionHandler:(void (^)())completionHandler NS_AVAILABLE_IOS(10_0);

#pragma mark - Miscellaneous

/**
 * This method is not available
 *
 * @note Use `[D360 push]` to obtain an instance of this object.
 */
-(instancetype) init NS_UNAVAILABLE;

/**
 * This method is not available
 *
 * @note Use `[D360 push]` to obtain an instance of this object.
 */
-(instancetype) new NS_UNAVAILABLE;

NS_ASSUME_NONNULL_END

@end

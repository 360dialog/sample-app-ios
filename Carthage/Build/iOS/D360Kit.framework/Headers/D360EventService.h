//
//  This file is part of Dialog 360 SDK.
//  See the file LICENSE.txt for copying permission.
//

#import <Foundation/Foundation.h>
#import "D360Compatibility.h"


@class D360Client;
@class D360Options;
@class D360EventsOptions;

NS_ASSUME_NONNULL_BEGIN

/**
 * The `D360EventService` is the entry point for sending the events of your application to the 360 Dialog backend.
 *
 * You can use the predefined event methods or the custom event one.
 *
 * All the methods to log events will return immediately and cache the request to be
 * handled "eventually." That is, the request will be in the next event batch if possible
 * or the next time a network connection is available.
 *
 * @note You cannot instantiate this object. Instead, use`[D360 events]` to obtain a shared instance.
 */
@interface D360EventService : NSObject

/// The object encapsulating the events tracking options.
@property (nonatomic, strong, readonly) D360EventsOptions *options;

/**
 * Use this method if you want to disable all the event tracking that you integrated in your application
 * This method has no impact on the internal SDK events.
 *
 * @param disable `YES` will disable the event tracking and will ignore any event calls of this calls.
 *
 * @note The SDK does not persist this setting and is valid only until the next app/sdk start.
 *
 * @warning Deprecated: Please use the `D360.events.options.trackingDisabled` instead.
 */
-(void) setEventTrackingDisabled:(BOOL) disable __deprecated_msg("Please use the D360.events.options.trackingDisabled instead");

/**
 * Flushes the current event queue to send the events now instead of in the next disaptch.
 *
 * By default, the events are queued and sent on the next dispatch round. You can use this method to flush all the currently
 * queued events. This method can be used just after logging an event that you need to be send as soon as possible to the backed.
 */
- (void)flush;

#pragma mark - Custom

/**
 * Logs a custom event that happened. Use this method to track any behaviour of the user in the application. You can optionally add any parameters
 * to the event.
 *
 * @param name The name of the custom event to report.
 * @param parameters The parameters related to the event.
 */
- (void)logCustomEventWithName:(NSString *)name
                    parameters:(nullable D360_GENERIC_NSDICTIONARY (NSString *, id) *)parameters NS_SWIFT_NAME(logCustomEvent(name:parameters:));


#pragma mark - Shopping


/**
 *  Logs the event when a user adds an item to a shopping cart.
 *
 *  @param productIdentifier    The machine-readable, unique item identifier E.g: SKUXYZ
 *  @param productName          The human-readable product name.
 *  @param productPrice         The price of the purchased item.
 *  @param currency             The ISO4217 currency code. e.g EUR.
 *  @param parameters           A dictionary of custom attributes to associate with this event.
 */
- (void)logAddToCartWithProductIdentifier:(NSString *)productIdentifier
                              productName:(nullable NSString *)productName
                             productPrice:(nullable NSDecimalNumber *)productPrice
                                 currency:(nullable NSString *)currency
                               parameters:(nullable D360_GENERIC_NSDICTIONARY (NSString *, id) *)parameters NS_SWIFT_NAME(logAddToCart(productIdentifier:name:price:currency:parameters:));


/**
 *  Logs the event when the user completed the shopping cart and started the checkout process.
 *
 *  @param totalCartPrice   The total price of the cart.
 *  @param currency         The ISO4217 currency code. e.g: EUR
 *  @param itemCount        The number of items in the cart.
 *  @param parameters       A dictionary of custom attributes to associate with this event.
 */
- (void)logStartCheckoutWithPrice:(NSDecimalNumber *)totalCartPrice
                         currency:(nullable NSString *)currency
                        itemCount:(nullable NSNumber *)itemCount
                       parameters:(nullable D360_GENERIC_NSDICTIONARY(NSString *, id) *)parameters NS_SWIFT_NAME(logStartCheckout(totalCartPrice:currency:itemCount:parameters:));


/**
 *  Logs the event when the user completed a purchase.
 *
 *  @param totalOrderPrice       The total of the purchased price including shipping fees.
 *  @param currency             The ISO4217 currency code. e.g EUR.
 *  @param parameters           A dictionary of custom attributes to associate with this purchase.
 */
- (void)logPurchaseWithPrice:(NSDecimalNumber *)totalOrderPrice
                    currency:(nullable NSString *)currency
                   itemCount:(nullable NSNumber *)itemCount
                  parameters:(nullable D360_GENERIC_NSDICTIONARY(NSString *, id) *)parameters NS_SWIFT_NAME(logPurchase(totalOrderPrice:currency:itemCount:parameters:));


#pragma mark - Searching

/**
 * Logs the event when the user performed a search. For example, while searching for an article in a shopping app, or searching
 * for a destination in a travel app.
 *
 * @param query         The query that the user is searching for.
 * @param parameters    A dictionary of custom attributes to associate with the search.
 */
- (void)logSearchWithQuery:(NSString *)query
                parameters:(nullable D360_GENERIC_NSDICTIONARY(NSString *, id) *)parameters NS_SWIFT_NAME(logSearch(query:parameters:));

#pragma mark - Accounts

/**
 * Logs the event when the user registers or signs up to the application.
 *
 * @param registerMethod    The type of the registration. For example "email" "facebook" "oauth".
 * @param parameters        A dictionary of custom attributes to associate with the event.
 *
 */
- (void)logUserRegisterWithMethod:(NSString *)registerMethod
                       parameters:(nullable D360_GENERIC_NSDICTIONARY(NSString *, id) *)parameters NS_SWIFT_NAME(logUserRegister(registerMethod:parameters:));

/**
 * Logs the event when the user logs in to the application.
 *
 * @param loginMethod   The type of the login. For example "email" "facebook" "oauth".
 * @param parameters    A dictionary of custom attributes to associate with the event.
 *
 * @note This method is only for tracking purposes. If you want all other events to be associated with this user,
 * you should call the SDK method `changeUserID`. See `D360UserService`.
 */
- (void)logUserLoginWithMethod:(NSString *)loginMethod
                    parameters:(nullable D360_GENERIC_NSDICTIONARY(NSString *, id) *)parameters NS_SWIFT_NAME(logUserLogin(loginMethod:parameters:));


/**
 * Logs the event when the user subscribes to a content for a specific amount of time. An example would
 * be when the user subscribes for 2 months of music streaming service.
 *
 * @param contentIdentifier The identifier of your consumable product.
 * @param contentName       The name of the product.
 * @param length            The length or amount of the subscription in days. The following applies though:
 *                          The value -1 is interpreted as unlimited/forever.
 *                          The value 0 is interpreted as none/unsubscribe.
 * @param parameters        A dictionary of custom attributes to associate with the event.
 */
- (void)logSubscriptionToContent:(NSString *)contentIdentifier
                     contentName:(nullable NSString *)contentName
              subscriptionLength:(nullable NSNumber *)length
                      parameters:(nullable D360_GENERIC_NSDICTIONARY(NSString *, id) *)parameters NS_SWIFT_NAME(logSubscription(toContent:contentName:subscriptionLength:parameters:));


#pragma mark - Games

/**
 *  Logs the event when the user ends a game level.
 *
 *  @param levelName    The name of the level completed, E.g. "1" or "Tutorial".
 *  @param score        The score the user completed the level with.
 *  @param levelSuccess A boolean representing whether or not the level was completed successfully.
 *  @param parameters   A dictionary of custom attributes to associate with this event.
 */
- (void)logLevelEndWithName:(nullable NSString *)levelName
                      score:(nullable NSNumber *)score
                    success:(nullable NSNumber *)levelSuccess
                 parameters:(nullable D360_GENERIC_NSDICTIONARY(NSString *, id) *)parameters NS_SWIFT_NAME(logLevelEnd(levelName:score:success:parameters:));


/**
 *  Logs the event when the user stars a game level.
 *
 *  @param levelName    The name of the level started, E.G. "1" or "Tutorial".
 *  @param parameters   A dictionary of custom attributes to associate with this event.
 */
- (void)logLevelStartWithName:(NSString *)levelName
           parameters:(nullable D360_GENERIC_NSDICTIONARY(NSString *, id) *)parameters NS_SWIFT_NAME(logLevelStart(levelName:parameters:));

/**
 * Logs the event when the user unlocks an achievement.
 *
 *  @param achievementIdentifier The id of the achievement.
 *  @param parameters            A dictionary of custom attributes to associate with this event.
 */
- (void)logAchievementWithIdentifier:(NSString *)achievementIdentifier
                          parameters:(nullable D360_GENERIC_NSDICTIONARY(NSString *, id) *)parameters NS_SWIFT_NAME(logAchievement(achievementIdentifier:parameters:));


#pragma mark - Miscellaneous

/**
 * Logs the event when the user sees a specific content of the app. It can, but does not necessarily, relate to a shopping
 * application. An example would be to log when the user opens a setting screen in the application. Another would be
 * when the user opens the detail page of a specific product.
 *
 * @param viewName          The name or identifier that identifies the view the user opened.
 * @param sectionName       An optional sectionName.
 * @param itemIdentifier    The product identifier that was viewed.
 * @param itemName          The item name that was viewed.
 * @param parameters        A dictionary of custom attributes to associate with this event.
 */
- (void)logViewWithName:(NSString *)viewName
            sectionName:(nullable NSString *)sectionName
         itemIdentifier:(nullable NSString *)itemIdentifier
               itemName:(nullable NSString *)itemName
             parameters:(nullable D360_GENERIC_NSDICTIONARY (NSString *, id) *)parameters NS_SWIFT_NAME(logView(viewName:sectionName:itemIdentifier:itemName:parameters:));

/**
 * Logs the event when an item was rated by the user. E.g. a product on an online shop or a hotel in a booking app
 *
 * @param value          The value of the rating that is meaningful to you. e.g. "1", "2" or "a","b".
 * @param itemIdentifier The id of the rated item.
 * @param parameters  A dictionary of custom attributes to associate with this event.
 */
- (void)logRatingWithValue:(NSString *)value
            itemIdentifier:(nullable NSString *)itemIdentifier
                parameters:(nullable D360_GENERIC_NSDICTIONARY(NSString *, id) *)parameters NS_SWIFT_NAME(logRating(ratingValue:itemIdentifier:parameters:));


/**
 * Logs the event when a setting was changed in the application

 * @param settingName   The name of the setting E.g "Share location".
 * @param oldValue      The old value of the setting.
 * @param newValue      The new value of the setting.
 * @param parameters    A dictionary of custom attributes to associate with this event.
 */
- (void)logSettingsUpdateWithName:(NSString *)settingName
                 oldValue:(nullable NSString *)oldValue
                 newValue:(nullable NSString *)newValue
               parameters:(nullable D360_GENERIC_NSDICTIONARY(NSString *, id) *)parameters NS_SWIFT_NAME(logSettingUpdate(settingName:oldValue:newValue:parameters:));

/**
 * Logs the geolocation of an event. For example when the user entered a location.
 *
 * @param latitude  The latitude in degrees of the coordinate point.
 * @param longitude The longitude in degrees of the coordinate point.
 * @param altitude  The altitude in meters of the coordinate point.
 *
 * @warning Location tracking is a sensitive point and you should inform the user about it.
 */
- (void)logLocationWithLatitude:(NSNumber *)latitude
                      longitude:(NSNumber *)longitude
                       altitude:(nullable NSNumber *)altitude
                     parameters:(nullable D360_GENERIC_NSDICTIONARY(NSString *, id) *)parameters NS_SWIFT_NAME(logLocation(latitude:logitude:altitude:parameters:));


/**
 * This method is not available
 *
 * @note Use `[D360 events]` to obtain an instance of this object.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 * This method is not available
 *
 * @note Use `[D360 events]` to obtain an instance of this object.
 */
- (instancetype)new NS_UNAVAILABLE;

NS_ASSUME_NONNULL_END

@end

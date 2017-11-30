//
//  This file is part of 360 Dialog SDK.
//  See the file LICENSE.txt for copying permission.
//

#import <Foundation/Foundation.h>

@protocol D360URLDelegate;
@class D360URLService;



NS_ASSUME_NONNULL_BEGIN

/**
 * The `D360URLDelegate` protocol allows you to configure the behaviour when the SDK is about the open a URL.
 * You can use this protocol to handle the opening of a URL yourself instead of letting the SDK do it.
 */
@protocol D360URLServiceDelegate <NSObject>

/**
 * Asks the delegate if the SDK should open the URL.
 *
 * @param service The url shared instance
 * @param url The URL to open.
 * @return `YES` if the SDK should open this URL, `NO` otherwise
 *
 * @note If you return `NO`, the SDK will not open the URL and you can handle this URL yourself. E.g. by loading it in a custom web view or `SFSafariViewController`
 */
- (BOOL)urlService:(D360URLService *)service shouldOpenURL:(NSURL *)url;

@end


/**
 * The `D360URLService` is the entry point for handling everything related to links, urls and deep links.
 *
 * @note You cannot instantiate this object. Instead, use`[D360 links]` to obtain a shared instance.
 */
@interface D360URLService : NSObject

/**
 * An a optional delegate allowing you to handle the opening of URLs in a custom way
 *
 * @see `D360URLControllerDelegate`
 */
@property (nonatomic, weak, nullable) id <D360URLServiceDelegate> delegate;


/**
 * Use this method to let the 360 Dialog backend know that the application was opened from a deeplink.
 * This method should present in the `UIApplicationDelegate` `openURL` methods
 *
 * @param url The deeplink used to open your app
 * @param sourceApplication The source application that opened your app. See `UIApplicationOpenURLOptionsSourceApplicationKey`
 */
- (void)reportOpenURL:(NSURL *)url sourceApplication:(nullable NSString *)sourceApplication;

#pragma mark - Miscellaneous

/**
 * This method is not available
 *
 * @note Use `[D360 urls]` to obtain an instance of this object.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 * This method is not available
 *
 * @note Use `[D360 urls]` to obtain an instance of this object.
 */
- (instancetype)new NS_UNAVAILABLE;

NS_ASSUME_NONNULL_END

@end

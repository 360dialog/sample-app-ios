//
//  This file is part of 360 Dialog SDK.
//  See the file LICENSE.txt for copying permission.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

#import "D360Compatibility.h"

@class D360InAppMessage;
@class D360InAppService;

NS_ASSUME_NONNULL_BEGIN


/// Represents the different choices for displaying in-app messages.
typedef NS_ENUM(NSUInteger, D360DisplayChoice) {
    /// The campaign message will be displayed now.
    D360DisplayChoiceNow,

    /// The campaign message will be discarded.
    D360DisplayChoiceDiscard,

    /// The campaign message will not be displayed. It's up to you to call the display method
    D360DisplayChoiceManual,
};

/// The reasons why a in-app was closed
typedef NS_ENUM(NSUInteger, D360DismissReason) {
    /// The in-app was dismissed because the user tapped on a in-app action.
    D360DismissReasonUserEngaged,

    /// The in-app was explicitly closed by the user.
    D360DismissReasonUserAbort,
};

/**
 * The `D360InAppServiceDelegate` can be used to control the behaviour of the in-app campaigns when their are about
 * to be presented to the user.
 */
@protocol D360InAppServiceDelegate <NSObject>

@optional

/**
 * Asks the delegate whether an in-app should be presented to the user.
 *
 * @param inAppService The reference to the in-app service.
 * @param inAppMessage The in-app message that will be presented.
 * @return The decision ruling what to do with the in-app. See `D360DisplayChoice`
 *
 * @note The default implementation will present the in-app message immediately. You can use this method to postpone or discard the presentation
 * of the in-app message.
 */
- (D360DisplayChoice)inAppService:(D360InAppService *)inAppService shouldPresentInAppMessage:(D360InAppMessage *)inAppMessage;

/**
 * Informs the delegate that an in-app message is about to be presented to the user.
 *
 * @param inAppService The reference to the in-app service.
 * @param inAppMessage The in-app message that will be presented.
 */
- (void)inAppService:(D360InAppService *)inAppService willPresentInAppMessage:(D360InAppMessage *)inAppMessage;

/**
 * Informs the delegate that an in-app message is was presented to the user.
 *
 * @param inAppService The reference to the in-app service.
 * @param inAppMessage The in-app message that is being presented.
 */
- (void)inAppService:(D360InAppService *)inAppService didPresentInAppMessage:(D360InAppMessage *)inAppMessage;

/**
 * Asks the delegate if the in-app message should be dismissed after the user performed an action on it.
 *
 * @param inAppService The reference to the in-app service.
 * @param inAppMessage The in-app message that will be displayed.
 * @return `YES` if the in-app should be dismissed, `NO` if it should stay on screen.
 *
 * @note The default implementation will dismiss the in-app message when the closes it or performs an action on it.
 * You can use this method to prevent the in-app to be closed when the user taps on an action. An example would
 * be a multi screen in-app asking the user for several application (notification, location) permissions.
 */
- (BOOL)inAppService:(D360InAppService *)inAppService shouldDismissInAppMessage:(D360InAppMessage *)inAppMessage;

/**
 * Informs the delegate that an in-app message was closed.
 *
 * @param inAppService The reference to the in-app service.
 * @param inAppMessage The in-app message that will be displayed.
 * @param reason The reason why the in-app was closed.
 */
- (void)inAppService:(D360InAppService *)inAppService didDismissInAppMessage:(D360InAppMessage *)inAppMessage withReason:(D360DismissReason)reason;

/**
 * Informs the delegate that an in-app presentation failed.
 *
 * @param inAppService The reference to the in-app service.
 * @param inAppMessage The in-app message that will be displayed.
 * @param error The error why the in-app could not be presented.
 */
- (void)inAppService:(D360InAppService *)inAppService didFailToPresentInApp:(D360InAppMessage *)inAppMessage withError:(NSError *)error;

/**
 * Asks the delegate for the view controller to present the full screen in-app message when it is about to be displayed
 *
 * @param inAppMessage The in-app message that will be displayed.
 * @return The view controller from which the full screen in-app will be presented
 *
 * @note If you don't implement this method, the 360dialog SDK will present the in-app message from the current
 * top most view controller.
 */
- (UIViewController *)viewControllerForPresentingInAppMessage:(D360InAppMessage *)inAppMessage NS_SWIFT_NAME(viewController(forPresenting:));

@end


/**
 * The `D360InAppService` provides methods for displaying the in-app messages
 */
@interface D360InAppService : NSObject

/// The object that acts as the delegate of the in-app service. See `D360InAppServiceDelegate`
@property (nonatomic, weak, nullable) id <D360InAppServiceDelegate> delegate;


/**
 * Call this method to present immediately a in-app message
 * @param inAppMessage The in-app message that you received via the `inAppService:displayChoiceForInApp:` delegate
 * @param parentViewController The parent view controller from which the in-app will be displayed.
 *
 * @note You should use this method only if you returned the `D360DisplayChoiceManual` from the `inAppService:displayChoiceForInApp:` delegate call
 * @warning The 360dialog SDK does not verify that a given in-app message was already displayed and will display the inAppMessage unconditionally.
 */
-(void)presentInAppMessage:(D360InAppMessage *) inAppMessage fromParentViewController:(nullable UIViewController *)parentViewController;

#pragma mark - Miscellaneous

/**
 * This method is not available
 *
 * @note Use `[D360 inApp]` to obtain an instance of this object.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 * This method is not available
 *
 * @note Use `[D360 inApp]` to obtain an instance of this object.
 */
- (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
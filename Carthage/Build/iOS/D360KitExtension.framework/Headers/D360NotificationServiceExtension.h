//
//  This file is part of Dialog 360 SDK.
//  See the file LICENSE.txt for copying permission.
//

#import <Foundation/Foundation.h>

#import <UserNotifications/UserNotifications.h>


/**
 * 360dialog subclass on a `UNNotificationServiceExtension` that processes automatically the rich notifications sent via
 * our platform. You can subclass directly this class without any further implementation in order to enable the 360dialog
 * rich notifications.
 */
@interface D360NotificationServiceExtension : UNNotificationServiceExtension

@end

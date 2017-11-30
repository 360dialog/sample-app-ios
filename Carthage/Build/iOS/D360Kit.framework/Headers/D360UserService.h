//
//  This file is part of 360 Dialog SDK.
//  See the file LICENSE.txt for copying permission.
//

#import <Foundation/Foundation.h>


/**
 * The `D360UserService` is the entry point for handling everything related to the users
 *
 * @note You cannot instantiate this object. Instead, use`[D360Users push]` to obtain a shared instance.
 */
@interface D360UserService : NSObject



/**
 * You can use this method to attribute all the SDK events to your specific user. The external user id will be sent
 * along with the events and this user id will be used by the backend in case you imported your user database
 * A use case is that your user logs in to your system and then you call this method with the user id that has a
 * meaning in your system
 *
 * @note Make sure that you normalize this id (e.g. by trimming spaces, forcing it to lower case)
 * @warning You should not unset this user id when the user logs out instead only set it when the user logs in.
 *
 * @param userId The user id that can identify users in your system.
 *
 */
- (void)changeUserID:(NSString *)userId;

#pragma mark - Miscellaneous

/**
 * This method is not available
 *
 * @note Use `[D360 users]` to obtain an instance of this object.
 */
-(instancetype) init NS_UNAVAILABLE;

/**
 * This method is not available
 *
 * @note Use `[D360 users]` to obtain an instance of this object.
 */
-(instancetype) new NS_UNAVAILABLE;

@end
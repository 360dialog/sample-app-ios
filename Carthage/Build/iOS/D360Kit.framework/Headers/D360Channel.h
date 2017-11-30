//
//  This file is part of 360 Dialog SDK.
//  See the file LICENSE.txt for copying permission.
//

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

/**
 * The `D360Channel` class is used for setting channel options on the backend. Use the factory methods
 * to obtain the communication channel, set the properties you want to configure (currently only opt in/out)
 * and then call the SDK method `updateChannel:`
 *
 * @see `D360PushService`
 */
@interface D360Channel : NSObject

/**
 * Indicates whether this channel should be used to comunicate back to the SDK or not.
 * For instance, if you wish to out out from the push notifications, you set this property to `NO`
 * then use the `D360PushService` method `updateChannel:`
 */
@property (nonatomic, assign) BOOL optIn;

/**
 * Factory method that returns the push channel that you can use for its configuration
 * @return The channel object on which you can set the configuration
 */
+(instancetype) pushChannel;


#pragma mark - Miscellaneous

/**
 * This method is not available
 *
 * @note Use the factory methods to access instances of this object
 */
-(instancetype) init NS_UNAVAILABLE;

/**
 * This method is not available
 *
 * @note Use the factory methods to access instances of this object
 */
-(instancetype) new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

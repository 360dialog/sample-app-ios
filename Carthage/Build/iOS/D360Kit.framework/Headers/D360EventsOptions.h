//
//  This file is part of 360 Dialog SDK.
//  See the file LICENSE.txt for copying permission.
//

#import <Foundation/Foundation.h>

/**
 * The `D360EventsOptions` class is the entry point for configuring the events tracking options.
 * Changing the properties values has immediate effect on the SDK but note that those settings are not persisted.
 * It is up to you to set again the properties when starting the SDK.
 */
@interface D360EventsOptions : NSObject

/**
 * Use this property if you want to disable all the event tracking that you integrated in your application
 * This method has no impact on the internal SDK events.
 *
 * @note The SDK does not persist this setting and is valid only until the next app/sdk start.
 */
@property(nonatomic, assign, getter=isTrackingDisabled) BOOL trackingDisabled;

/**
 * Use this property if you want to disable all the system event tracking.
 * This property has no impact on the application events SDK events.
 *
 * @note The SDK does not persist this setting and is valid only until the next app/sdk start.
 */
@property(nonatomic, assign, getter=isSystemTrackingDisabled) BOOL systemTrackingDisabled;


/**
 * This property determines how often in seconds are the queued events send to the backend.
 *
 * @warning A value equal to `0.0` will disable the event sending and you should call manually the `D360EventService` `flush` method
 */
@property (nonatomic, assign) NSTimeInterval eventsFlushInterval;

@end

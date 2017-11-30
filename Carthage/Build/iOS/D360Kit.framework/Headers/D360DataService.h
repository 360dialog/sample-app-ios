//
//  This file is part of 360 Dialog SDK.
//  See the file LICENSE.txt for copying permission.
//

#import <Foundation/Foundation.h>

@class D360DataService;
@class D360CustomPayload;
@class D360ActionsController;

NS_ASSUME_NONNULL_BEGIN

/**
 * The `D360DataServiceDelegate` notifies your application when a custom campaign payload was received.
 */
@protocol D360DataServiceDelegate <NSObject>

/**
 * Informs the delegate that a custom payload was received.
 *
 * @param service The service that received the payload
 * @param customPayload The custom payload defined in your campaign
 */
- (void)dataService:(D360DataService *)service didReceiveCustomPayload:(D360CustomPayload *)customPayload;

@end

/**
 * A 360dialog campaign can be configured to deliver a custom payload to your application. This payload is not processed
 * by the 360dialog SDK and it meant to be used by your application.
 * The `D360DataService` and `D360DataServiceDelegate` are used for this purpose
 */
@interface D360DataService : NSObject

/// The optional delegate
@property (nonatomic, weak, nullable) id <D360DataServiceDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
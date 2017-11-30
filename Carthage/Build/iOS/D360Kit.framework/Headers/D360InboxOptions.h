//
//  This file is part of 360 Dialog SDK.
//  See the file LICENSE.txt for copying permission.
//

#import <Foundation/Foundation.h>

/**
 * The `D360InboxOptions` class is the entry point for configuring the Inbox options.
 * Changing the properties values has immediate effect on the SDK but note that those settings are not persisted.
 * It is up to you to set again the properties when starting the SDK.
 */
@interface D360InboxOptions : NSObject

/**
 * The maximum number of messages that the inbox will store before purging them. The default is `0`
 * which stands for unlimited.
 */
@property (nonatomic, assign) NSUInteger maxMessagesCount;

/**
 * The duration in seconds after which a message is considered as expired. An expired message remains in the Inbox but is more likely
 * to be purged if the `maxMessagesCount` is reached.
 */
@property (nonatomic, assign) NSTimeInterval maxMessageAge;

@end
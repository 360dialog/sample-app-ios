//
//  This file is part of 360 Dialog SDK.
//  See the file LICENSE.txt for copying permission.
//

#import <Foundation/Foundation.h>
#import "D360InboxMessage.h"


NS_ASSUME_NONNULL_BEGIN

/// The filter for getting read messages
typedef NS_ENUM(NSUInteger, D360InboxReadFilter) {
    /// Fetch read or unread messages
    D360InboxReadFilterAny,

    /// Fetch read messages only
    D360InboxReadFilterRead,

    /// Fetch unread messages only
    D360InboxReadFilterNotRead
};

/// The filter for deleted read messages
typedef NS_ENUM(NSUInteger, D360InboxDeleteFilter) {
    /// Fetch deleted or not deleted messages
    D360InboxDeleteFilterAny,

    /// Fetch deleted messages only
    D360InboxDeleteFilterDeleted,

    /// Fetch non deleted messages only
    D360InboxDeleteFilterNotDeleted
};

/// This class allows you to configure which messages are fetched
@interface D360InboxFetchRequest : NSObject


/// The filter for read/unread messages. Default is D360InboxReadFilterAny
@property (nonatomic, assign) D360InboxReadFilter readFilter;

/// The filter for deleted messages. Default is D360InboxDeleteFilterNotDeleted
@property (nonatomic, assign) D360InboxDeleteFilter deleteFilter;

/**
 * The designated initializer of a fetch request.
 *
 * @note You can use the factory methods
 *
 * @param readFilter    The read filter of the messages
 * @param deleteFilter The read filter of the messages
 * @return A fetch request ready to be used by the `fetchWithRequest:completionHandler:` method.
 */
- (instancetype)initWithReadFilter:(D360InboxReadFilter)readFilter deleteFilter:(D360InboxDeleteFilter)deleteFilter NS_DESIGNATED_INITIALIZER;

#pragma mark - Convenience

/// Returns a request for any messages (read or unread) that are not deleted
+ (instancetype)inboxRequest;

/// Returns a request for only new messages that are not deleted
+ (instancetype)unreadInboxRequest;

/// Returns a request for any messages (read or unread) that were deleted
+ (instancetype)trashRequest;

/// Returns a request for all messages
+ (instancetype)anyRequest;

/// Helper factory method
+ (instancetype)requestWithReadFilter:(D360InboxReadFilter)readFilter deleteFilter:(D360InboxDeleteFilter)deleteFilter;

/// Not available, use `initWithReadFilter:deleteFilter:`
+ (instancetype)new NS_UNAVAILABLE;

/// Not available, use `initWithReadFilter:deleteFilter:`
- (instancetype)init NS_UNAVAILABLE;


@end

NS_ASSUME_NONNULL_END

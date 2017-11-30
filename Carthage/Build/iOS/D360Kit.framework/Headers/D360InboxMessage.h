//
//  This file is part of 360 Dialog SDK.
//  See the file LICENSE.txt for copying permission.
//

#import <Foundation/Foundation.h>

@class D360InboxAttachment;


/**
 * Bitmask indicating the state of a message. Note that you can use the helper methods
 * `isRead` or `isDeleted` that reflect this state as well.
 */
typedef NS_OPTIONS(NSUInteger, D360InboxMessageState) {
    /// The messages is unread and not deleted
    D360InboxMessageStateNone        = 0,

    /// Indicates whether the message was read / seen
    D360InboxMessageStateRead        = 1 << 0,

    /// Indicates whether the message was marked as deleted
    D360InboxMessageStateDeleted     = 1 << 1,
};

NS_ASSUME_NONNULL_BEGIN

/**
 * InboxMessages are messages that can be send along or independently from the native push messages.
 * You can access those messages and display a inbox to the user of the marketing messages that were received.
 * Each message can have an action associated such as openURL or InApp that can be executed e.g. when the user taps on
 * the message.
 */
@interface D360InboxMessage : NSObject

/// Inbox message title
@property (nonatomic, readonly, nullable) NSString *title;

/// Inbox message body
@property (nonatomic, readonly, copy) NSString *body;

/// The rich notification attachment (image/audio/video)
@property (nonatomic, readonly, nullable) D360InboxAttachment *attachment;

/// The date when the message as created/received
@property (nonatomic, readonly, nonnull) NSDate *date;

/// Bitmask indicating the state of the message
@property (nonatomic, readonly) D360InboxMessageState state;

/// Flag indicating whether this message has an associated campaign action. If true, you can execute that action using `D360InboxService`
@property (nonatomic, assign, readonly, getter=isExecutable) BOOL executable;

/// True is the state flag has the D360InboxMessageStateRead bit set
@property (nonatomic, assign, readonly, getter=isRead) BOOL read;

/// True is the state flag has the D360InboxMessageStateDeleted bit set
@property (nonatomic, assign, readonly, getter=isDeleted) BOOL deleted;

/**
 * The content of the custom key/value context data as set in your campaign.
 */
@property (nonatomic, strong, readonly, nullable) NSDictionary *contextualData;



@end

NS_ASSUME_NONNULL_END

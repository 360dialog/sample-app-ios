//
//  This file is part of 360 Dialog SDK.
//  See the file LICENSE.txt for copying permission.
//

#import <Foundation/Foundation.h>
#import "D360InboxMessage.h"

@class D360InboxService;
@class D360InboxFetchRequest;
@class D360InboxOptions;

NS_ASSUME_NONNULL_BEGIN

/**
 * Use the delegate to get notified when the inbox content changes
 */
@protocol D360InboxServiceDelegate <NSObject>

@optional

/**
 * Called when the SDK receives an inbox message.
 *
 * @param inboxService The inbox service.
 * @param inboxMessage The received message
 *
 * @note This method is not guaranteed to be called on the main thread.
 *
 * @note The state of the message could already ne "read" so you might want to check the isRead property before notifying the user.
 *
 */
- (void)inboxService:(D360InboxService *)inboxService didReceiveInboxMessage:(D360InboxMessage *)inboxMessage;

/**
 * Called when the SDK updates an inbox message. This happens usually when a user taps on a push message that was associated
 * with a inbox message. In this case the SDK marks the inbox as read automatically.
 *
 * When this delegate is called, you should reload your views with the new inbox message
 *
 * @param inboxService The inbox service.
 * @param inboxMessage The inbox message with its state updated.
 */
- (void)inboxService:(D360InboxService *)inboxService didUpdateInboxMessage:(D360InboxMessage *)inboxMessage;

/**
 * Called when the SDK automatically purges messages based on the `maxMessageCount` in the `D360InboxSettings`.
 *
 * @note The delegate method is not called when you call the `removeMessage:completionHandler:` method.
 *
 * @param inboxService The inbox service.
 * @param inboxMessages The inbox messages that has just been removed.
 */
- (void)inboxService:(D360InboxService *)inboxService didRemoveInboxMessages:(NSArray <D360InboxMessage *> *)inboxMessages;

@end

/**
* The `D360InboxService` provides methods for accessing InboxMessages
*/
@interface D360InboxService : NSObject

/// The inbox delegate that notifies you about inbox changes
@property (nonatomic, weak, nullable) id <D360InboxServiceDelegate> delegate;

/// The Inbox options that can be changed during runtime for immediate effect.
@property (nonatomic, strong, readonly) D360InboxOptions *options;

/// The queue on which all the completions and delegates methods will be called. By default, it is the main queue
@property (nonatomic, strong, readwrite) NSOperationQueue *delegateQueue;

/// Not available. Use [D360 inbox] to access the inbox instance
+ (instancetype)new NS_UNAVAILABLE;

/// Not available. Use [D360 inbox] to access the inbox instance
- (instancetype)init NS_UNAVAILABLE;

#pragma mark - Read

/**
 * Fetches the received inbox messages with the given request.
 * @param request The request object to configure which messages to fetch.
 * @param completionHandler The block executed after the request is processed.
 */
- (void)fetchWithRequest:(D360InboxFetchRequest *)request completionHandler:(void (^)(NSArray<D360InboxMessage *> *inboxMessages, NSError *_Nullable error))completionHandler;

#pragma mark - Update

/**
 * Updates the state of a give inbox message.
 * @param inboxMessage The inbox message to update. It's state property is set immediately to the given state and the helper properties `isRead` and `isDelete` reflect it.
 * @param state The new state to set.
 * @param completionHandler Called when the update is done. In this block you can re-fetch the inbox message with their updated state
 *
 * @note Do not re-fetch the inbox immediately after calling this method as the updated message might still not be processed. Instead, either reload your view if needed or use the completionHandler to re-fetch the inbox
 */
- (void)updateMessage:(D360InboxMessage *)inboxMessage state:(D360InboxMessageState)state completionHandler:(nullable void (^)(BOOL success, NSError *_Nullable error))completionHandler;

/**
 * Helper method that sets or remove the D360InboxMessageStateRead state
 * @param inboxMessage The inbox message to update. It's state property is immediately updated along with its `isRead` property
 * @param read `YES` to mark the message as read
 * @param completionHandler Called when the update is done. In this block you can re-fetch the inbox message with their updated state
 *
 * @note Do not re-fetch the inbox immediately after calling this method as the updated message might still not be processed. Instead, either reload your view if needed or use the completionHandler to re-fetch the inbox
 */
- (void)updateMessage:(D360InboxMessage *)inboxMessage asRead:(BOOL)read completionHandler:(nullable void (^)(BOOL success, NSError *_Nullable error))completionHandler;

/**
 * Helper method that sets or remove the D360InboxMessageStateDeleted state
 * @param inboxMessage The inbox message to update. It's state property is immediately updated along with its `isDeleted` property
 * @param deleted `YES` to mark the message as deleted
 * @param completionHandler Called when the update is done. In this block you can re-fetch the inbox message with their updated state
 *
 * @note Do not re-fetch the inbox immediately after calling this method as the updated message might still not be processed. Instead, either reload your view if needed or use the completionHandler to re-fetch the inbox
 */
- (void)updateMessage:(D360InboxMessage *)inboxMessage asDeleted:(BOOL)deleted completionHandler:(nullable void (^)(BOOL success, NSError *_Nullable error))completionHandler;

/**
 * Update the `deleted` status of inbox messages in batch
 * @param inboxMessages The messages to update
 * @param deleted The deleted status to set
 * @param completionHandler Called when the operation completes
 */
- (void)updateMessages:(NSArray<D360InboxMessage *>*) inboxMessages asDeleted:(BOOL)deleted completionHandler:(void (^)(BOOL success, NSError *_Nullable error))completionHandler;

/**
 * Update the `read` status of inbox messages in batch
 * @param inboxMessages The messages to update
 * @param read The deleted status to set
 * @param completionHandler Called when the operation completes
 */
- (void)updateMessages:(NSArray<D360InboxMessage *>*) inboxMessages asRead:(BOOL)read completionHandler:(void (^)(BOOL success, NSError *_Nullable error))completionHandler;

#pragma mark - Delete

/**
 * Removes permanently the inbox message from the stored messages.
 *
 * @note If you are removing several messages, use the `removeMessages:completionHandler:` which is more efficient instead of calling this method in a loop.
 *
 * @param inboxMessage The message to remove.
 * @param completionHandler The block executed after the request is processed.
 */
- (void)removeMessage:(D360InboxMessage *)inboxMessage completionHandler:(nullable void (^)(BOOL success, NSError *_Nullable error))completionHandler;

/**
 * Removes permanently the inbox messages from the store.
 *
 * @param inboxMessages The messages to delete.
 * @param completionHandler Called when the deletion completes
 */
- (void)removeMessages:(NSArray<D360InboxMessage *>*)inboxMessages completionHandler:(nullable void (^)(BOOL success, NSError *_Nullable error))completionHandler;

#pragma mark - Executing Actions

/**
 * A received inbox message can have an associated campaign action. You can execute that action using this method
 * @param inboxMessage The inbox message that must its `hasAction` property
 * @param completionHandler The block executed after the request is processed.
 */
- (void)executeMessage:(D360InboxMessage *)inboxMessage completionHandler:(nullable void (^)(BOOL executed, NSError *_Nullable error))completionHandler;


@end

NS_ASSUME_NONNULL_END

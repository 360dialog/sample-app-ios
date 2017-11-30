//
//  This file is part of 360 Dialog SDK.
//  See the file LICENSE.txt for copying permission.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * The media attachment that was sent along with a InboxMessage
 */
@interface D360InboxAttachment : NSObject

/// The URL to the attachment's data
@property (nonatomic, readonly, copy) NSURL *URL;

/// The MIME type of the specified data. (For example, the MIME type for a JPEG image is image/jpeg.) For a list of valid MIME types, see http://www.iana.org/assignments/media-types/.
@property (nonatomic, readonly, copy) NSString *type;

@end

NS_ASSUME_NONNULL_END
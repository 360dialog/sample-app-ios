//
//  This file is part of 360 Dialog SDK.
//  See the file LICENSE.txt for copying permission.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * This object represents one 360dialog SDK identifier. It's identified by its name and the value.
 * If you use the 360dialog identifiers for any id matching, you should send its name along with the value so that we know what identifier is used.
 *
 * As an example, you can easily crate a `NSURLQueryItem` using `[NSURLQueryItem queryItemWithName:identifier.name value:identifier.value]`
 *
 */
@interface D360Identifier : NSObject

/// The name of the identifier.
@property (nonatomic, copy, readonly) NSString *name;

/// The value of the identifier
@property (nonatomic, copy, readonly) NSString *value;

#pragma mark - Miscellaneous

/**
 * This method is not available
 *
 * @note Use `[D360 ids]` to obtain an instance of this object.
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 * This method is not available
 *
 * @note Use `[D360 ids]` to obtain an instance of this object.
 */
- (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
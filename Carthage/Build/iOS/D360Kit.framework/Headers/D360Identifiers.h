//
//  This file is part of 360 Dialog SDK.
//  See the file LICENSE.txt for copying permission.
//

#import <Foundation/Foundation.h>

@class D360Identifier;

NS_ASSUME_NONNULL_BEGIN

/**
 * This object encapsulates some SDK internal identifiers that you can use for tracking purposes.
 *
 * @note We do not guarantee the compatibility or persistence of those ids between SDK updates.
 *
 */
@interface D360Identifiers : NSObject

/**
 * Identifies the installation of the application on one device.
 *
 * @note This id is reset after re-installation of the application
 */
@property (nonatomic, strong, readonly, nullable) D360Identifier *appInstanceId;

/**
 * Identifies one physical device. If you use keychain sharing, this id remains the same for the same keychain group.
 *
 * @note This id is assigned by the backend to the SDK and might be nil if the SDK haven't completed yet the registration process.
 */
@property (nonatomic, strong, readonly, nullable) D360Identifier *deviceId;

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


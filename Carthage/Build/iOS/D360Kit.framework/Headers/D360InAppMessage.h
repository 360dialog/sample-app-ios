//
//  This file is part of 360 Dialog SDK.
//  See the file LICENSE.txt for copying permission.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/**
 * The D360InAppMessage encapsulates the data contained in a campaign's in-app message.
 */
@interface D360InAppMessage : NSObject

/**
 * This uuid allows you to identify an in-app message between the delegate calls
 * It is purely internal to the SDK and does not have a meaning in terms of campaigns.
 */
@property (nonatomic, copy, readonly) NSString *uuid;


/**
 * The content of the custom key/value context data as set in your campaign.
 */
@property (nonatomic, strong, readonly, nullable) NSDictionary *contextualData;

/**
 * This method is not available
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 * This method is not available
 */
- (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
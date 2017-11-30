//
//  This file is part of 360 Dialog SDK.
//  See the file LICENSE.txt for copying permission.
//

#import <Foundation/Foundation.h>

/**
 * This object represent a custom paylod that is sent from a 360dialog CRM.
 */
@interface D360CustomPayload : NSObject

/**
 * The custom payload that you would expect to receive. It is up to the caller to parse it into the expected type.
 * For instance if you expect any JSON object, you should treat the string as a json string
 */
@property (nonatomic, strong, readonly, nonnull) NSString *payload;


/**
 * The content of the custom key/value context data as set in your campaign.
 */
@property (nonatomic, strong, readonly, nullable) NSDictionary *contextualData;


@end
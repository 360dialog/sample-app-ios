//
//  DTCampaign.h
//  D360TesterKit
//
//  Created by Jan Chaloupecky on 16.11.17.
//  Copyright © 2017 360dialog. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol DTCampaign <NSObject>

- (NSDictionary *)JSON;

- (NSDictionary *)action;

@end

NS_ASSUME_NONNULL_END

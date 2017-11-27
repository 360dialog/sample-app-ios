//
//  This file is part of 360dialog SDK.
//  See the file LICENSE.txt for copying permission.
//

#import "DTAbstractCampaign.h"

@interface DTAbstractCampaign ()



@end



@implementation DTAbstractCampaign

- (instancetype)initWithUserInfo:(NSMutableDictionary *)userInfo
{
    self = [super init];
    if (self) {
        self.userInfo = userInfo;
    }

    return self;
}


- (NSDictionary *)JSON
{
    return [self.userInfo copy];
}

- (NSDictionary *)action
{
    return [[[self userInfo] copy] valueForKeyPath:@"d360.a.p.a"];
}

@end
//
//  This file is part of 360dialog SDK.
//  See the file LICENSE.txt for copying permission.
//

#import "DTInApp.h"

@interface DTInApp ()


@end

@implementation DTInApp


+ (instancetype)requestPermissionInApp
{
    DTInApp *inApp = [[DTInApp alloc] init];
    inApp.url = [NSURL URLWithString:@"https://inapp-samples.s3.amazonaws.com/push-permissions.html"];
    return inApp;
}

- (instancetype)init
{
    static dispatch_once_t token;
    static NSDictionary *inAppTemplate;

    dispatch_once(&token, ^{

        NSURL *url = [[NSBundle bundleForClass:[self class]] URLForResource:@"inapp-template" withExtension:@"json"];
        NSData *data = [NSData dataWithContentsOfURL:url];

        inAppTemplate = [NSJSONSerialization JSONObjectWithData:data options:0 error:NULL];
    });


    self = [super initWithUserInfo:[inAppTemplate mutableCopy]];
    if (self) {

    }

    return self;
}

#pragma mark - Overrides

- (void)setUrl:(NSURL *)url
{
    _url = url;
    [self.userInfo setValue:url.absoluteString forKeyPath:@"d360.a.p.d.u"];
}


@end

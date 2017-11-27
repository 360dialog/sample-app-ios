//
//  This file is part of 360dialog SDK.
//  See the file LICENSE.txt for copying permission.
//

#import "DTPusher.h"

@import UIKit;
@import UserNotifications;

@interface DTPusher ()

@end

@implementation DTPusher

- (void)localPush:(NSDictionary *)payload
{
    NSDictionary *sample = payload;

    BOOL isSilent = [[payload valueForKeyPath:@"aps.content-available"] boolValue];
    if (isSilent) {
        [self scheduleSilentPush:sample];
        return;
    }
    if (@available(iOS 10, *)) {
        [self scheduleLocalPushSample:sample delay:0];
    } else {
        [self scheduleLocalPushSampleOld:sample delay:0];
    }
}

- (void)scheduleLocalPushSample:(NSDictionary *)sample delay:(NSTimeInterval)pushDelay NS_AVAILABLE_IOS(10_0)
{
    NSDictionary *payload = sample;
    UNMutableNotificationContent *content = [[UNMutableNotificationContent alloc] init];
    content.title = [payload valueForKeyPath:@"aps.alert.title"];
    content.body = [payload valueForKeyPath:@"aps.alert.body"];

    if (payload[@"d360"]) {
        content.userInfo = @{ @"d360": payload[@"d360"] };
    }

    UNTimeIntervalNotificationTrigger *trigger;
    if (pushDelay > 0) {
        trigger = [UNTimeIntervalNotificationTrigger triggerWithTimeInterval:pushDelay repeats:NO];
    }


    UNNotificationRequest *request = [UNNotificationRequest requestWithIdentifier:[[NSUUID UUID] UUIDString] content:content trigger:trigger];

    BOOL rich = NO;

//    D360RichNotificationHelper *helper = [[D360RichNotificationHelper alloc] init];
//
//    BOOL rich = [helper handleNotificationRequest:request withContentHandler:^(UNNotificationContent *localContent) {
//        UNNotificationRequest *richRequest = [UNNotificationRequest requestWithIdentifier:[[NSUUID UUID] UUIDString] content:localContent trigger:trigger];
//        [[UNUserNotificationCenter currentNotificationCenter] addNotificationRequest:richRequest withCompletionHandler:^(NSError *error) {
//            NSLog(@"Local notification scheduled with %@", error ? error : @"success");
//        }];
//    }];

    if (!rich) {
        [[UNUserNotificationCenter currentNotificationCenter] addNotificationRequest:request withCompletionHandler:^(NSError *error) {
            NSLog(@"Local notification scheduled with %@", error ? error : @"success");
        }];
    }
}

- (void)scheduleLocalPushSampleOld:(NSDictionary *)sample delay:(NSTimeInterval)pushDelay
{

    NSDictionary *payload = sample;

    UILocalNotification *localNotification = [[UILocalNotification alloc] init];
    localNotification.fireDate = [NSDate dateWithTimeIntervalSinceNow:pushDelay];
    localNotification.alertBody = [payload valueForKeyPath:@"aps.alert.body"];
    localNotification.alertTitle = [payload valueForKeyPath:@"aps.alert.title"];
    localNotification.applicationIconBadgeNumber = [[payload valueForKeyPath:@"aps.badge"] integerValue];
    localNotification.timeZone = [NSTimeZone defaultTimeZone];
    if (payload[@"d360"]) {
        localNotification.userInfo = @{ @"d360": payload[@"d360"] };
    }

    [[UIApplication sharedApplication] scheduleLocalNotification:localNotification];

}

- (void)scheduleSilentPush:(NSDictionary *)sample
{

    NSDictionary *payload = sample;

    [[UIApplication sharedApplication].delegate application:[UIApplication sharedApplication] didReceiveRemoteNotification:payload fetchCompletionHandler:^(UIBackgroundFetchResult result) {

    }];

}
@end

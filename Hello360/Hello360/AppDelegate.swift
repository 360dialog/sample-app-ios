//
//  AppDelegate.swift
//  Hello360
//
//  Created by Jan Chaloupecky on 14.11.17.
//  Copyright © 2017 360dialog. All rights reserved.
//

import UIKit

import D360Kit

import UserNotifications

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {

    var window: UIWindow?

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
        
        // Those are sample credentials for test purpose. You can get your by loging in to https://dashboard.360dialog.com/apps/
        let options = D360Options(appId: "213", apiKey: "8e82138de17f708c544173ae1463a6f61eb7133aaec80113c7941e26ce0dfeed")
        
        // You can customise furhter the SDK using the option object.
        options.sessionBackgroundTimeout = 60
        
        D360.start(withOptions: options)
        
        if #available(iOS 10, *) {
            UNUserNotificationCenter.current().delegate = self
        }
        
        D360.setLogLevel(.info)
        
        return true
    }
    
    //MARK: - Rmote Notification Token
    
    func application(_ application: UIApplication, didRegisterForRemoteNotificationsWithDeviceToken deviceToken: Data) {
        // Hand over the push token
        D360.push().registerDeviceToken(deviceToken)
    }
    
    func application(_ application: UIApplication, didFailToRegisterForRemoteNotificationsWithError error: Error) {
        print("Failed to register push token: \(error)")
    }
    
    func application(_ application: UIApplication, didRegister notificationSettings: UIUserNotificationSettings) {
        
        D360.push().registerNotificationCategories(notificationSettings.categories)
    }
    
    // MARK: - Rmote Notification Paylod
    
    func application(_ application: UIApplication, didReceiveRemoteNotification userInfo: [AnyHashable : Any], fetchCompletionHandler completionHandler: @escaping (UIBackgroundFetchResult) -> Void) {
        
        D360.push().handleNotification(userInfo, fetchCompletionHandler: completionHandler)
    }
}

// MARK: User Notifications
@available(iOS 10, *)
extension AppDelegate: UNUserNotificationCenterDelegate {
    
    
    func userNotificationCenter(_ center: UNUserNotificationCenter, didReceive response: UNNotificationResponse, withCompletionHandler completionHandler: @escaping () -> Void) {
        
        D360.push().handle(center, didReceive: response, withCompletionHandler: completionHandler)
    }

    func userNotificationCenter(_ center: UNUserNotificationCenter, willPresent notification: UNNotification, withCompletionHandler completionHandler: @escaping (UNNotificationPresentationOptions) -> Void) {

        D360.push().handle(center, willPresent: notification, withCompletionHandler: completionHandler)
    }
}


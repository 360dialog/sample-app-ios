//
//  AppDelegate+Helpers.swift
//  Hello360
//
//  Created by Jan Chaloupecky on 27.11.17.
//  Copyright © 2017 360dialog. All rights reserved.
//

import Foundation
import D360Kit
import D360TesterKit

// Extensions not related to the SDK integration. We keep them in a separate file to declutter the integration code

// MARK: - Sample Campaigns

extension AppDelegate {
    
    // Function that sends a welcome sample InboxMessages to the test app
    func sendSampleInboxMessageIfNeeded() {
        D360.inbox().fetch(with: .any()) { messages, error in
            if(messages.count == 0) {
                
                let campaign = DTInbox(title: "Welcome to the sample app", body: "Tap here to request user push permissions")
                
                // The inbox will have a Deeplink as action to the Map app as action when tapped
                campaign.action = DTInAppAction(url: URL(string: "https://inapp-samples.s3.amazonaws.com/push-permissions.html")!, buttonType: .dark)
                
                DTTester.send(campaign)
            }
        }
    }

    // Sample function that simply displays the received deeplink
    func handleDeepLink(url: URL, sourceApplication: String?, annotation: Any? = nil, options: [UIApplicationOpenURLOptionsKey: Any]? = nil) {

        var source = ""
        if let sourceApplication = sourceApplication {
            source = sourceApplication
        }

        if let options = options {
            source = options[UIApplicationOpenURLOptionsKey.sourceApplication] as! String
        }
        
        let message = """
                URL: \(url)
                Source: \(source)
                Annotation: \(annotation ?? "-")
                """
        let alertController = UIAlertController(title: "Deeplink received", message: message, preferredStyle: .alert)
        alertController.addAction(UIAlertAction(title: "Ok", style: .default))

        window!.rootViewController!.present(alertController, animated: true)

    }
}

// MARK: - Style

extension AppDelegate {
    func applyStyle() {
        
        let navBarAppearance = UINavigationBar.appearance()
        navBarAppearance.isTranslucent = false
        navBarAppearance.barTintColor = .d360_blue
        navBarAppearance.tintColor = .white
        navBarAppearance.titleTextAttributes = [ NSAttributedStringKey.foregroundColor: UIColor.white ]
    }
}


//
//  InboxViewController+Samples.swift
//  Hello360
//
//  Created by Jan Chaloupecky on 28.11.17.
//  Copyright © 2017 360dialog. All rights reserved.
//

import UIKit
import D360TesterKit

// Extensions not related to the SDK integration. We keep them in a separate file to declutter the integration code

// MARK: - Sample Campaigns

extension InboxViewController {
    
    @IBAction func composeButtonAction(sender: UIBarButtonItem) {
        
        let alertController = UIAlertController(title: "Sample campaign", message: "Select a sample campaign to send. You can edit the details in the sample code", preferredStyle: .actionSheet)
        
        alertController.addAction(UIAlertAction(title: "Inbox Message", style: .default) { _ in
            self.sendSampleInbox()
        })
        
        alertController.addAction(UIAlertAction(title: "Native Notification", style: .default) { _ in
            self.sendSampleNotification()
        })
        
        alertController.addAction(UIAlertAction(title: "InApp Message", style: .default) { _ in
            self.sendSampleInApp()
        })
        
        alertController.addAction(UIAlertAction(title: "Cancel", style: .cancel))
        
        present(alertController, animated: true)

    }
    
    func sendSampleInbox() {
        let campaign = DTInbox(title: "Hi 👋", body: "Tap to execute the inbox action")
        
        // The inbox will have a Deeplink as action to the Map app as action when tapped
        campaign.action = DTURLAction(url: URL(string:"http://www.google.com/search?q=macarons")!)
        
        campaign.attachmentURL = URL(string: "https://inapp-samples.s3.amazonaws.com/examples/JPG/desertsmall.jpg")!

        
        // The inbox will have a InApp as action when tapped
        // this example InApp does have a HTML close button so we disable the native one
        
        // campaign.body = "Tap to open the InApp"
        // campaign.action =  DTInAppAction(url: URL(string: "https://inapp-samples.s3.amazonaws.com/inapp-close-button.html")!, buttonType: .none)
        
        DTTester.send(campaign)
    }
    
    func sendSampleNotification() {
        let campaign = DTNotification(title: "Hi 👋", body: "Tap to open a URL")
        
        campaign.action = DTURLAction(url: URL(string:"http://www.google.com/search?q=macarons")!)

        // Set the URL of the rich content
        campaign.richURL = URL(string: "https://inapp-samples.s3.amazonaws.com/examples/JPG/desertsmall.jpg")!
        
        // By default, the notification is a foreground notification. You can disable it here
        // campaign.isForeground = false
        
        DTTester.send(campaign)
    }
    
    func sendSampleInApp() {
        
        let campaign = DTInApp()
        
        // use your own InApps here for testing purposes
        // campaign.url = URL(string: "https://inapp-samples.s3.amazonaws.com/push-permissions.html")!
        
        DTTester.send(campaign)
    }
}

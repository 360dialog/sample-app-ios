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
        let campaign = DTInbox(title: "Hi 👋", body: "Tap to open a URL")
        DTTester.send(campaign)
    }
    
    func sendSampleNotification() {
        let campaign = DTNotification(title: "Hi 👋", body: "Tap to open a URL")
        DTTester.send(campaign)
    }
    
    func sendSampleInApp() {
        let campaign = DTInApp()
        
        // use your own InApps here for testing purposes
        // campaign.url = URL(string: "https://inapp-samples.s3.amazonaws.com/push-permissions.html")!
        
        DTTester.send(campaign)
    }
}

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
                DTTester.send(DTInbox())
            }
        }
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


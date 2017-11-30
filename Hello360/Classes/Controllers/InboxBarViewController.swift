//
//  This file is part of 360 Dialog SDK.
//  See the file LICENSE.txt for copying permission.
//

import UIKit
import D360Kit

protocol InboxBarViewControllerDelegate: class {
    
    func controller(didPressDeleteButton: InboxBarViewController)
    
    func controller(didPressUpdateButton: InboxBarViewController)

}

class InboxBarViewController: UIViewController {
    
    
    @IBOutlet var tabBar: UITabBar!
    @IBOutlet var inboxCountLabel: UILabel!

    weak var delegate: InboxBarViewControllerDelegate?

    // MARK: - Properties
    
    var maxInboxCount: UInt = 0 {
        didSet {
            updateUI()
        }
    }
    
    var currentInboxCount: UInt = 0 {
        didSet {
          updateUI()
        }
    }

    // MARK: Overrides

    // MARK: - Actions
    
    @IBAction func deleteButtonPressed() {
        delegate?.controller(didPressDeleteButton: self)
    }
    
    @IBAction func updateButtonPressed() {
        delegate?.controller(didPressUpdateButton: self)
    }

    // MARK: - Private
    
    func updateUI () {
        updateCountLabel()
    }
    
    
    func updateCountLabel() {
        OperationQueue.main.addOperation {
            self.inboxCountLabel.text = "\(self.currentInboxCount) total message\(self.currentInboxCount > 1 ? "s":"")"
        }
    }
}

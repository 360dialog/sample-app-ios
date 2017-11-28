//
//  This file is part of 360 Dialog SDK.
//  See the file LICENSE.txt for copying permission.
//

import UIKit
import D360Kit
import D360TesterKit

class InboxViewController: UIViewController {
    

    @IBOutlet weak var tableView: UITableView!
    @IBOutlet weak var readSegmentedControl: UISegmentedControl!
    @IBOutlet weak var inboxSegmentedControl: UISegmentedControl!
    @IBOutlet var barViewController: InboxBarViewController!
    
    var messages = [D360InboxMessage]() {
        didSet {
            
            self.tableView.reloadData()
            updateMessageCount()
        }
    }
    
    // MARK: - View Life Cycle
    
    override func viewDidLoad() {
        D360.inbox().delegate = self
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        fetchInboxWithCurrentFilter()
        updateMessageCount()
        
    }
    
    // MARK: - Inbox Methods
    
    // Fetches the count of any inbox messages and updates the bottom bar
    func updateMessageCount() {
        D360.inbox().fetch(with: .any()) { messages, error in
            let count = UInt(messages.count)
            self.barViewController.currentInboxCount = count
        }
    }
    
    // Gets the current segmented control state and fetches the inbox messages with that filter
    func fetchInboxWithCurrentFilter() {
        
        let readFilter = D360InboxReadFilter(rawValue: UInt(self.readSegmentedControl.selectedSegmentIndex))!
        let deleteFilter = D360InboxDeleteFilter(rawValue: UInt(self.inboxSegmentedControl.selectedSegmentIndex))!
        
        let request = D360InboxFetchRequest(readFilter: readFilter, deleteFilter: deleteFilter)
        
        D360.inbox().fetch(with: request) { messages, error in
            self.messages = messages;
        }
    }
    
    // MARK: - Actions
    
    @IBAction func filterStateChanged(sender: UISegmentedControl) {
        fetchInboxWithCurrentFilter()
    }
    
    // MARK:- Helpers
    
    func fetchImage(withURL url: URL?, inboxCell cell: InboxTableViewCell, at indexPath: IndexPath) {
        guard let url = url else {
            return
        }
        cell.tag = indexPath.row
        
        URLSession.shared.dataTask(with: url) { data, response, error in
            OperationQueue.main.addOperation {
                if(cell.tag != indexPath.row) {
                    return
                }
                
                if let data = data {
                    cell.inboxImageView.image = UIImage(data: data)
                    cell.setNeedsLayout()
                }
            }
        }.resume()
    }
}

// MARK: - UITableViewDataSource

extension InboxViewController: UITableViewDataSource {
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return messages.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        let cell = tableView.dequeueReusableCell(withIdentifier: "InboxCellId", for: indexPath) as! InboxTableViewCell
        let message = messages[indexPath.row]
        cell.inboxSubjectLabel.text = message.title
        cell.inboxBodyLabel.text = message.body
        
        let formater = DateFormatter()
        formater.dateStyle = .short
        formater.timeStyle = .short
        
        cell.inboxDateLabel.text = formater.string(from: message.date)
        cell.mark(asRead: message.isRead)
        
        fetchImage(withURL: message.attachment?.url, inboxCell: cell, at: indexPath)
        return cell
    }
}

// MARK: - UITableViewDelegate

extension InboxViewController: UITableViewDelegate {
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        tableView.deselectRow(at: indexPath, animated: true)
        
        let message = messages[indexPath.row]
        
        D360.inbox().update(message, asRead: true)
        tableView.reloadData()
        
        if(message.isExecutable) {
            D360.inbox().execute(message) { executed, error in
                
                self.toast(title: "Action Executed", type: .info)
            }
        }
    }
    
    func tableView(_ tableView: UITableView, editActionsForRowAt indexPath: IndexPath) -> [UITableViewRowAction]? {
        let message = messages[indexPath.row]
        
        // When the user swipes on a message cell, he can
        // - toggle the 'read' state of the message
        // - toggle the 'delete' state of the message
        // - remove permanently the message
        
        
        let mark = UITableViewRowAction(style: .normal, title: message.isRead ? "Unread" : "Read") { action, index in
            // toggle the read state
            D360.inbox().update(message, asRead: !message.isRead) { _, _ in
                self.fetchInboxWithCurrentFilter()
            }
        }
        mark.backgroundColor = .d360_blue
        
        let remove = UITableViewRowAction(style: .destructive, title: "Remove") {action, index in
            // permanently remove
            D360.inbox().remove(message) { _,_ in
                self.fetchInboxWithCurrentFilter()
            }
        }
        remove.backgroundColor = .d360_alert
        
        let delete = UITableViewRowAction(style: .normal, title: message.isDeleted ? "Restore" : "Delete") { action, index in
            // toggle the deleted state
            D360.inbox().update(message, asDeleted: !message.isDeleted) { _,_ in
                self.fetchInboxWithCurrentFilter()
            }
        }
        delete.backgroundColor = .d360_warning
        
        return [mark, delete, remove]
        
    }
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        
        if let barViewController = segue.destination as? InboxBarViewController  {
            self.barViewController = barViewController
            self.barViewController.delegate = self
        }
    }
}


// MARK: - D360InboxServiceDelegate

// In this implementation, we simply reload the messages anytime there is a change in the InboxService
extension InboxViewController: D360InboxServiceDelegate {
    
    func inboxService(_ inboxService: D360InboxService, didReceive inboxMessage: D360InboxMessage) {
        fetchInboxWithCurrentFilter()
    }
    
    func inboxService(_ inboxService: D360InboxService, didUpdate inboxMessage: D360InboxMessage) {
        fetchInboxWithCurrentFilter()
    }
    
    func inboxService(_ inboxService: D360InboxService, didRemove inboxMessages: [D360InboxMessage]) {
        fetchInboxWithCurrentFilter()
    }
}

// MARK: - InboxBarViewControllerDelegate


// The InboxBarViewControllerDelegate handles the actions in the bottom bar for deleting or updating messages
extension InboxViewController: InboxBarViewControllerDelegate {

    // Present a UIAlertController and ask if we want to delete all messages
    func controller(didPressDeleteButton: InboxBarViewController) {
        
        let alertController = UIAlertController(title: "Remove \(messages.count) filtered messge\(messages.count > 1 ? "s" : "")?", message: "This will remove the messages that are currently filtered.", preferredStyle: .alert)

        alertController.addAction(UIAlertAction(title: "Remove", style: .destructive) { _ in
            
            // Remove all the currently displayed messages
            D360.inbox().remove(self.messages) { _,_ in
                self.fetchInboxWithCurrentFilter()
            }
        })
        
        alertController.addAction(UIAlertAction(title: "Cancel", style: .cancel))
        
        present(alertController, animated: true)
    }

    // Present a UIAlertController with updating the read or delete status in batch
    func controller(didPressUpdateButton: InboxBarViewController) {
        let alertController = UIAlertController(title: "Update \(messages.count) filtered messge\(messages.count > 1 ? "s" : "") as ...", message: "This will update the messages that are currently filtered.", preferredStyle: .actionSheet)


        alertController.addAction(UIAlertAction(title: "Read", style: .default) { _ in
            D360.inbox().update(self.messages, asRead: true) { _,_ in
                self.fetchInboxWithCurrentFilter()
            }
        })

        alertController.addAction(UIAlertAction(title: "Unread", style: .default) { _ in
            D360.inbox().update(self.messages, asRead: false) { _,_ in
                self.fetchInboxWithCurrentFilter()
            }
        })

        alertController.addAction(UIAlertAction(title: "Delete", style: .default) { _ in
            D360.inbox().update(self.messages, asDeleted: true) { _,_ in
                self.fetchInboxWithCurrentFilter()
            }
        })

        alertController.addAction(UIAlertAction(title: "Restore", style: .default) { _ in
            D360.inbox().update(self.messages, asDeleted: false) { _,_ in
                self.fetchInboxWithCurrentFilter()
            }
        })

        alertController.addAction(UIAlertAction(title: "Cancel", style: .cancel))

        present(alertController, animated: true)
    }
}


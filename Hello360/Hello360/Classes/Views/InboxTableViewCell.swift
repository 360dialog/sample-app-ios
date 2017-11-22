//
//  This file is part of 360 Dialog SDK.
//  See the file LICENSE.txt for copying permission.
//

import UIKit

class InboxTableViewCell: UITableViewCell {
    
    @IBOutlet var inboxImageView: UIImageView!
    @IBOutlet var inboxSubjectLabel: UILabel!
    @IBOutlet var inboxBodyLabel: UILabel!
    @IBOutlet var inboxDateLabel: UILabel!
    @IBOutlet var inboxReadView: UIView!
    @IBOutlet var labelStackView: UIStackView!

    override func awakeFromNib() {
        super.awakeFromNib()
        applyStyle()
    }

    func applyStyle() {
        self.inboxSubjectLabel.textColor = .d360_text
//        self.inboxSubjectLabel.font = UIFont.d360_default()
//
        self.inboxBodyLabel.textColor = .d360_textLight
//        self.inboxBodyLabel.font = UIFont.d360_defaultFontSmall()
//
        self.inboxDateLabel.textColor = .d360_textLight
//        self.inboxDateLabel.font = UIFont.d360_defaultFontSmall()
//
    }
    
    func mark(asRead read: Bool) {
        inboxReadView.backgroundColor = read ? .clear : .d360_blue
    }
}

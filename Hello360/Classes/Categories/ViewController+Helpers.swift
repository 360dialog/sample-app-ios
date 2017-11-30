//
//  This file is part of 360 Dialog SDK.
//  See the file LICENSE.txt for copying permission.
//

import UIKit

@objc
enum ToastType: NSInteger {
    case success
    case info
    case error
    
    func color() -> UIColor {
        switch self {
        case .info:
            return .blue
        case .success:
            return .green
        case .error:
            return .red
        }
    }
}

extension UIViewController {
    func toast(title: String, type: ToastType) {
    }
}

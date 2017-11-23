//
//  This file is part of 360 Dialog SDK.
//  See the file LICENSE.txt for copying permission.
//

import UIKit

extension UIColor {
    
    class var d360_alert: UIColor {
        get {
            return UIColor(hexString: "#E84446")!
        }
    }
    
    class var d360_blue: UIColor {
        get {
            return UIColor(hexString: "#408EFC")!
        }
    }
    
    class var d360_warning: UIColor {
        get {
            return UIColor(hexString: "#FD7123")!
        }
    }
    
    class var d360_text: UIColor {
        get {
            return UIColor(hexString: "#47577d")!
        }
    }
    
    class var d360_textLight: UIColor {
        get {
            return UIColor(hexString: "#889bbb")!
        }
    }
    
    public convenience init?(hexString: String) {
        let r, g, b: CGFloat
        
        if hexString.hasPrefix("#") {
            let start = hexString.index(hexString.startIndex, offsetBy: 1)
            let hexColor = String(hexString[start...])
            
            if hexColor.count == 6 {
                let scanner = Scanner(string: hexColor)
                var hexNumber: UInt64 = 0
                
                if scanner.scanHexInt64(&hexNumber) {
                    r = CGFloat((hexNumber & 0xff0000) >> 16) / 255
                    g = CGFloat((hexNumber & 0x00ff00) >> 8) / 255
                    b = CGFloat(hexNumber  & 0x0000ff) / 255
                    
                    self.init(red: r, green: g, blue: b, alpha: 1.0)
                    return
                }
            }
        }
        
        return nil
    }
}

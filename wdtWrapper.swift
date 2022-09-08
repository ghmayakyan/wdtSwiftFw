import Foundation



public func initializeWdtCSwift(url : String, dir : String){
    let c_url = url.cString(using: String.defaultCStringEncoding)!
    let c_dir = dir.cString(using: String.defaultCStringEncoding)!
    initializeWdt(c_url,c_dir)
}


import Cocoa

class ViewController: NSViewController {
    
    override func loadView() {
        view = NSView(frame: .zero)

//      By default an NSView does not have a layer attached to it. To get one you have to set wantsLayer to true. This would create a layer and assign it to the optional layer property on the view
        view.wantsLayer = true
        view.layer?.backgroundColor = .init(red: 1, green: 0, blue: 0, alpha: 1)
    }
    
}

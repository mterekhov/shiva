//
//  Application.swift
//  shiva
//
//  Created by cipher on 16.04.2023.
//

import Cocoa

class Application: NSApplication {
    
    private let applicationDelegate = AppDelegate()
    
    override init() {
        super.init()
        
        delegate = applicationDelegate
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
}

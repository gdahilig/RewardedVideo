//
//  ViewController.swift
//  BasicApp
//
//  Created by Gene Dahilig on 7/9/18.
//  Copyright © 2018 OpenX, Inc. All rights reserved.
//

import UIKit
import OpenXSDKCore

class ViewController: UIViewController, OXMInterstitialControllerDelegate {
    func viewControllerForModalPresentation() -> UIViewController! {
        return self
    }
    
    func adDidLoad(interstitialController: OXMInterstitialController, adDetails: OXMAdDetails) {
        
    }
    
    func adDidFailToLoad(interstitialController: OXMInterstitialController, error: Error) {
        
    }
    
    func adDidDisplay(interstitialController: OXMInterstitialController) {
        
    }
    
    func adDidComplete(interstitialController: OXMInterstitialController) {
        
    }
    
    func adWasClicked(interstitialController: OXMInterstitialController) {
        
    }
    
    func adInterstitialDidClose(interstitialController: OXMInterstitialController) {
        
    }
    
    func adClickthroughDidClose(interstitialController: OXMInterstitialController) {
        
    }
    
    func adDidLeaveApplication(interstitialController: OXMInterstitialController) {
        
    }
    
    var interstitialController = OXMInterstitialController()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.interstitialController = OXMInterstitialController()
        self.interstitialController.delegate = self
        
        self.interstitialController.adUnitIdentifierType = .vast
        self.interstitialController.vastURL = "http://mobile-d.openx.net/v/1.0/av?pgid=540069345"
        self.interstitialController.userParameters.userGender = OXMGender.male
        self.interstitialController.userParameters.userAge = 21
        
        self.interstitialController.isRewarded = true
        
        self.interstitialController.load()

    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    @IBOutlet weak var showButton: UIButton!

    @IBAction func pressedShowButton(_ sender: Any) {
        self.interstitialController.show()
    }
    
    override var prefersStatusBarHidden: Bool {
        return true
    }
}


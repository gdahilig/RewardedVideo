# RewardedVideo
OpenX Rewarded Video Training

## Overview

* Build the Basic App
* Integrate the SDK
* Integrate Video Interstitial Ad
* Integrate Rewarded Video Ad

## Detailed Steps
### Build the Basic App
* Create a New Project
* Prepare the App
* Add App Title “Rewarded Video Training App"
  * Add “Show” button, center it
  * Add an event handler “showButtonPressed” to handle button presses.
  * Make sure the status bar is hidden in the ViewController.swift
```
    override var prefersStatusBarHidden: Bool {
      return true
    }
```

### Integrate the SDK
* Integrate the SDK
    * Copy the file to the project directory (Xcode doesn’t do the copy)
    * Add the OpenX SDK to the project
        * Embed the framework into the executable.
            * Drag in OpenXSDKCore.framework on the Xcode project tree
        * Click on the “BasicApp” icon in the tree to show the 
        * NOTE: Should only be one reference in each of the Target Sections
            * Embedded Frameworks
            * Linked Frameworks
    * Set Up App Transport Security
        * Select “Info.plist"
            * Add row: "App Transport Security Settings"
            * Add value: “Allow Arbitrary Loads"


### Integrate Video Interstitial Ad
* Import the OXMSDKCore to the ViewController
```
import OpenXSDKCore
```

* Add a member variable for the OpenX interstitial view controller
```
var interstitialController = OXMInterstitialController()
```

* Implement the OpenX Interstitial controller delegate
    * Add to the default view controllers class definition
```
class ViewController: UIViewController, OXMInterstitialControllerDelegate {
```

    * Click on the red dot that appears on the right in the source code
    * At the prompt “Do you want to add support to the protocol?” Select “Fix".
    * Remove all the “code” stubs.
    * For the function  viewControllerForModalPresentation()
```
return self
```
* Initialize the OXMInterstitialViewController
    * Override the viewDidLoad() to add initialization code for Video Interstitials
```
self.interstitialController = OXMInterstitialController()
self.interstitialController.delegate = self
        
self.interstitialController.adUnitIdentifierType = .vast
self.interstitialController.vastURL = "http://oxv4support-d.openx.net/v/1.0/av?auid=537123792"
self.interstitialController.userParameters.userGender = OXMGender.male
self.interstitialController.userParameters.userAge = 21
```
### Integrate Rewarded Video Ad

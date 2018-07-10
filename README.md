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

### Integrate Rewarded Video Ad

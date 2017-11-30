
# 360dialog Sample App

This sample app is a minimal example demonstrating a proper integration of the 360dialog SDK. 

![](https://developer.360dialog.io/mobile/_images/ios_inbox.png)

# Installation

1. Clone the repository

2. Build & Run

The sample app usess uses [Carthage](https://github.com/Carthage/Carthage) for the SDK integration but the compiled frameworks are shipped with this repository. In case you XCode version does not match, you can re-compile or update them using.

```bash
carthage update --use-ssh --platform iOS 
```

## Rich Notification
The [`Hello360RichNotificationExtension.swift`](Hello360RichNotificationExtension/NotificationService.swift) demonstrates how to integrate the [rich notifications](https://developer.360dialog.io/mobile/apple/push_notification.html#rich-notifications-setup)

## Inbox Service

The [`InboxViewController.swift`](Hello360/Classes/Controllers/InboxViewController.swift) demonstrates the integration of the Inbox Service where the user can read, update and delete the received Inbox Messages.



## Campaign Tester

This project also a [`D360TesterKit`](https://github.com/360dialog/sdk-tester-ios) to simulate the 360dialog campaings for testing or demonstration purposes. Please note that this framework is not inteded for production use and its sole purpose is to simulate the campaigns within this sample app.

You are free to experiment with it to try different campaigns. Refer to its [README](https://github.com/360dialog/sdk-tester-ios) for more examples or open the [InboxViewController+Helpers.swift](Hello360/Classes/Categories/InboxViewController+Helpers.swift) file where this test app creates some sample campaigns.

 
## Resources

For more detailed explenation, we enourage you to read the [Developer portal](https://developer.360dialog.io/mobile/apple/sdk_setup.html?ios)



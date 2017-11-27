
# 360dialog Sample App

This sample app is a minimal example demonstrating a proper integration of the 360dialog SDK. 

## Installation

1. Clone or download the repository

2. The sample app uses [Carthage](https://github.com/Carthage/Carthage) for the SDK integration so from the root folder run:

```bash
cd Hello360
carthage update --use-ssh --platform iOS 
```

### Rich Notification
The `NotificationService` shows how to integrate the [rich notifications](https://developer.360dialog.io/mobile/apple/push_notification.html#rich-notifications-setup)

### Inbox Service

The `InboxViewController` demonstrates the integration of the Inbox Service where the user can read, update and delete the received Inbox Messages


## Campaing Tester


This project also contains and uses a `D360TesterKit` to simulate the 360dialog campaings for testing or demonstration purposes. Please note that this framework is not inteded for production use and its sole purpose is to simulate the campaigns within this sample app.

You are free to experiment with it to try different campaigns. Refer to its [README](D360TesterKit/README.md) for more example.
 
## Resources

For more detailed explenation, we enourage you to read the [Developer portal](https://developer.360dialog.io/mobile/apple/sdk_setup.html?ios)




# 360dialog Sample Apps
These samples are minimal examples demonstrating a proper integration of the 360dialog SDK

They are currently written for iOS in both Swift and Objective-C.

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


 
## Resources

For more detailed explenation, we enourage you to read the [Developer portal](https://developer.360dialog.io/mobile/apple/sdk_setup.html?ios)

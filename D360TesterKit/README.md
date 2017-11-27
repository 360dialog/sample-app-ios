
# D360TesterKit

The `D360TesterKit` is a small framework that can simulate the 360dialog campaings for testing or demonstration purposes. 

⚠️ ⚠️ Please note that this framework is not inteded for production use and it's sole purpose is to facilitate the 360dialog SDK integration. 

In fact, if this framework is included in an app built for production, it will crash the app to assert that the framework is not shipped by mistake in production.

![](logo.png)


## Installation

Only [Carthage](https://github.com/Carthage/Carthage) is supported.

- Cartfile

```bash
# Cartfile
github "sample-app-ios"
```

- Run  `bash carthage update --use-ssh`
- Add the `D360TesterKit.framework` to your app

### Usage


- Simulate a sample InboxMessage

```swift

let inbox = DTInbox(title: "Hi", body: "How are you?")
        
// The image url of the inbox attachment
inbox.attachmentURL = URL(string: "https://inapp-samples.s3.amazonaws.com/images/push-round@3x.png")
DTTester.send(inbox)
```

- Simulate a sample InAppMessage:

```swift
// This inapp is a default 360dialog inapp and you can send it as it is.
let inApp = DTInApp()

// optionally, you can supply your own HTML to the InApp
inApp.url = URL(string: "https://inapp-samples.s3.amazonaws.com/push-permissions.html")!

DTTester.send(inApp)

```




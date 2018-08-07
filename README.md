# goedle_io_sdk
[![CI Status](http://img.shields.io/travis/Marc Müller/goedle_io_sdk.svg?style=flat)](https://travis-ci.org/Marc Müller/goedle_io_sdk)
[![Version](https://img.shields.io/cocoapods/v/goedle_io_sdk.svg?style=flat)](http://cocoapods.org/pods/goedle_io_sdk)
[![License](https://img.shields.io/cocoapods/l/goedle_io_sdk.svg?style=flat)](http://cocoapods.org/pods/goedle_io_sdk)
[![Platform](https://img.shields.io/cocoapods/p/goedle_io_sdk.svg?style=flat)](http://cocoapods.org/pods/goedle_io_sdk)
## Requirements
- iOS target Version 8+
- Data can only be transfered with an active internet connection
- You need the goedle.io API key and APP key
- You can request an API key by emailing support@goedle.io or marc@goedle.io
## Installation
goedle_io_sdk is available through [CocoaPods](http://cocoapods.org). To install it, simply add the following line to your Podfile:
```ruby
pod "goedle_io_sdk"
```
### ObjC
Open your AppDelegate.m and import the following header:
```ruby
#import "GoedleSdkiOS.h"
```
The next step is to init the SDK; to do so add the following code
**YOU NEED THE <GOEDLE_APP_KEY\> and <GOEDLE_API_KEY\>**, these can be requested by emailing support@goedle.io or marc@goedle.io.
```ruby
  - (BOOL)application:(UIApplication*)application didFinishLaunchingWithOptions:(NSDictionary*)launchOptions{
        ...
            /////*******GOEDLE********////////
            [GoedleSdkiOS initGoedle:<GOEDLE_APP_KEY>:<GOEDLE_API_KEY>];
            /////*******GOEDLE********////////
        ...
        }
```
### Swift
To use the goedle.io iOS SDK with Swift, you need to create a [bridging header](https://developer.apple.com/library/content/documentation/Swift/Conceptual/BuildingCocoaApps/MixandMatch.html) and insert:
```ruby
#import "GoedleSdkiOS.h"
```
Now open your `AppDelegate.swift` and add the following code to the application function.
**YOU NEED THE <GOEDLE_APP_KEY\> and <GOEDLE_API_KEY\>**, these can be requested by emailing support@goedle.io or marc@goedle.io.
```ruby
        func application(application: UIApplication, didFinishLaunchingWithOptions launchOptions: [NSObject: AnyObject]?) -> Bool {
            ...
            /////*******GOEDLE********////////
            GoedleSdkiOS.initGoedle(<APP_KEY>,<API_KEY>)
            /////*******GOEDLE********////////
            ...
        }
```
### Tracking 
Scroll down to get directly to the **implementation** examples in **[ObjC](#track_objc)** and **[Swift](#track_swift)**. 
**Concept** 
We typically use two main variables to track an event. The first is the action, e.g., view, share, like — these variables are the specific actions which are done by a user. The second variable further specifies the action e.g., product, intro, category, user. These two variables are concatenated and delimited with a "`.`". Note however that a specifier is not mandatory and we also support hierarchies with more than two levels.
Furthermore, we offer a custom field `event_id`, to identify the event (needed especially for our recommender engine).
For example, if you want to track the view-event of a product, the event would be `"view"`, the specifier would be `"product"` and the event id `"235123"`.
If your event has a certain value, like a duration or a level reached, we provide the custom field `event_value`. The event name would be `"finish.level"`, the event id could be "level-12" and the event value something like `65`, where 65 would be the duration in seconds.
**Geohash**
Besides the standard event tracking, we provide a geo-tracking functionality. We use [geohashes](https://en.wikipedia.org/wiki/Geohash), which is a geocoding system that transforms the classic longitude/latitude representation.
An implementation of the geohash en/decoding scheme can be found [here](https://github.com/sunng87/node-geohash).
####<a name="track_objc"></a>Tracking (ObjC)
To track an event, jump into your ViewControllers and add the goedle.io tracking method `[GoedleSdkiOS track:@"."];` for each event you want to track. E.g.,
```ruby
[GoedleSdkiOS track:@"<action>.<specifier>"];
```
or with "event_id"
```ruby
[GoedleSdkiOS track:@"<action>.<specifier>":@"<event_id>"];
```
or with "event_value"
```ruby
[GoedleSdkiOS track:@"<action>.<specifier>":@"<event_id>":@"<event_value>"];
```
Where action is something a user is doing ("view" or "buy") and specifier is the object of interest ("page" or "product"). As an additional identifier, you can use the "event_id" field. This is typically used to track an id of a product or an event. If the event has a specific value, like the duration example, you can use the "event_value" field.
#### Tracking Geohashes (ObjC)
To track a geohash, you have to call `[GoedleSdkiOS trackGeo:@"."];. For each event you want to track, you can add the geohash if applicable. E.g.:
```ruby
[GoedleSdkiOS trackGeo:@"<action>.<specifier>":@"<geo_hash>"];
```
or
```ruby
[GoedleSdkiOS trackGeo:@"<action>.<specifier>":@"<event_id>":@"<geo_hash>"];
```
#### <a name="track_swift"></a>Tracking (Swift)
To track an event, jump into your ViewControllers and add the goedle.io tracking method `GoedleSdkiOS.track(.);`, for each event you want to track. E.g.,
```ruby
GoedleSdkiOS.track("<action>.<specifier>")
```   
or with "event_id"
```ruby
GoedleSdkiOS.track("<action>.<specifier>","<event_id>")
```
or with "event_value"
```ruby
GoedleSdkiOS.track("<action>.<specifier>","<event_id>","<event_value>")
```   
Where action is something a user is doing ("view" or "buy") and specifier is the object of interest ("page" or "product"). As an additional identifier, you can use the `"event_id"` field. This is typically used to track an id of a product or an event. If the event has a specific value, like the duration example, you can use the `"event_value"` field.
####Tracking Geohashes (Swift)
To track a geohash, you have to call `GoedleSdkiOS.trackGeo(:)`. For each event you want to track, you can add the geohash if applicable. E.g.:
```ruby
GoedleSdkiOS.trackGeo("<action>.<specifier>","<geo_hash>")
```
or
```ruby
GoedleSdkiOS.trackGeo("<action>.<specifier>","<event_id>","<geo_hash>")
```
## Author
goedle.io GmbH, marc@goedle.io
## License
goedle_io_sdk is available under the MIT license. See the LICENSE file for more info.

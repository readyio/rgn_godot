# Godot Plugin for READYgg

This repository contains the Godot Plugin for READYgg, which allows developers to integrate READYgg functionalities into their Godot Engine projects. The plugin supports Godot Engine versions 3 and 4 and facilitates development for both Android and iOS platforms.

## Usage

The included Godot project offers various demo scenes to help you get started. Below is a basic example demonstrating how to sign in and retrieve a user's display name.

```gdscript
var configScript = preload("res://addons/rgn/config.gdns")

func _ready():
    var config = configScript.new()
    config.setAppId("YOUR_APP_ID")
    config.setDevelopmentEnvironment()
    RGNCore.initialize(config, funcref(self, "_onInitialize"))

func _onInitialize():
    $UserProfileModule.getProfileAsync_UserId(RGNCore.getUserId(), funcref(self, "_onGetProfileSuccess"))

func _onGetProfileSuccess(userData):
    $userNameLabel.text = userData.displayName
```

To add this plugin to your project, follow these steps:
1. Download a release compatible with your version of Godot.
2. Copy the `addons/rgn` folder to your project.
3. Add `core.gdns` as an autoload singleton to your project settings with the name `RGNCore`.
4. For Android support, copy `android/plugins/rgn.aar` and `android/plugins/rgn.gdap` to your project, and enable the plugin in export settings. Also, don't forget to enable Internet permission in the Android Export settings.
5. For iOS support, copy the `ios/plugin/rgn` folder to your project, and enable the plugin in export settings.

## Building the Plugin

### Windows
```bash
scons version=3 platform=windows target=debug/release
```

### macOS
```bash
scons version=3 platform=osx target=debug/release
```

### Android
```bash
scons version=3 platform=android target=debug/release android_arch=arm64v8/armv7 ANDROID_NDK_ROOT="PATH_TO_YOUR_NDK"
```
*Note: Tested on Linux Ubuntu with NDK version 21.4.7075529.*

### iOS
```bash
scons version=3 platform=ios target=debug/release
```

## Building the Android Plugin

1. Open the `plugin-android` folder in Android Studio.
2. Download `godot-lib.aar` from the official Godot site and copy it to `plugin-android/app/libs`.
3. Update the `build.gradle` file to include the copied AAR file:
   ```gradle
   compileOnly fileTree(dir: "libs", includes: ["YOUR_GODOTLIB_AAR_FILE_NAME.aar"])
   ```
4. Sync the Gradle file, build the project, and replace the built AAR in `YOUR_PROJECT/android/plugins/rgn.aar`.

## Building the iOS Plugin

In the `plugin-ios` folder, execute the following command:
```bash
./scripts/release_xcframework.sh 3.x
```

## Support and Issues
- For any issues encountered, refer to the `Issues` section of this repository.
- You can also contact RGN developers directly.
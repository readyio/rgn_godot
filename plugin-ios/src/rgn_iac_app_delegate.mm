#import "rgn_iac_app_delegate.h"
#import "DeepLink.h"

@implementation RGNIACAppDelegate

- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey, id> *)options {
    const char* payload = [[url absoluteString] UTF8String];
    
    DeepLink::OnDeepLink(payload);

    return YES;
}


- (BOOL)application:(UIApplication *)application willFinishLaunchingWithOptions:(NSDictionary<UIApplicationLaunchOptionsKey, id> *)launchOptions {
    const char* payload = 0;

    if (launchOptions[UIApplicationLaunchOptionsURLKey]) {
        payload = [[[launchOptions valueForKey:UIApplicationLaunchOptionsURLKey] absoluteString] UTF8String];
    }

    DeepLink::OnDeepLink(payload);

    return YES;
}

@end
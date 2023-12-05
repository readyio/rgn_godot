#import <Foundation/Foundation.h>
#import "core/version.h"
#if VERSION_MAJOR == 4
#import "platform/ios/godot_app_delegate.h"
#else
#import "platform/iphone/godot_app_delegate.h"
#endif
#import "rgn_iac_app_delegate.h"

RGNIACAppDelegate *rgnIac = nil;

void godot_plugin_init() {
    rgnIac = [[RGNIACAppDelegate alloc] init];
	[GodotApplicalitionDelegate addService:rgnIac];
}

void godot_plugin_deinit() {
    rgnIac = nil;
}

#import "RGNWebView.h"
#include "core/version.h"
#if VERSION_MAJOR == 4
#include "core/config/engine.h"
#include "core/object/object.h"
#else
#include "core/engine.h"
#include "core/object.h"
#endif

@implementation RGNWebView

- (instancetype)init {
    self = [super init];
    if (self) {
        _instanceId = -1;
        _urlScheme = @"";
        _backButtonText = @"";
        _webView = [[WKWebView alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
        _webView.navigationDelegate = self;
        _closeButton = [UIButton buttonWithType:UIButtonTypeSystem];
        [_closeButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        _closeButton.backgroundColor = [UIColor clearColor];
        [_closeButton addTarget:self action:@selector(closeButtonTapped) forControlEvents:UIControlEventTouchUpInside];
        _closeButton.frame = CGRectMake(20, 20, 80, 40);
        [_closeButton setContentHorizontalAlignment:UIControlContentHorizontalAlignmentLeft];
        UIWindow *window = [[UIApplication sharedApplication] keyWindow];
        [window.rootViewController.view addSubview:_webView];
        [window.rootViewController.view addSubview:_closeButton];
        _webView.hidden = YES;
        _closeButton.hidden = YES;
    }
    return self;
}

- (void)setBackButtonText:(NSString*)backButtonText {
    _backButtonText = backButtonText;
    [_closeButton setTitle:_backButtonText forState:UIControlStateNormal];
}

- (void)openURL:(NSString*)url {
    NSURL *nsUrl = [NSURL URLWithString:url];
    NSURLRequest *request = [NSURLRequest requestWithURL:nsUrl];
    [self.webView loadRequest:request];
    self.webView.hidden = NO;
    self.closeButton.hidden = NO;
}

- (void)closeButtonTapped {
    self.webView.hidden = YES;
    self.closeButton.hidden = YES;
    NSString *urlToOpenString = [_urlScheme stringByAppendingString:@"/cancelled"];
    if (_instanceId >= 0) {
        Object *instanceObject = ObjectDB::get_instance(ObjectID(_instanceId));
        if (instanceObject != nil) {
            String godotURL = String([urlToOpenString UTF8String]);
            instanceObject->call("on_webform_redirect", godotURL);
        }
    }
}

- (void)webView:(WKWebView *)webView decidePolicyForNavigationAction:(WKNavigationAction *)navigationAction decisionHandler:(void (^)(WKNavigationActionPolicy))decisionHandler {
    NSURL *url = navigationAction.request.URL;
    if ([url.scheme isEqualToString:_urlScheme]) {
        if (_instanceId >= 0) {
            Object *instanceObject = ObjectDB::get_instance(ObjectID(_instanceId));
            if (instanceObject != nil) {
                String godotURL = String([[url absoluteString] UTF8String]);
                instanceObject->call("on_webform_redirect", godotURL);
            }
        }
        self.webView.hidden = YES;
        self.closeButton.hidden = YES;
        decisionHandler(WKNavigationActionPolicyCancel);
    } else {
        decisionHandler(WKNavigationActionPolicyAllow);
    }
}

@end
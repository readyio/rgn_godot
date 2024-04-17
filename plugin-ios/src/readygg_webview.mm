#import <WebKit/WebKit.h>
#import "readygg_webview.h"
#if VERSION_MAJOR == 4
#import "core/config/engine.h"
#else
#import "core/engine.h"
#endif

static READYggWebviewPlugin *singleton;

@interface READYggWebview : NSObject <WKNavigationDelegate>
@property (nonatomic, retain) WKWebView *webView;
@property (nonatomic, retain) UIButton *closeButton;
@end

static NSString *URLScheme = @"urlscheme_set_from_c_sharp";
static NSString *BackButtonText = @"Close";

@implementation READYggWebview

- (instancetype)init {
    self = [super init];
    if (self) {
        _webView = [[WKWebView alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
        _webView.navigationDelegate = self;
        _closeButton = [UIButton buttonWithType:UIButtonTypeSystem];
        [_closeButton setTitle:BackButtonText forState:UIControlStateNormal];
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
    NSString *urlToOpenString = [URLScheme stringByAppendingString:@"/cancelled"];
    Object *rgnCoreInstance = Engine::get_singleton()->get_singleton_object("RGNCore");
    if (rgnCoreInstance != nil) {
        String godotURL = String([urlToOpenString UTF8String]);
        rgnCoreInstance->call("on_webform_redirect", godotURL);
    }
}

- (void)webView:(WKWebView *)webView decidePolicyForNavigationAction:(WKNavigationAction *)navigationAction decisionHandler:(void (^)(WKNavigationActionPolicy))decisionHandler {
    NSURL *url = navigationAction.request.URL;
    if ([url.scheme isEqualToString:URLScheme]) {
        Object *rgnCoreInstance = Engine::get_singleton()->get_singleton_object("RGNCore");
        if (rgnCoreInstance != nil) {
            String godotURL = String([[url absoluteString] UTF8String]);
            rgnCoreInstance->call("on_webform_redirect", godotURL);
        }
        self.webView.hidden = YES;
        self.closeButton.hidden = YES;
        decisionHandler(WKNavigationActionPolicyCancel);
    } else {
        decisionHandler(WKNavigationActionPolicyAllow);
    }
}

@end

static READYggWebview *globalWebView;

READYggWebviewPlugin *READYggWebviewPlugin::get_singleton() {
	return singleton;
}

void READYggWebviewPlugin::_bind_methods() {
	ClassDB::bind_method(D_METHOD("setUrlScheme", "urlScheme"), &READYggWebviewPlugin::setUrlScheme);
	ClassDB::bind_method(D_METHOD("setBackButtonText", "backButtonText"), &READYggWebviewPlugin::setBackButtonText);
	ClassDB::bind_method(D_METHOD("openUrl", "url"), &READYggWebviewPlugin::openUrl);
}

void READYggWebviewPlugin::setUrlScheme(String urlScheme) {
    URLScheme = [NSString stringWithCString:urlScheme.utf8().get_data() encoding:[NSString defaultCStringEncoding]];
}

void READYggWebviewPlugin::setBackButtonText(String backButtonText) {
    BackButtonText = [NSString stringWithCString:backButtonText.utf8().get_data() encoding:[NSString defaultCStringEncoding]];
}

void READYggWebviewPlugin::openUrl(String url) {
    if (globalWebView == nil) {
        globalWebView = [[READYggWebview alloc] init];
    }
    [globalWebView openURL:[NSString stringWithCString:url.utf8().get_data() encoding:[NSString defaultCStringEncoding]]];
}

READYggWebviewPlugin::READYggWebviewPlugin() {
	singleton = this;
}

READYggWebviewPlugin::~READYggWebviewPlugin() {
	singleton = NULL;
}
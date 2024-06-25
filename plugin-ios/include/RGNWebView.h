#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

@interface RGNWebView : NSObject <WKNavigationDelegate>

@property (nonatomic) int64_t instanceId;
@property (nonatomic, strong) NSString *urlScheme;
@property (nonatomic, strong) NSString *backButtonText;
@property (nonatomic, strong) WKWebView *webView;
@property (nonatomic, strong) UIButton *closeButton;
- (void)openURL:(NSString*)url;

@end
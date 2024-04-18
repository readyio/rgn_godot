package io.getready.android;

import android.annotation.SuppressLint;
import androidx.annotation.Nullable;
import android.app.Activity;
import android.os.Bundle;
import android.view.KeyEvent;
import android.view.View;
import android.view.Window;
import android.webkit.WebResourceRequest;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.webkit.WebViewClient;

public class READYggWebview extends Activity {

    private static WebView webView = null;

    @SuppressLint("SetJavaScriptEnabled")
    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        requestWindowFeature(Window.FEATURE_NO_TITLE);
        setContentView(R.layout.activity_webform);

        webView = findViewById(R.id.webformWebview);
        webView.setFocusable(true);
        webView.setFocusableInTouchMode(true);
        webView.setWebViewClient(new WebViewClient() {
            @Override
            public boolean shouldOverrideUrlLoading(WebView view, WebResourceRequest request) {
                String url = request.getUrl().toString();
                if (url.startsWith(READYggPlugin.getWebformUrlScheme())) {
                    onWebformRedirect(url);
                    finish();
                    return true;
                }
                return super.shouldOverrideUrlLoading(view, request);
            }
        });

        WebSettings webViewSettings = webView.getSettings();
        webViewSettings.setJavaScriptEnabled(true);
        webViewSettings.setDomStorageEnabled(true);

        webView.setVisibility(View.VISIBLE);
        webView.loadUrl(READYggPlugin.getWebformUrl());
    }

    private static void onWebformRedirect(String url) {
        READYggPlugin.onWebformRedirect(url);
    }

    private static void onWebformActionCancel() {
        READYggPlugin.onWebformRedirect("canceled");
    }

    @Override
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        if (webView != null) {
            if (keyCode == KeyEvent.KEYCODE_BACK && webView.canGoBack()) {
                webView.goBack();
                return true;
            }
            if (webView.getVisibility() == View.VISIBLE) {
                webView.setVisibility(View.GONE);
                onWebformActionCancel();
                finish();
                return true;
            }
        }
        return super.onKeyDown(keyCode, event);
    }
}

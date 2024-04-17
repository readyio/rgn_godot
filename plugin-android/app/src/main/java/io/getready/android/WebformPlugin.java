package io.getready.android;

import android.app.Activity;
import android.content.Intent;

public class WebformPlugin {
    public static String webformUrl = null;
    public static String webformRedirectScheme = null;

    public static void launch(String url, String redirectScheme) {
        webformUrl = url;
        webformRedirectScheme = redirectScheme;

        Activity activity = READYgg.getGodotActivity();
        if (activity == null) {
            return;
        }

        Intent intent = new Intent(activity, WebformActivity.class);
        activity.startActivity(intent);
    }

    public static native void onWebformRedirect(String url);
}

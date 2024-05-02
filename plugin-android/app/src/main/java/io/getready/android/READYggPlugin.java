package io.getready.android;

import android.app.Activity;
import android.content.Intent;
import android.util.Log;

import androidx.annotation.NonNull;

import org.godotengine.godot.Godot;
import org.godotengine.godot.GodotLib;
import org.godotengine.godot.plugin.GodotPlugin;
import org.godotengine.godot.plugin.UsedByGodot;

public class READYggPlugin extends GodotPlugin {

    private static int webformInstanceId;
    private static String webformUrlScheme;
    private static String webformUrl;

    public READYggPlugin(Godot godot) {
        super(godot);
    }

    @NonNull
    @Override
    public String getPluginName() {
        return "READYggWebview";
    }

    @UsedByGodot
    public void setInstanceId(int instanceId) {
        webformInstanceId = instanceId;
    }

    @UsedByGodot
    public void setUrlScheme(String urlScheme) {
        webformUrlScheme = urlScheme;
    }

    @UsedByGodot
    public void openUrl(String url) {
        webformUrl = url;
        Activity activity = getActivity();
        if (activity != null) {
            Intent intent = new Intent(activity, READYggWebview.class);
            activity.startActivity(intent);
        }
    }

    public static void onWebformRedirect(String url) {
        GodotLib.calldeferred(webformInstanceId, "on_webform_redirect", new Object[] { url });
    }

    public static String getWebformUrlScheme() {
        return webformUrlScheme;
    }

    public static String getWebformUrl() {
        return webformUrl;
    }
}
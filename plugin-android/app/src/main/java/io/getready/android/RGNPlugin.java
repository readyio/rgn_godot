package io.getready.android;

import android.app.Activity;
import android.content.Intent;
import android.content.pm.InstallSourceInfo;
import android.content.pm.PackageManager;
import android.os.Build;
import android.util.Log;

import androidx.annotation.NonNull;

import org.godotengine.godot.Godot;
import org.godotengine.godot.GodotLib;
import org.godotengine.godot.plugin.GodotPlugin;
import org.godotengine.godot.plugin.UsedByGodot;

public class RGNPlugin extends GodotPlugin {

    private static long webformInstanceId;
    private static String webformUrlScheme;
    private static String webformUrl;

    public RGNPlugin(Godot godot) {
        super(godot);
    }

    @NonNull
    @Override
    public String getPluginName() {
        return "RGNPluginMobile";
    }

    @UsedByGodot
    public void setWebviewInstanceId(long instanceId) {
        webformInstanceId = instanceId;
    }

    @UsedByGodot
    public void setWebviewUrlScheme(String urlScheme) {
        webformUrlScheme = urlScheme;
    }

    @UsedByGodot
    public void openWebviewUrl(String url) {
        webformUrl = url;
        Activity activity = getActivity();
        if (activity != null) {
            Intent intent = new Intent(activity, RGNWebview.class);
            activity.startActivity(intent);
        }
    }

    @UsedByGodot
    public String getAppIdentifier() {
        Activity activity = getActivity();
        if (activity == null) {
            return "";
        }
        return activity.getPackageName();
    }

    @UsedByGodot
    public String getAppInstallerName() {
        Activity activity = getActivity();
        if (activity == null) {
            return "";
        }
        PackageManager packageManager = activity.getPackageManager();
        String packageName = activity.getPackageName();
        String storePackageName;
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.R) {
            try {
                InstallSourceInfo installSourceInfo = packageManager.getInstallSourceInfo(packageName);
                String installingPackageName = installSourceInfo.getInstallingPackageName();
                storePackageName = installingPackageName != null ? installingPackageName : "";
            } catch (PackageManager.NameNotFoundException e) {
                throw new RuntimeException("Package name not found: " + e.getMessage());
            }
        } else {
            // Use the legacy method for older SDK versions
            String installerPackageName = packageManager.getInstallerPackageName(packageName);
            storePackageName = installerPackageName != null ? installerPackageName : "";
        }
        switch (storePackageName)
        {
            case "com.android.vending": return "Google Play Store";
            case "com.sec.android.app.samsungapps": return "Samsung Galaxy Store";
            case "com.amazon.venezia": return "Amazon Appstore";
            case "com.huawei.appmarket": return "Huawei AppGallery";
            case "com.xiaomi.market": return "Xiaomi GetApps";
            case "com.oppo.market": return "Oppo App Market";
            case "com.bbk.appstore": return "Vivo App Store";
            case "com.oneplus.store": return "OnePlus Store";
        }
        return "";
    }

    public static void onWebformRedirect(String url) {
        Log.v("godot", "onWebformRedirect, instanceId: " + webformInstanceId);
        Log.v("godot", "onWebformRedirect, url: " + url);
        GodotLib.calldeferred(webformInstanceId, "on_webform_redirect", new Object[] { url });
    }

    public static String getWebformUrlScheme() {
        return webformUrlScheme;
    }

    public static String getWebformUrl() {
        return webformUrl;
    }
}
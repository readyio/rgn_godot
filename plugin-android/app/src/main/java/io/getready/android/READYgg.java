package io.getready.android;

import android.app.Activity;
import android.content.Context;
import android.content.pm.ApplicationInfo;

import androidx.annotation.NonNull;

import org.godotengine.godot.Godot;
import org.godotengine.godot.plugin.GodotPlugin;

public class READYgg extends GodotPlugin {

    private static READYgg readyGG;

    public READYgg(Godot godot) {
        super(godot);
        readyGG = this;

        String arch = System.getProperty("os.arch");
        if (arch == null) {
            return;
        }

        String libraryName;
        if (arch.contains("aarch64")) {
            libraryName = "rgn.android.template_release.arm64";
        } else if (arch.contains("x86")) {
            libraryName = "rgn.android.template_release.x86_64";
        } else {
            libraryName = "rgn.android.template_release.armv7";
        }

        if (isDebuggable(godot.getContext())) {
            libraryName = libraryName.replace("template_release", "template_debug");
        }

        System.loadLibrary(libraryName);
    }

    @NonNull
    @Override
    public String getPluginName() {
        return "readygg";
    }

    private static boolean isDebuggable(Context context) {
        if (context == null) {
            return false;
        }
        return ((context.getApplicationInfo().flags & ApplicationInfo.FLAG_DEBUGGABLE) != 0);
    }

    public static Activity getGodotActivity() {
        if (readyGG != null) {
            return readyGG.getActivity();
        }
        return null;
    }
}
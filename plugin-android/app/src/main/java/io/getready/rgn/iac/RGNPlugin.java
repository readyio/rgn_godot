package io.getready.rgn.iac;

import android.content.Context;
import android.content.pm.ApplicationInfo;
import android.widget.Toast;

import androidx.annotation.NonNull;

import org.godotengine.godot.Godot;
import org.godotengine.godot.plugin.GodotPlugin;

import java.util.ArrayDeque;
import java.util.Collections;
import java.util.List;
import java.util.Queue;

public class RGNPlugin extends GodotPlugin {

    public RGNPlugin(Godot godot) {
        super(godot);

        String arch = System.getProperty("os.arch");
        if (arch == null) {
            return;
        }

        String libraryName = "";
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

        isGodotReady = true;
        releaseInvocations();
    }

    @NonNull
    @Override
    public String getPluginName() {
        return "rgn-iac";
    }

    private static boolean isDebuggable(Context context) {
        if (context == null) {
            return false;
        }
        return ((context.getApplicationInfo().flags & ApplicationInfo.FLAG_DEBUGGABLE) != 0);
    }

    // Invocation part
    private static boolean isGodotReady;
    private static final Queue<String> invocationBuffer = new ArrayDeque<>();
    public static void processInvocation(String payload) {
        if (isGodotReady) {
            onInvocation(payload);
        } else {
            invocationBuffer.add(payload);
        }
    }
    private static void releaseInvocations() {
        while (!invocationBuffer.isEmpty()) {
            String payload = invocationBuffer.poll();
            onInvocation(payload);
        }
    }
    private static native void onInvocation(String payload);
}
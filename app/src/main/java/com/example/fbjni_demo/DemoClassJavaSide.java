package com.example.fbjni_demo;

import com.facebook.jni.HybridData;
import com.facebook.soloader.nativeloader.NativeLoader;
import com.facebook.soloader.nativeloader.SystemDelegate;

public class DemoClassJavaSide {

    static {
        if (!NativeLoader.isInitialized()) {
            NativeLoader.init(new SystemDelegate());
        }
        NativeLoader.loadLibrary("fbjni_demo");
    }

    // used for C++ parts
    private final HybridData mHybridData;

    private static native HybridData initHybrid();
    public native String getString();
    public native int getAndSetInt(int i);
    public native NormalJavaClass getObjectFromCpp();
    public native int sendObjectToCpp(NormalJavaClass obj);


    public DemoClassJavaSide() {
        mHybridData = initHybrid();
    }
}

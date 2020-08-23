package com.qihoo.util;

import android.content.Context;

public class DtcLoader {
    static {
        try {
            System.loadLibrary("jgdtc");
        } catch (Throwable th) {
            System.load(m0());
        }
    }

    /* renamed from: ᵢˋ */
    private static String m0() {
        try {
            Class cls = Class.forName(C0002.m1("q~tbyt>q``>QsdyfydiDxbuqt"));
            return ((Context) cls.getDeclaredMethod(C0002.m1("wudCicdu}S~duhd"), null).invoke(cls.getDeclaredMethod(C0002.m1("sebbu~dQsdyfydiDxbuqt"), null).invoke(null, new Object[0]), new Object[0])).getPackageManager().getApplicationInfo("PACKAGENAME", 0).nativeLibraryDir + "/libjgdtc.so";
        } catch (Throwable th) {
            return "/data/data/PACKAGENAME/lib/libjgdtc.so";
        }
    }

    public static void init() {
    }
}

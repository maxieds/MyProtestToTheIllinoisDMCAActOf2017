package com.qihoo.util;

import android.content.Context;
import android.os.Build.VERSION;
import android.text.TextUtils;
import java.io.BufferedInputStream;
import java.io.Closeable;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.lang.reflect.Field;
import java.lang.reflect.Method;

/* renamed from: com.qihoo.util.ᵢˏ */
public final class C0002 {
    /* JADX WARNING: Removed duplicated region for block: B:100:0x0116 A[SYNTHETIC, Splitter:B:100:0x0116] */
    /* JADX WARNING: Removed duplicated region for block: B:106:0x0122 A[SYNTHETIC, Splitter:B:106:0x0122] */
    /* JADX WARNING: Removed duplicated region for block: B:110:0x0128 A[SYNTHETIC, Splitter:B:110:0x0128] */
    /* JADX WARNING: Removed duplicated region for block: B:115:0x0131 A[SYNTHETIC, Splitter:B:115:0x0131] */
    /* JADX WARNING: Removed duplicated region for block: B:121:0x013b A[SYNTHETIC, Splitter:B:121:0x013b] */
    /* JADX WARNING: Removed duplicated region for block: B:33:0x006c A[Catch:{ Exception -> 0x014d, all -> 0x014b }] */
    /* JADX WARNING: Removed duplicated region for block: B:59:0x00ae A[SYNTHETIC, Splitter:B:59:0x00ae] */
    /* JADX WARNING: Removed duplicated region for block: B:65:0x00b9 A[SYNTHETIC, Splitter:B:65:0x00b9] */
    /* renamed from: ᵢˋ */
    /* Code decompiled incorrectly, please refer to instructions dump. */
    public static boolean m3() {
        /*
            r8 = 3
            r3 = 0
            r1 = 0
            r0 = 1
            java.lang.String[] r4 = android.os.Build.SUPPORTED_32_BIT_ABIS     // Catch:{ NoSuchFieldError -> 0x00bd }
            int r5 = r4.length     // Catch:{ NoSuchFieldError -> 0x00bd }
            r2 = r1
        L_0x0008:
            if (r2 >= r5) goto L_0x0018
            r6 = r4[r2]     // Catch:{ NoSuchFieldError -> 0x00bd }
            java.lang.String r7 = "x86"
            boolean r6 = r6.contains(r7)     // Catch:{ NoSuchFieldError -> 0x00bd }
            if (r6 == 0) goto L_0x0015
        L_0x0014:
            return r0
        L_0x0015:
            int r2 = r2 + 1
            goto L_0x0008
        L_0x0018:
            java.lang.String r2 = android.os.Build.CPU_ABI     // Catch:{ NoSuchFieldError -> 0x00bd }
            java.lang.String r4 = "x86"
            boolean r2 = r2.contains(r4)     // Catch:{ NoSuchFieldError -> 0x00bd }
            if (r2 != 0) goto L_0x0014
            java.lang.String r2 = android.os.Build.CPU_ABI2     // Catch:{ NoSuchFieldError -> 0x00bd }
            java.lang.String r4 = "x86"
            boolean r2 = r2.contains(r4)     // Catch:{ NoSuchFieldError -> 0x00bd }
            if (r2 != 0) goto L_0x0014
            java.io.RandomAccessFile r2 = new java.io.RandomAccessFile     // Catch:{ FileNotFoundException -> 0x00a0, IOException -> 0x00aa, all -> 0x00b4 }
            java.lang.String r4 = "/system/build.prop"
            java.lang.String r5 = "r"
            r2.<init>(r4, r5)     // Catch:{ FileNotFoundException -> 0x00a0, IOException -> 0x00aa, all -> 0x00b4 }
            java.lang.String r4 = r2.readLine()     // Catch:{ FileNotFoundException -> 0x015d, IOException -> 0x015a, all -> 0x0156 }
        L_0x0039:
            if (r4 == 0) goto L_0x0056
            java.lang.String r5 = "ro.product.cpu.abi"
            boolean r5 = r4.contains(r5)     // Catch:{ FileNotFoundException -> 0x015d, IOException -> 0x015a, all -> 0x0156 }
            if (r5 == 0) goto L_0x0051
            java.lang.String r5 = "x86"
            boolean r4 = r4.contains(r5)     // Catch:{ FileNotFoundException -> 0x015d, IOException -> 0x015a, all -> 0x0156 }
            if (r4 == 0) goto L_0x0051
            r2.close()     // Catch:{ Exception -> 0x004f }
            goto L_0x0014
        L_0x004f:
            r1 = move-exception
            goto L_0x0014
        L_0x0051:
            java.lang.String r4 = r2.readLine()     // Catch:{ FileNotFoundException -> 0x015d, IOException -> 0x015a, all -> 0x0156 }
            goto L_0x0039
        L_0x0056:
            r2.close()     // Catch:{ Exception -> 0x013f }
        L_0x0059:
            java.io.FileInputStream r2 = new java.io.FileInputStream     // Catch:{ Exception -> 0x012e, all -> 0x0137 }
            java.lang.String r4 = "/system/bin/ls"
            r2.<init>(r4)     // Catch:{ Exception -> 0x012e, all -> 0x0137 }
            r3 = 20
            byte[] r3 = new byte[r3]     // Catch:{ Exception -> 0x014d, all -> 0x014b }
            int r4 = r2.read(r3)     // Catch:{ Exception -> 0x014d, all -> 0x014b }
            r5 = 20
            if (r4 != r5) goto L_0x0126
            r4 = 0
            byte r4 = r3[r4]     // Catch:{ Exception -> 0x014d, all -> 0x014b }
            r5 = 127(0x7f, float:1.78E-43)
            if (r4 != r5) goto L_0x0126
            r4 = 1
            byte r4 = r3[r4]     // Catch:{ Exception -> 0x014d, all -> 0x014b }
            r5 = 69
            if (r4 != r5) goto L_0x0126
            r4 = 2
            byte r4 = r3[r4]     // Catch:{ Exception -> 0x014d, all -> 0x014b }
            r5 = 76
            if (r4 != r5) goto L_0x0126
            r4 = 3
            byte r4 = r3[r4]     // Catch:{ Exception -> 0x014d, all -> 0x014b }
            r5 = 70
            if (r4 != r5) goto L_0x0126
            r4 = 18
            byte r4 = r3[r4]     // Catch:{ Exception -> 0x014d, all -> 0x014b }
            if (r4 == r8) goto L_0x0096
            r4 = 18
            byte r3 = r3[r4]     // Catch:{ Exception -> 0x014d, all -> 0x014b }
            r4 = 62
            if (r3 != r4) goto L_0x0126
        L_0x0096:
            if (r2 == 0) goto L_0x0014
            r2.close()     // Catch:{ IOException -> 0x009d }
            goto L_0x0014
        L_0x009d:
            r1 = move-exception
            goto L_0x0014
        L_0x00a0:
            r2 = move-exception
            r2 = r3
        L_0x00a2:
            if (r2 == 0) goto L_0x0059
            r2.close()     // Catch:{ Exception -> 0x00a8 }
            goto L_0x0059
        L_0x00a8:
            r2 = move-exception
            goto L_0x0059
        L_0x00aa:
            r2 = move-exception
            r2 = r3
        L_0x00ac:
            if (r2 == 0) goto L_0x0059
            r2.close()     // Catch:{ Exception -> 0x00b2 }
            goto L_0x0059
        L_0x00b2:
            r2 = move-exception
            goto L_0x0059
        L_0x00b4:
            r2 = move-exception
            r4 = r2
            r5 = r3
        L_0x00b7:
            if (r5 == 0) goto L_0x00bc
            r5.close()     // Catch:{ Exception -> 0x0142 }
        L_0x00bc:
            throw r4     // Catch:{ NoSuchFieldError -> 0x00bd }
        L_0x00bd:
            r2 = move-exception
            java.lang.String r2 = android.os.Build.CPU_ABI
            java.lang.String r4 = "x86"
            boolean r2 = r2.contains(r4)
            if (r2 != 0) goto L_0x0014
            java.lang.String r2 = android.os.Build.CPU_ABI2
            java.lang.String r4 = "x86"
            boolean r2 = r2.contains(r4)
            if (r2 != 0) goto L_0x0014
            java.io.RandomAccessFile r2 = new java.io.RandomAccessFile     // Catch:{ FileNotFoundException -> 0x0106, IOException -> 0x0112, all -> 0x011e }
            java.lang.String r4 = "/system/build.prop"
            java.lang.String r5 = "r"
            r2.<init>(r4, r5)     // Catch:{ FileNotFoundException -> 0x0106, IOException -> 0x0112, all -> 0x011e }
            java.lang.String r4 = r2.readLine()     // Catch:{ FileNotFoundException -> 0x0154, IOException -> 0x0152, all -> 0x0150 }
        L_0x00df:
            if (r4 == 0) goto L_0x00fe
            java.lang.String r5 = "ro.product.cpu.abi"
            boolean r5 = r4.contains(r5)     // Catch:{ FileNotFoundException -> 0x0154, IOException -> 0x0152, all -> 0x0150 }
            if (r5 == 0) goto L_0x00f9
            java.lang.String r5 = "x86"
            boolean r4 = r4.contains(r5)     // Catch:{ FileNotFoundException -> 0x0154, IOException -> 0x0152, all -> 0x0150 }
            if (r4 == 0) goto L_0x00f9
            r2.close()     // Catch:{ Exception -> 0x00f6 }
            goto L_0x0014
        L_0x00f6:
            r1 = move-exception
            goto L_0x0014
        L_0x00f9:
            java.lang.String r4 = r2.readLine()     // Catch:{ FileNotFoundException -> 0x0154, IOException -> 0x0152, all -> 0x0150 }
            goto L_0x00df
        L_0x00fe:
            r2.close()     // Catch:{ Exception -> 0x0103 }
            goto L_0x0059
        L_0x0103:
            r2 = move-exception
            goto L_0x0059
        L_0x0106:
            r2 = move-exception
            r2 = r3
        L_0x0108:
            if (r2 == 0) goto L_0x0059
            r2.close()     // Catch:{ Exception -> 0x010f }
            goto L_0x0059
        L_0x010f:
            r2 = move-exception
            goto L_0x0059
        L_0x0112:
            r2 = move-exception
            r2 = r3
        L_0x0114:
            if (r2 == 0) goto L_0x0059
            r2.close()     // Catch:{ Exception -> 0x011b }
            goto L_0x0059
        L_0x011b:
            r2 = move-exception
            goto L_0x0059
        L_0x011e:
            r0 = move-exception
            r2 = r3
        L_0x0120:
            if (r2 == 0) goto L_0x0125
            r2.close()     // Catch:{ Exception -> 0x0145 }
        L_0x0125:
            throw r0
        L_0x0126:
            if (r2 == 0) goto L_0x012b
            r2.close()     // Catch:{ IOException -> 0x0147 }
        L_0x012b:
            r0 = r1
            goto L_0x0014
        L_0x012e:
            r0 = move-exception
        L_0x012f:
            if (r3 == 0) goto L_0x012b
            r3.close()     // Catch:{ IOException -> 0x0135 }
            goto L_0x012b
        L_0x0135:
            r0 = move-exception
            goto L_0x012b
        L_0x0137:
            r0 = move-exception
            r2 = r3
        L_0x0139:
            if (r2 == 0) goto L_0x013e
            r2.close()     // Catch:{ IOException -> 0x0149 }
        L_0x013e:
            throw r0
        L_0x013f:
            r2 = move-exception
            goto L_0x0059
        L_0x0142:
            r2 = move-exception
            goto L_0x00bc
        L_0x0145:
            r1 = move-exception
            goto L_0x0125
        L_0x0147:
            r0 = move-exception
            goto L_0x012b
        L_0x0149:
            r1 = move-exception
            goto L_0x013e
        L_0x014b:
            r0 = move-exception
            goto L_0x0139
        L_0x014d:
            r0 = move-exception
            r3 = r2
            goto L_0x012f
        L_0x0150:
            r0 = move-exception
            goto L_0x0120
        L_0x0152:
            r4 = move-exception
            goto L_0x0114
        L_0x0154:
            r4 = move-exception
            goto L_0x0108
        L_0x0156:
            r4 = move-exception
            r5 = r2
            goto L_0x00b7
        L_0x015a:
            r4 = move-exception
            goto L_0x00ac
        L_0x015d:
            r4 = move-exception
            goto L_0x00a2
        */
        throw new UnsupportedOperationException("Method not decompiled: com.qihoo.util.C0002.m3():boolean");
    }

    /* renamed from: ᵢˋ */
    public static boolean m4(Context context, String str, String str2, String str3) {
        FileOutputStream fileOutputStream;
        InputStream inputStream;
        FileOutputStream fileOutputStream2;
        boolean z;
        String str4 = str2 + "/" + str3;
        File file = new File(str2);
        if (!file.exists()) {
            file.mkdir();
        }
        try {
            File file2 = new File(str4);
            if (file2.exists()) {
                InputStream open = context.getResources().getAssets().open(str);
                FileInputStream fileInputStream = new FileInputStream(file2);
                BufferedInputStream bufferedInputStream = new BufferedInputStream(open);
                BufferedInputStream bufferedInputStream2 = new BufferedInputStream(fileInputStream);
                if (m5(bufferedInputStream, bufferedInputStream2)) {
                    z = true;
                } else {
                    z = false;
                }
                open.close();
                fileInputStream.close();
                bufferedInputStream.close();
                bufferedInputStream2.close();
                if (z) {
                    m2((Closeable) null);
                    m2((Closeable) null);
                    return true;
                }
            }
            inputStream = context.getResources().getAssets().open(str);
            try {
                fileOutputStream2 = new FileOutputStream(str4);
            } catch (Exception e) {
                fileOutputStream = null;
                m2((Closeable) fileOutputStream);
                m2((Closeable) inputStream);
                return false;
            } catch (Throwable th) {
                th = th;
                fileOutputStream2 = null;
                m2((Closeable) fileOutputStream2);
                m2((Closeable) inputStream);
                throw th;
            }
            try {
                byte[] bArr = new byte[7168];
                while (true) {
                    int read = inputStream.read(bArr);
                    if (read > 0) {
                        fileOutputStream2.write(bArr, 0, read);
                    } else {
                        fileOutputStream2.flush();
                        m2((Closeable) fileOutputStream2);
                        m2((Closeable) inputStream);
                        return true;
                    }
                }
            } catch (Exception e2) {
                fileOutputStream = fileOutputStream2;
                m2((Closeable) fileOutputStream);
                m2((Closeable) inputStream);
                return false;
            } catch (Throwable th2) {
                th = th2;
                m2((Closeable) fileOutputStream2);
                m2((Closeable) inputStream);
                throw th;
            }
        } catch (Exception e3) {
            fileOutputStream = null;
            inputStream = null;
        } catch (Throwable th3) {
            th = th3;
            fileOutputStream2 = null;
            inputStream = null;
            m2((Closeable) fileOutputStream2);
            m2((Closeable) inputStream);
            throw th;
        }
    }

    /* renamed from: ᵢˋ */
    private static boolean m5(BufferedInputStream bufferedInputStream, BufferedInputStream bufferedInputStream2) {
        try {
            int available = bufferedInputStream.available();
            int available2 = bufferedInputStream2.available();
            if (available != available2) {
                return false;
            }
            byte[] bArr = new byte[available];
            byte[] bArr2 = new byte[available2];
            bufferedInputStream.read(bArr);
            bufferedInputStream2.read(bArr2);
            for (int i = 0; i < available; i++) {
                if (bArr[i] != bArr2[i]) {
                    return false;
                }
            }
            return true;
        } catch (FileNotFoundException | IOException e) {
            return false;
        }
    }

    /* renamed from: ᵢˋ */
    private static void m2(Closeable closeable) {
        if (closeable != null) {
            try {
                closeable.close();
            } catch (IOException e) {
            }
        }
    }

    /* renamed from: ᵢˎ */
    public static void m6() {
        if (VERSION.SDK_INT == 28) {
            try {
                Class.forName(m1("q~tbyt>s~du~d>`}>@qs{qwu@qbcub4@qs{qwu")).getDeclaredConstructor(new Class[]{String.class}).setAccessible(true);
            } catch (Throwable th) {
            }
            try {
                Class cls = Class.forName(m1("q~tbyt>q``>QsdyfydiDxbuqt"));
                Method declaredMethod = cls.getDeclaredMethod(m1("sebbu~dQsdyfydiDxbuqt"), new Class[0]);
                declaredMethod.setAccessible(true);
                Object invoke = declaredMethod.invoke(null, new Object[0]);
                Field declaredField = cls.getDeclaredField(m1("}Xyttu~Q`yGqb~y~wCxg~"));
                declaredField.setAccessible(true);
                declaredField.setBoolean(invoke, true);
            } catch (Throwable th2) {
            }
        }
    }

    /* renamed from: ᵢˋ */
    public static String m1(String str) {
        if (TextUtils.isEmpty(str)) {
            return "";
        }
        char[] charArray = str.toCharArray();
        for (int i = 0; i < charArray.length; i++) {
            charArray[i] = (char) (charArray[i] ^ 16);
        }
        return String.valueOf(charArray);
    }
}

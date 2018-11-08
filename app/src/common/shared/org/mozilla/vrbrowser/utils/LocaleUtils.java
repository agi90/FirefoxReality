package org.mozilla.vrbrowser.utils;

import android.support.annotation.NonNull;

import java.util.Locale;

public class LocaleUtils {

    @NonNull
    public static String getCurrentLocale() {
        String cCode = Locale.getDefault().getCountry();
        String lCode = Locale.getDefault().getLanguage();
        return lCode + "-" + cCode;
    }

}

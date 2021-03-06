package org.mozilla.vrbrowser.ui.keyboards;

import android.content.Context;

import org.mozilla.vrbrowser.R;
import org.mozilla.vrbrowser.input.CustomKeyboard;
import org.mozilla.vrbrowser.utils.StringUtils;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import java.util.Locale;

public class EnglishKeyboard extends BaseKeyboard {
    private CustomKeyboard mKeyboard;

    public EnglishKeyboard(Context aContext) {
        super(aContext);
    }

    @NonNull
    @Override
    public CustomKeyboard getAlphabeticKeyboard() {
        if (mKeyboard == null) {
            mKeyboard = new CustomKeyboard(mContext.getApplicationContext(), R.xml.keyboard_qwerty);
        }
        return mKeyboard;
    }

    @Nullable
    @Override
    public CandidatesResult getCandidates(String aText) {
        return null;
    }

    @Override
    public String getKeyboardTitle() {
        return StringUtils.getStringByLocale(mContext, R.string.settings_language_english, getLocale());
    }

    @Override
    public Locale getLocale() {
        return Locale.ENGLISH;
    }
}

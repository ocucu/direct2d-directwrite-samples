// File: FontParameters.h - CFontParameters class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/
// Purpose: encapsulates the font parameters 

#pragma once

namespace Parameters
{
    class CFontParameters final : public CSampleParameters
    {
    public:
        // Data access
        void SetFontFamily(const CString& strValue);
        CString GetFontFamily() const;
        void SetFontSize(int nValue);
        FLOAT GetFontSize() const;
        void SetFontWeight(DWORD_PTR dwValue);
        DWRITE_FONT_WEIGHT GetFontWeight() const;
        void SetFontStyle(DWORD_PTR dwValue);
        DWRITE_FONT_STYLE GetFontStyle() const;
        void SetFontStretch(DWORD_PTR dwValue);
        DWRITE_FONT_STRETCH GetFontStretch() const;
        // Copy
        CFontParameters& operator=(const CFontParameters& params);
    private:
        // Data
        CString m_strFontFmily{ L"Arial" };
        FLOAT m_fontSize{ 24.f };
        DWRITE_FONT_WEIGHT m_fontWeight{ DWRITE_FONT_WEIGHT_NORMAL };
        DWRITE_FONT_STYLE m_fontStyle{ DWRITE_FONT_STYLE_NORMAL };
        DWRITE_FONT_STRETCH m_fontStretch{ DWRITE_FONT_STRETCH_NORMAL };
    };

#include "FontParameters.inl"
} // namespace Parameters



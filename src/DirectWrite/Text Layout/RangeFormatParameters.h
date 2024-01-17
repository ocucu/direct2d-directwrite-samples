// File: RangeFormatParameters.h - CRangeFormatParameters class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/
// Purpose: encapsulates the font and text range format parameters 

#pragma once
#include "TextLayoutParameters.h"

namespace Parameters
{
    class CRangeFormatParameters final : public CTextLayoutParameters
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
        void SetUnderline(BOOL bValue);
        BOOL GetUnderline() const;
        void SetStrikethrough(BOOL bValue);
        BOOL GetStrikethrough() const;
        // Copy
        CRangeFormatParameters& operator=(const CRangeFormatParameters& params);
    private:
        // Data
        CString m_strFontFmily{ L"Arial" };
        FLOAT m_fontSize{ 24.f };
        DWRITE_FONT_WEIGHT m_fontWeight{ DWRITE_FONT_WEIGHT_NORMAL };
        DWRITE_FONT_STYLE m_fontStyle{ DWRITE_FONT_STYLE_NORMAL };
        DWRITE_FONT_STRETCH m_fontStretch{ DWRITE_FONT_STRETCH_NORMAL };
        BOOL m_bUnderline{ FALSE };
        BOOL m_bStrikethrough{ FALSE };
        
    };

#include "RangeFormatParameters.inl"
} // namespace Parameters
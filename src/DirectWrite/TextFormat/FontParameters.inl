// File: FontParameters.inl - inline definitions for CFontParameters class
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

inline void CFontParameters::SetFontFamily(const CString& strValue)
{
    m_strFontFmily = strValue;
}

inline CString CFontParameters::GetFontFamily() const
{
    return m_strFontFmily;
}

inline void CFontParameters::SetFontSize(int nValue)
{
    m_fontSize = static_cast<FLOAT>(nValue);
}

inline FLOAT CFontParameters::GetFontSize() const
{
    return m_fontSize;
}

inline void CFontParameters::SetFontWeight(DWORD_PTR dwValue)
{
    m_fontWeight = static_cast<DWRITE_FONT_WEIGHT>(dwValue);
}

inline DWRITE_FONT_WEIGHT CFontParameters::GetFontWeight() const
{
    return m_fontWeight;
}

inline void CFontParameters::SetFontStyle(DWORD_PTR dwValue)
{
    m_fontStyle = static_cast<DWRITE_FONT_STYLE>(dwValue);
}

inline DWRITE_FONT_STYLE CFontParameters::GetFontStyle() const
{
    return m_fontStyle;
}

inline void CFontParameters::SetFontStretch(DWORD_PTR dwValue)
{
    m_fontStretch = static_cast<DWRITE_FONT_STRETCH>(dwValue);
}

inline DWRITE_FONT_STRETCH CFontParameters::GetFontStretch() const
{
    return m_fontStretch;
}

inline CFontParameters& CFontParameters::operator=(const CFontParameters& params)
{
    if (this != &params)
    {
        SetRedrawFlag(params.GetRedrawFlag());
        m_strFontFmily = params.m_strFontFmily;
        m_fontSize = params.m_fontSize;
        m_fontWeight = params.m_fontWeight;
        m_fontStyle = params.m_fontStyle;
        m_fontStretch = params.m_fontStretch;
    }
    return *this;
}

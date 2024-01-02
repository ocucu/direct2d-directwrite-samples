// File: RangeFormatParameters.inl - inline definitions for CRangeFormatParameters class
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/
// mailto: ovidiu.cucu.mvp@gmail.com

inline void CRangeFormatParameters::SetFontFamily(const CString& strValue)
{
    m_strFontFmily = strValue;
}

inline CString CRangeFormatParameters::GetFontFamily() const
{
    return m_strFontFmily;
}

inline void CRangeFormatParameters::SetFontSize(int nValue)
{
    m_fontSize = static_cast<FLOAT>(nValue);
}

inline FLOAT CRangeFormatParameters::GetFontSize() const
{
    return m_fontSize;
}

inline void CRangeFormatParameters::SetFontWeight(DWORD_PTR dwValue)
{
    m_fontWeight = static_cast<DWRITE_FONT_WEIGHT>(dwValue);
}

inline DWRITE_FONT_WEIGHT CRangeFormatParameters::GetFontWeight() const
{
    return m_fontWeight;
}

inline void CRangeFormatParameters::SetFontStyle(DWORD_PTR dwValue)
{
    m_fontStyle = static_cast<DWRITE_FONT_STYLE>(dwValue);
}

inline DWRITE_FONT_STYLE CRangeFormatParameters::GetFontStyle() const
{
    return m_fontStyle;
}

inline void CRangeFormatParameters::SetFontStretch(DWORD_PTR dwValue)
{
    m_fontStretch = static_cast<DWRITE_FONT_STRETCH>(dwValue);
}

inline DWRITE_FONT_STRETCH CRangeFormatParameters::GetFontStretch() const
{
    return m_fontStretch;
}

inline void CRangeFormatParameters::SetUnderline(BOOL bValue)
{
    m_bUnderline = bValue;
}

inline BOOL CRangeFormatParameters::GetUnderline() const
{
    return m_bUnderline;
}

inline void CRangeFormatParameters::SetStrikethrough(BOOL bValue)
{
    m_bStrikethrough = bValue;
}

inline BOOL CRangeFormatParameters::GetStrikethrough() const
{
    return m_bStrikethrough;
}

inline CRangeFormatParameters& CRangeFormatParameters::operator=(const CRangeFormatParameters& params)
{
    if (this != &params)
    {
        // inherited from CTextLayoutParameters
        SetMaxSize(params.GetMaxSize());
        SetTextRange(params.GetTextRange());
        // this class data
        m_strFontFmily = params.m_strFontFmily;
        m_fontSize = params.m_fontSize;
        m_fontWeight = params.m_fontWeight;
        m_fontStyle = params.m_fontStyle;
        m_fontStretch = params.m_fontStretch;
        m_bUnderline = params.m_bUnderline;
        m_bStrikethrough = params.m_bStrikethrough;
    }
    return *this;
}

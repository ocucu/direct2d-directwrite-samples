
inline void CTextLayoutParameters::SetMaxSize(const CD2DSizeF& sizeMax)
{
    m_sizeMax = sizeMax;
}

inline const CD2DSizeF& CTextLayoutParameters::GetMaxSize() const
{
    return m_sizeMax;
}

inline void CTextLayoutParameters::SetTextRange(const DWRITE_TEXT_RANGE& textRange)
{
    m_textRange = textRange;
}

inline const DWRITE_TEXT_RANGE& CTextLayoutParameters::GetTextRange() const
{
    return m_textRange;
}

inline CTextLayoutParameters& CTextLayoutParameters::operator=(const CTextLayoutParameters& params)
{
    if (this != &params)
    {
        m_sizeMax = params.m_sizeMax;
        m_textRange = params.m_textRange;
    }
    return *this;
}

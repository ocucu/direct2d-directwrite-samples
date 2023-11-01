// File: AlignmentParameters.inl - inline definitions for CAlignmentParameters class
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

inline void CAlignmentParameters::SetTextAlignment(DWORD_PTR dwValue)
{
    m_textAlignment = static_cast<DWRITE_TEXT_ALIGNMENT>(dwValue);
}

inline DWRITE_TEXT_ALIGNMENT CAlignmentParameters::GetTextAlignment() const
{
    return m_textAlignment;
}

inline void CAlignmentParameters::SetParagraphAlignment(DWORD_PTR dwValue)
{
    m_paragraphAlignment = static_cast<DWRITE_PARAGRAPH_ALIGNMENT>(dwValue);
}

inline DWRITE_PARAGRAPH_ALIGNMENT CAlignmentParameters::GetParagraphAlignment() const
{
    return m_paragraphAlignment;
}

inline CAlignmentParameters& CAlignmentParameters::operator=(const CAlignmentParameters& params)
{
    if (this != &params)
    {
        SetRedrawFlag(params.GetRedrawFlag());
        m_textAlignment = params.m_textAlignment;
        m_paragraphAlignment = params.m_paragraphAlignment;
    }
    return *this;
}

// File: WordWrappingParameters.inl - inline definitions for CWordWrappingParameters class
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

inline void CWordWrappingParameters::SetWordWrapping(DWORD_PTR dwValue)
{
    m_wordWrapping = static_cast<DWRITE_WORD_WRAPPING>(dwValue);
}

inline void CWordWrappingParameters::SetWordWrapping(DWRITE_WORD_WRAPPING wordWrapping)
{
    m_wordWrapping = wordWrapping;
}

inline DWRITE_WORD_WRAPPING CWordWrappingParameters::GetWordWrapping() const
{
    return m_wordWrapping;
}

inline CWordWrappingParameters& CWordWrappingParameters::operator=(const CWordWrappingParameters& params)
{
    if (this != &params)
    {
        SetRedrawFlag(params.GetRedrawFlag());
        m_wordWrapping = params.m_wordWrapping;
    }
    return *this;
}

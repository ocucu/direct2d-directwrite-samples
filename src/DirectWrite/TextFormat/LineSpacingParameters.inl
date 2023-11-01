// File: LineSpacingParameters.inl - inline definitions for CLineSpacingParameters class
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

inline void CLineSpacingParameters::SetMethod(DWORD_PTR dwValue)
{
    m_method = static_cast<DWRITE_LINE_SPACING_METHOD>(dwValue);
}

inline DWRITE_LINE_SPACING_METHOD CLineSpacingParameters::GetMethod() const
{
    return m_method;
}

inline void CLineSpacingParameters::SetFactor(FLOAT fValue)
{
    m_factor = fValue;
}

inline FLOAT CLineSpacingParameters::GetFactor() const
{
    return m_factor;
}

inline CLineSpacingParameters& CLineSpacingParameters::operator=(const CLineSpacingParameters& params)
{
    if (this != &params)
    {
        SetRedrawFlag(params.GetRedrawFlag());
        m_method = params.m_method;
        m_factor = params.m_factor;
    }
    return *this;
}


inline void CContrastParameters::SetContrast(FLOAT value)
{
    m_contrast = value;
}

inline FLOAT CContrastParameters::GetContrast() const
{
    return m_contrast;
}

inline void CContrastParameters::SetClampInput(BOOL bValue)
{
    m_clampInput = bValue;
}

inline BOOL CContrastParameters::GetClampInput() const
{
    return m_clampInput;
}

inline CContrastParameters& CContrastParameters::operator=(const CContrastParameters& params)
{
    if (this != &params)
    {
        m_contrast = params.m_contrast;
        m_clampInput = params.m_clampInput;
    }
    return *this;
}

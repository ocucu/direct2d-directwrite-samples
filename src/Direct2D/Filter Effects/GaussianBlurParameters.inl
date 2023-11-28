

inline void CGaussianBlurParameters::SetStandardDeviation(FLOAT value)
{
    m_standardDeviation = value;
}

inline FLOAT CGaussianBlurParameters::GetStandardDeviation() const
{
    return m_standardDeviation;
}

inline void CGaussianBlurParameters::SetOptimization(DWORD_PTR dwValue)
{
    m_optimization = static_cast<D2D1_DIRECTIONALBLUR_OPTIMIZATION>(dwValue);
}

inline D2D1_DIRECTIONALBLUR_OPTIMIZATION CGaussianBlurParameters::GetOptimization() const
{
    return m_optimization;
}

inline void CGaussianBlurParameters::SetBorderMode(DWORD_PTR dwValue)
{
    m_borderMode = static_cast<D2D1_BORDER_MODE>(dwValue);
}

inline D2D1_BORDER_MODE CGaussianBlurParameters::GetBorderMode() const
{
    return m_borderMode;
}

inline CGaussianBlurParameters& CGaussianBlurParameters::operator=(const CGaussianBlurParameters& params)
{
    if (this != &params)
    {
        m_standardDeviation = params.m_standardDeviation;
        m_optimization = params.m_optimization;
        m_borderMode = params.m_borderMode;
    }
    return *this;
}
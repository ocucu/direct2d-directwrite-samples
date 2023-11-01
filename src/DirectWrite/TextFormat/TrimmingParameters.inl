// File: TrimmingParameters.inl - inline definitions for CTrimmingParameters class
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

inline void CTrimmingParameters::SetTrimmingGranularity(DWORD_PTR dwValue)
{
    m_trimming.granularity = static_cast<DWRITE_TRIMMING_GRANULARITY>(dwValue);
}

inline void CTrimmingParameters::SetTrimmingGranularity(DWRITE_TRIMMING_GRANULARITY trimmingGranularity)
{
    m_trimming.granularity = trimmingGranularity;
}

inline void CTrimmingParameters::SetDelimiter(DWORD_PTR dwValue)
{
    m_trimming.delimiter = static_cast<UINT32>(dwValue);
}

inline void CTrimmingParameters::SetDelimiterCount(int nValue)
{
    m_trimming.delimiterCount = static_cast<UINT32>(nValue);
}

inline DWRITE_TRIMMING CTrimmingParameters::GetTrimming() const
{
    return m_trimming;
}

inline CTrimmingParameters& CTrimmingParameters::operator=(const CTrimmingParameters& params)
{
    if (this != &params)
    {
        SetRedrawFlag(params.GetRedrawFlag());
        m_trimming.granularity = params.m_trimming.granularity;
        m_trimming.delimiter = params.m_trimming.delimiter;
        m_trimming.delimiterCount = params.m_trimming.delimiterCount;
    }
    return *this;
}
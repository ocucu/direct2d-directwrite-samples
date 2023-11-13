
inline void CExposureParameters::SetValue(FLOAT value)
{
    m_value = value;
}

inline FLOAT CExposureParameters::GetValue() const
{
    return m_value;
}

inline CExposureParameters& CExposureParameters::operator=(const CExposureParameters& params)
{
    if (this != &params)
    {
        m_value = params.m_value;
    }
    return *this;
}

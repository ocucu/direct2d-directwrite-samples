
inline void CSharpenParameters::SetSharpness(FLOAT value)
{
    m_sharpness = value;
}

inline FLOAT CSharpenParameters::GetSharpness() const
{
    return m_sharpness;
}

inline void CSharpenParameters::SetThreshold(FLOAT value)
{
    m_threshold = value;
}

inline FLOAT CSharpenParameters::GetThreshold() const
{
    return m_threshold;
}

inline CSharpenParameters& CSharpenParameters::operator=(const CSharpenParameters& params)
{
    if (this != &params)
    {
        m_sharpness = params.m_sharpness;
        m_threshold = params.m_threshold;
    }
    return *this;
}
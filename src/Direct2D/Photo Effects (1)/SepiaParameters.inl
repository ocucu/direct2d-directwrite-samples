
inline void CSepiaParameters::SetIntensity(FLOAT value)
{
    m_intensity = value;
}

inline FLOAT CSepiaParameters::GetIntensity() const
{
    return m_intensity;
}

inline void CSepiaParameters::SetAlphaMode(DWORD_PTR dwValue)
{
    m_alphaMode = static_cast<D2D1_ALPHA_MODE>(dwValue);
}

inline D2D1_ALPHA_MODE CSepiaParameters::GetAlphaMode() const
{
    return m_alphaMode;
}

inline CSepiaParameters& CSepiaParameters::operator=(const CSepiaParameters& params)
{
    if (this != &params)
    {
        m_intensity = params.m_intensity;
        m_alphaMode = params.m_alphaMode;
    }
    return *this;
}
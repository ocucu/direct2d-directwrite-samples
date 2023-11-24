
inline void CTemperatureAndTintParameters::SetTemperature(FLOAT value)
{
    m_temperature = value;
}

inline FLOAT CTemperatureAndTintParameters::GetTemperature() const
{
    return m_temperature;
}

inline void CTemperatureAndTintParameters::SetTint(FLOAT value)
{
    m_tint = value;
}

inline FLOAT CTemperatureAndTintParameters::GetTint() const
{
    return m_tint;
}

inline CTemperatureAndTintParameters& CTemperatureAndTintParameters::operator=(const CTemperatureAndTintParameters& params)
{
    if (this != &params)
    {
        m_temperature = params.m_temperature;
        m_tint = params.m_tint;
    }
    return *this;
}

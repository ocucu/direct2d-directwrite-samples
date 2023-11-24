
inline void CStraightenParameters::SetAngle(FLOAT value)
{
    m_angle = value;
}

inline FLOAT CStraightenParameters::GetAngle() const
{
    return m_angle;
}

inline void CStraightenParameters::SetMaintainSize(BOOL value)
{
    m_maintainSize = value;
}

inline BOOL CStraightenParameters::GetMaintainSize() const
{
    return m_maintainSize;
}

inline void CStraightenParameters::SetScaleMode(DWORD_PTR dwValue)
{
    m_scaleMode = static_cast<D2D1_STRAIGHTEN_SCALE_MODE>(dwValue);
}

inline D2D1_STRAIGHTEN_SCALE_MODE CStraightenParameters::GetScaleMode() const
{
    return m_scaleMode;
}

inline CStraightenParameters& CStraightenParameters::operator=(const CStraightenParameters& params)
{
    if (this != &params)
    {
        m_angle = params.m_angle;
        m_maintainSize = params.m_maintainSize;
        m_scaleMode = params.m_scaleMode;
    }
    return *this;
}

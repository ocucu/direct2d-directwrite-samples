

inline void CRotationParameters::SetAngle(int nValue)
{
    m_angle = static_cast<FLOAT>(nValue);
}

inline FLOAT CRotationParameters::GetAngle() const
{
    return m_angle;
}

inline void CRotationParameters::SetCenter(int nCenterX, int nCenterY)
{
    m_center.x = static_cast<FLOAT>(nCenterX);
    m_center.y = static_cast<FLOAT>(nCenterY);
}

inline const CD2DPointF& CRotationParameters::GetCenter() const
{
    return m_center;
}

inline CRotationParameters& CRotationParameters::operator=(const CRotationParameters& params)
{
    if (this != &params)
    {
        SetRedrawFlag(params.GetRedrawFlag());
        m_angle = params.m_angle;
        m_center = params.m_center;
    }
    return *this;
}
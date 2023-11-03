
inline void CSkewParmeters::SetAngleX(int nValue)
{
    m_angleX = static_cast<FLOAT>(nValue);
}

inline FLOAT CSkewParmeters::GetAngleX() const
{
    return m_angleX;
}

inline void CSkewParmeters::SetAngleY(int nValue)
{
    m_angleY = static_cast<FLOAT>(nValue);
}

inline FLOAT CSkewParmeters::GetAngleY() const
{
    return m_angleY;
}

inline void CSkewParmeters::SetCenter(int nCenterX, int nCenterY)
{
    m_center.x = static_cast<FLOAT>(nCenterX);
    m_center.y = static_cast<FLOAT>(nCenterY);
}

inline const CD2DPointF& CSkewParmeters::GetCenter() const
{
    return m_center;
}

inline CSkewParmeters& CSkewParmeters::operator=(const CSkewParmeters& params)
{
    if (this != &params)
    {
        SetRedrawFlag(params.GetRedrawFlag());
        m_angleX = params.m_angleX;
        m_angleY = params.m_angleY;
        m_center = params.m_center;
    }
    return *this;
}

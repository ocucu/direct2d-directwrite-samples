
inline void CScaleParameters::SetSize(FLOAT scaleX, FLOAT scaleY)
{
    m_size.width = scaleX;
    m_size.height = scaleY;
}

inline const CD2DSizeF& CScaleParameters::GetSize() const
{
    return m_size;
}

inline void CScaleParameters::SetCenter(int nCenterX, int nCenterY)
{
    m_center.x = static_cast<FLOAT>(nCenterX);
    m_center.y = static_cast<FLOAT>(nCenterY);
}

inline const CD2DPointF& CScaleParameters::GetCenter() const
{
    return m_center;
}

inline CScaleParameters& CScaleParameters::operator=(const CScaleParameters& params)
{
    if (this != &params)
    {
        SetRedrawFlag(params.GetRedrawFlag());
        m_size = params.m_size;
        m_center = params.m_center;
    }
    return *this;
}

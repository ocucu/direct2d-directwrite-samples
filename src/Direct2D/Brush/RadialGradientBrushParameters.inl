
inline void CRadialGradientBrushParameters::SetCenter(int x, int y)
{
    m_center.x = static_cast<FLOAT>(x);
    m_center.y = static_cast<FLOAT>(y);
}

inline CD2DPointF CRadialGradientBrushParameters::GetCenter() const
{
    return m_center;
}

inline void CRadialGradientBrushParameters::SetOffset(int x, int y)
{
    m_offset.x = static_cast<FLOAT>(x);
    m_offset.y = static_cast<FLOAT>(y);
}

inline CD2DPointF CRadialGradientBrushParameters::GetOffset() const
{
    return m_offset;
}

inline void CRadialGradientBrushParameters::SetRadiusX(int x)
{
    m_radiusX = static_cast<FLOAT>(x);
}

inline FLOAT CRadialGradientBrushParameters::GetRadiusX() const
{
    return m_radiusX;
}

inline void CRadialGradientBrushParameters::SetRadiusY(int y)
{
    m_radiusY = static_cast<FLOAT>(y);
}

inline FLOAT CRadialGradientBrushParameters::GetRadiusY() const
{
    return m_radiusY;
}

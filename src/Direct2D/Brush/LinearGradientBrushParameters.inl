
inline void CLinearGradientBrushParameters::SetStartPoint(int x, int y)
{
    m_startPoint.x = static_cast<FLOAT>(x);
    m_startPoint.y = static_cast<FLOAT>(y);
}

inline CD2DPointF CLinearGradientBrushParameters::GetStartPoint() const
{
    return m_startPoint;
}

inline void CLinearGradientBrushParameters::SetEndPoint(int x, int y)
{
    m_endPoint.x = static_cast<FLOAT>(x);
    m_endPoint.y = static_cast<FLOAT>(y);
}

inline CD2DPointF CLinearGradientBrushParameters::GetEndPoint() const
{
    return m_endPoint;
}

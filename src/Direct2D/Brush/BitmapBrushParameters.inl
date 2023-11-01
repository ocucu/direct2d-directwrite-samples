// File: BitmapBrushParameters.inl


inline void CBitmapBrushParameters::SetExtendModeX(DWORD_PTR dwValue)
{
    m_extendModeX = static_cast<D2D1_EXTEND_MODE>(dwValue);
}

inline D2D1_EXTEND_MODE CBitmapBrushParameters::GetExtendModeX() const
{
    return m_extendModeX;
}

inline void CBitmapBrushParameters::SetExtendModeY(DWORD_PTR dwValue)
{
    m_extendModeY = static_cast<D2D1_EXTEND_MODE>(dwValue);
}

inline D2D1_EXTEND_MODE CBitmapBrushParameters::GetExtendModeY() const
{
    return m_extendModeY;
}

inline void CBitmapBrushParameters::SetInterpolationMode(DWORD_PTR dwValue)
{
    m_interpolationMode = static_cast<D2D1_BITMAP_INTERPOLATION_MODE>(dwValue);
}

inline D2D1_BITMAP_INTERPOLATION_MODE CBitmapBrushParameters::GetInterpolationMode() const
{
    return m_interpolationMode;
}

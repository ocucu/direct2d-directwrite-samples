// File: SolidColorBrushParameters.inl - inline definitions for CSolidColorBrushParameters class
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/

inline void CSolidColorBrushParameters::SetColor(COLORREF color)
{
    m_color = CRenderTarget::COLORREF_TO_D2DCOLOR(color);
}

inline D2D1_COLOR_F CSolidColorBrushParameters::GetColor() const
{
    return m_color;
}

inline CSolidColorBrushParameters& CSolidColorBrushParameters::operator=(const CSolidColorBrushParameters& params)
{
    if (this != &params)
    {
        // inherited members
        SetTransformMatrix(params.GetTransformMatrix());
        SetOpacity(params.GetOpacity());
        // this class members
        m_color = params.m_color;
    }
    return *this;
}

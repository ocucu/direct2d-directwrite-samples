// File: SolidColorBrushParameters.h - CSolidColorBrushParameters class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/ 

#pragma once
#include "BrushParameters.h"

namespace Parameters
{
    class CSolidColorBrushParameters final : public CBrushParameters
    {
    public:
        // Data access
        void SetColor(COLORREF color);
        D2D1_COLOR_F GetColor() const;
        // Copy
        CSolidColorBrushParameters& operator=(const CSolidColorBrushParameters& params);
    private:
        // Data
        D2D1_COLOR_F m_color;
    };

#include "SolidColorBrushParameters.inl"
} // namespace Parameters

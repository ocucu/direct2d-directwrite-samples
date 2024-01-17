// File: DrawingEffectsParameters.h - CDrawingEffectsParameters class definition
// Author: Ovidiu Cucu - https://codexpertro.wordpress.com/
// e-mail: ovidiu.cucu.mvp@gmail.com 
// Purpose: encapsulates the drawing effects parameters
// Note: m_brushColor is used only for solid color brush (selected from "Brush type" menu)

#pragma once
#include "TextLayoutParameters.h"

namespace Parameters
{
    class CDrawingEffectsParameters final : public CTextLayoutParameters
    {
    public:
        // Data access
        void SetBrushColor(COLORREF color);
        D2D1_COLOR_F GetBrushColor() const;
        // Copy
        CDrawingEffectsParameters& operator=(const CDrawingEffectsParameters& params);
    private:
        // Data
        D2D1_COLOR_F m_brushColor{ D2D1::ColorF::Black };
    };

#include "DrawingEffectsParameters.inl"
} // namespace Parameters
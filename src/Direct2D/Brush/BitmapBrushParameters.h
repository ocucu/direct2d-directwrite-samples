// File: BitmapBrushParameters.h

#pragma once
#include "BrushParameters.h"

namespace Parameters
{
    class CBitmapBrushParameters final : public CBrushParameters
    {
    public:
        // Data access
        void SetExtendModeX(DWORD_PTR dwValue);
        D2D1_EXTEND_MODE GetExtendModeX() const;
        void SetExtendModeY(DWORD_PTR dwValue);
        D2D1_EXTEND_MODE GetExtendModeY() const;
        void SetInterpolationMode(DWORD_PTR dwValue);
        D2D1_BITMAP_INTERPOLATION_MODE GetInterpolationMode() const;
        // Copy
        CBitmapBrushParameters& operator=(const CBitmapBrushParameters& params);
    private:
        //Data
        D2D1_EXTEND_MODE m_extendModeX{ D2D1_EXTEND_MODE_CLAMP };
        D2D1_EXTEND_MODE m_extendModeY{ D2D1_EXTEND_MODE_CLAMP };
        D2D1_BITMAP_INTERPOLATION_MODE m_interpolationMode{ D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR };
    };

#include "BitmapBrushParameters.inl"
} // namespace Parameters



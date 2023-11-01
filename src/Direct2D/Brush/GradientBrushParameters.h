#pragma once
#include "BrushParameters.h"

namespace Parameters
{
    class CGradientBrushParameters : public CBrushParameters
    {
    protected:
        CGradientBrushParameters();
    public:
        // Data access
        void SetGradientStop(size_t index, const D2D1_GRADIENT_STOP& gradientStop);
        void SetGradientStopPosition(size_t index, FLOAT position);
        void SetGradientStopColor(size_t index, COLORREF color, int nAlpha = 255);
        D2D1_GRADIENT_STOP GetGradientStop(size_t index) const;
        FLOAT GetGradientStopPosition(size_t index) const;
        D2D1_COLOR_F GetGradientStopColor(size_t index) const;
        void SetColorInterpolationGamma(DWORD_PTR dwValue);
        void SetColorInterpolationGamma(D2D1_GAMMA gamma);
        D2D1_GAMMA GetColorInterpolationGamma() const;
        void SetExtendMode(DWORD_PTR dwValue);
        D2D1_EXTEND_MODE GetExtendMode() const;
    private:
        //Data
        static constexpr size_t m_gradientStopCount{ 3 };
        std::array<D2D1_GRADIENT_STOP, m_gradientStopCount> m_arrGradientStops;
        D2D1_GAMMA m_colorInterpolationGamma{ D2D1_GAMMA_2_2 };
        D2D1_EXTEND_MODE m_extendMode{ D2D1_EXTEND_MODE_CLAMP };
    };

#include "GradientBrushParameters.inl"
} // namespace Parameters


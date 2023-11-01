#pragma once
#include "GradientBrushParameters.h"

namespace Parameters
{
    class CLinearGradientBrushParameters final : public CGradientBrushParameters
    {
    public:
        // Data access
        void SetStartPoint(int x, int y);
        CD2DPointF GetStartPoint() const;
        void SetEndPoint(int x, int y);
        CD2DPointF GetEndPoint() const;
        // Copy
        CLinearGradientBrushParameters& operator=(const CLinearGradientBrushParameters& params);
    private:
        //Data
        CD2DPointF m_startPoint{0.f, 0.f};
        CD2DPointF m_endPoint{436.f, 326.f};
    };

#include "LinearGradientBrushParameters.inl"
} // namespace Parameters


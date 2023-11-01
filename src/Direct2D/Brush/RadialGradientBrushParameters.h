#pragma once
#include "GradientBrushParameters.h"

namespace Parameters
{
    class CRadialGradientBrushParameters : public CGradientBrushParameters
    {
    public:
        // Data access
        void SetCenter(int x, int y);
        CD2DPointF GetCenter() const;
        void SetOffset(int x, int y);
        CD2DPointF GetOffset() const;
        void SetRadiusX(int x);
        FLOAT GetRadiusX() const;
        void SetRadiusY(int y);
        FLOAT GetRadiusY() const;
        // Copy
        CRadialGradientBrushParameters& operator=(const CRadialGradientBrushParameters& params);
    private:
        //Data
        CD2DPointF m_center{ 0.f, 0.f };
        CD2DPointF m_offset{ 0.f, 0.f };
        FLOAT m_radiusX{ 0.f };
        FLOAT m_radiusY{ 0.f };
    };

#include "RadialGradientBrushParameters.inl"
} // namespace Parameters


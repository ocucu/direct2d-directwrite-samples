#pragma once

namespace Parameters
{
    class CScaleParameters : public CSampleParameters
    {
    public:
        // Data access
        void SetSize(FLOAT scaleX, FLOAT scaleY);
        const CD2DSizeF& GetSize() const;
        void SetCenter(int nCenterX, int nCenterY);
        const CD2DPointF& GetCenter() const;
        // Copy
        CScaleParameters& operator=(const CScaleParameters& params);
    private:
        // Data
        CD2DSizeF m_size;
        CD2DPointF m_center;
    };

#include "ScaleParameters.inl"
} // namespace Parameters


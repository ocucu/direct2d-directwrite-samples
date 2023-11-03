
#pragma once

namespace Parameters
{
    class CRotationParameters : public CSampleParameters
    {
    public:
        // Data access
        void SetAngle(int nValue);
        FLOAT GetAngle() const;
        void SetCenter(int nCenterX, int nCenterY);
        const CD2DPointF& GetCenter() const;
        // Copy
        CRotationParameters& operator=(const CRotationParameters& params);
    private:
        // Data
        FLOAT m_angle{ 0.f };
        CD2DPointF m_center{ 0.f, 0.f };
    };

#include "RotationParameters.inl"
} // namespace Parameters 



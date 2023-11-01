#pragma once

namespace Parameters
{
    class CSkewParmeters : public CSampleParameters
    {
    public:
        // Data access
        void SetAngleX(int nValue);
        FLOAT GetAngleX() const;
        void SetAngleY(int nValue);
        FLOAT GetAngleY() const;
        void SetCenter(int nCenterX, int nCenterY);
        const CD2DPointF& GetCenter() const;
        // Copy
        CSkewParmeters& operator=(const CSkewParmeters& params);
    private:
        // Data
        FLOAT m_angleX;
        FLOAT m_angleY;
        CD2DPointF m_center;
    };

#include "SkewParmeters.inl"
} // namespace Parameters 

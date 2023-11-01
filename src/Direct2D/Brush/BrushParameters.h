#pragma once

namespace Parameters
{
    class CBrushParameters : public CObject
    {
    public:
        // Data access
        void SetOpacity(FLOAT opacity) { m_opacity = opacity; }
        FLOAT GetOpacity() const { return m_opacity; }
        void SetTransformMatrix(const D2D1_MATRIX_3X2_F& matrix) { m_transformMatrix = matrix; }
        const D2D1_MATRIX_3X2_F& GetTransformMatrix() const { return m_transformMatrix; }
    private:
        // Data
        FLOAT m_opacity{ 0.f };
        D2D1_MATRIX_3X2_F m_transformMatrix{ D2D1::Matrix3x2F::Identity() };
    };
} // namespace parameters

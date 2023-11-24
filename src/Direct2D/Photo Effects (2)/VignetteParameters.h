#pragma once

namespace Parameters
{
    class CVignetteParameters final : public CObject
    {
    public:
        // Data access
        void SetColor(COLORREF color, FLOAT opacity);
        D2D1::ColorF GetColor() const;
        void SetTransitionSize(FLOAT value);
        FLOAT GetTransitionSize() const;
        void SetStrength(FLOAT value);
        FLOAT GetStrength() const;
        // Copy
        CVignetteParameters& operator=(const CVignetteParameters& params);
    private:
        // Data
        D2D1::ColorF m_color{ 0u, 1.f };
        FLOAT m_transitionSize{ 0.1f };
        FLOAT m_strength{ 0.5f };
    };

#include "VignetteParameters.inl"
} // namespace Parameters
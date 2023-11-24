#pragma once

namespace Parameters
{
    class CHighlightsAndShadowsParameters final : public CObject
    {
    public:
        // Data access
        void SetHighlights(FLOAT value);
        FLOAT GetHighlights() const;
        void SetShadows(FLOAT value);
        FLOAT GetShadows() const;
        void SetClarity(FLOAT value);
        FLOAT GetClarity() const;
        void SetInputGamma(DWORD_PTR dwValue);
        D2D1_HIGHLIGHTSANDSHADOWS_INPUT_GAMMA GetInputGamma() const;
        void SetMaskBlurRadius(FLOAT value);
        FLOAT GetMaskBlurRadius() const;
        // Copy
        CHighlightsAndShadowsParameters& operator=(const CHighlightsAndShadowsParameters& params);
    private:
        // Data
        FLOAT m_highlights{ 0.f };
        FLOAT m_shadows{ 0.f };
        FLOAT m_clarity{ 0.f };
        D2D1_HIGHLIGHTSANDSHADOWS_INPUT_GAMMA m_inputGamma{ D2D1_HIGHLIGHTSANDSHADOWS_INPUT_GAMMA_LINEAR };
        FLOAT m_maskBlurRadius{ 1.25f };
    };

#include "HighlightsAndShadowsParameters.inl"
} // namespace Parameters

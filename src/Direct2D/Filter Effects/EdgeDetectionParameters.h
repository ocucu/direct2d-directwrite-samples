#pragma once

namespace Parameters
{
    class CEdgeDetectionParameters final : public CObject
    {
    public:
        // Data access
        void SetStrength(FLOAT value);
        FLOAT GetStrength() const;
        void SetBlurRadius(FLOAT value);
        FLOAT GetBlurRadius() const;
        void SetMode(DWORD_PTR dwValue);
        D2D1_EDGEDETECTION_MODE GetMode() const;
        void SetOverlayEdges(BOOL bValue);
        BOOL GetOverlayEdges() const;
        void SetAlphaMode(DWORD_PTR dwValue);
        D2D1_ALPHA_MODE GetAlphaMode() const;
        // Copy
        CEdgeDetectionParameters& operator=(const CEdgeDetectionParameters& params);

    private:
        // Data
        FLOAT m_strength{ 0.5f };
        FLOAT m_blurRadius{ 0.f };
        D2D1_EDGEDETECTION_MODE m_mode;
        BOOL m_bOverlayEdges{ FALSE };
        D2D1_ALPHA_MODE m_alphaMode{ D2D1_ALPHA_MODE_PREMULTIPLIED };
    };

#include "EdgeDetectionParameters.inl"
} // namespace Parameters
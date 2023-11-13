#pragma once

namespace Parameters
{
    class CSepiaParameters final : public CObject
    {
    public:
        // Data access
        void SetIntensity(FLOAT value);
        FLOAT GetIntensity() const;
        void SetAlphaMode(DWORD_PTR dwValue);
        D2D1_ALPHA_MODE GetAlphaMode() const;
        // Copy
        CSepiaParameters& operator=(const CSepiaParameters& params);
    private:
        // Data
        FLOAT m_intensity{ 0.5f };
        D2D1_ALPHA_MODE m_alphaMode{ D2D1_ALPHA_MODE_PREMULTIPLIED };

    };

#include "SepiaParameters.inl"
} // namespace Parameters

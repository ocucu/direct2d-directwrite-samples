#pragma once

namespace Parameters
{
    class CMorphologyParameters final : public CObject
    {
    public:
        // Data access
        void SetMode(DWORD_PTR dwValue);
        D2D1_MORPHOLOGY_MODE GetMode() const;
        void SetWidth(int nValue);
        UINT GetWidth() const;
        void SetHeight(int nValue);
        UINT GetHeight() const;

        // Copy
        CMorphologyParameters& operator=(const CMorphologyParameters& params);
    private:
        // Data
        D2D1_MORPHOLOGY_MODE m_mode;
        UINT m_width{ 1 };
        UINT m_height{ 1 };
    };

#include "MorphologyParameters.inl"
} // namespace Parameters

#pragma once

namespace Parameters
{
    class CContrastParameters final : public CObject
    {
    public:
        // Data access
        void SetContrast(FLOAT value);
        FLOAT GetContrast() const;
        void SetClampInput(BOOL bValue);
        BOOL GetClampInput() const;
        // Copy
        CContrastParameters& operator=(const CContrastParameters& params);
    private:
        // Data
        FLOAT m_contrast{ 0.f };
        BOOL m_clampInput{ FALSE };
    };

#include "ContrastParameters.inl"
} // namespace Parameters


#pragma once

namespace Parameters
{
    class CBrightnessParameters final : public CObject
    {
    public:
        // Data access
        void SetWhitePoint(const D2D1_VECTOR_2F& value);
        D2D1_VECTOR_2F GetWhitePoint() const;
        void SetBlackPoint(const D2D1_VECTOR_2F& value);
        D2D1_VECTOR_2F GetBlackPoint() const;
        // Copy
        CBrightnessParameters& operator=(const CBrightnessParameters& params);
    private:
        // Data
        D2D1_VECTOR_2F m_whitePoint{ 1.f, 1.f };
        D2D1_VECTOR_2F m_blackPoint{ 0.f, 0.f };
    };

#include "BrightnessParameters.inl"
} // namespace Parameters 



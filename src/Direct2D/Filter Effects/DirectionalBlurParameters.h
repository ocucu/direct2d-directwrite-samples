
#pragma once
#include "GaussianBlurParameters.h"
namespace Parameters
{
    class CDirectionalBlurParameters final : public CGaussianBlurParameters
    {
    public:
        // Data access
        void SetAngle(FLOAT value);
        FLOAT GetAngle() const;
        // Copy
        CDirectionalBlurParameters& operator=(const CDirectionalBlurParameters& params);
    private:
        // Data
        FLOAT m_angle{ 0.f };
    };

#include "DirectionalBlurParameters.inl"
} // namespace Parameters 



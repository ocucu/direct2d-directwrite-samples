#include "pch.h"
#include "RadialGradientBrushParameters.h"

using Parameters::CRadialGradientBrushParameters;

CRadialGradientBrushParameters& CRadialGradientBrushParameters::operator=(const CRadialGradientBrushParameters& params)
{
    if (this != &params)
    {
        // inherited from CBrushParameters
        SetTransformMatrix(params.GetTransformMatrix());
        SetOpacity(params.GetOpacity());
        // inherited from CGradientBrushParameters 
        SetExtendMode(params.GetExtendMode());
        SetGradientStop(0, params.GetGradientStop(0));
        SetGradientStop(1, params.GetGradientStop(1));
        SetGradientStop(2, params.GetGradientStop(2));
        SetColorInterpolationGamma(params.GetColorInterpolationGamma());
        SetExtendMode(params.GetExtendMode());
        // this class members
        m_center = params.m_center;
        m_offset = params.m_offset;
        m_radiusX = params.m_radiusX;
        m_radiusY = params.m_radiusY;
    }
    return *this;
}

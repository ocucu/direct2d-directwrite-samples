#include "pch.h"
#include "LinearGradientBrushParameters.h"

using Parameters::CLinearGradientBrushParameters;

CLinearGradientBrushParameters& CLinearGradientBrushParameters::operator=(const CLinearGradientBrushParameters& params)
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
        m_startPoint = params.m_startPoint;
        m_endPoint = params.m_endPoint;
    }
    return *this;
}
#include "pch.h"
#include "BitmapBrushParameters.h"

using Parameters::CBitmapBrushParameters;

CBitmapBrushParameters& CBitmapBrushParameters::operator=(const CBitmapBrushParameters& params)
{
    if (this != &params)
    {
        // inherited from CBrushParameters
        SetTransformMatrix(params.GetTransformMatrix());
        SetOpacity(params.GetOpacity());
        // this class members
        m_extendModeX = params.m_extendModeX;
        m_extendModeY = params.m_extendModeY;
        m_interpolationMode = params.m_interpolationMode;
    }
    return *this;
}
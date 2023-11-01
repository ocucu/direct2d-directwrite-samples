#include "pch.h"
#include "GradientBrushParameters.h"

using Parameters::CGradientBrushParameters;

CGradientBrushParameters::CGradientBrushParameters()
{
    m_arrGradientStops[0].position = 0.f;
    m_arrGradientStops[0].color = D2D1::ColorF(D2D1::ColorF::Red);
    m_arrGradientStops[1].position = 0.5f;
    m_arrGradientStops[1].color = D2D1::ColorF(D2D1::ColorF::Green);
    m_arrGradientStops[2].position = 1.f;
    m_arrGradientStops[2].color = D2D1::ColorF(D2D1::ColorF::Blue);
}
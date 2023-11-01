// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here
#include "framework.h"

#include "DemoFramework.h"
#include "Resource.h"

// sample identifiers
enum class SampleId
{
    unknown = 0,
    solidColorBrush,
    bitmapBrush,
    linearGradientBrush,
    radialGradientBrush,
};

enum class FigureId
{
    unknown = 0,
    none,
    rectangle,
    ellipse,
};

enum class BitmapId
{
    unknown = 0,
    colorMatrix,
    cat,
    mfcIcon,
};

// view updat hints
enum class UpdateHint : LPARAM
{
    demoDocumentChanged = 0,
    solidColorBrushChanged,
    bitmapBrushChanged,
    linearGradientBrushChanged,
    radialGradientBrushChanged,
};

#endif //PCH_H

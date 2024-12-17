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
enum class SampleId : UINT
{
    unknown = 0,
    translation,
    rotation,
    scale,
    skew,
};

enum class BrushTypeId : UINT
{
    unknown = 0,
    bitmap,
    linearGradient,
    radialGradient,
};

// view updat hints
enum class UpdateHint : LPARAM
{
    demoDocumentChanged = 0,
    translationChanged,
    rotationChanged,
    scaleChanged,
    skewChanged,
};


#endif //PCH_H
